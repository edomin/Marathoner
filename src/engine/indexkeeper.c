#include "indexkeeper.h"

void *__stdcall mtrIndexkeeperCreate(uint32_t dmSize, uint32_t reservedCount,
                                     size_t datasize)
{
    mtrIndexkeeper_t *indexkeeper;
    uint32_t          i;
    uint32_t          newDmSize;

    mtrLogWrite("Creating indexkeeper structure", 0, MTR_LMT_INFO);

    newDmSize = dmSize;
    indexkeeper = malloc(sizeof(mtrIndexkeeper_t));
    if (indexkeeper == NULL)
    {
        mtrNotify("Unable to allocate memory for indexkeeper", 1, MTR_LMT_ERROR);
        return (void *)(NULL);
    }
    indexkeeper->dataSize = datasize;
    if (reservedCount <= dmSize * 32)
        if ((dmSize == MTR_IKDM_SMALL) ||
         (dmSize == MTR_IKDM_MEDIUM) ||
         (dmSize == MTR_IKDM_LARGE))
            if (reservedCount < 32)
            {
                mtrLogWrite("Reserved data places count are too few for correct working indexkeeper. Reserved data places count will be set to 32.", 0, MTR_LMT_WARNING);
                indexkeeper->reservedData = 32;
            }
            else
                indexkeeper->reservedData = reservedCount;
        else
        {
            mtrLogWrite("Invalid data map size value. Value set on default - MTR_IKDM_SMALL", 0, MTR_LMT_WARNING);
            newDmSize = MTR_IKDM_SMALL;
        }
    else
    {
        mtrLogWrite("Reserved data places count are larger than data map size. Reserved data places count will be lowed to max data map size.", 0, MTR_LMT_WARNING);
        indexkeeper->reservedData = dmSize * 32;
    }
    /* flooring to nearest power of 2 */
    indexkeeper->reservedData = indexkeeper->reservedData |
     (indexkeeper->reservedData >> 1);
    indexkeeper->reservedData = indexkeeper->reservedData |
     (indexkeeper->reservedData >> 2);
    indexkeeper->reservedData = indexkeeper->reservedData |
     (indexkeeper->reservedData >> 4);
    indexkeeper->reservedData = indexkeeper->reservedData |
     (indexkeeper->reservedData >> 8);
    if (newDmSize >= MTR_IKDM_MEDIUM)
        indexkeeper->reservedData = indexkeeper->reservedData |
         (indexkeeper->reservedData >> 16);
    if (newDmSize == MTR_IKDM_LARGE)
        indexkeeper->reservedData = indexkeeper->reservedData |
         (indexkeeper->reservedData >> 32);
    indexkeeper->reservedData = indexkeeper->reservedData -
     (indexkeeper->reservedData >> 1);
    indexkeeper->dataCount = 0;
    indexkeeper->dmSize = newDmSize;
    indexkeeper->dataMap = malloc(sizeof(uint32_t) * newDmSize);
    if (indexkeeper->dataMap == NULL)
    {
        mtrNotify("Unable to allocate memory for indexkeeper data map", 1,
         MTR_LMT_ERROR);
        free(indexkeeper);
        return (void *)(NULL);
    }
    /* zero index must be set and reserved for error index */
    indexkeeper->dataMap[0] = 1;
    for (i = 1; i < indexkeeper->dmSize; i++)
    {
        indexkeeper->dataMap[i] = 0;
    }
    indexkeeper->data = malloc(datasize * indexkeeper->reservedData);
    if (indexkeeper->data == NULL)
    {
        mtrNotify("Unable to allocate memory for indexkeeper data", 1,
         MTR_LMT_ERROR);
        free(indexkeeper->dataMap);
        free(indexkeeper);
        return (void *)(NULL);
    }
    else
        mtrLogWrite_i("Memory for indexkeeper data allocated. Reserved places: ",
         0, MTR_LMT_INFO, indexkeeper->reservedData);
    return (void *)indexkeeper;
}

uint32_t __stdcall mtrIndexkeeperGetFreeIndex(void *ik)
{
    uint32_t i;
    uint8_t  j;
    uint16_t dataNum;
    uint16_t mapNumberNum;
    uint8_t  bitNum;
    mtrIndexkeeper_t *indexkeeper;

    indexkeeper = (mtrIndexkeeper_t *)ik;

    /* Searching empty place on textures map */
    for (i = 0; i < (indexkeeper->reservedData >> 5); i++) /* indexkeeper->reservedData >> 5 = */
    {                                                      /* indexkeeper->reservedData / 32   */
        if (indexkeeper->dataMap[i] < UINT32_MAX)
        {
            for (j = 0; j < 32; j++)
            {
                if (((indexkeeper->dataMap[i] & ( 1 << j )) >> j) == 0)
                {
                    mapNumberNum = i;
                    bitNum = j;
                    dataNum = (i << 5) + j; /* textureNum = i * 32 + j */
                    break;
                }
            }
            break;
        }
    }
    /* if no empty space for data, then we need allocate new
     * array with length larger than old in 2 times */
    if (dataNum > indexkeeper->reservedData)
    {
        if (indexkeeper->reservedData != indexkeeper->dmSize << 5)
        {
            indexkeeper->data = realloc(indexkeeper->data, indexkeeper->dataSize *
             indexkeeper->reservedData * 2);
            indexkeeper->reservedData = indexkeeper->reservedData * 2;
        }
        else
            mtrNotify("Unable to allocate memory for data indeces larger than data map size. Please, initialize indexkeeper with larger datamap size.", 1,
             MTR_LMT_FATAL);
    }
    indexkeeper->dataMap[mapNumberNum] = indexkeeper->dataMap[mapNumberNum] | (1 << bitNum);
    return dataNum;
}

void __stdcall mtrIndexkeeperFreeIndex(void *ik, uint32_t index)
{
    uint16_t          mapNumberNum;
    uint8_t           bitNum;
    mtrIndexkeeper_t *indexkeeper;

    indexkeeper = (mtrIndexkeeper_t *)ik;
    mapNumberNum = index >> 5; /* = index / 32 */
    bitNum = index - (mapNumberNum << 5);
    indexkeeper->dataMap[mapNumberNum] = indexkeeper->dataMap[mapNumberNum] - (1 << bitNum);
}

void __stdcall mtrIndexkeeperDestroy(void *ik)
{
    mtrIndexkeeper_t *indexkeeper;
    indexkeeper = (mtrIndexkeeper_t *) ik;
    free(indexkeeper->data);
    free(indexkeeper->dataMap);
    free(ik);
}
