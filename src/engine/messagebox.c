#include "messagebox.h"

void mtrShowSimpleMessageBox(uint8_t type, char *title, char *message)
{
    switch (type)
    {
        case MTR_DMT_INFO:
        case MTR_DMT_NOTE:
        case MTR_DMT_DEBUG:
        {
            MessageBox(0, message, title,
              MB_OK | MB_ICONINFORMATION | MB_TASKMODAL);
            break;
        }
        case MTR_DMT_WARNING:
        {
            MessageBox(0, message, title,
              MB_OK | MB_ICONWARNING | MB_TASKMODAL);
            break;
        }
        case MTR_DMT_ERROR:
        case MTR_DMT_FATAL:
        {
            MessageBox(0, message, title,
              MB_OK | MB_ICONERROR | MB_TASKMODAL);
            break;
        }
        default:
            break;
    }
}

bool mtrShowYesNoMessageBox(char *title, char *message)
{
    switch (MessageBox(0, message, title, MB_YESNO | MB_ICONQUESTION | MB_TASKMODAL))
    {
        case IDYES:
        {
            return true;
            break;
        }
        case IDNO:
        {
            return false;
            break;
        }
    }
    return false;
}
