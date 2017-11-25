#include "messagebox.h"

/*fa MTR_ShowSimpleMessageBox yes */
void MTR_CALL MTR_ShowSimpleMessageBox(uint8_t type, const char *title,
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

    #ifdef __MINGW32__
    switch (type)
    {
        case MTR_DMT_INFO:
        case MTR_DMT_NOTE:
        case MTR_DMT_DEBUG:
            tinyfd_messageBox(resultTitle, resultMessage, "ok", "info", 1);
            break;
        case MTR_DMT_WARNING:
            tinyfd_messageBox(resultTitle, resultMessage, "ok", "warning", 1);
            break;
        case MTR_DMT_ERROR:
        case MTR_DMT_FATAL:
            tinyfd_messageBox(resultTitle, resultMessage, "ok", "error", 1);
            break;
        default: /* Similar MTR_DMT_INFO */
            tinyfd_messageBox(resultTitle, resultMessage, "ok", "info", 1);
            break;
    }
    #else
    int dummy;
    dummy = EM_ASM_INT({
        var msg = UTF8ToString($0);
        alert(msg);
        return 0;
    }, resultMessage);
    #endif
}

/* MinGW only */
/*fa MTR_ShowYesNoMessageBox yes */
bool MTR_CALL MTR_ShowYesNoMessageBox(const char *title, const char *message)
{
    #ifdef __MINGW32__
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

    return tinyfd_messageBox(resultTitle, resultMessage, "yesno", "question",
     0);
    #else
    return false;
    #endif
}

/*fa MTR_ShowOkCancelMessageBox yes */
bool MTR_CALL MTR_ShowOkCancelMessageBox(const char *title, const char *message)
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
    return tinyfd_messageBox(resultTitle, resultMessage, "okcancel", "info", 0);
    #else
    int answer;
    answer = EM_ASM_INT({
        var msg = UTF8ToString($0);
        var result = confirm(msg);
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

/*fa MTR_ShowInputDialog yes */
const char *MTR_CALL MTR_ShowInputDialog(const char *title, const char *message,
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

    #ifdef __MINGW32__
    return tinyfd_inputBox(resultTitle, resultMessage, resultDefaultInput);
    #else
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wbad-function-cast"
    char *answer;
    answer = (char *)EM_ASM_INT({
        var msg = UTF8ToString($0);
        var defaultStr = UTF8ToString($1);
        var result = prompt(msg, defaultStr);
        var lengthBytes = lengthBytesUTF8(result) + 1;
        var stringOnWasmHeap = _malloc(lengthBytes);
        stringToUTF8(result, stringOnWasmHeap, lengthBytes + 1);
        return stringOnWasmHeap;
    }, resultMessage, resultDefaultInput);
    #pragma GCC diagnostic pop
    /* returned from sj value need to be freed from C after use */
    return answer;
    #endif
}

/* MinGW only */
/*fa MTR_ShowPasswordDialog yes */
const char *MTR_CALL MTR_ShowPasswordDialog(const char *title,
 const char *message)
{
    #ifdef __MINGW32__
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
    #else
    return NULL;
    #endif
}

/*fa MTR_AddFileFilter yes */
void MTR_CALL MTR_AddFileFilter(const char *filter)
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

/*fa MTR_ClearFileFilters yes */
void MTR_CALL MTR_ClearFileFilters(void)
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
/*fa MTR_ShowSaveFileDialog yes */
const char *MTR_CALL MTR_ShowSaveFileDialog(const char *title,
 const char *defaultPathAndFile, const char *singleFilterDescription)
{
    #ifdef __MINGW32__
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
     mtrFileFiltersCount, mtrFileFilter, singleFilterDescription);
    #else
    return NULL;
    #endif
}

/* MinGW only */
/*fa MTR_ShowOpenFileDialog yes */
const char *MTR_CALL MTR_ShowOpenFileDialog(const char *title,
 const char *defaultPathAndFile, const char *singleFilterDescription)
{
    #ifdef __MINGW32__
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
    #else
    return NULL;
    #endif
}

/* MinGW only */
/*fa MTR_ShowSelectFolderDialog yes */
const char *MTR_CALL MTR_ShowSelectFolderDialog(const char *title,
 const char *defaultPath)
{
    #ifdef __MINGW32__
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
    #else
    return NULL;
    #endif
}
