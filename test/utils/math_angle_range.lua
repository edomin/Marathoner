local i;

-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

FileWriteLineFast(
 "test/output.txt", "Testing Sin_f function on range -720..720: ", FM_APPEND);
for i = -720, 720, 10 do
    FileWriteLineFast("test/output.txt", "Sin_f(" .. i .. "): " .. Sin_f(i),
     FM_APPEND);
end;

FileWriteLineFast(
 "test/output.txt", "Testing Sin_d function on range -720..720: ", FM_APPEND);
for i = -720, 720, 10 do
    FileWriteLineFast("test/output.txt", "Sin_d(" .. i .. "): " .. Sin_d(i),
     FM_APPEND);
end;

FileWriteLineFast(
 "test/output.txt", "Testing SinFast_f function on range -720..720: ",
 FM_APPEND);
for i = -720, 720, 10 do
    FileWriteLineFast("test/output.txt",
     "SinFast_f(" .. i .. "): " .. SinFast_f(i), FM_APPEND);
end;

FileWriteLineFast(
 "test/output.txt", "Testing SinFast_d function on range -720..720: ",
 FM_APPEND);
for i = -720, 720, 10 do
    FileWriteLineFast("test/output.txt",
     "SinFast_d(" .. i .. "): " .. SinFast_d(i), FM_APPEND);
end;

FileWriteLineFast(
 "test/output.txt", "Testing Cos_f function on range -720..720", FM_APPEND);
for i = -720, 720, 10 do
    FileWriteLineFast("test/output.txt", "Cos_f(" .. i .. "): " .. Cos_f(i),
     FM_APPEND);
end;

FileWriteLineFast(
 "test/output.txt", "Testing Cos_d function on range -720..720", FM_APPEND);
for i = -720, 720, 10 do
    FileWriteLineFast("test/output.txt", "Cos_d(" .. i .. "): " .. Cos_d(i),
     FM_APPEND);
end;

FileWriteLineFast(
 "test/output.txt", "Testing CosFast_f function on range -720..720", FM_APPEND);
for i = -720, 720, 10 do
    FileWriteLineFast("test/output.txt",
     "CosFast_f(" .. i .. "): " .. CosFast_f(i), FM_APPEND);
end;

FileWriteLineFast(
 "test/output.txt", "Testing CosFast_d function on range -720..720", FM_APPEND);
for i = -720, 720, 10 do
    FileWriteLineFast("test/output.txt",
     "CosFast_d(" .. i .. "): " .. CosFast_d(i), FM_APPEND);
end;

FileWriteLineFast(
 "test/output.txt", "Testing Tan_f function on range -720..720", FM_APPEND);
for i = -720, 720, 10 do
    FileWriteLineFast("test/output.txt", "Tan_f(" .. i .. "): " .. Tan_f(i),
     FM_APPEND);
end;

FileWriteLineFast(
 "test/output.txt", "Testing Tan_d function on range -720..720", FM_APPEND);
for i = -720, 720, 10 do
    FileWriteLineFast("test/output.txt", "Tan_d(" .. i .. "): " .. Tan_d(i),
     FM_APPEND);
end;

FileWriteLineFast(
 "test/output.txt", "Testing TanFast_f function on range -720..720", FM_APPEND);
for i = -720, 720, 10 do
    FileWriteLineFast("test/output.txt",
     "TanFast_f(" .. i .. "): " .. TanFast_f(i), FM_APPEND);
end;

FileWriteLineFast(
 "test/output.txt", "Testing TanFast_d function on range -720..720", FM_APPEND);
for i = -720, 720, 10 do
    FileWriteLineFast("test/output.txt",
     "TanFast_d(" .. i .. "): " .. TanFast_d(i), FM_APPEND);
end;
