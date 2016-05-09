#include "notification.h"

char *mtrMessageTypeToTitle(uint8_t messageType)
{
    switch (messageType)
    {
        case MTR_DMT_INFO:
            return MTR_NTT_INFO;
            break;
        case MTR_DMT_NOTE:
            return MTR_NTT_NOTE;
            break;
        case MTR_DMT_WARNING:
            return MTR_NTT_WARNING;
            break;
        case MTR_DMT_ERROR:
            return MTR_NTT_ERROR;
            break;
        case MTR_DMT_FATAL:
            return MTR_NTT_FATAL;
            break;
        case MTR_DMT_DEBUG:
            return MTR_NTT_DEBUG;
            break;
        default:
            return " ";
            break;
    }
    return " ";
}

void mtrNotify(char *message, uint8_t level, uint8_t messageType)
{
    mtrLogWrite(message, level, messageType);
    mtrShowSimpleMessageBox(messageType, mtrMessageTypeToTitle(messageType),
      message);
}
