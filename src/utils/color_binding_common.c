#ifndef MTR_UTILS_COLOR_BINDING_COMMON_C
#define MTR_UTILS_COLOR_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_ColorFunctionSupported, MTR_ColorFunctionSupported)
MTR_SCRIPT_FUNC_U32t_U8t3(MTR_SF_ColorAssembleRGB, MTR_ColorAssembleRGB)
MTR_SCRIPT_FUNC_U32t_U8t4(MTR_SF_ColorAssembleRGBA, MTR_ColorAssembleRGBA)

#ifdef lua_h
MTR_SCRIPT_FUNC(MTR_SF_ColorSplitRGB)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint32_t rgb;

    MTR_SF_GET_UINT32(rgb, 1);
    MTR_ColorSplitRGB(rgb, &r, &g, &b);

    MTR_SF_PUSH_UINT8(r);
    MTR_SF_PUSH_UINT8(g);
    MTR_SF_PUSH_UINT8(b);

    return 3;
}

MTR_SCRIPT_FUNC(MTR_SF_ColorSplitRGBA)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    uint32_t rgba;

    MTR_SF_GET_UINT32(rgba, 1);
    MTR_ColorSplitRGBA(rgba, &r, &g, &b, &a);

    MTR_SF_PUSH_UINT8(r);
    MTR_SF_PUSH_UINT8(g);
    MTR_SF_PUSH_UINT8(b);
    MTR_SF_PUSH_UINT8(a);

    return 4;
}
#endif

MTR_SCRIPT_FUNC_U8t_U32t1(MTR_SF_ColorRGBGetR, MTR_ColorRGBGetR)
MTR_SCRIPT_FUNC_U8t_U32t1(MTR_SF_ColorRGBGetG, MTR_ColorRGBGetG)
MTR_SCRIPT_FUNC_U8t_U32t1(MTR_SF_ColorRGBGetB, MTR_ColorRGBGetB)
MTR_SCRIPT_FUNC_U32t_U32t1U8t1(MTR_SF_ColorRGBSetR, MTR_ColorRGBSetR)
MTR_SCRIPT_FUNC_U32t_U32t1U8t1(MTR_SF_ColorRGBSetG, MTR_ColorRGBSetG)
MTR_SCRIPT_FUNC_U32t_U32t1U8t1(MTR_SF_ColorRGBSetB, MTR_ColorRGBSetB)
MTR_SCRIPT_FUNC_U8t_U32t1(MTR_SF_ColorRGBAGetR, MTR_ColorRGBAGetR)
MTR_SCRIPT_FUNC_U8t_U32t1(MTR_SF_ColorRGBAGetG, MTR_ColorRGBAGetG)
MTR_SCRIPT_FUNC_U8t_U32t1(MTR_SF_ColorRGBAGetB, MTR_ColorRGBAGetB)
MTR_SCRIPT_FUNC_U8t_U32t1(MTR_SF_ColorRGBAGetA, MTR_ColorRGBAGetA)
MTR_SCRIPT_FUNC_U32t_U32t1U8t1(MTR_SF_ColorRGBASetR, MTR_ColorRGBASetR)
MTR_SCRIPT_FUNC_U32t_U32t1U8t1(MTR_SF_ColorRGBASetG, MTR_ColorRGBASetG)
MTR_SCRIPT_FUNC_U32t_U32t1U8t1(MTR_SF_ColorRGBASetB, MTR_ColorRGBASetB)
MTR_SCRIPT_FUNC_U32t_U32t1U8t1(MTR_SF_ColorRGBASetA, MTR_ColorRGBASetA)
MTR_SCRIPT_FUNC_U32t_U32t1(MTR_SF_ColorRGBtoRGBA, MTR_ColorRGBtoRGBA)
MTR_SCRIPT_FUNC_U32t_U32t1(MTR_SF_ColorRGBAtoRGB, MTR_ColorRGBAtoRGB)

void MTR_ScriptsRegisterAll(void)
{
    mtrVm = MTR_ScriptsGetVm();

    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorAssembleRGB);
    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorAssembleRGBA);
    #ifdef lua_h
    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorSplitRGB);
    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorSplitRGBA);
    #endif
    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorRGBGetR);
    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorRGBGetG);
    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorRGBGetB);
    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorRGBSetR);
    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorRGBSetG);
    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorRGBSetB);
    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorRGBAGetR);
    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorRGBAGetG);
    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorRGBAGetB);
    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorRGBAGetA);
    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorRGBASetR);
    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorRGBASetG);
    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorRGBASetB);
    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorRGBASetA);
    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorRGBtoRGBA);
    MTR_FIND_AND_ADD_FUNCTION("Utils_color", ColorRGBAtoRGB);

    MTR_ScriptsRegisterVariable_u("WEB_WHITE", MTR_CLR_WEB_WHITE);
    MTR_ScriptsRegisterVariable_u("WEB_SILVER", MTR_CLR_WEB_SILVER);
    MTR_ScriptsRegisterVariable_u("WEB_GRAY", MTR_CLR_WEB_GRAY);
    MTR_ScriptsRegisterVariable_u("WEB_BLACK", MTR_CLR_WEB_BLACK);
    MTR_ScriptsRegisterVariable_u("WEB_RED", MTR_CLR_WEB_RED);
    MTR_ScriptsRegisterVariable_u("WEB_MAROON", MTR_CLR_WEB_MAROON);
    MTR_ScriptsRegisterVariable_u("WEB_YELLOW", MTR_CLR_WEB_YELLOW);
    MTR_ScriptsRegisterVariable_u("WEB_OLIVE", MTR_CLR_WEB_OLIVE);
    MTR_ScriptsRegisterVariable_u("WEB_LIME", MTR_CLR_WEB_LIME);
    MTR_ScriptsRegisterVariable_u("WEB_GREEN", MTR_CLR_WEB_GREEN);
    MTR_ScriptsRegisterVariable_u("WEB_AQUA", MTR_CLR_WEB_AQUA);
    MTR_ScriptsRegisterVariable_u("WEB_TEAL", MTR_CLR_WEB_TEAL);
    MTR_ScriptsRegisterVariable_u("WEB_BLUE", MTR_CLR_WEB_BLUE);
    MTR_ScriptsRegisterVariable_u("WEB_NAVY", MTR_CLR_WEB_NAVY);
    MTR_ScriptsRegisterVariable_u("WEB_FUCHSIA", MTR_CLR_WEB_FUCHSIA);
    MTR_ScriptsRegisterVariable_u("WEB_PURPLE", MTR_CLR_WEB_PURPLE);
    MTR_ScriptsRegisterVariable_u("WEB_ORANGE", MTR_CLR_WEB_ORANGE);
    MTR_ScriptsRegisterVariable_u("WEB_REBECCA_PURPLE",
     MTR_CLR_WEB_REBECCA_PURPLE);

    MTR_ScriptsRegisterVariable_u("X11_SNOW", MTR_CLR_X11_SNOW);
    MTR_ScriptsRegisterVariable_u("X11_GHOST_WHITE", MTR_CLR_X11_GHOST_WHITE);
    MTR_ScriptsRegisterVariable_u("X11_GHOSTWHITE", MTR_CLR_X11_GHOSTWHITE);
    MTR_ScriptsRegisterVariable_u("X11_WHITE_SMOKE", MTR_CLR_X11_WHITE_SMOKE);
    MTR_ScriptsRegisterVariable_u("X11_WHITESMOKE", MTR_CLR_X11_WHITESMOKE);
    MTR_ScriptsRegisterVariable_u("X11_GAINSBORO", MTR_CLR_X11_GAINSBORO);
    MTR_ScriptsRegisterVariable_u("X11_FLORAL_WHITE", MTR_CLR_X11_FLORAL_WHITE);
    MTR_ScriptsRegisterVariable_u("X11_FLORALWHITE", MTR_CLR_X11_FLORALWHITE);
    MTR_ScriptsRegisterVariable_u("X11_OLD_LACE", MTR_CLR_X11_OLD_LACE);
    MTR_ScriptsRegisterVariable_u("X11_OLDLACE", MTR_CLR_X11_OLDLACE);
    MTR_ScriptsRegisterVariable_u("X11_LINEN", MTR_CLR_X11_LINEN);
    MTR_ScriptsRegisterVariable_u("X11_ANTIQUE_WHITE",
     MTR_CLR_X11_ANTIQUE_WHITE);
    MTR_ScriptsRegisterVariable_u("X11_ANTIQUEWHITE", MTR_CLR_X11_ANTIQUEWHITE);
    MTR_ScriptsRegisterVariable_u("X11_PAPAYA_WHIP", MTR_CLR_X11_PAPAYA_WHIP);
    MTR_ScriptsRegisterVariable_u("X11_PAPAYAWHIP", MTR_CLR_X11_PAPAYAWHIP);
    MTR_ScriptsRegisterVariable_u("X11_BLANCHED_ALMOND",
     MTR_CLR_X11_BLANCHED_ALMOND);
    MTR_ScriptsRegisterVariable_u("X11_BLANCHEDALMOND",
     MTR_CLR_X11_BLANCHEDALMOND);
    MTR_ScriptsRegisterVariable_u("X11_BISQUE", MTR_CLR_X11_BISQUE);
    MTR_ScriptsRegisterVariable_u("X11_PEACH_PUFF", MTR_CLR_X11_PEACH_PUFF);
    MTR_ScriptsRegisterVariable_u("X11_PEACHPUFF", MTR_CLR_X11_PEACHPUFF);
    MTR_ScriptsRegisterVariable_u("X11_NAVAJO_WHITE", MTR_CLR_X11_NAVAJO_WHITE);
    MTR_ScriptsRegisterVariable_u("X11_NAVAJOWHITE", MTR_CLR_X11_NAVAJOWHITE);
    MTR_ScriptsRegisterVariable_u("X11_MOCCASIN", MTR_CLR_X11_MOCCASIN);
    MTR_ScriptsRegisterVariable_u("X11_CORNSILK", MTR_CLR_X11_CORNSILK);
    MTR_ScriptsRegisterVariable_u("X11_IVORY", MTR_CLR_X11_IVORY);
    MTR_ScriptsRegisterVariable_u("X11_LEMON_CHIFFON",
     MTR_CLR_X11_LEMON_CHIFFON);
    MTR_ScriptsRegisterVariable_u("X11_LEMONCHIFFON", MTR_CLR_X11_LEMONCHIFFON);
    MTR_ScriptsRegisterVariable_u("X11_SEASHELL", MTR_CLR_X11_SEASHELL);
    MTR_ScriptsRegisterVariable_u("X11_HONEYDEW", MTR_CLR_X11_HONEYDEW);
    MTR_ScriptsRegisterVariable_u("X11_MINT_CREAM", MTR_CLR_X11_MINT_CREAM);
    MTR_ScriptsRegisterVariable_u("X11_MINTCREAM", MTR_CLR_X11_MINTCREAM);
    MTR_ScriptsRegisterVariable_u("X11_AZURE", MTR_CLR_X11_AZURE);
    MTR_ScriptsRegisterVariable_u("X11_ALICE_BLUE", MTR_CLR_X11_ALICE_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_ALICEBLUE", MTR_CLR_X11_ALICEBLUE);
    MTR_ScriptsRegisterVariable_u("X11_LAVENDER", MTR_CLR_X11_LAVENDER);
    MTR_ScriptsRegisterVariable_u("X11_LAVENDER_BLUSH",
     MTR_CLR_X11_LAVENDER_BLUSH);
    MTR_ScriptsRegisterVariable_u("X11_LAVENDERBLUSH",
     MTR_CLR_X11_LAVENDERBLUSH);
    MTR_ScriptsRegisterVariable_u("X11_MISTY_ROSE", MTR_CLR_X11_MISTY_ROSE);
    MTR_ScriptsRegisterVariable_u("X11_MISTYROSE", MTR_CLR_X11_MISTYROSE);
    MTR_ScriptsRegisterVariable_u("X11_WHITE", MTR_CLR_X11_WHITE);
    MTR_ScriptsRegisterVariable_u("X11_BLACK", MTR_CLR_X11_BLACK);
    MTR_ScriptsRegisterVariable_u("X11_DARK_SLATE_GRAY",
     MTR_CLR_X11_DARK_SLATE_GRAY);
    MTR_ScriptsRegisterVariable_u("X11_DARKSLATEGRAY",
     MTR_CLR_X11_DARKSLATEGRAY);
    MTR_ScriptsRegisterVariable_u("X11_DARK_SLATE_GREY",
     MTR_CLR_X11_DARK_SLATE_GREY);
    MTR_ScriptsRegisterVariable_u("X11_DARKSLATEGREY",
     MTR_CLR_X11_DARKSLATEGREY);
    MTR_ScriptsRegisterVariable_u("X11_DIM_GRAY", MTR_CLR_X11_DIM_GRAY);
    MTR_ScriptsRegisterVariable_u("X11_DIMGRAY", MTR_CLR_X11_DIMGRAY);
    MTR_ScriptsRegisterVariable_u("X11_DIM_GREY", MTR_CLR_X11_DIM_GREY);
    MTR_ScriptsRegisterVariable_u("X11_DIMGREY", MTR_CLR_X11_DIMGREY);
    MTR_ScriptsRegisterVariable_u("X11_SLATE_GRAY", MTR_CLR_X11_SLATE_GRAY);
    MTR_ScriptsRegisterVariable_u("X11_SLATEGRAY", MTR_CLR_X11_SLATEGRAY);
    MTR_ScriptsRegisterVariable_u("X11_SLATE_GREY", MTR_CLR_X11_SLATE_GREY);
    MTR_ScriptsRegisterVariable_u("X11_SLATEGREY", MTR_CLR_X11_SLATEGREY);
    MTR_ScriptsRegisterVariable_u("X11_LIGHT_SLATE_GRAY",
     MTR_CLR_X11_LIGHT_SLATE_GRAY);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTSLATEGRAY",
     MTR_CLR_X11_LIGHTSLATEGRAY);
    MTR_ScriptsRegisterVariable_u("X11_LIGHT_SLATE_GREY",
     MTR_CLR_X11_LIGHT_SLATE_GREY);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTSLATEGREY",
     MTR_CLR_X11_LIGHTSLATEGREY);
    MTR_ScriptsRegisterVariable_u("X11_GRAY", MTR_CLR_X11_GRAY);
    MTR_ScriptsRegisterVariable_u("X11_GREY", MTR_CLR_X11_GREY);
    MTR_ScriptsRegisterVariable_u("X11_LIGHT_GREY", MTR_CLR_X11_LIGHT_GREY);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTGREY", MTR_CLR_X11_LIGHTGREY);
    MTR_ScriptsRegisterVariable_u("X11_LIGHT_GRAY", MTR_CLR_X11_LIGHT_GRAY);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTGRAY", MTR_CLR_X11_LIGHTGRAY);
    MTR_ScriptsRegisterVariable_u("X11_MIDNIGHT_BLUE",
     MTR_CLR_X11_MIDNIGHT_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_MIDNIGHTBLUE", MTR_CLR_X11_MIDNIGHTBLUE);
    MTR_ScriptsRegisterVariable_u("X11_NAVY", MTR_CLR_X11_NAVY);
    MTR_ScriptsRegisterVariable_u("X11_NAVY_BLUE", MTR_CLR_X11_NAVY_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_NAVYBLUE", MTR_CLR_X11_NAVYBLUE);
    MTR_ScriptsRegisterVariable_u("X11_CORNFLOWER_BLUE",
     MTR_CLR_X11_CORNFLOWER_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_CORNFLOWERBLUE",
     MTR_CLR_X11_CORNFLOWERBLUE);
    MTR_ScriptsRegisterVariable_u("X11_DARK_SLATE_BLUE",
     MTR_CLR_X11_DARK_SLATE_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_DARKSLATEBLUE",
     MTR_CLR_X11_DARKSLATEBLUE);
    MTR_ScriptsRegisterVariable_u("X11_SLATE_BLUE", MTR_CLR_X11_SLATE_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_SLATEBLUE", MTR_CLR_X11_SLATEBLUE);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUM_SLATE_BLUE",
     MTR_CLR_X11_MEDIUM_SLATE_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUMSLATEBLUE",
     MTR_CLR_X11_MEDIUMSLATEBLUE);
    MTR_ScriptsRegisterVariable_u("X11_LIGHT_SLATE_BLUE",
     MTR_CLR_X11_LIGHT_SLATE_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTSLATEBLUE",
     MTR_CLR_X11_LIGHTSLATEBLUE);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUM_BLUE", MTR_CLR_X11_MEDIUM_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUMBLUE", MTR_CLR_X11_MEDIUMBLUE);
    MTR_ScriptsRegisterVariable_u("X11_ROYAL_BLUE", MTR_CLR_X11_ROYAL_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_ROYALBLUE", MTR_CLR_X11_ROYALBLUE);
    MTR_ScriptsRegisterVariable_u("X11_BLUE", MTR_CLR_X11_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_DODGER_BLUE", MTR_CLR_X11_DODGER_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_DODGERBLUE", MTR_CLR_X11_DODGERBLUE);
    MTR_ScriptsRegisterVariable_u("X11_DEEP_SKY_BLUE",
     MTR_CLR_X11_DEEP_SKY_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_DEEPSKYBLUE", MTR_CLR_X11_DEEPSKYBLUE);
    MTR_ScriptsRegisterVariable_u("X11_SKY_BLUE", MTR_CLR_X11_SKY_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_SKYBLUE", MTR_CLR_X11_SKYBLUE);
    MTR_ScriptsRegisterVariable_u("X11_LIGHT_SKY_BLUE",
     MTR_CLR_X11_LIGHT_SKY_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTSKYBLUE", MTR_CLR_X11_LIGHTSKYBLUE);
    MTR_ScriptsRegisterVariable_u("X11_STEEL_BLUE", MTR_CLR_X11_STEEL_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_STEELBLUE", MTR_CLR_X11_STEELBLUE);
    MTR_ScriptsRegisterVariable_u("X11_LIGHT_STEEL_BLUE",
     MTR_CLR_X11_LIGHT_STEEL_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTSTEELBLUE",
     MTR_CLR_X11_LIGHTSTEELBLUE);
    MTR_ScriptsRegisterVariable_u("X11_LIGHT_BLUE", MTR_CLR_X11_LIGHT_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTBLUE", MTR_CLR_X11_LIGHTBLUE);
    MTR_ScriptsRegisterVariable_u("X11_POWDER_BLUE", MTR_CLR_X11_POWDER_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_POWDERBLUE", MTR_CLR_X11_POWDERBLUE);
    MTR_ScriptsRegisterVariable_u("X11_PALE_TURQUOISE",
     MTR_CLR_X11_PALE_TURQUOISE);
    MTR_ScriptsRegisterVariable_u("X11_PALETURQUOISE",
     MTR_CLR_X11_PALETURQUOISE);
    MTR_ScriptsRegisterVariable_u("X11_DARK_TURQUOISE",
     MTR_CLR_X11_DARK_TURQUOISE);
    MTR_ScriptsRegisterVariable_u("X11_DARKTURQUOISE",
     MTR_CLR_X11_DARKTURQUOISE);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUM_TURQUOISE",
     MTR_CLR_X11_MEDIUM_TURQUOISE);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUMTURQUOISE",
     MTR_CLR_X11_MEDIUMTURQUOISE);
    MTR_ScriptsRegisterVariable_u("X11_TURQUOISE", MTR_CLR_X11_TURQUOISE);
    MTR_ScriptsRegisterVariable_u("X11_CYAN", MTR_CLR_X11_CYAN);
    MTR_ScriptsRegisterVariable_u("X11_LIGHT_CYAN", MTR_CLR_X11_LIGHT_CYAN);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTCYAN", MTR_CLR_X11_LIGHTCYAN);
    MTR_ScriptsRegisterVariable_u("X11_CADET_BLUE", MTR_CLR_X11_CADET_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_CADETBLUE", MTR_CLR_X11_CADETBLUE);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUM_AQUAMARINE",
     MTR_CLR_X11_MEDIUM_AQUAMARINE);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUMAQUAMARINE",
     MTR_CLR_X11_MEDIUMAQUAMARINE);
    MTR_ScriptsRegisterVariable_u("X11_AQUAMARINE", MTR_CLR_X11_AQUAMARINE);
    MTR_ScriptsRegisterVariable_u("X11_DARK_GREEN", MTR_CLR_X11_DARK_GREEN);
    MTR_ScriptsRegisterVariable_u("X11_DARKGREEN", MTR_CLR_X11_DARKGREEN);
    MTR_ScriptsRegisterVariable_u("X11_DARK_OLIVE_GREEN",
     MTR_CLR_X11_DARK_OLIVE_GREEN);
    MTR_ScriptsRegisterVariable_u("X11_DARKOLIVEGREEN",
     MTR_CLR_X11_DARKOLIVEGREEN);
    MTR_ScriptsRegisterVariable_u("X11_DARK_SEA_GREEN",
     MTR_CLR_X11_DARK_SEA_GREEN);
    MTR_ScriptsRegisterVariable_u("X11_DARKSEAGREEN",
     MTR_CLR_X11_DARKSEAGREEN);
    MTR_ScriptsRegisterVariable_u("X11_SEA_GREEN", MTR_CLR_X11_SEA_GREEN);
    MTR_ScriptsRegisterVariable_u("X11_SEAGREEN", MTR_CLR_X11_SEAGREEN);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUM_SEA_GREEN",
     MTR_CLR_X11_MEDIUM_SEA_GREEN);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUMSEAGREEN",
     MTR_CLR_X11_MEDIUMSEAGREEN);
    MTR_ScriptsRegisterVariable_u("X11_LIGHT_SEA_GREEN",
     MTR_CLR_X11_LIGHT_SEA_GREEN);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTSEAGREEN",
     MTR_CLR_X11_LIGHTSEAGREEN);
    MTR_ScriptsRegisterVariable_u("X11_PALE_GREEN", MTR_CLR_X11_PALE_GREEN);
    MTR_ScriptsRegisterVariable_u("X11_PALEGREEN", MTR_CLR_X11_PALEGREEN);
    MTR_ScriptsRegisterVariable_u("X11_SPRING_GREEN", MTR_CLR_X11_SPRING_GREEN);
    MTR_ScriptsRegisterVariable_u("X11_SPRINGGREEN", MTR_CLR_X11_SPRINGGREEN);
    MTR_ScriptsRegisterVariable_u("X11_LAWN_GREEN", MTR_CLR_X11_LAWN_GREEN);
    MTR_ScriptsRegisterVariable_u("X11_LAWNGREEN", MTR_CLR_X11_LAWNGREEN);
    MTR_ScriptsRegisterVariable_u("X11_GREEN", MTR_CLR_X11_GREEN);
    MTR_ScriptsRegisterVariable_u("X11_CHARTREUSE", MTR_CLR_X11_CHARTREUSE);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUM_SPRING_GREEN",
     MTR_CLR_X11_MEDIUM_SPRING_GREEN);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUMSPRINGGREEN",
     MTR_CLR_X11_MEDIUMSPRINGGREEN);
    MTR_ScriptsRegisterVariable_u("X11_GREEN_YELLOW", MTR_CLR_X11_GREEN_YELLOW);
    MTR_ScriptsRegisterVariable_u("X11_GREENYELLOW", MTR_CLR_X11_GREENYELLOW);
    MTR_ScriptsRegisterVariable_u("X11_LIME_GREEN", MTR_CLR_X11_LIME_GREEN);
    MTR_ScriptsRegisterVariable_u("X11_LIMEGREEN", MTR_CLR_X11_LIMEGREEN);
    MTR_ScriptsRegisterVariable_u("X11_YELLOW_GREEN", MTR_CLR_X11_YELLOW_GREEN);
    MTR_ScriptsRegisterVariable_u("X11_YELLOWGREEN", MTR_CLR_X11_YELLOWGREEN);
    MTR_ScriptsRegisterVariable_u("X11_FOREST_GREEN", MTR_CLR_X11_FOREST_GREEN);
    MTR_ScriptsRegisterVariable_u("X11_FORESTGREEN", MTR_CLR_X11_FORESTGREEN);
    MTR_ScriptsRegisterVariable_u("X11_OLIVE_DRAB", MTR_CLR_X11_OLIVE_DRAB);
    MTR_ScriptsRegisterVariable_u("X11_OLIVEDRAB", MTR_CLR_X11_OLIVEDRAB);
    MTR_ScriptsRegisterVariable_u("X11_DARK_KHAKI", MTR_CLR_X11_DARK_KHAKI);
    MTR_ScriptsRegisterVariable_u("X11_DARKKHAKI", MTR_CLR_X11_DARKKHAKI);
    MTR_ScriptsRegisterVariable_u("X11_KHAKI", MTR_CLR_X11_KHAKI);
    MTR_ScriptsRegisterVariable_u("X11_PALE_GOLDENROD",
     MTR_CLR_X11_PALE_GOLDENROD);
    MTR_ScriptsRegisterVariable_u("X11_PALEGOLDENROD",
     MTR_CLR_X11_PALEGOLDENROD);
    MTR_ScriptsRegisterVariable_u("X11_LIGHT_GOLDENROD_YELLOW",
     MTR_CLR_X11_LIGHT_GOLDENROD_YELLOW);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTGOLDENRODYELLOW",
     MTR_CLR_X11_LIGHTGOLDENRODYELLOW);
    MTR_ScriptsRegisterVariable_u("X11_LIGHT_YELLOW", MTR_CLR_X11_LIGHT_YELLOW);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTYELLOW", MTR_CLR_X11_LIGHTYELLOW);
    MTR_ScriptsRegisterVariable_u("X11_YELLOW", MTR_CLR_X11_YELLOW);
    MTR_ScriptsRegisterVariable_u("X11_GOLD", MTR_CLR_X11_GOLD);
    MTR_ScriptsRegisterVariable_u("X11_LIGHT_GOLDENROD",
     MTR_CLR_X11_LIGHT_GOLDENROD);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTGOLDENROD",
     MTR_CLR_X11_LIGHTGOLDENROD);
    MTR_ScriptsRegisterVariable_u("X11_GOLDENROD", MTR_CLR_X11_GOLDENROD);
    MTR_ScriptsRegisterVariable_u("X11_DARK_GOLDENROD",
     MTR_CLR_X11_DARK_GOLDENROD);
    MTR_ScriptsRegisterVariable_u("X11_DARKGOLDENROD",
     MTR_CLR_X11_DARKGOLDENROD);
    MTR_ScriptsRegisterVariable_u("X11_ROSY_BROWN", MTR_CLR_X11_ROSY_BROWN);
    MTR_ScriptsRegisterVariable_u("X11_ROSYBROWN", MTR_CLR_X11_ROSYBROWN);
    MTR_ScriptsRegisterVariable_u("X11_INDIAN_RED", MTR_CLR_X11_INDIAN_RED);
    MTR_ScriptsRegisterVariable_u("X11_INDIANRED", MTR_CLR_X11_INDIANRED);
    MTR_ScriptsRegisterVariable_u("X11_SADDLE_BROWN", MTR_CLR_X11_SADDLE_BROWN);
    MTR_ScriptsRegisterVariable_u("X11_SADDLEBROWN", MTR_CLR_X11_SADDLEBROWN);
    MTR_ScriptsRegisterVariable_u("X11_SIENNA", MTR_CLR_X11_SIENNA);
    MTR_ScriptsRegisterVariable_u("X11_PERU", MTR_CLR_X11_PERU);
    MTR_ScriptsRegisterVariable_u("X11_BURLYWOOD", MTR_CLR_X11_BURLYWOOD);
    MTR_ScriptsRegisterVariable_u("X11_BEIGE", MTR_CLR_X11_BEIGE);
    MTR_ScriptsRegisterVariable_u("X11_WHEAT", MTR_CLR_X11_WHEAT);
    MTR_ScriptsRegisterVariable_u("X11_SANDY_BROWN", MTR_CLR_X11_SANDY_BROWN);
    MTR_ScriptsRegisterVariable_u("X11_SANDYBROWN", MTR_CLR_X11_SANDYBROWN);
    MTR_ScriptsRegisterVariable_u("X11_TAN", MTR_CLR_X11_TAN);
    MTR_ScriptsRegisterVariable_u("X11_CHOCOLATE", MTR_CLR_X11_CHOCOLATE);
    MTR_ScriptsRegisterVariable_u("X11_FIREBRICK", MTR_CLR_X11_FIREBRICK);
    MTR_ScriptsRegisterVariable_u("X11_BROWN", MTR_CLR_X11_BROWN);
    MTR_ScriptsRegisterVariable_u("X11_DARK_SALMON", MTR_CLR_X11_DARK_SALMON);
    MTR_ScriptsRegisterVariable_u("X11_DARKSALMON", MTR_CLR_X11_DARKSALMON);
    MTR_ScriptsRegisterVariable_u("X11_SALMON", MTR_CLR_X11_SALMON);
    MTR_ScriptsRegisterVariable_u("X11_LIGHT_SALMON", MTR_CLR_X11_LIGHT_SALMON);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTSALMON", MTR_CLR_X11_LIGHTSALMON);
    MTR_ScriptsRegisterVariable_u("X11_ORANGE", MTR_CLR_X11_ORANGE);
    MTR_ScriptsRegisterVariable_u("X11_DARK_ORANGE", MTR_CLR_X11_DARK_ORANGE);
    MTR_ScriptsRegisterVariable_u("X11_DARKORANGE", MTR_CLR_X11_DARKORANGE);
    MTR_ScriptsRegisterVariable_u("X11_CORAL", MTR_CLR_X11_CORAL);
    MTR_ScriptsRegisterVariable_u("X11_LIGHT_CORAL", MTR_CLR_X11_LIGHT_CORAL);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTCORAL", MTR_CLR_X11_LIGHTCORAL);
    MTR_ScriptsRegisterVariable_u("X11_TOMATO", MTR_CLR_X11_TOMATO);
    MTR_ScriptsRegisterVariable_u("X11_ORANGE_RED", MTR_CLR_X11_ORANGE_RED);
    MTR_ScriptsRegisterVariable_u("X11_ORANGERED", MTR_CLR_X11_ORANGERED);
    MTR_ScriptsRegisterVariable_u("X11_RED", MTR_CLR_X11_RED);
    MTR_ScriptsRegisterVariable_u("X11_HOT_PINK", MTR_CLR_X11_HOT_PINK);
    MTR_ScriptsRegisterVariable_u("X11_HOTPINK", MTR_CLR_X11_HOTPINK);
    MTR_ScriptsRegisterVariable_u("X11_DEEP_PINK", MTR_CLR_X11_DEEP_PINK);
    MTR_ScriptsRegisterVariable_u("X11_DEEPPINK", MTR_CLR_X11_DEEPPINK);
    MTR_ScriptsRegisterVariable_u("X11_PINK", MTR_CLR_X11_PINK);
    MTR_ScriptsRegisterVariable_u("X11_LIGHT_PINK", MTR_CLR_X11_LIGHT_PINK);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTPINK", MTR_CLR_X11_LIGHTPINK);
    MTR_ScriptsRegisterVariable_u("X11_PALE_VIOLET_RED",
     MTR_CLR_X11_PALE_VIOLET_RED);
    MTR_ScriptsRegisterVariable_u("X11_PALEVIOLETRED",
     MTR_CLR_X11_PALEVIOLETRED);
    MTR_ScriptsRegisterVariable_u("X11_MAROON", MTR_CLR_X11_MAROON);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUM_VIOLET_RED",
     MTR_CLR_X11_MEDIUM_VIOLET_RED);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUMVIOLETRED",
     MTR_CLR_X11_MEDIUMVIOLETRED);
    MTR_ScriptsRegisterVariable_u("X11_VIOLET_RED", MTR_CLR_X11_VIOLET_RED);
    MTR_ScriptsRegisterVariable_u("X11_VIOLETRED", MTR_CLR_X11_VIOLETRED);
    MTR_ScriptsRegisterVariable_u("X11_MAGENTA", MTR_CLR_X11_MAGENTA);
    MTR_ScriptsRegisterVariable_u("X11_VIOLET", MTR_CLR_X11_VIOLET);
    MTR_ScriptsRegisterVariable_u("X11_PLUM", MTR_CLR_X11_PLUM);
    MTR_ScriptsRegisterVariable_u("X11_ORCHID", MTR_CLR_X11_ORCHID);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUM_ORCHID",
     MTR_CLR_X11_MEDIUM_ORCHID);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUMORCHID", MTR_CLR_X11_MEDIUMORCHID);
    MTR_ScriptsRegisterVariable_u("X11_DARK_ORCHID", MTR_CLR_X11_DARK_ORCHID);
    MTR_ScriptsRegisterVariable_u("X11_DARKORCHID", MTR_CLR_X11_DARKORCHID);
    MTR_ScriptsRegisterVariable_u("X11_DARK_VIOLET", MTR_CLR_X11_DARK_VIOLET);
    MTR_ScriptsRegisterVariable_u("X11_DARKVIOLET", MTR_CLR_X11_DARKVIOLET);
    MTR_ScriptsRegisterVariable_u("X11_BLUE_VIOLET", MTR_CLR_X11_BLUE_VIOLET);
    MTR_ScriptsRegisterVariable_u("X11_BLUEVIOLET", MTR_CLR_X11_BLUEVIOLET);
    MTR_ScriptsRegisterVariable_u("X11_PURPLE", MTR_CLR_X11_PURPLE);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUM_PURPLE",
     MTR_CLR_X11_MEDIUM_PURPLE);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUMPURPLE", MTR_CLR_X11_MEDIUMPURPLE);
    MTR_ScriptsRegisterVariable_u("X11_THISTLE", MTR_CLR_X11_THISTLE);
    MTR_ScriptsRegisterVariable_u("X11_SNOW1", MTR_CLR_X11_SNOW1);
    MTR_ScriptsRegisterVariable_u("X11_SNOW2", MTR_CLR_X11_SNOW2);
    MTR_ScriptsRegisterVariable_u("X11_SNOW3", MTR_CLR_X11_SNOW3);
    MTR_ScriptsRegisterVariable_u("X11_SNOW4", MTR_CLR_X11_SNOW4);
    MTR_ScriptsRegisterVariable_u("X11_SEASHELL1", MTR_CLR_X11_SEASHELL1);
    MTR_ScriptsRegisterVariable_u("X11_SEASHELL2", MTR_CLR_X11_SEASHELL2);
    MTR_ScriptsRegisterVariable_u("X11_SEASHELL3", MTR_CLR_X11_SEASHELL3);
    MTR_ScriptsRegisterVariable_u("X11_SEASHELL4", MTR_CLR_X11_SEASHELL4);
    MTR_ScriptsRegisterVariable_u("X11_ANTIQUEWHITE1",
     MTR_CLR_X11_ANTIQUEWHITE1);
    MTR_ScriptsRegisterVariable_u("X11_ANTIQUEWHITE2",
     MTR_CLR_X11_ANTIQUEWHITE2);
    MTR_ScriptsRegisterVariable_u("X11_ANTIQUEWHITE3",
     MTR_CLR_X11_ANTIQUEWHITE3);
    MTR_ScriptsRegisterVariable_u("X11_ANTIQUEWHITE4",
     MTR_CLR_X11_ANTIQUEWHITE4);
    MTR_ScriptsRegisterVariable_u("X11_BISQUE1", MTR_CLR_X11_BISQUE1);
    MTR_ScriptsRegisterVariable_u("X11_BISQUE2", MTR_CLR_X11_BISQUE2);
    MTR_ScriptsRegisterVariable_u("X11_BISQUE3", MTR_CLR_X11_BISQUE3);
    MTR_ScriptsRegisterVariable_u("X11_BISQUE4", MTR_CLR_X11_BISQUE4);
    MTR_ScriptsRegisterVariable_u("X11_PEACHPUFF1", MTR_CLR_X11_PEACHPUFF1);
    MTR_ScriptsRegisterVariable_u("X11_PEACHPUFF2", MTR_CLR_X11_PEACHPUFF2);
    MTR_ScriptsRegisterVariable_u("X11_PEACHPUFF3", MTR_CLR_X11_PEACHPUFF3);
    MTR_ScriptsRegisterVariable_u("X11_PEACHPUFF4", MTR_CLR_X11_PEACHPUFF4);
    MTR_ScriptsRegisterVariable_u("X11_NAVAJOWHITE1", MTR_CLR_X11_NAVAJOWHITE1);
    MTR_ScriptsRegisterVariable_u("X11_NAVAJOWHITE2", MTR_CLR_X11_NAVAJOWHITE2);
    MTR_ScriptsRegisterVariable_u("X11_NAVAJOWHITE3", MTR_CLR_X11_NAVAJOWHITE3);
    MTR_ScriptsRegisterVariable_u("X11_NAVAJOWHITE4", MTR_CLR_X11_NAVAJOWHITE4);
    MTR_ScriptsRegisterVariable_u("X11_LEMONCHIFFON1",
     MTR_CLR_X11_LEMONCHIFFON1);
    MTR_ScriptsRegisterVariable_u("X11_LEMONCHIFFON2",
     MTR_CLR_X11_LEMONCHIFFON2);
    MTR_ScriptsRegisterVariable_u("X11_LEMONCHIFFON3",
     MTR_CLR_X11_LEMONCHIFFON3);
    MTR_ScriptsRegisterVariable_u("X11_LEMONCHIFFON4",
     MTR_CLR_X11_LEMONCHIFFON4);
    MTR_ScriptsRegisterVariable_u("X11_CORNSILK1", MTR_CLR_X11_CORNSILK1);
    MTR_ScriptsRegisterVariable_u("X11_CORNSILK2", MTR_CLR_X11_CORNSILK2);
    MTR_ScriptsRegisterVariable_u("X11_CORNSILK3", MTR_CLR_X11_CORNSILK3);
    MTR_ScriptsRegisterVariable_u("X11_CORNSILK4", MTR_CLR_X11_CORNSILK4);
    MTR_ScriptsRegisterVariable_u("X11_IVORY1", MTR_CLR_X11_IVORY1);
    MTR_ScriptsRegisterVariable_u("X11_IVORY2", MTR_CLR_X11_IVORY2);
    MTR_ScriptsRegisterVariable_u("X11_IVORY3", MTR_CLR_X11_IVORY3);
    MTR_ScriptsRegisterVariable_u("X11_IVORY4", MTR_CLR_X11_IVORY4);
    MTR_ScriptsRegisterVariable_u("X11_HONEYDEW1", MTR_CLR_X11_HONEYDEW1);
    MTR_ScriptsRegisterVariable_u("X11_HONEYDEW2", MTR_CLR_X11_HONEYDEW2);
    MTR_ScriptsRegisterVariable_u("X11_HONEYDEW3", MTR_CLR_X11_HONEYDEW3);
    MTR_ScriptsRegisterVariable_u("X11_HONEYDEW4", MTR_CLR_X11_HONEYDEW4);
    MTR_ScriptsRegisterVariable_u("X11_LAVENDERBLUSH1",
     MTR_CLR_X11_LAVENDERBLUSH1);
    MTR_ScriptsRegisterVariable_u("X11_LAVENDERBLUSH2",
     MTR_CLR_X11_LAVENDERBLUSH2);
    MTR_ScriptsRegisterVariable_u("X11_LAVENDERBLUSH3",
     MTR_CLR_X11_LAVENDERBLUSH3);
    MTR_ScriptsRegisterVariable_u("X11_LAVENDERBLUSH4",
     MTR_CLR_X11_LAVENDERBLUSH4);
    MTR_ScriptsRegisterVariable_u("X11_MISTYROSE1", MTR_CLR_X11_MISTYROSE1);
    MTR_ScriptsRegisterVariable_u("X11_MISTYROSE2", MTR_CLR_X11_MISTYROSE2);
    MTR_ScriptsRegisterVariable_u("X11_MISTYROSE3", MTR_CLR_X11_MISTYROSE3);
    MTR_ScriptsRegisterVariable_u("X11_MISTYROSE4", MTR_CLR_X11_MISTYROSE4);
    MTR_ScriptsRegisterVariable_u("X11_AZURE1", MTR_CLR_X11_AZURE1);
    MTR_ScriptsRegisterVariable_u("X11_AZURE2", MTR_CLR_X11_AZURE2);
    MTR_ScriptsRegisterVariable_u("X11_AZURE3", MTR_CLR_X11_AZURE3);
    MTR_ScriptsRegisterVariable_u("X11_AZURE4", MTR_CLR_X11_AZURE4);
    MTR_ScriptsRegisterVariable_u("X11_SLATEBLUE1", MTR_CLR_X11_SLATEBLUE1);
    MTR_ScriptsRegisterVariable_u("X11_SLATEBLUE2", MTR_CLR_X11_SLATEBLUE2);
    MTR_ScriptsRegisterVariable_u("X11_SLATEBLUE3", MTR_CLR_X11_SLATEBLUE3);
    MTR_ScriptsRegisterVariable_u("X11_SLATEBLUE4", MTR_CLR_X11_SLATEBLUE4);
    MTR_ScriptsRegisterVariable_u("X11_ROYALBLUE1", MTR_CLR_X11_ROYALBLUE1);
    MTR_ScriptsRegisterVariable_u("X11_ROYALBLUE2", MTR_CLR_X11_ROYALBLUE2);
    MTR_ScriptsRegisterVariable_u("X11_ROYALBLUE3", MTR_CLR_X11_ROYALBLUE3);
    MTR_ScriptsRegisterVariable_u("X11_ROYALBLUE4", MTR_CLR_X11_ROYALBLUE4);
    MTR_ScriptsRegisterVariable_u("X11_BLUE1", MTR_CLR_X11_BLUE1);
    MTR_ScriptsRegisterVariable_u("X11_BLUE2", MTR_CLR_X11_BLUE2);
    MTR_ScriptsRegisterVariable_u("X11_BLUE3", MTR_CLR_X11_BLUE3);
    MTR_ScriptsRegisterVariable_u("X11_BLUE4", MTR_CLR_X11_BLUE4);
    MTR_ScriptsRegisterVariable_u("X11_DODGERBLUE1", MTR_CLR_X11_DODGERBLUE1);
    MTR_ScriptsRegisterVariable_u("X11_DODGERBLUE2", MTR_CLR_X11_DODGERBLUE2);
    MTR_ScriptsRegisterVariable_u("X11_DODGERBLUE3", MTR_CLR_X11_DODGERBLUE3);
    MTR_ScriptsRegisterVariable_u("X11_DODGERBLUE4", MTR_CLR_X11_DODGERBLUE4);
    MTR_ScriptsRegisterVariable_u("X11_STEELBLUE1", MTR_CLR_X11_STEELBLUE1);
    MTR_ScriptsRegisterVariable_u("X11_STEELBLUE2", MTR_CLR_X11_STEELBLUE2);
    MTR_ScriptsRegisterVariable_u("X11_STEELBLUE3", MTR_CLR_X11_STEELBLUE3);
    MTR_ScriptsRegisterVariable_u("X11_STEELBLUE4", MTR_CLR_X11_STEELBLUE4);
    MTR_ScriptsRegisterVariable_u("X11_DEEPSKYBLUE1", MTR_CLR_X11_DEEPSKYBLUE1);
    MTR_ScriptsRegisterVariable_u("X11_DEEPSKYBLUE2", MTR_CLR_X11_DEEPSKYBLUE2);
    MTR_ScriptsRegisterVariable_u("X11_DEEPSKYBLUE3", MTR_CLR_X11_DEEPSKYBLUE3);
    MTR_ScriptsRegisterVariable_u("X11_DEEPSKYBLUE4", MTR_CLR_X11_DEEPSKYBLUE4);
    MTR_ScriptsRegisterVariable_u("X11_SKYBLUE1", MTR_CLR_X11_SKYBLUE1);
    MTR_ScriptsRegisterVariable_u("X11_SKYBLUE2", MTR_CLR_X11_SKYBLUE2);
    MTR_ScriptsRegisterVariable_u("X11_SKYBLUE3", MTR_CLR_X11_SKYBLUE3);
    MTR_ScriptsRegisterVariable_u("X11_SKYBLUE4", MTR_CLR_X11_SKYBLUE4);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTSKYBLUE1",
     MTR_CLR_X11_LIGHTSKYBLUE1);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTSKYBLUE2",
     MTR_CLR_X11_LIGHTSKYBLUE2);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTSKYBLUE3",
     MTR_CLR_X11_LIGHTSKYBLUE3);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTSKYBLUE4",
     MTR_CLR_X11_LIGHTSKYBLUE4);
    MTR_ScriptsRegisterVariable_u("X11_SLATEGRAY1", MTR_CLR_X11_SLATEGRAY1);
    MTR_ScriptsRegisterVariable_u("X11_SLATEGRAY2", MTR_CLR_X11_SLATEGRAY2);
    MTR_ScriptsRegisterVariable_u("X11_SLATEGRAY3", MTR_CLR_X11_SLATEGRAY3);
    MTR_ScriptsRegisterVariable_u("X11_SLATEGRAY4", MTR_CLR_X11_SLATEGRAY4);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTSTEELBLUE1",
     MTR_CLR_X11_LIGHTSTEELBLUE1);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTSTEELBLUE2",
     MTR_CLR_X11_LIGHTSTEELBLUE2);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTSTEELBLUE3",
     MTR_CLR_X11_LIGHTSTEELBLUE3);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTSTEELBLUE4",
     MTR_CLR_X11_LIGHTSTEELBLUE4);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTBLUE1", MTR_CLR_X11_LIGHTBLUE1);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTBLUE2", MTR_CLR_X11_LIGHTBLUE2);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTBLUE3", MTR_CLR_X11_LIGHTBLUE3);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTBLUE4", MTR_CLR_X11_LIGHTBLUE4);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTCYAN1", MTR_CLR_X11_LIGHTCYAN1);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTCYAN2", MTR_CLR_X11_LIGHTCYAN2);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTCYAN3", MTR_CLR_X11_LIGHTCYAN3);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTCYAN4", MTR_CLR_X11_LIGHTCYAN4);
    MTR_ScriptsRegisterVariable_u("X11_PALETURQUOISE1",
     MTR_CLR_X11_PALETURQUOISE1);
    MTR_ScriptsRegisterVariable_u("X11_PALETURQUOISE2",
     MTR_CLR_X11_PALETURQUOISE2);
    MTR_ScriptsRegisterVariable_u("X11_PALETURQUOISE3",
     MTR_CLR_X11_PALETURQUOISE3);
    MTR_ScriptsRegisterVariable_u("X11_PALETURQUOISE4",
     MTR_CLR_X11_PALETURQUOISE4);
    MTR_ScriptsRegisterVariable_u("X11_CADETBLUE1", MTR_CLR_X11_CADETBLUE1);
    MTR_ScriptsRegisterVariable_u("X11_CADETBLUE2", MTR_CLR_X11_CADETBLUE2);
    MTR_ScriptsRegisterVariable_u("X11_CADETBLUE3", MTR_CLR_X11_CADETBLUE3);
    MTR_ScriptsRegisterVariable_u("X11_CADETBLUE4", MTR_CLR_X11_CADETBLUE4);
    MTR_ScriptsRegisterVariable_u("X11_TURQUOISE1", MTR_CLR_X11_TURQUOISE1);
    MTR_ScriptsRegisterVariable_u("X11_TURQUOISE2", MTR_CLR_X11_TURQUOISE2);
    MTR_ScriptsRegisterVariable_u("X11_TURQUOISE3", MTR_CLR_X11_TURQUOISE3);
    MTR_ScriptsRegisterVariable_u("X11_TURQUOISE4", MTR_CLR_X11_TURQUOISE4);
    MTR_ScriptsRegisterVariable_u("X11_CYAN1", MTR_CLR_X11_CYAN1);
    MTR_ScriptsRegisterVariable_u("X11_CYAN2", MTR_CLR_X11_CYAN2);
    MTR_ScriptsRegisterVariable_u("X11_CYAN3", MTR_CLR_X11_CYAN3);
    MTR_ScriptsRegisterVariable_u("X11_CYAN4", MTR_CLR_X11_CYAN4);
    MTR_ScriptsRegisterVariable_u("X11_DARKSLATEGRAY1",
     MTR_CLR_X11_DARKSLATEGRAY1);
    MTR_ScriptsRegisterVariable_u("X11_DARKSLATEGRAY2",
     MTR_CLR_X11_DARKSLATEGRAY2);
    MTR_ScriptsRegisterVariable_u("X11_DARKSLATEGRAY3",
     MTR_CLR_X11_DARKSLATEGRAY3);
    MTR_ScriptsRegisterVariable_u("X11_DARKSLATEGRAY4",
     MTR_CLR_X11_DARKSLATEGRAY4);
    MTR_ScriptsRegisterVariable_u("X11_AQUAMARINE1", MTR_CLR_X11_AQUAMARINE1);
    MTR_ScriptsRegisterVariable_u("X11_AQUAMARINE2", MTR_CLR_X11_AQUAMARINE2);
    MTR_ScriptsRegisterVariable_u("X11_AQUAMARINE3", MTR_CLR_X11_AQUAMARINE3);
    MTR_ScriptsRegisterVariable_u("X11_AQUAMARINE4", MTR_CLR_X11_AQUAMARINE4);
    MTR_ScriptsRegisterVariable_u("X11_DARKSEAGREEN1",
     MTR_CLR_X11_DARKSEAGREEN1);
    MTR_ScriptsRegisterVariable_u("X11_DARKSEAGREEN2",
     MTR_CLR_X11_DARKSEAGREEN2);
    MTR_ScriptsRegisterVariable_u("X11_DARKSEAGREEN3",
     MTR_CLR_X11_DARKSEAGREEN3);
    MTR_ScriptsRegisterVariable_u("X11_DARKSEAGREEN4",
     MTR_CLR_X11_DARKSEAGREEN4);
    MTR_ScriptsRegisterVariable_u("X11_SEAGREEN1", MTR_CLR_X11_SEAGREEN1);
    MTR_ScriptsRegisterVariable_u("X11_SEAGREEN2", MTR_CLR_X11_SEAGREEN2);
    MTR_ScriptsRegisterVariable_u("X11_SEAGREEN3", MTR_CLR_X11_SEAGREEN3);
    MTR_ScriptsRegisterVariable_u("X11_SEAGREEN4", MTR_CLR_X11_SEAGREEN4);
    MTR_ScriptsRegisterVariable_u("X11_PALEGREEN1", MTR_CLR_X11_PALEGREEN1);
    MTR_ScriptsRegisterVariable_u("X11_PALEGREEN2", MTR_CLR_X11_PALEGREEN2);
    MTR_ScriptsRegisterVariable_u("X11_PALEGREEN3", MTR_CLR_X11_PALEGREEN3);
    MTR_ScriptsRegisterVariable_u("X11_PALEGREEN4", MTR_CLR_X11_PALEGREEN4);
    MTR_ScriptsRegisterVariable_u("X11_SPRINGGREEN1", MTR_CLR_X11_SPRINGGREEN1);
    MTR_ScriptsRegisterVariable_u("X11_SPRINGGREEN2", MTR_CLR_X11_SPRINGGREEN2);
    MTR_ScriptsRegisterVariable_u("X11_SPRINGGREEN3", MTR_CLR_X11_SPRINGGREEN3);
    MTR_ScriptsRegisterVariable_u("X11_SPRINGGREEN4", MTR_CLR_X11_SPRINGGREEN4);
    MTR_ScriptsRegisterVariable_u("X11_GREEN1", MTR_CLR_X11_GREEN1);
    MTR_ScriptsRegisterVariable_u("X11_GREEN2", MTR_CLR_X11_GREEN2);
    MTR_ScriptsRegisterVariable_u("X11_GREEN3", MTR_CLR_X11_GREEN3);
    MTR_ScriptsRegisterVariable_u("X11_GREEN4", MTR_CLR_X11_GREEN4);
    MTR_ScriptsRegisterVariable_u("X11_CHARTREUSE1", MTR_CLR_X11_CHARTREUSE1);
    MTR_ScriptsRegisterVariable_u("X11_CHARTREUSE2", MTR_CLR_X11_CHARTREUSE2);
    MTR_ScriptsRegisterVariable_u("X11_CHARTREUSE3", MTR_CLR_X11_CHARTREUSE3);
    MTR_ScriptsRegisterVariable_u("X11_CHARTREUSE4", MTR_CLR_X11_CHARTREUSE4);
    MTR_ScriptsRegisterVariable_u("X11_OLIVEDRAB1", MTR_CLR_X11_OLIVEDRAB1);
    MTR_ScriptsRegisterVariable_u("X11_OLIVEDRAB2", MTR_CLR_X11_OLIVEDRAB2);
    MTR_ScriptsRegisterVariable_u("X11_OLIVEDRAB3", MTR_CLR_X11_OLIVEDRAB3);
    MTR_ScriptsRegisterVariable_u("X11_OLIVEDRAB4", MTR_CLR_X11_OLIVEDRAB4);
    MTR_ScriptsRegisterVariable_u("X11_DARKOLIVEGREEN1",
     MTR_CLR_X11_DARKOLIVEGREEN1);
    MTR_ScriptsRegisterVariable_u("X11_DARKOLIVEGREEN2",
     MTR_CLR_X11_DARKOLIVEGREEN2);
    MTR_ScriptsRegisterVariable_u("X11_DARKOLIVEGREEN3",
     MTR_CLR_X11_DARKOLIVEGREEN3);
    MTR_ScriptsRegisterVariable_u("X11_DARKOLIVEGREEN4",
     MTR_CLR_X11_DARKOLIVEGREEN4);
    MTR_ScriptsRegisterVariable_u("X11_KHAKI1", MTR_CLR_X11_KHAKI1);
    MTR_ScriptsRegisterVariable_u("X11_KHAKI2", MTR_CLR_X11_KHAKI2);
    MTR_ScriptsRegisterVariable_u("X11_KHAKI3", MTR_CLR_X11_KHAKI3);
    MTR_ScriptsRegisterVariable_u("X11_KHAKI4", MTR_CLR_X11_KHAKI4);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTGOLDENROD1",
     MTR_CLR_X11_LIGHTGOLDENROD1);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTGOLDENROD2",
     MTR_CLR_X11_LIGHTGOLDENROD2);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTGOLDENROD3",
     MTR_CLR_X11_LIGHTGOLDENROD3);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTGOLDENROD4",
     MTR_CLR_X11_LIGHTGOLDENROD4);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTYELLOW1", MTR_CLR_X11_LIGHTYELLOW1);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTYELLOW2", MTR_CLR_X11_LIGHTYELLOW2);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTYELLOW3", MTR_CLR_X11_LIGHTYELLOW3);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTYELLOW4", MTR_CLR_X11_LIGHTYELLOW4);
    MTR_ScriptsRegisterVariable_u("X11_YELLOW1", MTR_CLR_X11_YELLOW1);
    MTR_ScriptsRegisterVariable_u("X11_YELLOW2", MTR_CLR_X11_YELLOW2);
    MTR_ScriptsRegisterVariable_u("X11_YELLOW3", MTR_CLR_X11_YELLOW3);
    MTR_ScriptsRegisterVariable_u("X11_YELLOW4", MTR_CLR_X11_YELLOW4);
    MTR_ScriptsRegisterVariable_u("X11_GOLD1", MTR_CLR_X11_GOLD1);
    MTR_ScriptsRegisterVariable_u("X11_GOLD2", MTR_CLR_X11_GOLD2);
    MTR_ScriptsRegisterVariable_u("X11_GOLD3", MTR_CLR_X11_GOLD3);
    MTR_ScriptsRegisterVariable_u("X11_GOLD4", MTR_CLR_X11_GOLD4);
    MTR_ScriptsRegisterVariable_u("X11_GOLDENROD1", MTR_CLR_X11_GOLDENROD1);
    MTR_ScriptsRegisterVariable_u("X11_GOLDENROD2", MTR_CLR_X11_GOLDENROD2);
    MTR_ScriptsRegisterVariable_u("X11_GOLDENROD3", MTR_CLR_X11_GOLDENROD3);
    MTR_ScriptsRegisterVariable_u("X11_GOLDENROD4", MTR_CLR_X11_GOLDENROD4);
    MTR_ScriptsRegisterVariable_u("X11_DARKGOLDENROD1",
     MTR_CLR_X11_DARKGOLDENROD1);
    MTR_ScriptsRegisterVariable_u("X11_DARKGOLDENROD2",
     MTR_CLR_X11_DARKGOLDENROD2);
    MTR_ScriptsRegisterVariable_u("X11_DARKGOLDENROD3",
     MTR_CLR_X11_DARKGOLDENROD3);
    MTR_ScriptsRegisterVariable_u("X11_DARKGOLDENROD4",
     MTR_CLR_X11_DARKGOLDENROD4);
    MTR_ScriptsRegisterVariable_u("X11_ROSYBROWN1", MTR_CLR_X11_ROSYBROWN1);
    MTR_ScriptsRegisterVariable_u("X11_ROSYBROWN2", MTR_CLR_X11_ROSYBROWN2);
    MTR_ScriptsRegisterVariable_u("X11_ROSYBROWN3", MTR_CLR_X11_ROSYBROWN3);
    MTR_ScriptsRegisterVariable_u("X11_ROSYBROWN4", MTR_CLR_X11_ROSYBROWN4);
    MTR_ScriptsRegisterVariable_u("X11_INDIANRED1", MTR_CLR_X11_INDIANRED1);
    MTR_ScriptsRegisterVariable_u("X11_INDIANRED2", MTR_CLR_X11_INDIANRED2);
    MTR_ScriptsRegisterVariable_u("X11_INDIANRED3", MTR_CLR_X11_INDIANRED3);
    MTR_ScriptsRegisterVariable_u("X11_INDIANRED4", MTR_CLR_X11_INDIANRED4);
    MTR_ScriptsRegisterVariable_u("X11_SIENNA1", MTR_CLR_X11_SIENNA1);
    MTR_ScriptsRegisterVariable_u("X11_SIENNA2", MTR_CLR_X11_SIENNA2);
    MTR_ScriptsRegisterVariable_u("X11_SIENNA3", MTR_CLR_X11_SIENNA3);
    MTR_ScriptsRegisterVariable_u("X11_SIENNA4", MTR_CLR_X11_SIENNA4);
    MTR_ScriptsRegisterVariable_u("X11_BURLYWOOD1", MTR_CLR_X11_BURLYWOOD1);
    MTR_ScriptsRegisterVariable_u("X11_BURLYWOOD2", MTR_CLR_X11_BURLYWOOD2);
    MTR_ScriptsRegisterVariable_u("X11_BURLYWOOD3", MTR_CLR_X11_BURLYWOOD3);
    MTR_ScriptsRegisterVariable_u("X11_BURLYWOOD4", MTR_CLR_X11_BURLYWOOD4);
    MTR_ScriptsRegisterVariable_u("X11_WHEAT1", MTR_CLR_X11_WHEAT1);
    MTR_ScriptsRegisterVariable_u("X11_WHEAT2", MTR_CLR_X11_WHEAT2);
    MTR_ScriptsRegisterVariable_u("X11_WHEAT3", MTR_CLR_X11_WHEAT3);
    MTR_ScriptsRegisterVariable_u("X11_WHEAT4", MTR_CLR_X11_WHEAT4);
    MTR_ScriptsRegisterVariable_u("X11_TAN1", MTR_CLR_X11_TAN1);
    MTR_ScriptsRegisterVariable_u("X11_TAN2", MTR_CLR_X11_TAN2);
    MTR_ScriptsRegisterVariable_u("X11_TAN3", MTR_CLR_X11_TAN3);
    MTR_ScriptsRegisterVariable_u("X11_TAN4", MTR_CLR_X11_TAN4);
    MTR_ScriptsRegisterVariable_u("X11_CHOCOLATE1", MTR_CLR_X11_CHOCOLATE1);
    MTR_ScriptsRegisterVariable_u("X11_CHOCOLATE2", MTR_CLR_X11_CHOCOLATE2);
    MTR_ScriptsRegisterVariable_u("X11_CHOCOLATE3", MTR_CLR_X11_CHOCOLATE3);
    MTR_ScriptsRegisterVariable_u("X11_CHOCOLATE4", MTR_CLR_X11_CHOCOLATE4);
    MTR_ScriptsRegisterVariable_u("X11_FIREBRICK1", MTR_CLR_X11_FIREBRICK1);
    MTR_ScriptsRegisterVariable_u("X11_FIREBRICK2", MTR_CLR_X11_FIREBRICK2);
    MTR_ScriptsRegisterVariable_u("X11_FIREBRICK3", MTR_CLR_X11_FIREBRICK3);
    MTR_ScriptsRegisterVariable_u("X11_FIREBRICK4", MTR_CLR_X11_FIREBRICK4);
    MTR_ScriptsRegisterVariable_u("X11_BROWN1", MTR_CLR_X11_BROWN1);
    MTR_ScriptsRegisterVariable_u("X11_BROWN2", MTR_CLR_X11_BROWN2);
    MTR_ScriptsRegisterVariable_u("X11_BROWN3", MTR_CLR_X11_BROWN3);
    MTR_ScriptsRegisterVariable_u("X11_BROWN4", MTR_CLR_X11_BROWN4);
    MTR_ScriptsRegisterVariable_u("X11_SALMON1", MTR_CLR_X11_SALMON1);
    MTR_ScriptsRegisterVariable_u("X11_SALMON2", MTR_CLR_X11_SALMON2);
    MTR_ScriptsRegisterVariable_u("X11_SALMON3", MTR_CLR_X11_SALMON3);
    MTR_ScriptsRegisterVariable_u("X11_SALMON4", MTR_CLR_X11_SALMON4);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTSALMON1", MTR_CLR_X11_LIGHTSALMON1);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTSALMON2", MTR_CLR_X11_LIGHTSALMON2);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTSALMON3", MTR_CLR_X11_LIGHTSALMON3);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTSALMON4", MTR_CLR_X11_LIGHTSALMON4);
    MTR_ScriptsRegisterVariable_u("X11_ORANGE1", MTR_CLR_X11_ORANGE1);
    MTR_ScriptsRegisterVariable_u("X11_ORANGE2", MTR_CLR_X11_ORANGE2);
    MTR_ScriptsRegisterVariable_u("X11_ORANGE3", MTR_CLR_X11_ORANGE3);
    MTR_ScriptsRegisterVariable_u("X11_ORANGE4", MTR_CLR_X11_ORANGE4);
    MTR_ScriptsRegisterVariable_u("X11_DARKORANGE1", MTR_CLR_X11_DARKORANGE1);
    MTR_ScriptsRegisterVariable_u("X11_DARKORANGE2", MTR_CLR_X11_DARKORANGE2);
    MTR_ScriptsRegisterVariable_u("X11_DARKORANGE3", MTR_CLR_X11_DARKORANGE3);
    MTR_ScriptsRegisterVariable_u("X11_DARKORANGE4", MTR_CLR_X11_DARKORANGE4);
    MTR_ScriptsRegisterVariable_u("X11_CORAL1", MTR_CLR_X11_CORAL1);
    MTR_ScriptsRegisterVariable_u("X11_CORAL2", MTR_CLR_X11_CORAL2);
    MTR_ScriptsRegisterVariable_u("X11_CORAL3", MTR_CLR_X11_CORAL3);
    MTR_ScriptsRegisterVariable_u("X11_CORAL4", MTR_CLR_X11_CORAL4);
    MTR_ScriptsRegisterVariable_u("X11_TOMATO1", MTR_CLR_X11_TOMATO1);
    MTR_ScriptsRegisterVariable_u("X11_TOMATO2", MTR_CLR_X11_TOMATO2);
    MTR_ScriptsRegisterVariable_u("X11_TOMATO3", MTR_CLR_X11_TOMATO3);
    MTR_ScriptsRegisterVariable_u("X11_TOMATO4", MTR_CLR_X11_TOMATO4);
    MTR_ScriptsRegisterVariable_u("X11_ORANGERED1", MTR_CLR_X11_ORANGERED1);
    MTR_ScriptsRegisterVariable_u("X11_ORANGERED2", MTR_CLR_X11_ORANGERED2);
    MTR_ScriptsRegisterVariable_u("X11_ORANGERED3", MTR_CLR_X11_ORANGERED3);
    MTR_ScriptsRegisterVariable_u("X11_ORANGERED4", MTR_CLR_X11_ORANGERED4);
    MTR_ScriptsRegisterVariable_u("X11_RED1", MTR_CLR_X11_RED1);
    MTR_ScriptsRegisterVariable_u("X11_RED2", MTR_CLR_X11_RED2);
    MTR_ScriptsRegisterVariable_u("X11_RED3", MTR_CLR_X11_RED3);
    MTR_ScriptsRegisterVariable_u("X11_RED4", MTR_CLR_X11_RED4);
    MTR_ScriptsRegisterVariable_u("X11_DEEPPINK1", MTR_CLR_X11_DEEPPINK1);
    MTR_ScriptsRegisterVariable_u("X11_DEEPPINK2", MTR_CLR_X11_DEEPPINK2);
    MTR_ScriptsRegisterVariable_u("X11_DEEPPINK3", MTR_CLR_X11_DEEPPINK3);
    MTR_ScriptsRegisterVariable_u("X11_DEEPPINK4", MTR_CLR_X11_DEEPPINK4);
    MTR_ScriptsRegisterVariable_u("X11_HOTPINK1", MTR_CLR_X11_HOTPINK1);
    MTR_ScriptsRegisterVariable_u("X11_HOTPINK2", MTR_CLR_X11_HOTPINK2);
    MTR_ScriptsRegisterVariable_u("X11_HOTPINK3", MTR_CLR_X11_HOTPINK3);
    MTR_ScriptsRegisterVariable_u("X11_HOTPINK4", MTR_CLR_X11_HOTPINK4);
    MTR_ScriptsRegisterVariable_u("X11_PINK1", MTR_CLR_X11_PINK1);
    MTR_ScriptsRegisterVariable_u("X11_PINK2", MTR_CLR_X11_PINK2);
    MTR_ScriptsRegisterVariable_u("X11_PINK3", MTR_CLR_X11_PINK3);
    MTR_ScriptsRegisterVariable_u("X11_PINK4", MTR_CLR_X11_PINK4);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTPINK1", MTR_CLR_X11_LIGHTPINK1);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTPINK2", MTR_CLR_X11_LIGHTPINK2);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTPINK3", MTR_CLR_X11_LIGHTPINK3);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTPINK4", MTR_CLR_X11_LIGHTPINK4);
    MTR_ScriptsRegisterVariable_u("X11_PALEVIOLETRED1",
     MTR_CLR_X11_PALEVIOLETRED1);
    MTR_ScriptsRegisterVariable_u("X11_PALEVIOLETRED2",
     MTR_CLR_X11_PALEVIOLETRED2);
    MTR_ScriptsRegisterVariable_u("X11_PALEVIOLETRED3",
     MTR_CLR_X11_PALEVIOLETRED3);
    MTR_ScriptsRegisterVariable_u("X11_PALEVIOLETRED4",
     MTR_CLR_X11_PALEVIOLETRED4);
    MTR_ScriptsRegisterVariable_u("X11_MAROON1", MTR_CLR_X11_MAROON1);
    MTR_ScriptsRegisterVariable_u("X11_MAROON2", MTR_CLR_X11_MAROON2);
    MTR_ScriptsRegisterVariable_u("X11_MAROON3", MTR_CLR_X11_MAROON3);
    MTR_ScriptsRegisterVariable_u("X11_MAROON4", MTR_CLR_X11_MAROON4);
    MTR_ScriptsRegisterVariable_u("X11_VIOLETRED1", MTR_CLR_X11_VIOLETRED1);
    MTR_ScriptsRegisterVariable_u("X11_VIOLETRED2", MTR_CLR_X11_VIOLETRED2);
    MTR_ScriptsRegisterVariable_u("X11_VIOLETRED3", MTR_CLR_X11_VIOLETRED3);
    MTR_ScriptsRegisterVariable_u("X11_VIOLETRED4", MTR_CLR_X11_VIOLETRED4);
    MTR_ScriptsRegisterVariable_u("X11_MAGENTA1", MTR_CLR_X11_MAGENTA1);
    MTR_ScriptsRegisterVariable_u("X11_MAGENTA2", MTR_CLR_X11_MAGENTA2);
    MTR_ScriptsRegisterVariable_u("X11_MAGENTA3", MTR_CLR_X11_MAGENTA3);
    MTR_ScriptsRegisterVariable_u("X11_MAGENTA4", MTR_CLR_X11_MAGENTA4);
    MTR_ScriptsRegisterVariable_u("X11_ORCHID1", MTR_CLR_X11_ORCHID1);
    MTR_ScriptsRegisterVariable_u("X11_ORCHID2", MTR_CLR_X11_ORCHID2);
    MTR_ScriptsRegisterVariable_u("X11_ORCHID3", MTR_CLR_X11_ORCHID3);
    MTR_ScriptsRegisterVariable_u("X11_ORCHID4", MTR_CLR_X11_ORCHID4);
    MTR_ScriptsRegisterVariable_u("X11_PLUM1", MTR_CLR_X11_PLUM1);
    MTR_ScriptsRegisterVariable_u("X11_PLUM2", MTR_CLR_X11_PLUM2);
    MTR_ScriptsRegisterVariable_u("X11_PLUM3", MTR_CLR_X11_PLUM3);
    MTR_ScriptsRegisterVariable_u("X11_PLUM4", MTR_CLR_X11_PLUM4);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUMORCHID1",
     MTR_CLR_X11_MEDIUMORCHID1);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUMORCHID2",
     MTR_CLR_X11_MEDIUMORCHID2);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUMORCHID3",
     MTR_CLR_X11_MEDIUMORCHID3);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUMORCHID4",
     MTR_CLR_X11_MEDIUMORCHID4);
    MTR_ScriptsRegisterVariable_u("X11_DARKORCHID1", MTR_CLR_X11_DARKORCHID1);
    MTR_ScriptsRegisterVariable_u("X11_DARKORCHID2", MTR_CLR_X11_DARKORCHID2);
    MTR_ScriptsRegisterVariable_u("X11_DARKORCHID3", MTR_CLR_X11_DARKORCHID3);
    MTR_ScriptsRegisterVariable_u("X11_DARKORCHID4", MTR_CLR_X11_DARKORCHID4);
    MTR_ScriptsRegisterVariable_u("X11_PURPLE1", MTR_CLR_X11_PURPLE1);
    MTR_ScriptsRegisterVariable_u("X11_PURPLE2", MTR_CLR_X11_PURPLE2);
    MTR_ScriptsRegisterVariable_u("X11_PURPLE3", MTR_CLR_X11_PURPLE3);
    MTR_ScriptsRegisterVariable_u("X11_PURPLE4", MTR_CLR_X11_PURPLE4);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUMPURPLE1",
     MTR_CLR_X11_MEDIUMPURPLE1);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUMPURPLE2",
     MTR_CLR_X11_MEDIUMPURPLE2);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUMPURPLE3",
     MTR_CLR_X11_MEDIUMPURPLE3);
    MTR_ScriptsRegisterVariable_u("X11_MEDIUMPURPLE4",
     MTR_CLR_X11_MEDIUMPURPLE4);
    MTR_ScriptsRegisterVariable_u("X11_THISTLE1", MTR_CLR_X11_THISTLE1);
    MTR_ScriptsRegisterVariable_u("X11_THISTLE2", MTR_CLR_X11_THISTLE2);
    MTR_ScriptsRegisterVariable_u("X11_THISTLE3", MTR_CLR_X11_THISTLE3);
    MTR_ScriptsRegisterVariable_u("X11_THISTLE4", MTR_CLR_X11_THISTLE4);
    MTR_ScriptsRegisterVariable_u("X11_GRAY0", MTR_CLR_X11_GRAY0);
    MTR_ScriptsRegisterVariable_u("X11_GREY0", MTR_CLR_X11_GREY0);
    MTR_ScriptsRegisterVariable_u("X11_GRAY1", MTR_CLR_X11_GRAY1);
    MTR_ScriptsRegisterVariable_u("X11_GREY1", MTR_CLR_X11_GREY1);
    MTR_ScriptsRegisterVariable_u("X11_GRAY2", MTR_CLR_X11_GRAY2);
    MTR_ScriptsRegisterVariable_u("X11_GREY2", MTR_CLR_X11_GREY2);
    MTR_ScriptsRegisterVariable_u("X11_GRAY3", MTR_CLR_X11_GRAY3);
    MTR_ScriptsRegisterVariable_u("X11_GREY3", MTR_CLR_X11_GREY3);
    MTR_ScriptsRegisterVariable_u("X11_GRAY4", MTR_CLR_X11_GRAY4);
    MTR_ScriptsRegisterVariable_u("X11_GREY4", MTR_CLR_X11_GREY4);
    MTR_ScriptsRegisterVariable_u("X11_GRAY5", MTR_CLR_X11_GRAY5);
    MTR_ScriptsRegisterVariable_u("X11_GREY5", MTR_CLR_X11_GREY5);
    MTR_ScriptsRegisterVariable_u("X11_GRAY6", MTR_CLR_X11_GRAY6);
    MTR_ScriptsRegisterVariable_u("X11_GREY6", MTR_CLR_X11_GREY6);
    MTR_ScriptsRegisterVariable_u("X11_GRAY7", MTR_CLR_X11_GRAY7);
    MTR_ScriptsRegisterVariable_u("X11_GREY7", MTR_CLR_X11_GREY7);
    MTR_ScriptsRegisterVariable_u("X11_GRAY8", MTR_CLR_X11_GRAY8);
    MTR_ScriptsRegisterVariable_u("X11_GREY8", MTR_CLR_X11_GREY8);
    MTR_ScriptsRegisterVariable_u("X11_GRAY9", MTR_CLR_X11_GRAY9);
    MTR_ScriptsRegisterVariable_u("X11_GREY9", MTR_CLR_X11_GREY9);
    MTR_ScriptsRegisterVariable_u("X11_GRAY10", MTR_CLR_X11_GRAY10);
    MTR_ScriptsRegisterVariable_u("X11_GREY10", MTR_CLR_X11_GREY10);
    MTR_ScriptsRegisterVariable_u("X11_GRAY11", MTR_CLR_X11_GRAY11);
    MTR_ScriptsRegisterVariable_u("X11_GREY11", MTR_CLR_X11_GREY11);
    MTR_ScriptsRegisterVariable_u("X11_GRAY12", MTR_CLR_X11_GRAY12);
    MTR_ScriptsRegisterVariable_u("X11_GREY12", MTR_CLR_X11_GREY12);
    MTR_ScriptsRegisterVariable_u("X11_GRAY13", MTR_CLR_X11_GRAY13);
    MTR_ScriptsRegisterVariable_u("X11_GREY13", MTR_CLR_X11_GREY13);
    MTR_ScriptsRegisterVariable_u("X11_GRAY14", MTR_CLR_X11_GRAY14);
    MTR_ScriptsRegisterVariable_u("X11_GREY14", MTR_CLR_X11_GREY14);
    MTR_ScriptsRegisterVariable_u("X11_GRAY15", MTR_CLR_X11_GRAY15);
    MTR_ScriptsRegisterVariable_u("X11_GREY15", MTR_CLR_X11_GREY15);
    MTR_ScriptsRegisterVariable_u("X11_GRAY16", MTR_CLR_X11_GRAY16);
    MTR_ScriptsRegisterVariable_u("X11_GREY16", MTR_CLR_X11_GREY16);
    MTR_ScriptsRegisterVariable_u("X11_GRAY17", MTR_CLR_X11_GRAY17);
    MTR_ScriptsRegisterVariable_u("X11_GREY17", MTR_CLR_X11_GREY17);
    MTR_ScriptsRegisterVariable_u("X11_GRAY18", MTR_CLR_X11_GRAY18);
    MTR_ScriptsRegisterVariable_u("X11_GREY18", MTR_CLR_X11_GREY18);
    MTR_ScriptsRegisterVariable_u("X11_GRAY19", MTR_CLR_X11_GRAY19);
    MTR_ScriptsRegisterVariable_u("X11_GREY19", MTR_CLR_X11_GREY19);
    MTR_ScriptsRegisterVariable_u("X11_GRAY20", MTR_CLR_X11_GRAY20);
    MTR_ScriptsRegisterVariable_u("X11_GREY20", MTR_CLR_X11_GREY20);
    MTR_ScriptsRegisterVariable_u("X11_GRAY21", MTR_CLR_X11_GRAY21);
    MTR_ScriptsRegisterVariable_u("X11_GREY21", MTR_CLR_X11_GREY21);
    MTR_ScriptsRegisterVariable_u("X11_GRAY22", MTR_CLR_X11_GRAY22);
    MTR_ScriptsRegisterVariable_u("X11_GREY22", MTR_CLR_X11_GREY22);
    MTR_ScriptsRegisterVariable_u("X11_GRAY23", MTR_CLR_X11_GRAY23);
    MTR_ScriptsRegisterVariable_u("X11_GREY23", MTR_CLR_X11_GREY23);
    MTR_ScriptsRegisterVariable_u("X11_GRAY24", MTR_CLR_X11_GRAY24);
    MTR_ScriptsRegisterVariable_u("X11_GREY24", MTR_CLR_X11_GREY24);
    MTR_ScriptsRegisterVariable_u("X11_GRAY25", MTR_CLR_X11_GRAY25);
    MTR_ScriptsRegisterVariable_u("X11_GREY25", MTR_CLR_X11_GREY25);
    MTR_ScriptsRegisterVariable_u("X11_GRAY26", MTR_CLR_X11_GRAY26);
    MTR_ScriptsRegisterVariable_u("X11_GREY26", MTR_CLR_X11_GREY26);
    MTR_ScriptsRegisterVariable_u("X11_GRAY27", MTR_CLR_X11_GRAY27);
    MTR_ScriptsRegisterVariable_u("X11_GREY27", MTR_CLR_X11_GREY27);
    MTR_ScriptsRegisterVariable_u("X11_GRAY28", MTR_CLR_X11_GRAY28);
    MTR_ScriptsRegisterVariable_u("X11_GREY28", MTR_CLR_X11_GREY28);
    MTR_ScriptsRegisterVariable_u("X11_GRAY29", MTR_CLR_X11_GRAY29);
    MTR_ScriptsRegisterVariable_u("X11_GREY29", MTR_CLR_X11_GREY29);
    MTR_ScriptsRegisterVariable_u("X11_GRAY30", MTR_CLR_X11_GRAY30);
    MTR_ScriptsRegisterVariable_u("X11_GREY30", MTR_CLR_X11_GREY30);
    MTR_ScriptsRegisterVariable_u("X11_GRAY31", MTR_CLR_X11_GRAY31);
    MTR_ScriptsRegisterVariable_u("X11_GREY31", MTR_CLR_X11_GREY31);
    MTR_ScriptsRegisterVariable_u("X11_GRAY32", MTR_CLR_X11_GRAY32);
    MTR_ScriptsRegisterVariable_u("X11_GREY32", MTR_CLR_X11_GREY32);
    MTR_ScriptsRegisterVariable_u("X11_GRAY33", MTR_CLR_X11_GRAY33);
    MTR_ScriptsRegisterVariable_u("X11_GREY33", MTR_CLR_X11_GREY33);
    MTR_ScriptsRegisterVariable_u("X11_GRAY34", MTR_CLR_X11_GRAY34);
    MTR_ScriptsRegisterVariable_u("X11_GREY34", MTR_CLR_X11_GREY34);
    MTR_ScriptsRegisterVariable_u("X11_GRAY35", MTR_CLR_X11_GRAY35);
    MTR_ScriptsRegisterVariable_u("X11_GREY35", MTR_CLR_X11_GREY35);
    MTR_ScriptsRegisterVariable_u("X11_GRAY36", MTR_CLR_X11_GRAY36);
    MTR_ScriptsRegisterVariable_u("X11_GREY36", MTR_CLR_X11_GREY36);
    MTR_ScriptsRegisterVariable_u("X11_GRAY37", MTR_CLR_X11_GRAY37);
    MTR_ScriptsRegisterVariable_u("X11_GREY37", MTR_CLR_X11_GREY37);
    MTR_ScriptsRegisterVariable_u("X11_GRAY38", MTR_CLR_X11_GRAY38);
    MTR_ScriptsRegisterVariable_u("X11_GREY38", MTR_CLR_X11_GREY38);
    MTR_ScriptsRegisterVariable_u("X11_GRAY39", MTR_CLR_X11_GRAY39);
    MTR_ScriptsRegisterVariable_u("X11_GREY39", MTR_CLR_X11_GREY39);
    MTR_ScriptsRegisterVariable_u("X11_GRAY40", MTR_CLR_X11_GRAY40);
    MTR_ScriptsRegisterVariable_u("X11_GREY40", MTR_CLR_X11_GREY40);
    MTR_ScriptsRegisterVariable_u("X11_GRAY41", MTR_CLR_X11_GRAY41);
    MTR_ScriptsRegisterVariable_u("X11_GREY41", MTR_CLR_X11_GREY41);
    MTR_ScriptsRegisterVariable_u("X11_GRAY42", MTR_CLR_X11_GRAY42);
    MTR_ScriptsRegisterVariable_u("X11_GREY42", MTR_CLR_X11_GREY42);
    MTR_ScriptsRegisterVariable_u("X11_GRAY43", MTR_CLR_X11_GRAY43);
    MTR_ScriptsRegisterVariable_u("X11_GREY43", MTR_CLR_X11_GREY43);
    MTR_ScriptsRegisterVariable_u("X11_GRAY44", MTR_CLR_X11_GRAY44);
    MTR_ScriptsRegisterVariable_u("X11_GREY44", MTR_CLR_X11_GREY44);
    MTR_ScriptsRegisterVariable_u("X11_GRAY45", MTR_CLR_X11_GRAY45);
    MTR_ScriptsRegisterVariable_u("X11_GREY45", MTR_CLR_X11_GREY45);
    MTR_ScriptsRegisterVariable_u("X11_GRAY46", MTR_CLR_X11_GRAY46);
    MTR_ScriptsRegisterVariable_u("X11_GREY46", MTR_CLR_X11_GREY46);
    MTR_ScriptsRegisterVariable_u("X11_GRAY47", MTR_CLR_X11_GRAY47);
    MTR_ScriptsRegisterVariable_u("X11_GREY47", MTR_CLR_X11_GREY47);
    MTR_ScriptsRegisterVariable_u("X11_GRAY48", MTR_CLR_X11_GRAY48);
    MTR_ScriptsRegisterVariable_u("X11_GREY48", MTR_CLR_X11_GREY48);
    MTR_ScriptsRegisterVariable_u("X11_GRAY49", MTR_CLR_X11_GRAY49);
    MTR_ScriptsRegisterVariable_u("X11_GREY49", MTR_CLR_X11_GREY49);
    MTR_ScriptsRegisterVariable_u("X11_GRAY50", MTR_CLR_X11_GRAY50);
    MTR_ScriptsRegisterVariable_u("X11_GREY50", MTR_CLR_X11_GREY50);
    MTR_ScriptsRegisterVariable_u("X11_GRAY51", MTR_CLR_X11_GRAY51);
    MTR_ScriptsRegisterVariable_u("X11_GREY51", MTR_CLR_X11_GREY51);
    MTR_ScriptsRegisterVariable_u("X11_GRAY52", MTR_CLR_X11_GRAY52);
    MTR_ScriptsRegisterVariable_u("X11_GREY52", MTR_CLR_X11_GREY52);
    MTR_ScriptsRegisterVariable_u("X11_GRAY53", MTR_CLR_X11_GRAY53);
    MTR_ScriptsRegisterVariable_u("X11_GREY53", MTR_CLR_X11_GREY53);
    MTR_ScriptsRegisterVariable_u("X11_GRAY54", MTR_CLR_X11_GRAY54);
    MTR_ScriptsRegisterVariable_u("X11_GREY54", MTR_CLR_X11_GREY54);
    MTR_ScriptsRegisterVariable_u("X11_GRAY55", MTR_CLR_X11_GRAY55);
    MTR_ScriptsRegisterVariable_u("X11_GREY55", MTR_CLR_X11_GREY55);
    MTR_ScriptsRegisterVariable_u("X11_GRAY56", MTR_CLR_X11_GRAY56);
    MTR_ScriptsRegisterVariable_u("X11_GREY56", MTR_CLR_X11_GREY56);
    MTR_ScriptsRegisterVariable_u("X11_GRAY57", MTR_CLR_X11_GRAY57);
    MTR_ScriptsRegisterVariable_u("X11_GREY57", MTR_CLR_X11_GREY57);
    MTR_ScriptsRegisterVariable_u("X11_GRAY58", MTR_CLR_X11_GRAY58);
    MTR_ScriptsRegisterVariable_u("X11_GREY58", MTR_CLR_X11_GREY58);
    MTR_ScriptsRegisterVariable_u("X11_GRAY59", MTR_CLR_X11_GRAY59);
    MTR_ScriptsRegisterVariable_u("X11_GREY59", MTR_CLR_X11_GREY59);
    MTR_ScriptsRegisterVariable_u("X11_GRAY60", MTR_CLR_X11_GRAY60);
    MTR_ScriptsRegisterVariable_u("X11_GREY60", MTR_CLR_X11_GREY60);
    MTR_ScriptsRegisterVariable_u("X11_GRAY61", MTR_CLR_X11_GRAY61);
    MTR_ScriptsRegisterVariable_u("X11_GREY61", MTR_CLR_X11_GREY61);
    MTR_ScriptsRegisterVariable_u("X11_GRAY62", MTR_CLR_X11_GRAY62);
    MTR_ScriptsRegisterVariable_u("X11_GREY62", MTR_CLR_X11_GREY62);
    MTR_ScriptsRegisterVariable_u("X11_GRAY63", MTR_CLR_X11_GRAY63);
    MTR_ScriptsRegisterVariable_u("X11_GREY63", MTR_CLR_X11_GREY63);
    MTR_ScriptsRegisterVariable_u("X11_GRAY64", MTR_CLR_X11_GRAY64);
    MTR_ScriptsRegisterVariable_u("X11_GREY64", MTR_CLR_X11_GREY64);
    MTR_ScriptsRegisterVariable_u("X11_GRAY65", MTR_CLR_X11_GRAY65);
    MTR_ScriptsRegisterVariable_u("X11_GREY65", MTR_CLR_X11_GREY65);
    MTR_ScriptsRegisterVariable_u("X11_GRAY66", MTR_CLR_X11_GRAY66);
    MTR_ScriptsRegisterVariable_u("X11_GREY66", MTR_CLR_X11_GREY66);
    MTR_ScriptsRegisterVariable_u("X11_GRAY67", MTR_CLR_X11_GRAY67);
    MTR_ScriptsRegisterVariable_u("X11_GREY67", MTR_CLR_X11_GREY67);
    MTR_ScriptsRegisterVariable_u("X11_GRAY68", MTR_CLR_X11_GRAY68);
    MTR_ScriptsRegisterVariable_u("X11_GREY68", MTR_CLR_X11_GREY68);
    MTR_ScriptsRegisterVariable_u("X11_GRAY69", MTR_CLR_X11_GRAY69);
    MTR_ScriptsRegisterVariable_u("X11_GREY69", MTR_CLR_X11_GREY69);
    MTR_ScriptsRegisterVariable_u("X11_GRAY70", MTR_CLR_X11_GRAY70);
    MTR_ScriptsRegisterVariable_u("X11_GREY70", MTR_CLR_X11_GREY70);
    MTR_ScriptsRegisterVariable_u("X11_GRAY71", MTR_CLR_X11_GRAY71);
    MTR_ScriptsRegisterVariable_u("X11_GREY71", MTR_CLR_X11_GREY71);
    MTR_ScriptsRegisterVariable_u("X11_GRAY72", MTR_CLR_X11_GRAY72);
    MTR_ScriptsRegisterVariable_u("X11_GREY72", MTR_CLR_X11_GREY72);
    MTR_ScriptsRegisterVariable_u("X11_GRAY73", MTR_CLR_X11_GRAY73);
    MTR_ScriptsRegisterVariable_u("X11_GREY73", MTR_CLR_X11_GREY73);
    MTR_ScriptsRegisterVariable_u("X11_GRAY74", MTR_CLR_X11_GRAY74);
    MTR_ScriptsRegisterVariable_u("X11_GREY74", MTR_CLR_X11_GREY74);
    MTR_ScriptsRegisterVariable_u("X11_GRAY75", MTR_CLR_X11_GRAY75);
    MTR_ScriptsRegisterVariable_u("X11_GREY75", MTR_CLR_X11_GREY75);
    MTR_ScriptsRegisterVariable_u("X11_GRAY76", MTR_CLR_X11_GRAY76);
    MTR_ScriptsRegisterVariable_u("X11_GREY76", MTR_CLR_X11_GREY76);
    MTR_ScriptsRegisterVariable_u("X11_GRAY77", MTR_CLR_X11_GRAY77);
    MTR_ScriptsRegisterVariable_u("X11_GREY77", MTR_CLR_X11_GREY77);
    MTR_ScriptsRegisterVariable_u("X11_GRAY78", MTR_CLR_X11_GRAY78);
    MTR_ScriptsRegisterVariable_u("X11_GREY78", MTR_CLR_X11_GREY78);
    MTR_ScriptsRegisterVariable_u("X11_GRAY79", MTR_CLR_X11_GRAY79);
    MTR_ScriptsRegisterVariable_u("X11_GREY79", MTR_CLR_X11_GREY79);
    MTR_ScriptsRegisterVariable_u("X11_GRAY80", MTR_CLR_X11_GRAY80);
    MTR_ScriptsRegisterVariable_u("X11_GREY80", MTR_CLR_X11_GREY80);
    MTR_ScriptsRegisterVariable_u("X11_GRAY81", MTR_CLR_X11_GRAY81);
    MTR_ScriptsRegisterVariable_u("X11_GREY81", MTR_CLR_X11_GREY81);
    MTR_ScriptsRegisterVariable_u("X11_GRAY82", MTR_CLR_X11_GRAY82);
    MTR_ScriptsRegisterVariable_u("X11_GREY82", MTR_CLR_X11_GREY82);
    MTR_ScriptsRegisterVariable_u("X11_GRAY83", MTR_CLR_X11_GRAY83);
    MTR_ScriptsRegisterVariable_u("X11_GREY83", MTR_CLR_X11_GREY83);
    MTR_ScriptsRegisterVariable_u("X11_GRAY84", MTR_CLR_X11_GRAY84);
    MTR_ScriptsRegisterVariable_u("X11_GREY84", MTR_CLR_X11_GREY84);
    MTR_ScriptsRegisterVariable_u("X11_GRAY85", MTR_CLR_X11_GRAY85);
    MTR_ScriptsRegisterVariable_u("X11_GREY85", MTR_CLR_X11_GREY85);
    MTR_ScriptsRegisterVariable_u("X11_GRAY86", MTR_CLR_X11_GRAY86);
    MTR_ScriptsRegisterVariable_u("X11_GREY86", MTR_CLR_X11_GREY86);
    MTR_ScriptsRegisterVariable_u("X11_GRAY87", MTR_CLR_X11_GRAY87);
    MTR_ScriptsRegisterVariable_u("X11_GREY87", MTR_CLR_X11_GREY87);
    MTR_ScriptsRegisterVariable_u("X11_GRAY88", MTR_CLR_X11_GRAY88);
    MTR_ScriptsRegisterVariable_u("X11_GREY88", MTR_CLR_X11_GREY88);
    MTR_ScriptsRegisterVariable_u("X11_GRAY89", MTR_CLR_X11_GRAY89);
    MTR_ScriptsRegisterVariable_u("X11_GREY89", MTR_CLR_X11_GREY89);
    MTR_ScriptsRegisterVariable_u("X11_GRAY90", MTR_CLR_X11_GRAY90);
    MTR_ScriptsRegisterVariable_u("X11_GREY90", MTR_CLR_X11_GREY90);
    MTR_ScriptsRegisterVariable_u("X11_GRAY91", MTR_CLR_X11_GRAY91);
    MTR_ScriptsRegisterVariable_u("X11_GREY91", MTR_CLR_X11_GREY91);
    MTR_ScriptsRegisterVariable_u("X11_GRAY92", MTR_CLR_X11_GRAY92);
    MTR_ScriptsRegisterVariable_u("X11_GREY92", MTR_CLR_X11_GREY92);
    MTR_ScriptsRegisterVariable_u("X11_GRAY93", MTR_CLR_X11_GRAY93);
    MTR_ScriptsRegisterVariable_u("X11_GREY93", MTR_CLR_X11_GREY93);
    MTR_ScriptsRegisterVariable_u("X11_GRAY94", MTR_CLR_X11_GRAY94);
    MTR_ScriptsRegisterVariable_u("X11_GREY94", MTR_CLR_X11_GREY94);
    MTR_ScriptsRegisterVariable_u("X11_GRAY95", MTR_CLR_X11_GRAY95);
    MTR_ScriptsRegisterVariable_u("X11_GREY95", MTR_CLR_X11_GREY95);
    MTR_ScriptsRegisterVariable_u("X11_GRAY96", MTR_CLR_X11_GRAY96);
    MTR_ScriptsRegisterVariable_u("X11_GREY96", MTR_CLR_X11_GREY96);
    MTR_ScriptsRegisterVariable_u("X11_GRAY97", MTR_CLR_X11_GRAY97);
    MTR_ScriptsRegisterVariable_u("X11_GREY97", MTR_CLR_X11_GREY97);
    MTR_ScriptsRegisterVariable_u("X11_GRAY98", MTR_CLR_X11_GRAY98);
    MTR_ScriptsRegisterVariable_u("X11_GREY98", MTR_CLR_X11_GREY98);
    MTR_ScriptsRegisterVariable_u("X11_GRAY99", MTR_CLR_X11_GRAY99);
    MTR_ScriptsRegisterVariable_u("X11_GREY99", MTR_CLR_X11_GREY99);
    MTR_ScriptsRegisterVariable_u("X11_GRAY100", MTR_CLR_X11_GRAY100);
    MTR_ScriptsRegisterVariable_u("X11_GREY100", MTR_CLR_X11_GREY100);
    MTR_ScriptsRegisterVariable_u("X11_DARK_GREY", MTR_CLR_X11_DARK_GREY);
    MTR_ScriptsRegisterVariable_u("X11_DARKGREY", MTR_CLR_X11_DARKGREY);
    MTR_ScriptsRegisterVariable_u("X11_DARK_GRAY", MTR_CLR_X11_DARK_GRAY);
    MTR_ScriptsRegisterVariable_u("X11_DARKGRAY", MTR_CLR_X11_DARKGRAY);
    MTR_ScriptsRegisterVariable_u("X11_DARK_BLUE", MTR_CLR_X11_DARK_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_DARKBLUE", MTR_CLR_X11_DARKBLUE);
    MTR_ScriptsRegisterVariable_u("X11_DARK_CYAN", MTR_CLR_X11_DARK_CYAN);
    MTR_ScriptsRegisterVariable_u("X11_DARKCYAN", MTR_CLR_X11_DARKCYAN);
    MTR_ScriptsRegisterVariable_u("X11_DARK_MAGENTA", MTR_CLR_X11_DARK_MAGENTA);
    MTR_ScriptsRegisterVariable_u("X11_DARKMAGENTA", MTR_CLR_X11_DARKMAGENTA);
    MTR_ScriptsRegisterVariable_u("X11_DARK_RED", MTR_CLR_X11_DARK_RED);
    MTR_ScriptsRegisterVariable_u("X11_DARKRED", MTR_CLR_X11_DARKRED);
    MTR_ScriptsRegisterVariable_u("X11_LIGHT_GREEN", MTR_CLR_X11_LIGHT_GREEN);
    MTR_ScriptsRegisterVariable_u("X11_LIGHTGREEN", MTR_CLR_X11_LIGHTGREEN);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_0", MTR_CLR_X11_SGI_GRAY_0);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY0", MTR_CLR_X11_SGIGRAY0);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_0", MTR_CLR_X11_SGI_GREY_0);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY0", MTR_CLR_X11_SGIGREY0);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_4", MTR_CLR_X11_SGI_GRAY_4);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY4", MTR_CLR_X11_SGIGRAY4);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_4", MTR_CLR_X11_SGI_GREY_4);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY4", MTR_CLR_X11_SGIGREY4);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_8", MTR_CLR_X11_SGI_GRAY_8);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY8", MTR_CLR_X11_SGIGRAY8);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_8", MTR_CLR_X11_SGI_GREY_8);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY8", MTR_CLR_X11_SGIGREY8);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_12", MTR_CLR_X11_SGI_GRAY_12);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY12", MTR_CLR_X11_SGIGRAY12);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_12", MTR_CLR_X11_SGI_GREY_12);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY12", MTR_CLR_X11_SGIGREY12);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_16", MTR_CLR_X11_SGI_GRAY_16);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY16", MTR_CLR_X11_SGIGRAY16);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_16", MTR_CLR_X11_SGI_GREY_16);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY16", MTR_CLR_X11_SGIGREY16);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_20", MTR_CLR_X11_SGI_GRAY_20);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY20", MTR_CLR_X11_SGIGRAY20);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_20", MTR_CLR_X11_SGI_GREY_20);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY20", MTR_CLR_X11_SGIGREY20);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_24", MTR_CLR_X11_SGI_GRAY_24);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY24", MTR_CLR_X11_SGIGRAY24);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_24", MTR_CLR_X11_SGI_GREY_24);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY24", MTR_CLR_X11_SGIGREY24);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_28", MTR_CLR_X11_SGI_GRAY_28);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY28", MTR_CLR_X11_SGIGRAY28);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_28", MTR_CLR_X11_SGI_GREY_28);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY28", MTR_CLR_X11_SGIGREY28);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_32", MTR_CLR_X11_SGI_GRAY_32);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY32", MTR_CLR_X11_SGIGRAY32);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_32", MTR_CLR_X11_SGI_GREY_32);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY32", MTR_CLR_X11_SGIGREY32);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_36", MTR_CLR_X11_SGI_GRAY_36);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY36", MTR_CLR_X11_SGIGRAY36);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_36", MTR_CLR_X11_SGI_GREY_36);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY36", MTR_CLR_X11_SGIGREY36);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_40", MTR_CLR_X11_SGI_GRAY_40);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY40", MTR_CLR_X11_SGIGRAY40);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_40", MTR_CLR_X11_SGI_GREY_40);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY40", MTR_CLR_X11_SGIGREY40);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_44", MTR_CLR_X11_SGI_GRAY_44);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY44", MTR_CLR_X11_SGIGRAY44);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_44", MTR_CLR_X11_SGI_GREY_44);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY44", MTR_CLR_X11_SGIGREY44);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_48", MTR_CLR_X11_SGI_GRAY_48);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY48", MTR_CLR_X11_SGIGRAY48);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_48", MTR_CLR_X11_SGI_GREY_48);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY48", MTR_CLR_X11_SGIGREY48);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_52", MTR_CLR_X11_SGI_GRAY_52);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY52", MTR_CLR_X11_SGIGRAY52);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_52", MTR_CLR_X11_SGI_GREY_52);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY52", MTR_CLR_X11_SGIGREY52);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_56", MTR_CLR_X11_SGI_GRAY_56);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY56", MTR_CLR_X11_SGIGRAY56);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_56", MTR_CLR_X11_SGI_GREY_56);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY56", MTR_CLR_X11_SGIGREY56);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_60", MTR_CLR_X11_SGI_GRAY_60);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY60", MTR_CLR_X11_SGIGRAY60);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_60", MTR_CLR_X11_SGI_GREY_60);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY60", MTR_CLR_X11_SGIGREY60);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_64", MTR_CLR_X11_SGI_GRAY_64);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY64", MTR_CLR_X11_SGIGRAY64);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_64", MTR_CLR_X11_SGI_GREY_64);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY64", MTR_CLR_X11_SGIGREY64);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_68", MTR_CLR_X11_SGI_GRAY_68);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY68", MTR_CLR_X11_SGIGRAY68);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_68", MTR_CLR_X11_SGI_GREY_68);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY68", MTR_CLR_X11_SGIGREY68);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_72", MTR_CLR_X11_SGI_GRAY_72);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY72", MTR_CLR_X11_SGIGRAY72);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_72", MTR_CLR_X11_SGI_GREY_72);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY72", MTR_CLR_X11_SGIGREY72);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_76", MTR_CLR_X11_SGI_GRAY_76);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY76", MTR_CLR_X11_SGIGRAY76);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_76", MTR_CLR_X11_SGI_GREY_76);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY76", MTR_CLR_X11_SGIGREY76);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_80", MTR_CLR_X11_SGI_GRAY_80);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY80", MTR_CLR_X11_SGIGRAY80);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_80", MTR_CLR_X11_SGI_GREY_80);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY80", MTR_CLR_X11_SGIGREY80);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_84", MTR_CLR_X11_SGI_GRAY_84);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY84", MTR_CLR_X11_SGIGRAY84);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_84", MTR_CLR_X11_SGI_GREY_84);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY84", MTR_CLR_X11_SGIGREY84);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_88", MTR_CLR_X11_SGI_GRAY_88);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY88", MTR_CLR_X11_SGIGRAY88);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_88", MTR_CLR_X11_SGI_GREY_88);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY88", MTR_CLR_X11_SGIGREY88);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_92", MTR_CLR_X11_SGI_GRAY_92);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY92", MTR_CLR_X11_SGIGRAY92);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_92", MTR_CLR_X11_SGI_GREY_92);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY92", MTR_CLR_X11_SGIGREY92);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_96", MTR_CLR_X11_SGI_GRAY_96);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY96", MTR_CLR_X11_SGIGRAY96);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_96", MTR_CLR_X11_SGI_GREY_96);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY96", MTR_CLR_X11_SGIGREY96);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GRAY_100", MTR_CLR_X11_SGI_GRAY_100);
    MTR_ScriptsRegisterVariable_u("X11_SGIGRAY100", MTR_CLR_X11_SGIGRAY100);
    MTR_ScriptsRegisterVariable_u("X11_SGI_GREY_100", MTR_CLR_X11_SGI_GREY_100);
    MTR_ScriptsRegisterVariable_u("X11_SGIGREY100", MTR_CLR_X11_SGIGREY100);
    MTR_ScriptsRegisterVariable_u("X11_SGI_LIGHT_BLUE",
     MTR_CLR_X11_SGI_LIGHT_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_SGILIGHTBLUE", MTR_CLR_X11_SGILIGHTBLUE);
    MTR_ScriptsRegisterVariable_u("X11_SGI_DARK_GRAY",
     MTR_CLR_X11_SGI_DARK_GRAY);
    MTR_ScriptsRegisterVariable_u("X11_SGIDARKGRAY", MTR_CLR_X11_SGIDARKGRAY);
    MTR_ScriptsRegisterVariable_u("X11_SGI_DARK_GREY",
     MTR_CLR_X11_SGI_DARK_GREY);
    MTR_ScriptsRegisterVariable_u("X11_SGIDARKGREY", MTR_CLR_X11_SGIDARKGREY);
    MTR_ScriptsRegisterVariable_u("X11_SGI_SALMON", MTR_CLR_X11_SGI_SALMON);
    MTR_ScriptsRegisterVariable_u("X11_SGISALMON", MTR_CLR_X11_SGISALMON);
    MTR_ScriptsRegisterVariable_u("X11_SGI_CHARTREUSE",
     MTR_CLR_X11_SGI_CHARTREUSE);
    MTR_ScriptsRegisterVariable_u("X11_SGICHARTREUSE",
     MTR_CLR_X11_SGICHARTREUSE);
    MTR_ScriptsRegisterVariable_u("X11_SGI_OLIVE_DRAB",
     MTR_CLR_X11_SGI_OLIVE_DRAB);
    MTR_ScriptsRegisterVariable_u("X11_SGIOLIVEDRAB", MTR_CLR_X11_SGIOLIVEDRAB);
    MTR_ScriptsRegisterVariable_u("X11_SGI_SLATE_BLUE",
     MTR_CLR_X11_SGI_SLATE_BLUE);
    MTR_ScriptsRegisterVariable_u("X11_SGISLATEBLUE", MTR_CLR_X11_SGISLATEBLUE);
    MTR_ScriptsRegisterVariable_u("X11_SGI_BEET", MTR_CLR_X11_SGI_BEET);
    MTR_ScriptsRegisterVariable_u("X11_SGIBEET", MTR_CLR_X11_SGIBEET);
    MTR_ScriptsRegisterVariable_u("X11_SGI_TEAL", MTR_CLR_X11_SGI_TEAL);
    MTR_ScriptsRegisterVariable_u("X11_SGITEAL", MTR_CLR_X11_SGITEAL);
    MTR_ScriptsRegisterVariable_u("X11_SGI_LIGHT_GRAY",
     MTR_CLR_X11_SGI_LIGHT_GRAY);
    MTR_ScriptsRegisterVariable_u("X11_SGILIGHTGRAY", MTR_CLR_X11_SGILIGHTGRAY);
    MTR_ScriptsRegisterVariable_u("X11_SGI_LIGHT_GREY",
     MTR_CLR_X11_SGI_LIGHT_GREY);
    MTR_ScriptsRegisterVariable_u("X11_SGILIGHTGREY", MTR_CLR_X11_SGILIGHTGREY);
    MTR_ScriptsRegisterVariable_u("X11_SGI_VERY_LIGHT_GRAY",
     MTR_CLR_X11_SGI_VERY_LIGHT_GRAY);
    MTR_ScriptsRegisterVariable_u("X11_SGIVERYLIGHTGRAY",
     MTR_CLR_X11_SGIVERYLIGHTGRAY);
    MTR_ScriptsRegisterVariable_u("X11_SGI_VERY_LIGHT_GREY",
     MTR_CLR_X11_SGI_VERY_LIGHT_GREY);
    MTR_ScriptsRegisterVariable_u("X11_SGIVERYLIGHTGREY",
     MTR_CLR_X11_SGIVERYLIGHTGREY);
    MTR_ScriptsRegisterVariable_u("X11_SGI_MEDIUM_GRAY",
     MTR_CLR_X11_SGI_MEDIUM_GRAY);
    MTR_ScriptsRegisterVariable_u("X11_SGIMEDIUMGRAY",
     MTR_CLR_X11_SGIMEDIUMGRAY);
    MTR_ScriptsRegisterVariable_u("X11_SGI_MEDIUM_GREY",
     MTR_CLR_X11_SGI_MEDIUM_GREY);
    MTR_ScriptsRegisterVariable_u("X11_SGIMEDIUMGREY",
     MTR_CLR_X11_SGIMEDIUMGREY);
    MTR_ScriptsRegisterVariable_u("X11_SGI_VERY_DARK_GRAY",
     MTR_CLR_X11_SGI_VERY_DARK_GRAY);
    MTR_ScriptsRegisterVariable_u("X11_SGIVERYDARKGRAY",
     MTR_CLR_X11_SGIVERYDARKGRAY);
    MTR_ScriptsRegisterVariable_u("X11_SGI_VERY_DARK_GREY",
     MTR_CLR_X11_SGI_VERY_DARK_GREY);
    MTR_ScriptsRegisterVariable_u("X11_SGIVERYDARKGREY",
     MTR_CLR_X11_SGIVERYDARKGREY);
    MTR_ScriptsRegisterVariable_u("X11_SGI_BRIGHT_GRAY",
     MTR_CLR_X11_SGI_BRIGHT_GRAY);
    MTR_ScriptsRegisterVariable_u("X11_SGIBRIGHTGRAY",
     MTR_CLR_X11_SGIBRIGHTGRAY);
    MTR_ScriptsRegisterVariable_u("X11_SGI_BRIGHT_GREY",
     MTR_CLR_X11_SGI_BRIGHT_GREY);
    MTR_ScriptsRegisterVariable_u("X11_SGIBRIGHTGREY",
     MTR_CLR_X11_SGIBRIGHTGREY);
    MTR_ScriptsRegisterVariable_u("X11_INDIGO", MTR_CLR_X11_INDIGO);
    MTR_ScriptsRegisterVariable_u("X11_INDIGO2", MTR_CLR_X11_INDIGO2);
    MTR_ScriptsRegisterVariable_u("X11_CRIMSON", MTR_CLR_X11_CRIMSON);
}

#endif
