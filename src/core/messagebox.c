#include "messagebox.h"

void MTR_CALL mtrShowSimpleMessageBox(uint8_t type, const char *title,
 const char *message)
{
    const char *emptyString = "";
    const char *resultTitle;
    const char *resultMessage;

    if (title == NULL)
        resultTitle = emptyString;
    else
        resultTitle = title;

    if (message == NULL)
        resultMessage = emptyString;
    else
        resultMessage = message;

    switch (type)
    {
        case MTR_DMT_INFO:
        case MTR_DMT_NOTE:
        case MTR_DMT_DEBUG:
            #ifdef __MINGW32__
                tinyfd_messageBox(resultTitle, resultMessage, "ok", "info", 1);
            #else
                EM_ASM_ARGS({
                    var msg = Pointer_stringify($0);
                    alert(msg);
                }, resultMessage);
            #endif
            break;
        case MTR_DMT_WARNING:
            #ifdef __MINGW32__
                tinyfd_messageBox(resultTitle, resultMessage, "ok", "warning", 1);
            #else
                EM_ASM_ARGS({
                    var msg = Pointer_stringify($0);
                    alert(msg);
                }, resultMessage);
            #endif
            break;
        case MTR_DMT_ERROR:
        case MTR_DMT_FATAL:
            #ifdef __MINGW32__
                tinyfd_messageBox(resultTitle, resultMessage, "ok", "error", 1);
            #else
                EM_ASM_ARGS({
                    var msg = Pointer_stringify($0);
                    alert(msg);
                }, resultMessage);
            #endif
            break;
        default: /* Similar MTR_DMT_INFO */
            #ifdef __MINGW32__
                tinyfd_messageBox(resultTitle, resultMessage, "ok", "info", 1);
            #else
                EM_ASM_ARGS({
                    var msg = Pointer_stringify($0);
                    alert(msg);
                }, resultMessage);
            #endif
            break;
    }
}

bool MTR_CALL mtrShowYesNoMessageBox(const char *title, const char *message)
{
    const char *emptyString = "";
    const char *resultTitle;
    const char *resultMessage;

    if (title == NULL)
        resultTitle = emptyString;
    else
        resultTitle = title;

    if (message == NULL)
        resultMessage = emptyString;
    else
        resultMessage = message;

    #ifdef __MINGW32__
        return tinyfd_messageBox(resultTitle, resultMessage, "yesno",
         "question", 0);
    #else
        int answer;
        answer = EM_ASM_ARGS({
            var msg = Pointer_stringify($0);
            var result = confirm(msg);
            alert(msg);
            return +result;
        }, resultMessage);

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
                break;
        }
        return false;
    #endif
}

/* MinGW only */
bool MTR_CALL mtrShowOkCancelMessageBox(const char *title, const char *message)
{
    const char *emptyString = "";
    const char *resultTitle;
    const char *resultMessage;

    if (title == NULL)
        resultTitle = emptyString;
    else
        resultTitle = title;

    if (message == NULL)
        resultMessage = emptyString;
    else
        resultMessage = message;

    return tinyfd_messageBox(resultTitle, resultMessage, "okcancel", "info", 0);
}

/* MinGW only */
const char *MTR_CALL mtrShowInputDialog(const char *title, const char *message,
 const char *defaultInput)
{
    const char *emptyString = "";
    const char *resultTitle;
    const char *resultMessage;
    const char *resultDefaultInput;

    if (title == NULL)
        resultTitle = emptyString;
    else
        resultTitle = title;

    if (message == NULL)
        resultMessage = emptyString;
    else
        resultMessage = message;

    if (defaultInput == NULL)
        resultDefaultInput = emptyString;
    else
        resultDefaultInput = defaultInput;

    return tinyfd_inputBox(resultTitle, resultMessage, resultDefaultInput);
}

/* MinGW only */
const char *MTR_CALL mtrShowPasswordDialog(const char *title,
 const char *message)
{
    const char *emptyString = "";
    const char *resultTitle;
    const char *resultMessage;

    if (title == NULL)
        resultTitle = emptyString;
    else
        resultTitle = title;

    if (message == NULL)
        resultMessage = emptyString;
    else
        resultMessage = message;

    return tinyfd_inputBox(resultTitle, resultMessage, NULL);
}

void MTR_CALL mtrAddFileFilter(const char *filter)
{
//    int len;
//    len = strlen(filter);
    mtrFileFilter[mtrFileFiltersCount] = filter;
//    mtrFileFilter[mtrFileFiltersCount] = malloc(sizeof(char) * (len + 1));
//    mtrFileFilter[mtrFileFiltersCount] = strcpy(
//     mtrFileFilter[mtrFileFiltersCount], filter);
//    mtrFileFilter[mtrFileFiltersCount][len] = '\0';
    mtrFileFiltersCount++;
}

void MTR_CALL mtrClearFileFilters(void)
{
    int i;

    for (i = 0; i < 255; i++)
    {
//        if (mtrFileFilter[i] != NULL)
//        {
//            if (i < mtrFileFiltersCount)
//                free(mtrFileFilter[i]);
            mtrFileFilter[i] = NULL;
//        }
    }

    mtrFileFiltersCount = 0;
}

/* MinGW only */
const char *MTR_CALL mtrShowSaveFileDialog(const char *title,
 const char *defaultPathAndFile, const char *singleFilterDescription)
{
    const char *emptyString = "";
    const char *resultTitle;
    const char *resultDefaultPathAndFile;

    if (title == NULL)
        resultTitle = emptyString;
    else
        resultTitle = title;

    if (defaultPathAndFile == NULL)
        resultDefaultPathAndFile = emptyString;
    else
        resultDefaultPathAndFile = defaultPathAndFile;

    return tinyfd_saveFileDialog(resultTitle, resultDefaultPathAndFile,
     mtrFileFiltersCount, mtrFileFilter, singleFilterDescription) ;
}

/* MinGW only */
const char *MTR_CALL mtrShowOpenFileDialog(const char *title,
 const char *defaultPathAndFile, const char *singleFilterDescription)
{
    const char *emptyString = "";
    const char *resultTitle;
    const char *resultDefaultPathAndFile;

    if (title == NULL)
        resultTitle = emptyString;
    else
        resultTitle = title;

    if (defaultPathAndFile == NULL)
        resultDefaultPathAndFile = emptyString;
    else
        resultDefaultPathAndFile = defaultPathAndFile;

    return tinyfd_openFileDialog(resultTitle, resultDefaultPathAndFile,
     mtrFileFiltersCount, (const char * const * const)mtrFileFilter, singleFilterDescription, 0);
}

/* TODO: Open Several files by selection */

/* MinGW only */
const char *MTR_CALL mtrShowSelectFolderDialog(const char *title,
 const char *defaultPath)
{
    const char *emptyString = "";
    const char *resultTitle;
    const char *resultDefaultPath;

    if (title == NULL)
        resultTitle = emptyString;
    else
        resultTitle = title;

    if (defaultPath == NULL)
        resultDefaultPath = emptyString;
    else
        resultDefaultPath = defaultPath;

    return tinyfd_selectFolderDialog(resultTitle, resultDefaultPath);
}
