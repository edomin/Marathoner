local M = {};

local function FunctionBinded(func, functionName)
    if functionName == nil then
        FileWriteLineFast("test/output.txt",
         "Function '" .. functionName .. "' are not binded", FM_APPEND);
        return false;
    end;
    return true;
end;

local function FunctionSupported(func, functionName, faFunc)
    if FunctionBinded(func, functionName) then
        local funcAvail = faFunc(functionName);
        if funcAvail == FA_NO then
            FileWriteLineFast("test/output.txt",
             "Function's availability data for function '" .. functionName ..
             "' not found", FM_APPEND);
        elseif funcAvail == FA_DUMMY then
            FileWriteLineFast("test/output.txt",
             "Function '" .. functionName .. "' not supported", FM_APPEND);
        elseif funcAvail == FA_BUGGY then
            FileWriteLineFast("test/output.txt",
             "Function '" .. functionName .. "' are not working correct",
             FM_APPEND);
        elseif funcAvail == FA_PARTIAL then
            FileWriteLineFast("test/output.txt",
             "Function '" .. functionName .. "' partially supported",
             FM_APPEND);
        elseif funcAvail == FA_YES then
            FileWriteLineFast("test/output.txt",
             "Function '" .. functionName .. "' supported", FM_APPEND);
        else
            FileWriteLineFast("test/output.txt",
             "Unexpected function's availability data for function '" ..
             functionName .. "'", FM_APPEND);
        end;
    end;
end;

M.FunctionBinded = FunctionBinded;
M.FunctionSupported = FunctionSupported;

return M;
