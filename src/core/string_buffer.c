#include "string_buffer.h"

bool MTR_CALL MTR_StringBufferInit(uint32_t dmSize, uint32_t reservedCount)
{
    MTR_LogWrite("Initializing string buffers' structures and routines", 0,
     MTR_LMT_INFO);

    mtrStringBufferKeeper = (mtrIndexkeeper_t *)MTR_IndexkeeperCreate(dmSize,
     reservedCount, sizeof(mtrStringBuffer_t));
    if (mtrStringBufferKeeper == NULL)
    {
        MTR_Notify("Unable to initialize string buffers' structures and "
         "routines", 1, MTR_LMT_ERROR);
        return false;
    }
    else
        MTR_LogWrite("string buffers' structures and routines initialized",
         0, MTR_LMT_INFO);

    return true;
}

uint32_t MTR_CALL MTR_StringBufferAdd(const char *initialString, int maxlen)
{
    uint32_t           freeIndex;
    mtrStringBuffer_t *buffer;
    int                len;

    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrStringBufferKeeper);
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

void MTR_CALL MTR_StringBufferDelete(uint32_t sbnum)
{
    mtrStringBuffer_t *buffer;

    if (sbnum != 0)
    {
        buffer = IK_GET_DATA(mtrStringBuffer_t *, mtrStringBufferKeeper, sbnum);
        free(buffer->string);
        MTR_IndexkeeperFreeIndex(mtrStringBufferKeeper, sbnum);
    }
}

void MTR_CALL MTR_StringBufferSetString(uint32_t sbnum, const char* string)
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

char *MTR_CALL MTR_StringBufferGetString(uint32_t sbnum)
{
    mtrStringBuffer_t *buffer;

    if (sbnum != 0)
    {
        buffer = IK_GET_DATA(mtrStringBuffer_t *, mtrStringBufferKeeper, sbnum);
        return buffer->string;
    }
    return NULL;
}

int MTR_CALL MTR_StringBufferGetMaxLen(uint32_t sbnum)
{
    mtrStringBuffer_t *buffer;

    if (sbnum != 0)
    {
        buffer = IK_GET_DATA(mtrStringBuffer_t *, mtrStringBufferKeeper, sbnum);
        return buffer->maxlen;
    }
    return NULL;
}
