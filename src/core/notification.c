#include "notification.h"

char *MTR_MessageTypeToTitle(uint8_t messageType)
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

void MTR_CALL MTR_Notify(const char *message, uint8_t level,
 uint8_t messageType)
{
    MTR_LogWrite(message, level, messageType);
    MTR_ShowSimpleMessageBox(messageType, MTR_MessageTypeToTitle(messageType),
     message);
}
