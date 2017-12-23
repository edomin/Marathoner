-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);
ScreenInit(640, 480, false, "Audio Test");
PrimitiveInit();
KeyboardInit();
TimerInit();
AudioInit(IKDM_SMALL, 32, IKDM_SMALL, 32, AU_FREQ_DEFAULT, AU_CHANNELS_DEFAULT,
 1024);
local pickup = AudioSoundLoad("test/media/pickup.wav");
local punch = AudioSoundLoad("test/media/punch.wav");
local explosion = AudioSoundLoad("test/media/explosion.wav");
local music = AudioMusicLoad("test/media/bu-a-ninja-and-shields.ogg");
local volume1 = 128;
local volume2 = 128;
local volume3 = 1.0;

while not quit do
    TimerStart();
    KeyboardRefresh();
    if KeyboardPress(KEY_ESCAPE) then
        quit = true;
    end;
    if KeyboardPress(KEY_1) then
        AudioSoundPlay(pickup);
    end;
    if KeyboardPress(KEY_2) then
        AudioSoundPlay(punch);
    end;
    if KeyboardPress(KEY_3) then
        AudioSoundPlay(explosion);
    end;
    if KeyboardPress(KEY_Q) then
        AudioSoundFadeInPlay(pickup, 200);
    end;
    if KeyboardPress(KEY_W) then
        AudioSoundFadeInPlay(punch, 200);
    end;
    if KeyboardPress(KEY_E) then
        AudioSoundFadeInPlay(explosion, 200);
    end;
    if KeyboardPress(KEY_A) then
        if volume1 > 120 then
            volume1 = 128;
        else
            volume1 = volume1 + 8;
        end;
        AudioSoundSetVolume(pickup, volume1);
        AudioSoundPlay(pickup);
    end;
    if KeyboardPress(KEY_S) then
        if volume2 > 120 then
            volume2 = 128;
        else
            volume2 = volume2 + 8;
        end;
        AudioSoundSetVolume(punch, volume2);
        AudioSoundPlay(punch);
    end;
    if KeyboardPress(KEY_D) then
        if volume3 > 0.9 then
            volume3 = 1.0;
        else
            volume3 = volume3 + 0.1;
        end;
        AudioSoundSetVolume_f(explosion, volume3);
        AudioSoundPlay(explosion);
    end;
    if KeyboardPress(KEY_Z) then
        if volume1 < 8 then
            volume1 = 0;
        else
            volume1 = volume1 - 8;
        end;
        AudioSoundSetVolume(pickup, volume1);
        AudioSoundPlay(pickup);
    end;
    if KeyboardPress(KEY_X) then
        if volume2 < 8 then
            volume2 = 0;
        else
            volume2 = volume2 - 8;
        end;
        AudioSoundSetVolume(punch, volume2);
        AudioSoundPlay(punch);
    end;
    if KeyboardPress(KEY_C) then
        if volume3 < 0.1 then
            volume3 = 0.0;
        else
            volume3 = volume3 - 0.1;
        end;
        AudioSoundSetVolume_f(explosion, volume3);
        AudioSoundPlay(explosion);
    end;
    if KeyboardPress(KEY_4) then
        AudioSoundStop(pickup);
    end;
    if KeyboardPress(KEY_5) then
        AudioSoundStop(punch);
    end;
    if KeyboardPress(KEY_6) then
        AudioSoundStop(explosion);
    end;
    if KeyboardPress(KEY_R) then
        AudioSoundFadeOutStop(pickup, 200);
    end;
    if KeyboardPress(KEY_T) then
        AudioSoundFadeOutStop(punch, 200);
    end;
    if KeyboardPress(KEY_Y) then
        AudioSoundFadeOutStop(explosion, 200);
    end;
    if KeyboardPress(KEY_F) then
        AudioChannelsSetVolume(24);
    end;
    if KeyboardPress(KEY_G) then
        AudioChannelsSetVolume_f(0.5);
    end;
    if KeyboardPress(KEY_H) then
        AudioChannelsSetVolume(128);
    end;
    if KeyboardPress(KEY_V) then
        AudioChannelsPause();
    end;
    if KeyboardPress(KEY_B) then
        AudioChannelsResume();
    end;
    if KeyboardPress(KEY_N) then
        AudioChannelsStop();
    end;
    if KeyboardPress(KEY_SPACE) then
        AudioChannelsFadeOutStop(200);
    end;
    if KeyboardPress(KEY_7) then
        AudioMusicPlay(music, -1);
    end;
    if KeyboardPress(KEY_8) then
        AudioMusicPause();
    end;
    if KeyboardPress(KEY_9) then
        AudioMusicResume();
    end;
    if KeyboardPress(KEY_0) then
        AudioMusicStop();
    end;
    if KeyboardPress(KEY_U) then
        AudioMusicFadeInPlay(music, 1000);
    end;
    if KeyboardPress(KEY_I) then
        AudioMusicFadeOutStop(1000);
    end;
    if KeyboardPress(KEY_LEFT) then
        AudioMusicSetVolume(24);
    end;
    if KeyboardPress(KEY_UP) then
        AudioMusicSetVolume_f(0.35);
    end;
    if KeyboardPress(KEY_DOWN) then
        AudioMusicSetVolume_f(0.75);
    end;
    if KeyboardPress(KEY_RIGHT) then
        AudioMusicSetVolume(128);
    end;

    PrimitiveFill_c(0x000000);

    if AudioMusicPlaying(music) then
        PrimitiveRectangleFilled_c_f(32, 32, 64, 64, 0xFF0000);
    end;
    if AudioMusicFadingIn() then
        PrimitiveRectangleFilled_c_f(32, 32, 64, 64, 0x00FF00);
    end;
    if AudioMusicFadingOut() then
        PrimitiveRectangleFilled_c_f(32, 32, 64, 64, 0x0000FF);
    end;

    ScreenFlip();
    TimerDelayForFPS(30);
end;

AudioChannelsStop();
AudioMusicStop();
AudioSoundFree(pickup);
AudioSoundFree(punch);
AudioSoundFree(explosion);
AudioMusicFree(music);
AudioQuit();
ScreenQuit();
