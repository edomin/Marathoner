#include "texture.h"

#include "plugin_common.c"
__declspec(dllexport) void __stdcall mtrTextureInit(uint16_t reservedCount)
{
    mtrLogWrite("Initializing texture manager", 0, MTR_LMT_INFO);
    reservedTextures = reservedCount;
    /* flooring to nearest power of 2 */
    reservedTextures = reservedTextures | (reservedTextures >> 1);
    reservedTextures = reservedTextures | (reservedTextures >> 2);
    reservedTextures = reservedTextures | (reservedTextures >> 4);
    reservedTextures = reservedTextures | (reservedTextures >> 8);
    reservedTextures = reservedTextures | (reservedTextures >> 16);
    reservedTextures = reservedTextures - (reservedTextures >> 1);
    texturesCount = 0;
    texturesMap = 0;
    mtrTexture = malloc(sizeof(mtrTexture_t) * reservedTextures);
    if (mtrTexture == NULL)
        mtrNotify("Unable to allocate memory for texture structures", 1,
         MTR_LMT_ERROR);
    else
        mtrLogWrite_i("Memory for texture structures allocated. Reserved places: ",
         0, MTR_LMT_INFO, reservedTextures);
    mtrLogWrite("Texture manager initialized", 0, MTR_LMT_INFO);
}

__declspec(dllexport) uint16_t __stdcall mtrTextureLoad(char *filename)
{
    uint16_t freeIndex;

    mtrLogWrite_s("Loading texture", 0, MTR_LMT_INFO, filename);
    freeIndex = mtrTextureGetFreeIndex();
    mtrTexture[freeIndex].texture = GPU_LoadImage(image_file);
    if (texture != NULL)
    {
        mtrTexture[freeIndex].name = malloc(sizeof(char) * (strlen(filename) +
         1));
        mtrTexture[freeIndex].name = strcpy(mtrTexture[freeIndex].name,
         (const char *)filename);

    }
    else
        ;
}
uint16_t mtrTextureGetFreeIndex(void)
{
    uint16_t i;
    uint8_t  j;
    uint16_t textureNum;
    uint16_t mapNumberNum;
    uint8_t  bitNum;
    mtrTexture_t *temp;

    /* Searching empty place on textures map */
    for (i = 0; i < (reservedTextures >> 5); i++) /* reservedTextures >> 5 = */
    {                                             /* reservedTextures / 32   */
        if (texturesMap[i] < 4294967295) /* max uint32_t = 4294967296 */
        {
            for (j = 0; j < 32; j++)
            {
                if (((texturesMap[i] & ( 1 << j )) >> j) == 0)
                {
                    mapNumberNum = i;
                    bitNum = j;
                    textureNum = i << 5 + j; /* textureNum = i * 32 + j */
                    break;
                }
            }
            break;
        }
    }
    /* if no empty space for texture structures, then we need allocate new
     * array with length larger than old in 2 times */
    if (textureNum > reservedTextures)
    {
        temp = mtrTexture;
        mtrTexture = malloc(sizeof(mtrTexture_t) * reservedTextures * 2);
        for (i = 0; i < reservedTextures; i++)
        {
            mtrTexture[i].texture = temp[i].texture;
            mtrTexture[i].filename = temp[i].filename;
        }
        free(temp);
        reservedTextures = reservedTextures * 2;
    }
    return textureNum;
}
