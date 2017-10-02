local M = {};

local function FunctionBinded(func, functionName)
{
    if (functionName == null)
    {
        FileWriteLineFast("test/output.txt",
         "Function '" + functionName + "' are not binded", FM_APPEND);
        return false;
    }
    return true;
}

local function FunctionSupported(func, functionName, faFunc)
{
    if (FunctionBinded(func, functionName))
    {
        local funcAvail = faFunc(functionName);
        switch (funcAvail)
        {
            case FA_NO:
                FileWriteLineFast("test/output.txt",
                 "Function's availability data for function '" +
                 functionName + "' not found", FM_APPEND);
                break;
            case FA_DUMMY:
                FileWriteLineFast("test/output.txt",
                 "Function '" + functionName + "' not supported", FM_APPEND);
                 break;
            case FA_BUGGY:
                FileWriteLineFast("test/output.txt",
                 "Function '" + functionName + "' are not working correct",
                 FM_APPEND);
                break;
            case FA_PARTIAL:
                FileWriteLineFast("test/output.txt",
                 "Function '" + functionName + "' partially supported",
                 FM_APPEND);
                break;
            case FA_YES:
                FileWriteLineFast("test/output.txt",
                 "Function '" + functionName + "' supported", FM_APPEND);
                break;
            default:
                FileWriteLineFast("test/output.txt",
                 "Unexpected function's availability data for function '" +
                 functionName + "'", FM_APPEND);
                break;
        }
    }
}

M.FunctionBinded <- FunctionBinded;
M.FunctionSupported <- FunctionSupported;

return M;
