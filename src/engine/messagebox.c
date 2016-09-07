#include "messagebox.h"

void MRT_CALL mtrShowSimpleMessageBox(uint8_t type, const char *title,
 const char *message)
{
    switch (type)
    {
        case MTR_DMT_INFO:
        case MTR_DMT_NOTE:
        case MTR_DMT_DEBUG:
            #ifdef __MINGW32__
                MessageBox(0, message, title,
                 MB_OK | MB_ICONINFORMATION | MB_TASKMODAL);
            #else
                EM_ASM_ARGS({
                    var msg = Pointer_stringify($0);
                    alert(msg);
                }, message);
            #endif
            break;
        case MTR_DMT_WARNING:
            #ifdef __MINGW32__
                MessageBox(0, message, title,
                 MB_OK | MB_ICONWARNING | MB_TASKMODAL);
            #else
                EM_ASM_ARGS({
                    var msg = Pointer_stringify($0);
                    alert(msg);
                }, message);
            #endif
            break;
        case MTR_DMT_ERROR:
        case MTR_DMT_FATAL:
            #ifdef __MINGW32__
                MessageBox(0, message, title,
                 MB_OK | MB_ICONERROR | MB_TASKMODAL);
            #else
                EM_ASM_ARGS({
                    var msg = Pointer_stringify($0);
                    alert(msg);
                }, message);
            #endif
            break;
        default:
            break;
    }
}

bool MRT_CALL mtrShowYesNoMessageBox(const char *title, const char *message)
{
    #ifdef __MINGW32__
        switch (MessageBox(0, message, title,
          MB_YESNO | MB_ICONQUESTION | MB_TASKMODAL))
        {
            case IDYES:
                return true;
                break;
            case IDNO:
                return false;
                break;
        }
    #else
        int answer;
        answer = EM_ASM_ARGS({
            var msg = Pointer_stringify($0);
            var result = confirm(msg);
            alert(msg);
            return +result;
        }, message);

        switch (answer)
        {
            case 1:
                return true;
                break;
            case 0:
                return false;
                break;
            default:
                return false;
        }
    #endif
    return false;
}
