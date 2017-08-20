-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

FileWriteLineFast("test/output.txt", "With fixed seed - 42", FM_APPEND);
RandSeed(42);
FileWriteLineFast("test/output.txt", "Rand(10)" .. Rand(10), FM_APPEND);
FileWriteLineFast("test/output.txt", "Rand(10)" .. Rand(10), FM_APPEND);
FileWriteLineFast("test/output.txt", "Rand(10)" .. Rand(10), FM_APPEND);
FileWriteLineFast("test/output.txt", "Rand(10)" .. Rand(10), FM_APPEND);
FileWriteLineFast("test/output.txt", "Rand(10)" .. Rand(10), FM_APPEND);
FileWriteLineFast("test/output.txt", "RandRange(5, 15)" .. RandRange(5, 15), FM_APPEND);
FileWriteLineFast("test/output.txt", "RandRange(5, 15)" .. RandRange(5, 15), FM_APPEND);
FileWriteLineFast("test/output.txt", "RandRange(5, 15)" .. RandRange(5, 15), FM_APPEND);
FileWriteLineFast("test/output.txt", "RandRange(5, 15)" .. RandRange(5, 15), FM_APPEND);
FileWriteLineFast("test/output.txt", "RandRange(5, 15)" .. RandRange(5, 15), FM_APPEND);
