#include "messagebox.h"

MTR_EXPORT void MTR_CALL mtrShowSimpleMessageBox(uint8_t type,
 const char *title, const char *message)
{
    switch (type)
    {
        case MTR_DMT_INFO:
        case MTR_DMT_NOTE:
        case MTR_DMT_DEBUG:
            #ifdef __MINGW32__
                tinyfd_messageBox(title, message, "ok", "info", 1);
            #else
                EM_ASM_ARGS({
                    var msg = Pointer_stringify($0);
                    alert(msg);
                }, message);
            #endif
            break;
        case MTR_DMT_WARNING:
            #ifdef __MINGW32__
                tinyfd_messageBox(title, message, "ok", "warning", 1);
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
                tinyfd_messageBox(title, message, "ok", "error", 1);
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

MTR_EXPORT bool MTR_CALL mtrShowYesNoMessageBox(const char *title,
 const char *message)
{
    #ifdef __MINGW32__
        return (bool)tinyfd_messageBox(title, message, "yesno", "question", 0);
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

/* MinGW only */
MTR_EXPORT bool MTR_CALL mtrShowOkCancelMessageBox(const char *title,
 const char *message)
{
    return (bool)tinyfd_messageBox(title, message, "okcancel", "info", 0);
}

/* MinGW only */
MTR_EXPORT const char *MTR_CALL mtrShowInputDialog(const char *title,
 const char *message, const char *defaultInput)
{
    if (defaultInput == NULL)
        return tinyfd_inputBox(title, message, "");
    else
        return tinyfd_inputBox(title, message, defaultInput);
}

/* MinGW only */
MTR_EXPORT const char *MTR_CALL mtrShowPasswordDialog(const char *title,
 const char *message)
{
    return tinyfd_inputBox(title, message, NULL);
}

/* MinGW only */
MTR_EXPORT const char *MTR_CALL mtrShowSaveFileDialog(const char *title,
 const char *defaultPathAndFile, int fpNum, const char **filterPatterns,
 const char **singleFilterDescription)
{
    return tinyfd_saveFileDialog(title, defaultPathAndFile, fpNum,
     filterPatterns, singleFilterDescription) ;
}

/* MinGW only */
MTR_EXPORT const char *MTR_CALL mtrShowOpenFileDialog(const char *title,
 const char *defaultPathAndFile, int fpNum, const char **filterPatterns,
 const char **singleFilterDescription)
{
    return tinyfd_openFileDialog(title, defaultPathAndFile, fpNum,
     filterPatterns, singleFilterDescription, 0);
}

/* TODO: Open Several files by selection */

/* MinGW only */
MTR_EXPORT const char *MTR_CALL mtrShowSelectFolderDialog(const char *title,
 const char *defaultPath)
{
    if (defaultPath == NULL)
        return tinyfd_selectFolderDialog(title, "");
    else
        return tinyfd_selectFolderDialog(title, defaultPath);
}
