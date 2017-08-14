local time;

-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

TimerInit();

TimerStart();
time = TimerDelay(30);
FileWriteLineFast("test/output.txt", "Delay 30ms: " .. time, FM_APPEND);

TimerStart();
time = TimerDelayForFPS(30);
FileWriteLineFast("test/output.txt", "Delay for 30FPS: " .. time, FM_APPEND);

TimerStart();
time = TimerDelayForFPS_f(33.33);
FileWriteLineFast("test/output.txt",
 "Delay for 33.33FPS floating point: " .. time, FM_APPEND);
