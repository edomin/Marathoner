local i;
local tileset;
local scene;
local quit = false;

-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

ScreenInit(640, 480, true, "Sprite Test");
TimerInit();
PrimitiveInit();
MouseInit();
KeyboardInit();
TextureInit(IKDM_SMALL, 32);
TtfInit(IKDM_SMALL, 32);
SpriteInit(IKDM_SMALL, 32);
FontInit(IKDM_SMALL, 32);
SceneInit(IKDM_SMALL, 32);

local ttf = TtfLoad("test/media/Vera.ttf");
TtfSetSizes(ttf, 12, 12);
local font = FontCacheTtf("Font", ttf, 1);

tileset = SpriteLoad("test/media/town_tileset_day.png", 32, 32, 1, 24, 24,
 0, 0);
scene = SceneCreate("Test scene", 6144, 6144, IKDM_SMALL, 32, 1, 1, 1);
SceneAddTileLayer(scene, 0, 32, 32, 192, 192, 0x111111FF);
for i = 0, 191, 1 do
    local j;
    for j = 0, 191, 1 do
        SceneTileLayerSetTile(scene, 0, i, j, tileset, 0);
    end;
end;
SceneAddCamera(scene, 0, 0, 0, 1.0, 0, 0, 640, 480);
SceneCameraSetBoundOut(scene, 0, 0.5, 0.5, false);
SceneCameraSetCursorScrolling(scene, 0, true);
SceneCameraSetScrollingKeys(scene, 0, KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN);
SceneCameraSetScrollingSpeed(scene, 0, 4);
SceneCameraSetMouseWheelScaling(scene, 0, true);

while not quit do
    local cameraX = SceneCameraGetSceneX(scene, 0);
    local cameraY = SceneCameraGetSceneY(scene, 0);
    TimerStart();
--    KeyboardRefresh();
    MouseRefresh();
    if KeyboardPress(KEY_ESCAPE) or ScreenXed() then
        quit = true;
    end;

    SceneUpdate(scene);

    PrimitiveFill_c(0x444444);

    SceneDraw(scene);

    FontDrawString_f(font, 32, 16, "Camera X:" .. cameraX);
    FontDrawString_f(font, 32, 32, "Camera Y:" .. cameraY);

    ScreenFlip();
    TimerDelayForFPS(60);
end;

-- Texture Copy
SpriteFree(helicopter);
SpriteFree(helicopterAnim);
