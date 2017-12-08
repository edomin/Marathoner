#include "ttf.h"

#ifdef MTR_MOD_PLUGIN
#include "marathoner/plugin_common.c"

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "TTF_FreeType2";
    report->version = MTR_VERSION_TTF_FREETYPE2;
    report->subsystem = "ttf";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}
#endif

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Ttf, FA_FUNCTIONS_COUNT)

/*fa MTR_TtfInit yes */
MTR_DCLSPC bool MTR_CALL MTR_TtfInit(uint32_t dmSize, uint32_t reservedCount)
{
    FT_Int major;
    FT_Int minor;
    FT_Int patch;

    MTR_LogWrite("Initializing TTF font format support", 0, MTR_LMT_INFO);

    MTR_LogWrite("Reporting FreeType2 compile-time version:", 1, MTR_LMT_INFO);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, FREETYPE_MAJOR);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, FREETYPE_MINOR);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, FREETYPE_PATCH);

    mtrFtError = FT_Init_FreeType(&mtrFtLibrary);
    if (mtrFtError) {
        MTR_Notify("Unable to initialize FreeType2 library", 1, MTR_LMT_ERROR);
        return false;
    }

    FT_Library_Version(mtrFtLibrary, &major, &minor, &patch);
    MTR_LogWrite("Reporting FreeType2 linked version:", 1, MTR_LMT_INFO);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, patch);

    tempPixels = NULL;

    mtrTtfKeeper = (mtrIndexkeeper_t *)MTR_IndexkeeperCreate(dmSize,
     reservedCount, sizeof(mtrTtf_t));
    if (mtrTtfKeeper == NULL) {
        MTR_Notify("Unable to initialize TTF font format support", 1,
         MTR_LMT_ERROR);
        FT_Done_FreeType(mtrFtLibrary);
        return false;
    }
    else
        MTR_LogWrite("TTF font format support initialized", 0, MTR_LMT_INFO);

    mtrTtfInited = true;
    return true;
}

/*fa MTR_TtfQuit yes */
MTR_DCLSPC void MTR_CALL MTR_TtfQuit(void)
{
    MTR_TTF_CHECK_IF_NOT_INITED_WITH_LOG(
     "Unable to destroy TTF font format support",);

    MTR_LogWrite("Destroying TTF font manager", 0, MTR_LMT_INFO);
    mtrFtError = FT_Done_FreeType(mtrFtLibrary);
    if (mtrFtError)
        MTR_LogWrite("Unable to destroy FreeType2 library", 1, MTR_LMT_ERROR);
    MTR_LogWrite("TTF font manager destroyed", 0, MTR_LMT_INFO);
}

bool MTR_TtfLoadFace(mtrTtf_t *font, const char *filename, int index)
{
    mtrFtError = FT_New_Face(mtrFtLibrary, filename, index,
     &font->face[index].face);
    if (mtrFtError == FT_Err_Unknown_File_Format) {
        MTR_LogWrite_i(
         "Unable to create face object from index. Unknown file format", 1,
         MTR_LMT_ERROR, index);
        font->face[index].face = NULL;
        return false;
    } else if (mtrFtError) {
        MTR_LogWrite_i("Unable to create face object from index", 1,
         MTR_LMT_ERROR, index);
        MTR_LogWrite_i("FreeType2 errorcode:", 1, MTR_LMT_ERROR, mtrFtError);
        font->face[index].face = NULL;
        return false;
    }
    return true;
}

/*fa MTR_TtfLoad yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_TtfLoad(const char *filename)
{
    uint32_t  freeIndex;
    mtrTtf_t *font;
    FT_Face   facesCount;
    int       i;
    MTR_TTF_CHECK_IF_NOT_INITED_WITH_LOG("Unable to load TTF font", 0U);

    if (filename == NULL) {
        MTR_Notify("Unable to load ttf-font. Filename is is not valid", 0,
         MTR_LMT_ERROR);
        return 0U;
    }

    MTR_LogWrite_s("Loading TTF font", 0, MTR_LMT_INFO, filename);
    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrTtfKeeper);
    MTR_LogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, freeIndex);

    mtrFtError = FT_New_Face(mtrFtLibrary, filename, -1, &facesCount);
    if (mtrFtError) {
        MTR_LogWrite("Unable to get font faces count", 1, MTR_LMT_WARNING);
        font->facesCount = 1;
    } else {
        font->facesCount = facesCount->num_faces;
        MTR_LogWrite_i("Faces count:", 1, MTR_LMT_INFO, font->facesCount);
    }

    font->face = malloc(sizeof(mtrTtfFace_t) * font->facesCount);
    if (font->face == NULL) {
        MTR_LogWrite("Unable to allocate memory for font faces", 1,
         MTR_LMT_ERROR);
        return 0U;
    }

    for (i = 0; i < font->facesCount; i++) {
        if (!MTR_TtfLoadFace(font, filename, i))
            continue;
    }
    font->currentFace = 0;
    font->width = 0;
    font->height = 0;

    MTR_LogWrite_s("TTF font loaded", 0, MTR_LMT_INFO, filename);
    return freeIndex;
}

/*fa MTR_TtfFree yes */
MTR_DCLSPC void MTR_CALL MTR_TtfFree(uint32_t fontNum)
{
    mtrTtf_t *font;
    int       i;
    MTR_TTF_CHECK_IF_NOT_INITED_WITH_LOG("Unable to unload TTF font",);

    if (fontNum == 0)
        return;
    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);
    MTR_LogWrite_s("Unloading TTF font", 0, MTR_LMT_INFO, font->name);
    if (font->name != mtrDefaultTTFName)
        free(font->name);
    for (i = 0; i < font->facesCount; i++) {
        mtrFtError = FT_Done_Face(font->face[i].face);
        if (mtrFtError) {
            MTR_LogWrite_i("Error occured while unloading TTF face with index",
             1, MTR_LMT_ERROR, i);
            MTR_LogWrite_i("FreeType2 errorcode:", 1, MTR_LMT_ERROR,
             mtrFtError);
        }
    }
    free(font->face);
    MTR_IndexkeeperFreeIndex(mtrTtfKeeper, fontNum);
    MTR_LogWrite("TTF font unloaded", 0, MTR_LMT_INFO);
}

/*fa MTR_TtfGetWidth yes */
MTR_DCLSPC int MTR_CALL MTR_TtfGetWidth(uint32_t fontNum)
{
    mtrTtf_t *font;
    MTR_TTF_CHECK_IF_NOT_INITED(0);

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);

    return font->width;
}

/*fa MTR_TtfGetHeight yes */
MTR_DCLSPC int MTR_CALL MTR_TtfGetHeight(uint32_t fontNum)
{
    mtrTtf_t *font;
    MTR_TTF_CHECK_IF_NOT_INITED(0);

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);

    return font->height;
}

/*fa MTR_TtfGetSizes yes */
MTR_DCLSPC void MTR_CALL MTR_TtfGetSizes(uint32_t fontNum, int *width,
 int *height)
{
    mtrTtf_t *font;
    MTR_TTF_CHECK_IF_NOT_INITED();

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);

    *width = font->width;
    *height = font->height;
}

/*fa MTR_TtfSetSizes yes */
MTR_DCLSPC bool MTR_CALL MTR_TtfSetSizes(uint32_t fontNum, int width,
 int height)
{
    mtrTtf_t *font;
    MTR_TTF_CHECK_IF_NOT_INITED(false);

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);
    FT_Set_Pixel_Sizes(font->face[font->currentFace].face, width, height);
    font->width = width;
    font->height = height;

    return true;
}

/*fa MTR_TtfGetGlyphSizes yes */
MTR_DCLSPC void MTR_CALL MTR_TtfGetGlyphSizes(uint32_t fontNum,
 uint32_t glyph, int *w, int *h)
{
    mtrTtf_t        *font;
    FT_UInt          glyph_index;
    FT_GlyphSlot     faceGlyph;
    MTR_TTF_CHECK_IF_NOT_INITED();

    if (fontNum == 0) {
        *w = 0;
        *h = 0;
        return;
    }
    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);

    glyph_index = FT_Get_Char_Index(font->face[font->currentFace].face, glyph);
    mtrFtError = FT_Load_Glyph(font->face[font->currentFace].face, glyph_index,
     FT_LOAD_DEFAULT);
    if (mtrFtError) {
        *w = 0;
        *h = 0;
        return;
    }
    faceGlyph = font->face[font->currentFace].face->glyph;

    if (faceGlyph->format != FT_GLYPH_FORMAT_BITMAP)
    {
        mtrFtError = FT_Render_Glyph(faceGlyph,
         FT_RENDER_MODE_NORMAL);
        if (mtrFtError) {
            *w = 0;
            *h = 0;
            return;
        }
    }

    *w = faceGlyph->bitmap.width;
    *h = faceGlyph->bitmap.rows;
}

/*fa MTR_TtfGetGlyphWidth yes */
MTR_DCLSPC int MTR_CALL MTR_TtfGetGlyphWidth(uint32_t fontNum, uint32_t glyph)
{
    mtrTtf_t        *font;
    FT_UInt          glyph_index;
    FT_GlyphSlot     faceGlyph;
    MTR_TTF_CHECK_IF_NOT_INITED(0);

    if (fontNum == 0)
        return 0;
    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);

    glyph_index = FT_Get_Char_Index(font->face[font->currentFace].face, glyph);
    mtrFtError = FT_Load_Glyph(font->face[font->currentFace].face, glyph_index,
     FT_LOAD_DEFAULT);
    if (mtrFtError)
        return 0;
    faceGlyph = font->face[font->currentFace].face->glyph;

    if (faceGlyph->format != FT_GLYPH_FORMAT_BITMAP)
    {
        mtrFtError = FT_Render_Glyph(faceGlyph,
         FT_RENDER_MODE_NORMAL);
        if (mtrFtError)
            return 0;
    }

    return faceGlyph->bitmap.width;
}

/*fa MTR_TtfGetGlyphHeight yes */
MTR_DCLSPC int MTR_CALL MTR_TtfGetGlyphHeight(uint32_t fontNum, uint32_t glyph)
{
    mtrTtf_t        *font;
    FT_UInt          glyph_index;
    FT_GlyphSlot     faceGlyph;
    MTR_TTF_CHECK_IF_NOT_INITED(0);

    if (fontNum == 0)
        return 0;
    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);

    glyph_index = FT_Get_Char_Index(font->face[font->currentFace].face, glyph);
    mtrFtError = FT_Load_Glyph(font->face[font->currentFace].face, glyph_index,
     FT_LOAD_DEFAULT);
    if (mtrFtError)
        return 0;
    faceGlyph = font->face[font->currentFace].face->glyph;

    if (faceGlyph->format != FT_GLYPH_FORMAT_BITMAP)
    {
        mtrFtError = FT_Render_Glyph(faceGlyph,
         FT_RENDER_MODE_NORMAL);
        if (mtrFtError)
            return 0;
    }

    return faceGlyph->bitmap.rows;
}

/*fa MTR_TtfRenderGlyph yes */
MTR_DCLSPC mtrPixels_t *MTR_CALL MTR_TtfRenderGlyph(uint32_t fontNum,
 uint8_t r, uint8_t g, uint8_t b, uint32_t glyph)
{
    mtrTtf_t        *font;
    FT_UInt          glyph_index;
//    FT_Bitmap        ConvertedBitmap;
    FT_GlyphSlot     faceGlyph;
    unsigned int     i;
    unsigned int     j;
    uint8_t         *tempPixelsData;
    unsigned int     glyphWidth;

    MTR_TTF_CHECK_IF_NOT_INITED(NULL);

    if (tempPixels != NULL)
        free(tempPixels);

    if (fontNum == 0)
        return NULL;
    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);

    glyph_index = FT_Get_Char_Index(font->face[font->currentFace].face, glyph);
    mtrFtError = FT_Load_Glyph(font->face[font->currentFace].face, glyph_index,
     FT_LOAD_DEFAULT);
    if (mtrFtError)
        return NULL;
    faceGlyph = font->face[font->currentFace].face->glyph;

    if (faceGlyph->format != FT_GLYPH_FORMAT_BITMAP)
    {
        mtrFtError = FT_Render_Glyph(faceGlyph,
         FT_RENDER_MODE_NORMAL);
        if (mtrFtError)
            return NULL;
    }
//
//    mtrFtError = FT_Bitmap_Convert(mtrFtLibrary,
//     &faceGlyph->bitmap, &ConvertedBitmap, 1);
//    if (mtrFtError)
//        return NULL;
    tempPixels = malloc(sizeof(mtrPixels_t));
    if (tempPixels == NULL)
        return NULL;

    glyphWidth = faceGlyph->bitmap.width;

    tempPixelsData = malloc(
     sizeof(uint8_t) * 4 * faceGlyph->bitmap.rows * glyphWidth);
    if (tempPixelsData == NULL)
        return NULL;

    for (i = 0; i < glyphWidth; i++) {
        for (j = 0; j < faceGlyph->bitmap.rows; j++) {
            int redByte = i * 4 + j * glyphWidth * 4;
            int greenByte = i * 4 + j * glyphWidth * 4 + 1;
            int blueByte = i * 4 + j * glyphWidth * 4 + 2;
            int alphaByte = i * 4 + j * glyphWidth * 4 + 3;
            tempPixelsData[redByte] = r;
            tempPixelsData[greenByte] = g;
            tempPixelsData[blueByte] = b;
            tempPixelsData[alphaByte] = faceGlyph->bitmap.buffer[
             i + j * glyphWidth];
        }
    }
    tempPixels->data = tempPixelsData;

    tempPixels->w = glyphWidth;
    tempPixels->h = faceGlyph->bitmap.rows;
    tempPixels->pitch = faceGlyph->bitmap.pitch * 4;
    tempPixels->pixelformat = MTR_PF_RGBA;
    return tempPixels;
}
