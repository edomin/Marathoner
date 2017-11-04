#include "png_include.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Png, FA_FUNCTIONS_COUNT)

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "PNG_libpng";
    report->version = MTR_VERSION_PNG_LIBPNG;
    report->subsystem = "png";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

/*fa MTR_PngInit yes */
MTR_DCLSPC void MTR_CALL MTR_PngInit(void)
{
    MTR_LogWrite("Initializing PNG format support", 0, MTR_LMT_INFO);

    MTR_LogWrite_s("Reporting libpng compile-time version:", 1, MTR_LMT_INFO,
     PNG_LIBPNG_VER_STRING);
    MTR_LogWrite_s("Reporting libpng linked version:", 1, MTR_LMT_INFO,
     png_libpng_ver);
    MTR_LogWrite_s("Reporting zlib compile-time version:", 1, MTR_LMT_INFO,
     ZLIB_VERSION);
    MTR_LogWrite_s("Reporting zlib linked version:", 1, MTR_LMT_INFO,
     zlib_version);

    tempPixels = NULL;

    MTR_LogWrite("PNG format support initialized", 0, MTR_LMT_INFO);
}

/*fa MTR_PngLoadFast yes */
MTR_DCLSPC mtrPixels_t *MTR_CALL MTR_PngLoadFast(const char *filename)
{
    FILE         *file;
    unsigned char singature[8];
    png_structp   pngPtr;
    png_infop     infoPtr;
    png_byte      colorType;
    png_byte      bitPerSample; /* bits per sample--R, G, B, A, or gray--or per
                                 * palette index, not per pixel */
//    png_color_16p bgColor;
//    uint8_t       bgRed;
//    uint8_t       bgGreen;
//    uint8_t       bgBlue;
    double        gamma;
//    int           channels;
    int           i;
    uint8_t     **row;

    if (filename == NULL)
        return NULL;

    if (tempPixels != NULL) {
        if (tempPixels->data != NULL)
            free(tempPixels->data);
        free(tempPixels);
    }

    file = fopen(filename, "rb");
    if (file == NULL)
        return NULL;

    fread(singature, 1, 8, file);
    #if PNG_LIBPNG_VER < 10400 /* 1.4.0 */
    if (!png_check_sig(singature, 8))
    #else
    if (png_sig_cmp(singature, 0, 8) != 0)
    #endif
    {
        fclose(file);
        return NULL;
    }

    pngPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (pngPtr == NULL) {
        fclose(file);
        return NULL;
    }

    infoPtr = png_create_info_struct(pngPtr);
    if (infoPtr == NULL) {
        fclose(file);
        png_destroy_read_struct(&pngPtr, NULL, NULL);
        return NULL;
    }

    if (setjmp(png_jmpbuf(pngPtr))) {
        fclose(file);
        png_destroy_read_struct(&pngPtr, NULL, NULL);
        return NULL;
    }

//    if (setjmp(pngPtr->jmpbuf)) {
//        fclose(file);
//        png_destroy_read_struct(&pngPtr, &infoPtr, NULL);
//        return NULL;
//    }

    png_init_io(pngPtr, file);
    png_set_sig_bytes(pngPtr, 8);
    png_read_info(pngPtr, infoPtr);

    tempPixels = malloc(sizeof(mtrPixels_t));
    if (tempPixels == NULL) {
        fclose(file);
        png_destroy_read_struct(&pngPtr, &infoPtr, NULL);
        return NULL;
    }

    tempPixels->data = NULL;
    tempPixels->w = png_get_image_width(pngPtr, infoPtr);
    tempPixels->h = png_get_image_height(pngPtr, infoPtr);
    tempPixels->pixelformat = MTR_PF_RGBA;
    colorType = png_get_color_type(pngPtr, infoPtr);
    bitPerSample = png_get_bit_depth(pngPtr, infoPtr);

    if (png_get_valid(pngPtr, infoPtr, PNG_INFO_bKGD) == 0) {
        fclose(file);
        png_destroy_read_struct(&pngPtr, &infoPtr, NULL);
        free(tempPixels);
        return NULL;
    }

//    png_get_bKGD(pngPtr, infoPtr, &bgColor);
//
//    if (bitPerSample == 16) {
//        bgRed = bgColor->red   >> 8;
//        bgGreen = bgColor->green >> 8;
//        bgBlue = bgColor->blue  >> 8;
//    } else if (colorType == PNG_COLOR_TYPE_GRAY && bitPerSample < 8) {
//        if (bitPerSample == 1) {
//            if (bgColor->gray == 1) {
//                bgRed = 255;
//                bgGreen = 255;
//                bgBlue = 255;
//            } else {
//                bgRed = 0;
//                bgGreen = 0;
//                bgBlue = 0;
//            }
//        } else if (bitPerSample == 2) {   /* i.e., max value is 3 */
//            bgRed = (255 / 3) * bgColor->gray;
//            bgGreen = (255 / 3) * bgColor->gray;
//            bgBlue = (255 / 3) * bgColor->gray;
//        } else { /* bitPerSample == 4 */  /* i.e., max value is 15 */
//            bgRed = (255 / 15) * bgColor->gray;
//            bgGreen = (255 / 15) * bgColor->gray;
//            bgBlue = (255 / 15) * bgColor->gray;
//        }
//    } else {
//        bgRed = bgColor->red;
//        bgGreen = bgColor->green;
//        bgBlue = bgColor->blue;
//    }


    if (colorType == PNG_COLOR_TYPE_PALETTE) {
        #if PNG_LIBPNG_VER >= 10004 /* 1.0.4 */
        png_set_palette_to_rgb(pngPtr);
        #else
        png_set_expand(pngPtr);
        #endif
    }

    if (colorType == PNG_COLOR_TYPE_GRAY && bitPerSample < 8) {
        #if PNG_LIBPNG_VER >= 10209 /* 1.2.9 */
        png_set_expand_gray_1_2_4_to_8(pngPtr);
        #else
        png_set_expand(pngPtr);
        #endif
    }

    if (png_get_valid(pngPtr, infoPtr, PNG_INFO_tRNS)) {
        #if PNG_LIBPNG_VER >= 10004 /* 1.0.4 */
        png_set_tRNS_to_alpha(pngPtr);
        #else
        png_set_expand(pngPtr);
        #endif
    }

    if (bitPerSample == 16)
        png_set_strip_16(pngPtr);
    if (colorType == PNG_COLOR_TYPE_GRAY ||
     colorType == PNG_COLOR_TYPE_GRAY_ALPHA)
        png_set_gray_to_rgb(pngPtr);

    if (png_get_gAMA(pngPtr, infoPtr, &gamma))
        png_set_gamma(pngPtr, MTR_PNG_DEFAULT_DISPLAY_GAMMA, gamma);
    else
        png_set_gamma(pngPtr, MTR_PNG_DEFAULT_DISPLAY_GAMMA,
         MTR_PNG_DEFAULT_IMAGE_GAMMA);

    png_read_update_info(pngPtr, infoPtr);
    if (setjmp(png_jmpbuf(pngPtr))) {
        fclose(file);
        png_destroy_read_struct(&pngPtr, NULL, NULL);
        free(tempPixels);
        tempPixels = NULL;
        return NULL;
    }

    tempPixels->pitch = png_get_rowbytes(pngPtr, infoPtr);
//    channels = png_get_channels(pngPtr, infoPtr);

    tempPixels->data = malloc(
     sizeof(uint8_t) * tempPixels->pitch * tempPixels->h);
    if (tempPixels->data == NULL) {
        fclose(file);
        png_destroy_read_struct(&pngPtr, &infoPtr, NULL);
        free(tempPixels);
        tempPixels = NULL;
        return NULL;
    }

    row = malloc(sizeof(uint8_t *) * tempPixels->h);
    if (row == NULL) {
        fclose(file);
        png_destroy_read_struct(&pngPtr, &infoPtr, NULL);
        free(tempPixels->data);
        tempPixels->data = NULL;
        free(tempPixels);
        tempPixels = NULL;
        return NULL;
    }
    for (i = 0; i < tempPixels->h; i++)
        row[i] = tempPixels->data + i * tempPixels->pitch;

    png_read_image(pngPtr, row);
    png_read_end(pngPtr, NULL);

    fclose(file);
    png_destroy_read_struct(&pngPtr, &infoPtr, NULL);
    pngPtr = NULL;
    infoPtr = NULL;
    free(row);

    return tempPixels;
}

/*fa MTR_PngSaveFast yes */
MTR_DCLSPC bool MTR_CALL MTR_PngSaveFast(const char *filename,
 mtrPixels_t *pixels)
{
    FILE        *file;
    png_structp  pngPtr;
    png_infop    infoPtr;
    time_t       currentTime;
    png_time     creationTime;
    int          i;
    uint8_t    **row;

    if (filename == NULL) {
        MTR_LogWrite("PNG not saved. Filename is empty", 0, MTR_LMT_ERROR);
        return false;
    }

    if (pixels == NULL) {
        MTR_LogWrite(
         "PNG not saved. Pointer to pixels' structure are not valid", 0,
         MTR_LMT_ERROR);
        return false;
    }

    if (pixels->data == NULL) {
        MTR_LogWrite(
         "PNG not saved. Pointer to pixels' data are not valid", 0,
         MTR_LMT_ERROR);
        return false;
    }

    file = fopen(filename, "wb");
    if (file == NULL) {
        MTR_LogWrite("PNG not saved. Unable to open file for binary write", 0,
         MTR_LMT_ERROR);
        return false;
    }

    pngPtr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (pngPtr == NULL) {
        MTR_LogWrite("PNG not saved. Unable to initialize libpng write struct",
         0, MTR_LMT_ERROR);
        fclose(file);
        return false;
    }

    infoPtr = png_create_info_struct(pngPtr);
    if (infoPtr == NULL) {
        MTR_LogWrite("PNG not saved. Unable to initialize libpng info struct",
         0, MTR_LMT_ERROR);
        png_destroy_write_struct(&pngPtr, NULL);
        fclose(file);
        return false;
    }

    if (setjmp(png_jmpbuf(pngPtr))) {
        MTR_LogWrite(
         "PNG not saved. The error occured while initializing libpng info "
         "struct", 0, MTR_LMT_ERROR);
        png_destroy_write_struct(&pngPtr, NULL);
        fclose(file);
        return false;
    }

    png_init_io(pngPtr, file);
    if (setjmp(png_jmpbuf(pngPtr))) {
        MTR_LogWrite("PNG not saved. Unable to initialize default libpng I/O",
         0, MTR_LMT_ERROR);
        png_destroy_write_struct(&pngPtr, NULL);
        fclose(file);
        return false;
    }

    png_set_compression_level(pngPtr, Z_BEST_COMPRESSION);

    png_set_IHDR(pngPtr, infoPtr, pixels->w, pixels->h, 8,
     PNG_COLOR_TYPE_RGB_ALPHA, PNG_INTERLACE_NONE,
     PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

    png_set_gAMA(pngPtr, infoPtr, MTR_PNG_DEFAULT_IMAGE_GAMMA);

    currentTime = time(NULL);
    png_convert_from_time_t(&creationTime, currentTime);
    png_set_tIME(pngPtr, infoPtr, &creationTime);

    png_write_info(pngPtr, infoPtr);
    if (setjmp(png_jmpbuf(pngPtr))) {
        MTR_LogWrite("PNG not saved. Unable to write data chunks to file", 0,
         MTR_LMT_ERROR);
        png_destroy_write_struct(&pngPtr, NULL);
        fclose(file);
        return false;
    }

    row = malloc(sizeof(uint8_t *) * pixels->h);
    if (row == NULL) {
        MTR_LogWrite(
         "PNG not saved. Unable to allocate memory for image rows' pointers", 0,
         MTR_LMT_ERROR);
        png_destroy_write_struct(&pngPtr, NULL);
        fclose(file);
        return false;
    }
    for (i = 0; i < pixels->h; i++)
        row[i] = pixels->data + i * pixels->pitch;

    png_write_image(pngPtr, row);
    if (setjmp(png_jmpbuf(pngPtr))) {
        MTR_LogWrite("PNG not saved. Unable to write pixels to image", 0,
         MTR_LMT_ERROR);
        png_destroy_write_struct(&pngPtr, NULL);
        fclose(file);
        return false;
    }
    png_write_end(pngPtr, NULL);

    free(row);
    png_destroy_write_struct(&pngPtr, NULL);
    fclose(file);

    return true;
}
