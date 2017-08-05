#include "string_buffer.h"

bool MTR_CALL mtrStringBufferInit(uint32_t dmSize, uint32_t reservedCount)
{
    mtrLogWrite("Initializing string buffers' structures and routines", 0,
     MTR_LMT_INFO);

    mtrStringBufferKeeper = (mtrIndexkeeper_t *)mtrIndexkeeperCreate(dmSize,
     reservedCount, sizeof(mtrStringBuffer_t));
    if (mtrStringBufferKeeper == NULL)
    {
        mtrNotify("Unable to initialize string buffers' structures and "
         "routines", 1, MTR_LMT_ERROR);
        return false;
    }
    else
        mtrLogWrite("string buffers' structures and routines initialized",
         0, MTR_LMT_INFO);

    return true;
}

uint32_t MTR_CALL mtrStringBufferAdd(const char *initialString, int maxlen)
{
    uint32_t           freeIndex;
    mtrStringBuffer_t *buffer;
    int                len;

    freeIndex = mtrIndexkeeperGetFreeIndex(mtrStringBufferKeeper);
    buffer = IK_GET_DATA(mtrStringBuffer_t *, mtrStringBufferKeeper, freeIndex);

    if (initialString == NULL)
    {
        buffer->string = malloc(sizeof(char) * maxlen);
        buffer->string[0] = '\0';
    }
    else
    {
        len = strlen(initialString);
        if (len > maxlen)
            len = maxlen;
        buffer->string = malloc(sizeof(char) * (maxlen + 1));
        strncpy(buffer->string, initialString, maxlen);
        buffer->string[len] = '\0';
    }
    buffer->maxlen = maxlen;

    return freeIndex;
}

void MTR_CALL mtrStringBufferDelete(uint32_t sbnum)
{
    mtrStringBuffer_t *buffer;

    if (sbnum != 0)
    {
        buffer = IK_GET_DATA(mtrStringBuffer_t *, mtrStringBufferKeeper, sbnum);
        free(buffer->string);
        mtrIndexkeeperFreeIndex(mtrStringBufferKeeper, sbnum);
    }
}

void MTR_CALL mtrStringBufferSetString(uint32_t sbnum, const char* string)
{
    mtrStringBuffer_t *buffer;
    int                len;

    if (sbnum != 0)
    {
        buffer = IK_GET_DATA(mtrStringBuffer_t *, mtrStringBufferKeeper, sbnum);
        len = strlen(string);
        if (len > buffer->maxlen)
            len = buffer->maxlen;
        strncpy(buffer->string, string, buffer->maxlen);
        buffer->string[len] = '\0';
    }
}

char *MTR_CALL mtrStringBufferGetString(uint32_t sbnum)
{
    mtrStringBuffer_t *buffer;

    if (sbnum != 0)
    {
        buffer = IK_GET_DATA(mtrStringBuffer_t *, mtrStringBufferKeeper, sbnum);
        return buffer->string;
    }
    return NULL;
}

int MTR_CALL mtrStringBufferGetMaxLen(uint32_t sbnum)
{
    mtrStringBuffer_t *buffer;

    if (sbnum != 0)
    {
        buffer = IK_GET_DATA(mtrStringBuffer_t *, mtrStringBufferKeeper, sbnum);
        return buffer->maxlen;
    }
    return NULL;
}
