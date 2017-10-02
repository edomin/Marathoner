-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(MouseInit, "mtrMouseInit", MouseFunctionSupported);
fa.FunctionSupported(MouseRefresh, "mtrMouseRefresh", MouseFunctionSupported);
fa.FunctionSupported(MousePress, "mtrMousePress", MouseFunctionSupported);
fa.FunctionSupported(MouseRelease, "mtrMouseRelease", MouseFunctionSupported);
fa.FunctionSupported(MousePressed, "mtrMousePressed", MouseFunctionSupported);
fa.FunctionSupported(MouseGetWheelRelative, "mtrMouseGetWheelRelative",
 MouseFunctionSupported);
fa.FunctionSupported(MouseMoving, "mtrMouseMoving", MouseFunctionSupported);
fa.FunctionSupported(MouseGetX, "mtrMouseGetX", MouseFunctionSupported);
fa.FunctionSupported(MouseGetY, "mtrMouseGetY", MouseFunctionSupported);
fa.FunctionSupported(MouseGetXY, "mtrMouseGetXY", MouseFunctionSupported);
fa.FunctionSupported(MouseGetDeltaX, "mtrMouseGetDeltaX",
 MouseFunctionSupported);
fa.FunctionSupported(MouseGetDeltaY, "mtrMouseGetDeltaY",
 MouseFunctionSupported);
fa.FunctionSupported(MouseGetDeltaXY, "mtrMouseGetDeltaXY",
 MouseFunctionSupported);
