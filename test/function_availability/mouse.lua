-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(MouseInit, "MTR_MouseInit", MouseFunctionSupported);
fa.FunctionSupported(MouseRefresh, "MTR_MouseRefresh", MouseFunctionSupported);
fa.FunctionSupported(MousePress, "MTR_MousePress", MouseFunctionSupported);
fa.FunctionSupported(MouseRelease, "MTR_MouseRelease", MouseFunctionSupported);
fa.FunctionSupported(MousePressed, "MTR_MousePressed", MouseFunctionSupported);
fa.FunctionSupported(MouseGetWheelRelative, "MTR_MouseGetWheelRelative",
 MouseFunctionSupported);
fa.FunctionSupported(MouseMoving, "MTR_MouseMoving", MouseFunctionSupported);
fa.FunctionSupported(MouseGetX, "MTR_MouseGetX", MouseFunctionSupported);
fa.FunctionSupported(MouseGetY, "MTR_MouseGetY", MouseFunctionSupported);
fa.FunctionSupported(MouseGetXY, "MTR_MouseGetXY", MouseFunctionSupported);
fa.FunctionSupported(MouseGetDeltaX, "MTR_MouseGetDeltaX",
 MouseFunctionSupported);
fa.FunctionSupported(MouseGetDeltaY, "MTR_MouseGetDeltaY",
 MouseFunctionSupported);
fa.FunctionSupported(MouseGetDeltaXY, "MTR_MouseGetDeltaXY",
 MouseFunctionSupported);
