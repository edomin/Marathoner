#ifndef MTR_UTILS_COLOR_BINDING_COMMON_H
#define MTR_UTILS_COLOR_BINDING_COMMON_H

MTR_FUNC(int, MTR_ColorFunctionSupported, const char *);
MTR_FUNC(uint32_t, MTR_ColorRgbAssemble, uint8_t, uint8_t, uint8_t);
MTR_FUNC(uint32_t, MTR_ColorRgbaAssemble, uint8_t, uint8_t, uint8_t, uint8_t);
#ifdef lua_h
MTR_FUNC(void, MTR_ColorRgbSplit, uint32_t, uint8_t *, uint8_t *, uint8_t *);
#endif
MTR_FUNC(uint8_t, MTR_ColorRgbGetRed, uint32_t);
MTR_FUNC(uint8_t, MTR_ColorRgbGetGreen, uint32_t);
MTR_FUNC(uint8_t, MTR_ColorRgbGetBlue, uint32_t);
MTR_FUNC(uint32_t, MTR_ColorRgbSetRed, uint32_t, uint8_t);
MTR_FUNC(uint32_t, MTR_ColorRgbSetGreen, uint32_t, uint8_t);
MTR_FUNC(uint32_t, MTR_ColorRgbSetBlue, uint32_t, uint8_t);
#ifdef lua_h
MTR_FUNC(void, MTR_ColorRgbaSplit, uint32_t, uint8_t *, uint8_t *, uint8_t *,
 uint8_t *);
#endif
MTR_FUNC(uint8_t, MTR_ColorRgbaGetRed, uint32_t);
MTR_FUNC(uint8_t, MTR_ColorRgbaGetGreen, uint32_t);
MTR_FUNC(uint8_t, MTR_ColorRgbaGetBlue, uint32_t);
MTR_FUNC(uint8_t, MTR_ColorRgbaGetAlpha, uint32_t);
MTR_FUNC(uint32_t, MTR_ColorRgbaSetRed, uint32_t, uint8_t);
MTR_FUNC(uint32_t, MTR_ColorRgbaSetGreen, uint32_t, uint8_t);
MTR_FUNC(uint32_t, MTR_ColorRgbaSetBlue, uint32_t, uint8_t);
MTR_FUNC(uint32_t, MTR_ColorRgbaSetAlpha, uint32_t, uint8_t);
MTR_FUNC(uint32_t, MTR_ColorRgbToRgba, uint32_t);
MTR_FUNC(uint32_t, MTR_ColorRgbaToRgb, uint32_t);

#endif
