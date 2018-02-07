-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(PackageInit, "MTR_PackageInit", PackageFunctionSupported);
fa.FunctionSupported(PackageMount, "MTR_PackageMount",
 PackageFunctionSupported);
fa.FunctionSupported(PackageUnmount, "MTR_PackageUnmount",
 PackageFunctionSupported);
fa.FunctionSupported(PackageQuit, "MTR_PackageQuit", PackageFunctionSupported);
fa.FunctionSupported(PackageGetFopen, "MTR_PackageGetFopen",
 PackageFunctionSupported);
fa.FunctionSupported(PackageGetFclose, "MTR_PackageGetFclose",
 PackageFunctionSupported);
fa.FunctionSupported(PackageGetFeof, "MTR_PackageGetFeof",
 PackageFunctionSupported);
fa.FunctionSupported(PackageGetFtell, "MTR_PackageGetFtell",
 PackageFunctionSupported);
fa.FunctionSupported(PackageGetFseek, "MTR_PackageGetFseek",
 PackageFunctionSupported);
fa.FunctionSupported(PackageGetFread, "MTR_PackageGetFread",
 PackageFunctionSupported);
fa.FunctionSupported(PackageGetFwrite, "MTR_PackageGetFwrite",
 PackageFunctionSupported);
