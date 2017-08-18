#ifndef MTR_UTILS_COLOR_BINDING_COMMON_C
#define MTR_UTILS_COLOR_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_U32t_U8t3(mtrSF_ColorAssembleRGB, mtrColorAssembleRGB)
MTR_SCRIPT_FUNC_U32t_U8t4(mtrSF_ColorAssembleRGBA, mtrColorAssembleRGBA)

#ifdef lua_h
MTR_SCRIPT_FUNC(mtrSF_ColorSplitRGB)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint32_t rgb;

    MTR_SF_GET_UINT32(rgb, 1);
    mtrColorSplitRGB(rgb, &r, &g, &b);

    MTR_SF_PUSH_UINT8(r);
    MTR_SF_PUSH_UINT8(g);
    MTR_SF_PUSH_UINT8(b);

    return 3;
}

MTR_SCRIPT_FUNC(mtrSF_ColorSplitRGBA)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    uint32_t rgba;

    MTR_SF_GET_UINT32(rgba, 1);
    mtrColorSplitRGBA(rgba, &r, &g, &b, &a);

    MTR_SF_PUSH_UINT8(r);
    MTR_SF_PUSH_UINT8(g);
    MTR_SF_PUSH_UINT8(b);
    MTR_SF_PUSH_UINT8(a);

    return 4;
}
#endif

MTR_SCRIPT_FUNC_U8t_U32t1(mtrSF_ColorRGBGetR, mtrColorRGBGetR)
MTR_SCRIPT_FUNC_U8t_U32t1(mtrSF_ColorRGBGetG, mtrColorRGBGetG)
MTR_SCRIPT_FUNC_U8t_U32t1(mtrSF_ColorRGBGetB, mtrColorRGBGetB)
MTR_SCRIPT_FUNC_U32t_U32t1U8t1(mtrSF_ColorRGBSetR, mtrColorRGBSetR)
MTR_SCRIPT_FUNC_U32t_U32t1U8t1(mtrSF_ColorRGBSetG, mtrColorRGBSetG)
MTR_SCRIPT_FUNC_U32t_U32t1U8t1(mtrSF_ColorRGBSetB, mtrColorRGBSetB)
MTR_SCRIPT_FUNC_U8t_U32t1(mtrSF_ColorRGBAGetR, mtrColorRGBAGetR)
MTR_SCRIPT_FUNC_U8t_U32t1(mtrSF_ColorRGBAGetG, mtrColorRGBAGetG)
MTR_SCRIPT_FUNC_U8t_U32t1(mtrSF_ColorRGBAGetB, mtrColorRGBAGetB)
MTR_SCRIPT_FUNC_U8t_U32t1(mtrSF_ColorRGBAGetA, mtrColorRGBAGetA)
MTR_SCRIPT_FUNC_U32t_U32t1U8t1(mtrSF_ColorRGBASetR, mtrColorRGBASetR)
MTR_SCRIPT_FUNC_U32t_U32t1U8t1(mtrSF_ColorRGBASetG, mtrColorRGBASetG)
MTR_SCRIPT_FUNC_U32t_U32t1U8t1(mtrSF_ColorRGBASetB, mtrColorRGBASetB)
MTR_SCRIPT_FUNC_U32t_U32t1U8t1(mtrSF_ColorRGBASetA, mtrColorRGBASetA)
MTR_SCRIPT_FUNC_U32t_U32t1(mtrSF_ColorRGBtoRGBA, mtrColorRGBtoRGBA)
MTR_SCRIPT_FUNC_U32t_U32t1(mtrSF_ColorRGBAtoRGB, mtrColorRGBAtoRGB)

void mtrScriptsRegisterAll(void)
{
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();

    MTR_FIND_FUNCTION(mtrColorAssembleRGB, "Utils_color");
    MTR_FIND_FUNCTION(mtrColorAssembleRGBA, "Utils_color");
    #ifdef lua_h
    MTR_FIND_FUNCTION(mtrColorSplitRGB, "Utils_color");
    MTR_FIND_FUNCTION(mtrColorSplitRGBA, "Utils_color");
    #endif
    MTR_FIND_FUNCTION(mtrColorRGBGetR, "Utils_color")
    MTR_FIND_FUNCTION(mtrColorRGBGetG, "Utils_color")
    MTR_FIND_FUNCTION(mtrColorRGBGetB, "Utils_color")
    MTR_FIND_FUNCTION(mtrColorRGBSetR, "Utils_color")
    MTR_FIND_FUNCTION(mtrColorRGBSetG, "Utils_color")
    MTR_FIND_FUNCTION(mtrColorRGBSetB, "Utils_color")
    MTR_FIND_FUNCTION(mtrColorRGBAGetR, "Utils_color")
    MTR_FIND_FUNCTION(mtrColorRGBAGetG, "Utils_color")
    MTR_FIND_FUNCTION(mtrColorRGBAGetB, "Utils_color")
    MTR_FIND_FUNCTION(mtrColorRGBAGetA, "Utils_color")
    MTR_FIND_FUNCTION(mtrColorRGBASetR, "Utils_color")
    MTR_FIND_FUNCTION(mtrColorRGBASetG, "Utils_color")
    MTR_FIND_FUNCTION(mtrColorRGBASetB, "Utils_color")
    MTR_FIND_FUNCTION(mtrColorRGBASetA, "Utils_color")
    MTR_FIND_FUNCTION(mtrColorRGBtoRGBA, "Utils_color");
    MTR_FIND_FUNCTION(mtrColorRGBAtoRGB, "Utils_color");

    if (ok)
    {
        mtrScriptsRegisterNumericVariable("WEB_WHITE", MTR_CLR_WEB_WHITE);
        mtrScriptsRegisterNumericVariable("WEB_SILVER", MTR_CLR_WEB_SILVER);
        mtrScriptsRegisterNumericVariable("WEB_GRAY", MTR_CLR_WEB_GRAY);
        mtrScriptsRegisterNumericVariable("WEB_BLACK", MTR_CLR_WEB_BLACK);
        mtrScriptsRegisterNumericVariable("WEB_RED", MTR_CLR_WEB_RED);
        mtrScriptsRegisterNumericVariable("WEB_MAROON", MTR_CLR_WEB_MAROON);
        mtrScriptsRegisterNumericVariable("WEB_YELLOW", MTR_CLR_WEB_YELLOW);
        mtrScriptsRegisterNumericVariable("WEB_OLIVE", MTR_CLR_WEB_OLIVE);
        mtrScriptsRegisterNumericVariable("WEB_LIME", MTR_CLR_WEB_LIME);
        mtrScriptsRegisterNumericVariable("WEB_GREEN", MTR_CLR_WEB_GREEN);
        mtrScriptsRegisterNumericVariable("WEB_AQUA", MTR_CLR_WEB_AQUA);
        mtrScriptsRegisterNumericVariable("WEB_TEAL", MTR_CLR_WEB_TEAL);
        mtrScriptsRegisterNumericVariable("WEB_BLUE", MTR_CLR_WEB_BLUE);
        mtrScriptsRegisterNumericVariable("WEB_NAVY", MTR_CLR_WEB_NAVY);
        mtrScriptsRegisterNumericVariable("WEB_FUCHSIA", MTR_CLR_WEB_FUCHSIA);
        mtrScriptsRegisterNumericVariable("WEB_PURPLE", MTR_CLR_WEB_PURPLE);
        mtrScriptsRegisterNumericVariable("WEB_ORANGE", MTR_CLR_WEB_ORANGE);
        mtrScriptsRegisterNumericVariable("WEB_REBECCA_PURPLE",
         MTR_CLR_WEB_REBECCA_PURPLE);

        mtrScriptsRegisterNumericVariable("X11_SNOW", MTR_CLR_X11_SNOW);
        mtrScriptsRegisterNumericVariable("X11_GHOST_WHITE",
         MTR_CLR_X11_GHOST_WHITE);
        mtrScriptsRegisterNumericVariable("X11_GHOSTWHITE",
         MTR_CLR_X11_GHOSTWHITE);
        mtrScriptsRegisterNumericVariable("X11_WHITE_SMOKE",
         MTR_CLR_X11_WHITE_SMOKE);
        mtrScriptsRegisterNumericVariable("X11_WHITESMOKE",
         MTR_CLR_X11_WHITESMOKE);
        mtrScriptsRegisterNumericVariable("X11_GAINSBORO",
         MTR_CLR_X11_GAINSBORO);
        mtrScriptsRegisterNumericVariable("X11_FLORAL_WHITE",
         MTR_CLR_X11_FLORAL_WHITE);
        mtrScriptsRegisterNumericVariable("X11_FLORALWHITE",
         MTR_CLR_X11_FLORALWHITE);
        mtrScriptsRegisterNumericVariable("X11_OLD_LACE", MTR_CLR_X11_OLD_LACE);
        mtrScriptsRegisterNumericVariable("X11_OLDLACE", MTR_CLR_X11_OLDLACE);
        mtrScriptsRegisterNumericVariable("X11_LINEN", MTR_CLR_X11_LINEN);
        mtrScriptsRegisterNumericVariable("X11_ANTIQUE_WHITE",
         MTR_CLR_X11_ANTIQUE_WHITE);
        mtrScriptsRegisterNumericVariable("X11_ANTIQUEWHITE",
         MTR_CLR_X11_ANTIQUEWHITE);
        mtrScriptsRegisterNumericVariable("X11_PAPAYA_WHIP",
         MTR_CLR_X11_PAPAYA_WHIP);
        mtrScriptsRegisterNumericVariable("X11_PAPAYAWHIP",
         MTR_CLR_X11_PAPAYAWHIP);
        mtrScriptsRegisterNumericVariable("X11_BLANCHED_ALMOND",
         MTR_CLR_X11_BLANCHED_ALMOND);
        mtrScriptsRegisterNumericVariable("X11_BLANCHEDALMOND",
         MTR_CLR_X11_BLANCHEDALMOND);
        mtrScriptsRegisterNumericVariable("X11_BISQUE", MTR_CLR_X11_BISQUE);
        mtrScriptsRegisterNumericVariable("X11_PEACH_PUFF",
         MTR_CLR_X11_PEACH_PUFF);
        mtrScriptsRegisterNumericVariable("X11_PEACHPUFF",
         MTR_CLR_X11_PEACHPUFF);
        mtrScriptsRegisterNumericVariable("X11_NAVAJO_WHITE",
         MTR_CLR_X11_NAVAJO_WHITE);
        mtrScriptsRegisterNumericVariable("X11_NAVAJOWHITE",
         MTR_CLR_X11_NAVAJOWHITE);
        mtrScriptsRegisterNumericVariable("X11_MOCCASIN", MTR_CLR_X11_MOCCASIN);
        mtrScriptsRegisterNumericVariable("X11_CORNSILK", MTR_CLR_X11_CORNSILK);
        mtrScriptsRegisterNumericVariable("X11_IVORY", MTR_CLR_X11_IVORY);
        mtrScriptsRegisterNumericVariable("X11_LEMON_CHIFFON",
         MTR_CLR_X11_LEMON_CHIFFON);
        mtrScriptsRegisterNumericVariable("X11_LEMONCHIFFON",
         MTR_CLR_X11_LEMONCHIFFON);
        mtrScriptsRegisterNumericVariable("X11_SEASHELL", MTR_CLR_X11_SEASHELL);
        mtrScriptsRegisterNumericVariable("X11_HONEYDEW", MTR_CLR_X11_HONEYDEW);
        mtrScriptsRegisterNumericVariable("X11_MINT_CREAM",
         MTR_CLR_X11_MINT_CREAM);
        mtrScriptsRegisterNumericVariable("X11_MINTCREAM",
         MTR_CLR_X11_MINTCREAM);
        mtrScriptsRegisterNumericVariable("X11_AZURE", MTR_CLR_X11_AZURE);
        mtrScriptsRegisterNumericVariable("X11_ALICE_BLUE",
         MTR_CLR_X11_ALICE_BLUE);
        mtrScriptsRegisterNumericVariable("X11_ALICEBLUE",
         MTR_CLR_X11_ALICEBLUE);
        mtrScriptsRegisterNumericVariable("X11_LAVENDER", MTR_CLR_X11_LAVENDER);
        mtrScriptsRegisterNumericVariable("X11_LAVENDER_BLUSH",
         MTR_CLR_X11_LAVENDER_BLUSH);
        mtrScriptsRegisterNumericVariable("X11_LAVENDERBLUSH",
         MTR_CLR_X11_LAVENDERBLUSH);
        mtrScriptsRegisterNumericVariable("X11_MISTY_ROSE",
         MTR_CLR_X11_MISTY_ROSE);
        mtrScriptsRegisterNumericVariable("X11_MISTYROSE",
         MTR_CLR_X11_MISTYROSE);
        mtrScriptsRegisterNumericVariable("X11_WHITE", MTR_CLR_X11_WHITE);
        mtrScriptsRegisterNumericVariable("X11_BLACK", MTR_CLR_X11_BLACK);
        mtrScriptsRegisterNumericVariable("X11_DARK_SLATE_GRAY",
         MTR_CLR_X11_DARK_SLATE_GRAY);
        mtrScriptsRegisterNumericVariable("X11_DARKSLATEGRAY",
         MTR_CLR_X11_DARKSLATEGRAY);
        mtrScriptsRegisterNumericVariable("X11_DARK_SLATE_GREY",
         MTR_CLR_X11_DARK_SLATE_GREY);
        mtrScriptsRegisterNumericVariable("X11_DARKSLATEGREY",
         MTR_CLR_X11_DARKSLATEGREY);
        mtrScriptsRegisterNumericVariable("X11_DIM_GRAY", MTR_CLR_X11_DIM_GRAY);
        mtrScriptsRegisterNumericVariable("X11_DIMGRAY", MTR_CLR_X11_DIMGRAY);
        mtrScriptsRegisterNumericVariable("X11_DIM_GREY", MTR_CLR_X11_DIM_GREY);
        mtrScriptsRegisterNumericVariable("X11_DIMGREY", MTR_CLR_X11_DIMGREY);
        mtrScriptsRegisterNumericVariable("X11_SLATE_GRAY",
         MTR_CLR_X11_SLATE_GRAY);
        mtrScriptsRegisterNumericVariable("X11_SLATEGRAY",
         MTR_CLR_X11_SLATEGRAY);
        mtrScriptsRegisterNumericVariable("X11_SLATE_GREY",
         MTR_CLR_X11_SLATE_GREY);
        mtrScriptsRegisterNumericVariable("X11_SLATEGREY",
         MTR_CLR_X11_SLATEGREY);
        mtrScriptsRegisterNumericVariable("X11_LIGHT_SLATE_GRAY",
         MTR_CLR_X11_LIGHT_SLATE_GRAY);
        mtrScriptsRegisterNumericVariable("X11_LIGHTSLATEGRAY",
         MTR_CLR_X11_LIGHTSLATEGRAY);
        mtrScriptsRegisterNumericVariable("X11_LIGHT_SLATE_GREY",
         MTR_CLR_X11_LIGHT_SLATE_GREY);
        mtrScriptsRegisterNumericVariable("X11_LIGHTSLATEGREY",
         MTR_CLR_X11_LIGHTSLATEGREY);
        mtrScriptsRegisterNumericVariable("X11_GRAY", MTR_CLR_X11_GRAY);
        mtrScriptsRegisterNumericVariable("X11_GREY", MTR_CLR_X11_GREY);
        mtrScriptsRegisterNumericVariable("X11_LIGHT_GREY",
         MTR_CLR_X11_LIGHT_GREY);
        mtrScriptsRegisterNumericVariable("X11_LIGHTGREY",
         MTR_CLR_X11_LIGHTGREY);
        mtrScriptsRegisterNumericVariable("X11_LIGHT_GRAY",
         MTR_CLR_X11_LIGHT_GRAY);
        mtrScriptsRegisterNumericVariable("X11_LIGHTGRAY",
         MTR_CLR_X11_LIGHTGRAY);
        mtrScriptsRegisterNumericVariable("X11_MIDNIGHT_BLUE",
         MTR_CLR_X11_MIDNIGHT_BLUE);
        mtrScriptsRegisterNumericVariable("X11_MIDNIGHTBLUE",
         MTR_CLR_X11_MIDNIGHTBLUE);
        mtrScriptsRegisterNumericVariable("X11_NAVY", MTR_CLR_X11_NAVY);
        mtrScriptsRegisterNumericVariable("X11_NAVY_BLUE",
         MTR_CLR_X11_NAVY_BLUE);
        mtrScriptsRegisterNumericVariable("X11_NAVYBLUE", MTR_CLR_X11_NAVYBLUE);
        mtrScriptsRegisterNumericVariable("X11_CORNFLOWER_BLUE",
         MTR_CLR_X11_CORNFLOWER_BLUE);
        mtrScriptsRegisterNumericVariable("X11_CORNFLOWERBLUE",
         MTR_CLR_X11_CORNFLOWERBLUE);
        mtrScriptsRegisterNumericVariable("X11_DARK_SLATE_BLUE",
         MTR_CLR_X11_DARK_SLATE_BLUE);
        mtrScriptsRegisterNumericVariable("X11_DARKSLATEBLUE",
         MTR_CLR_X11_DARKSLATEBLUE);
        mtrScriptsRegisterNumericVariable("X11_SLATE_BLUE",
         MTR_CLR_X11_SLATE_BLUE);
        mtrScriptsRegisterNumericVariable("X11_SLATEBLUE",
         MTR_CLR_X11_SLATEBLUE);
        mtrScriptsRegisterNumericVariable("X11_MEDIUM_SLATE_BLUE",
         MTR_CLR_X11_MEDIUM_SLATE_BLUE);
        mtrScriptsRegisterNumericVariable("X11_MEDIUMSLATEBLUE",
         MTR_CLR_X11_MEDIUMSLATEBLUE);
        mtrScriptsRegisterNumericVariable("X11_LIGHT_SLATE_BLUE",
         MTR_CLR_X11_LIGHT_SLATE_BLUE);
        mtrScriptsRegisterNumericVariable("X11_LIGHTSLATEBLUE",
         MTR_CLR_X11_LIGHTSLATEBLUE);
        mtrScriptsRegisterNumericVariable("X11_MEDIUM_BLUE",
         MTR_CLR_X11_MEDIUM_BLUE);
        mtrScriptsRegisterNumericVariable("X11_MEDIUMBLUE",
         MTR_CLR_X11_MEDIUMBLUE);
        mtrScriptsRegisterNumericVariable("X11_ROYAL_BLUE",
         MTR_CLR_X11_ROYAL_BLUE);
        mtrScriptsRegisterNumericVariable("X11_ROYALBLUE",
         MTR_CLR_X11_ROYALBLUE);
        mtrScriptsRegisterNumericVariable("X11_BLUE", MTR_CLR_X11_BLUE);
        mtrScriptsRegisterNumericVariable("X11_DODGER_BLUE",
         MTR_CLR_X11_DODGER_BLUE);
        mtrScriptsRegisterNumericVariable("X11_DODGERBLUE",
         MTR_CLR_X11_DODGERBLUE);
        mtrScriptsRegisterNumericVariable("X11_DEEP_SKY_BLUE",
         MTR_CLR_X11_DEEP_SKY_BLUE);
        mtrScriptsRegisterNumericVariable("X11_DEEPSKYBLUE",
         MTR_CLR_X11_DEEPSKYBLUE);
        mtrScriptsRegisterNumericVariable("X11_SKY_BLUE", MTR_CLR_X11_SKY_BLUE);
        mtrScriptsRegisterNumericVariable("X11_SKYBLUE", MTR_CLR_X11_SKYBLUE);
        mtrScriptsRegisterNumericVariable("X11_LIGHT_SKY_BLUE",
         MTR_CLR_X11_LIGHT_SKY_BLUE);
        mtrScriptsRegisterNumericVariable("X11_LIGHTSKYBLUE",
         MTR_CLR_X11_LIGHTSKYBLUE);
        mtrScriptsRegisterNumericVariable("X11_STEEL_BLUE",
         MTR_CLR_X11_STEEL_BLUE);
        mtrScriptsRegisterNumericVariable("X11_STEELBLUE",
         MTR_CLR_X11_STEELBLUE);
        mtrScriptsRegisterNumericVariable("X11_LIGHT_STEEL_BLUE",
         MTR_CLR_X11_LIGHT_STEEL_BLUE);
        mtrScriptsRegisterNumericVariable("X11_LIGHTSTEELBLUE",
         MTR_CLR_X11_LIGHTSTEELBLUE);
        mtrScriptsRegisterNumericVariable("X11_LIGHT_BLUE",
         MTR_CLR_X11_LIGHT_BLUE);
        mtrScriptsRegisterNumericVariable("X11_LIGHTBLUE",
         MTR_CLR_X11_LIGHTBLUE);
        mtrScriptsRegisterNumericVariable("X11_POWDER_BLUE",
         MTR_CLR_X11_POWDER_BLUE);
        mtrScriptsRegisterNumericVariable("X11_POWDERBLUE",
         MTR_CLR_X11_POWDERBLUE);
        mtrScriptsRegisterNumericVariable("X11_PALE_TURQUOISE",
         MTR_CLR_X11_PALE_TURQUOISE);
        mtrScriptsRegisterNumericVariable("X11_PALETURQUOISE",
         MTR_CLR_X11_PALETURQUOISE);
        mtrScriptsRegisterNumericVariable("X11_DARK_TURQUOISE",
         MTR_CLR_X11_DARK_TURQUOISE);
        mtrScriptsRegisterNumericVariable("X11_DARKTURQUOISE",
         MTR_CLR_X11_DARKTURQUOISE);
        mtrScriptsRegisterNumericVariable("X11_MEDIUM_TURQUOISE",
         MTR_CLR_X11_MEDIUM_TURQUOISE);
        mtrScriptsRegisterNumericVariable("X11_MEDIUMTURQUOISE",
         MTR_CLR_X11_MEDIUMTURQUOISE);
        mtrScriptsRegisterNumericVariable("X11_TURQUOISE",
         MTR_CLR_X11_TURQUOISE);
        mtrScriptsRegisterNumericVariable("X11_CYAN", MTR_CLR_X11_CYAN);
        mtrScriptsRegisterNumericVariable("X11_LIGHT_CYAN",
         MTR_CLR_X11_LIGHT_CYAN);
        mtrScriptsRegisterNumericVariable("X11_LIGHTCYAN",
         MTR_CLR_X11_LIGHTCYAN);
        mtrScriptsRegisterNumericVariable("X11_CADET_BLUE",
         MTR_CLR_X11_CADET_BLUE);
        mtrScriptsRegisterNumericVariable("X11_CADETBLUE",
         MTR_CLR_X11_CADETBLUE);
        mtrScriptsRegisterNumericVariable("X11_MEDIUM_AQUAMARINE",
         MTR_CLR_X11_MEDIUM_AQUAMARINE);
        mtrScriptsRegisterNumericVariable("X11_MEDIUMAQUAMARINE",
         MTR_CLR_X11_MEDIUMAQUAMARINE);
        mtrScriptsRegisterNumericVariable("X11_AQUAMARINE",
         MTR_CLR_X11_AQUAMARINE);
        mtrScriptsRegisterNumericVariable("X11_DARK_GREEN",
         MTR_CLR_X11_DARK_GREEN);
        mtrScriptsRegisterNumericVariable("X11_DARKGREEN",
         MTR_CLR_X11_DARKGREEN);
        mtrScriptsRegisterNumericVariable("X11_DARK_OLIVE_GREEN",
         MTR_CLR_X11_DARK_OLIVE_GREEN);
        mtrScriptsRegisterNumericVariable("X11_DARKOLIVEGREEN",
         MTR_CLR_X11_DARKOLIVEGREEN);
        mtrScriptsRegisterNumericVariable("X11_DARK_SEA_GREEN",
         MTR_CLR_X11_DARK_SEA_GREEN);
        mtrScriptsRegisterNumericVariable("X11_DARKSEAGREEN",
         MTR_CLR_X11_DARKSEAGREEN);
        mtrScriptsRegisterNumericVariable("X11_SEA_GREEN",
         MTR_CLR_X11_SEA_GREEN);
        mtrScriptsRegisterNumericVariable("X11_SEAGREEN", MTR_CLR_X11_SEAGREEN);
        mtrScriptsRegisterNumericVariable("X11_MEDIUM_SEA_GREEN",
         MTR_CLR_X11_MEDIUM_SEA_GREEN);
        mtrScriptsRegisterNumericVariable("X11_MEDIUMSEAGREEN",
         MTR_CLR_X11_MEDIUMSEAGREEN);
        mtrScriptsRegisterNumericVariable("X11_LIGHT_SEA_GREEN",
         MTR_CLR_X11_LIGHT_SEA_GREEN);
        mtrScriptsRegisterNumericVariable("X11_LIGHTSEAGREEN",
         MTR_CLR_X11_LIGHTSEAGREEN);
        mtrScriptsRegisterNumericVariable("X11_PALE_GREEN",
         MTR_CLR_X11_PALE_GREEN);
        mtrScriptsRegisterNumericVariable("X11_PALEGREEN",
         MTR_CLR_X11_PALEGREEN);
        mtrScriptsRegisterNumericVariable("X11_SPRING_GREEN",
         MTR_CLR_X11_SPRING_GREEN);
        mtrScriptsRegisterNumericVariable("X11_SPRINGGREEN",
         MTR_CLR_X11_SPRINGGREEN);
        mtrScriptsRegisterNumericVariable("X11_LAWN_GREEN",
         MTR_CLR_X11_LAWN_GREEN);
        mtrScriptsRegisterNumericVariable("X11_LAWNGREEN",
         MTR_CLR_X11_LAWNGREEN);
        mtrScriptsRegisterNumericVariable("X11_GREEN", MTR_CLR_X11_GREEN);
        mtrScriptsRegisterNumericVariable("X11_CHARTREUSE",
         MTR_CLR_X11_CHARTREUSE);
        mtrScriptsRegisterNumericVariable("X11_MEDIUM_SPRING_GREEN",
         MTR_CLR_X11_MEDIUM_SPRING_GREEN);
        mtrScriptsRegisterNumericVariable("X11_MEDIUMSPRINGGREEN",
         MTR_CLR_X11_MEDIUMSPRINGGREEN);
        mtrScriptsRegisterNumericVariable("X11_GREEN_YELLOW",
         MTR_CLR_X11_GREEN_YELLOW);
        mtrScriptsRegisterNumericVariable("X11_GREENYELLOW",
         MTR_CLR_X11_GREENYELLOW);
        mtrScriptsRegisterNumericVariable("X11_LIME_GREEN",
         MTR_CLR_X11_LIME_GREEN);
        mtrScriptsRegisterNumericVariable("X11_LIMEGREEN",
         MTR_CLR_X11_LIMEGREEN);
        mtrScriptsRegisterNumericVariable("X11_YELLOW_GREEN",
         MTR_CLR_X11_YELLOW_GREEN);
        mtrScriptsRegisterNumericVariable("X11_YELLOWGREEN",
         MTR_CLR_X11_YELLOWGREEN);
        mtrScriptsRegisterNumericVariable("X11_FOREST_GREEN",
         MTR_CLR_X11_FOREST_GREEN);
        mtrScriptsRegisterNumericVariable("X11_FORESTGREEN",
         MTR_CLR_X11_FORESTGREEN);
        mtrScriptsRegisterNumericVariable("X11_OLIVE_DRAB",
         MTR_CLR_X11_OLIVE_DRAB);
        mtrScriptsRegisterNumericVariable("X11_OLIVEDRAB",
         MTR_CLR_X11_OLIVEDRAB);
        mtrScriptsRegisterNumericVariable("X11_DARK_KHAKI",
         MTR_CLR_X11_DARK_KHAKI);
        mtrScriptsRegisterNumericVariable("X11_DARKKHAKI",
         MTR_CLR_X11_DARKKHAKI);
        mtrScriptsRegisterNumericVariable("X11_KHAKI", MTR_CLR_X11_KHAKI);
        mtrScriptsRegisterNumericVariable("X11_PALE_GOLDENROD",
         MTR_CLR_X11_PALE_GOLDENROD);
        mtrScriptsRegisterNumericVariable("X11_PALEGOLDENROD",
         MTR_CLR_X11_PALEGOLDENROD);
        mtrScriptsRegisterNumericVariable("X11_LIGHT_GOLDENROD_YELLOW",
         MTR_CLR_X11_LIGHT_GOLDENROD_YELLOW);
        mtrScriptsRegisterNumericVariable("X11_LIGHTGOLDENRODYELLOW",
         MTR_CLR_X11_LIGHTGOLDENRODYELLOW);
        mtrScriptsRegisterNumericVariable("X11_LIGHT_YELLOW",
         MTR_CLR_X11_LIGHT_YELLOW);
        mtrScriptsRegisterNumericVariable("X11_LIGHTYELLOW",
         MTR_CLR_X11_LIGHTYELLOW);
        mtrScriptsRegisterNumericVariable("X11_YELLOW", MTR_CLR_X11_YELLOW);
        mtrScriptsRegisterNumericVariable("X11_GOLD", MTR_CLR_X11_GOLD);
        mtrScriptsRegisterNumericVariable("X11_LIGHT_GOLDENROD",
         MTR_CLR_X11_LIGHT_GOLDENROD);
        mtrScriptsRegisterNumericVariable("X11_LIGHTGOLDENROD",
         MTR_CLR_X11_LIGHTGOLDENROD);
        mtrScriptsRegisterNumericVariable("X11_GOLDENROD",
         MTR_CLR_X11_GOLDENROD);
        mtrScriptsRegisterNumericVariable("X11_DARK_GOLDENROD",
         MTR_CLR_X11_DARK_GOLDENROD);
        mtrScriptsRegisterNumericVariable("X11_DARKGOLDENROD",
         MTR_CLR_X11_DARKGOLDENROD);
        mtrScriptsRegisterNumericVariable("X11_ROSY_BROWN",
         MTR_CLR_X11_ROSY_BROWN);
        mtrScriptsRegisterNumericVariable("X11_ROSYBROWN",
         MTR_CLR_X11_ROSYBROWN);
        mtrScriptsRegisterNumericVariable("X11_INDIAN_RED",
         MTR_CLR_X11_INDIAN_RED);
        mtrScriptsRegisterNumericVariable("X11_INDIANRED",
         MTR_CLR_X11_INDIANRED);
        mtrScriptsRegisterNumericVariable("X11_SADDLE_BROWN",
         MTR_CLR_X11_SADDLE_BROWN);
        mtrScriptsRegisterNumericVariable("X11_SADDLEBROWN",
         MTR_CLR_X11_SADDLEBROWN);
        mtrScriptsRegisterNumericVariable("X11_SIENNA", MTR_CLR_X11_SIENNA);
        mtrScriptsRegisterNumericVariable("X11_PERU", MTR_CLR_X11_PERU);
        mtrScriptsRegisterNumericVariable("X11_BURLYWOOD",
         MTR_CLR_X11_BURLYWOOD);
        mtrScriptsRegisterNumericVariable("X11_BEIGE", MTR_CLR_X11_BEIGE);
        mtrScriptsRegisterNumericVariable("X11_WHEAT", MTR_CLR_X11_WHEAT);
        mtrScriptsRegisterNumericVariable("X11_SANDY_BROWN",
         MTR_CLR_X11_SANDY_BROWN);
        mtrScriptsRegisterNumericVariable("X11_SANDYBROWN",
         MTR_CLR_X11_SANDYBROWN);
        mtrScriptsRegisterNumericVariable("X11_TAN", MTR_CLR_X11_TAN);
        mtrScriptsRegisterNumericVariable("X11_CHOCOLATE",
         MTR_CLR_X11_CHOCOLATE);
        mtrScriptsRegisterNumericVariable("X11_FIREBRICK",
         MTR_CLR_X11_FIREBRICK);
        mtrScriptsRegisterNumericVariable("X11_BROWN", MTR_CLR_X11_BROWN);
        mtrScriptsRegisterNumericVariable("X11_DARK_SALMON",
         MTR_CLR_X11_DARK_SALMON);
        mtrScriptsRegisterNumericVariable("X11_DARKSALMON",
         MTR_CLR_X11_DARKSALMON);
        mtrScriptsRegisterNumericVariable("X11_SALMON", MTR_CLR_X11_SALMON);
        mtrScriptsRegisterNumericVariable("X11_LIGHT_SALMON",
         MTR_CLR_X11_LIGHT_SALMON);
        mtrScriptsRegisterNumericVariable("X11_LIGHTSALMON",
         MTR_CLR_X11_LIGHTSALMON);
        mtrScriptsRegisterNumericVariable("X11_ORANGE", MTR_CLR_X11_ORANGE);
        mtrScriptsRegisterNumericVariable("X11_DARK_ORANGE",
         MTR_CLR_X11_DARK_ORANGE);
        mtrScriptsRegisterNumericVariable("X11_DARKORANGE",
         MTR_CLR_X11_DARKORANGE);
        mtrScriptsRegisterNumericVariable("X11_CORAL", MTR_CLR_X11_CORAL);
        mtrScriptsRegisterNumericVariable("X11_LIGHT_CORAL",
         MTR_CLR_X11_LIGHT_CORAL);
        mtrScriptsRegisterNumericVariable("X11_LIGHTCORAL",
         MTR_CLR_X11_LIGHTCORAL);
        mtrScriptsRegisterNumericVariable("X11_TOMATO", MTR_CLR_X11_TOMATO);
        mtrScriptsRegisterNumericVariable("X11_ORANGE_RED",
         MTR_CLR_X11_ORANGE_RED);
        mtrScriptsRegisterNumericVariable("X11_ORANGERED",
         MTR_CLR_X11_ORANGERED);
        mtrScriptsRegisterNumericVariable("X11_RED", MTR_CLR_X11_RED);
        mtrScriptsRegisterNumericVariable("X11_HOT_PINK", MTR_CLR_X11_HOT_PINK);
        mtrScriptsRegisterNumericVariable("X11_HOTPINK", MTR_CLR_X11_HOTPINK);
        mtrScriptsRegisterNumericVariable("X11_DEEP_PINK",
         MTR_CLR_X11_DEEP_PINK);
        mtrScriptsRegisterNumericVariable("X11_DEEPPINK", MTR_CLR_X11_DEEPPINK);
        mtrScriptsRegisterNumericVariable("X11_PINK", MTR_CLR_X11_PINK);
        mtrScriptsRegisterNumericVariable("X11_LIGHT_PINK",
         MTR_CLR_X11_LIGHT_PINK);
        mtrScriptsRegisterNumericVariable("X11_LIGHTPINK",
         MTR_CLR_X11_LIGHTPINK);
        mtrScriptsRegisterNumericVariable("X11_PALE_VIOLET_RED",
         MTR_CLR_X11_PALE_VIOLET_RED);
        mtrScriptsRegisterNumericVariable("X11_PALEVIOLETRED",
         MTR_CLR_X11_PALEVIOLETRED);
        mtrScriptsRegisterNumericVariable("X11_MAROON", MTR_CLR_X11_MAROON);
        mtrScriptsRegisterNumericVariable("X11_MEDIUM_VIOLET_RED",
         MTR_CLR_X11_MEDIUM_VIOLET_RED);
        mtrScriptsRegisterNumericVariable("X11_MEDIUMVIOLETRED",
         MTR_CLR_X11_MEDIUMVIOLETRED);
        mtrScriptsRegisterNumericVariable("X11_VIOLET_RED",
         MTR_CLR_X11_VIOLET_RED);
        mtrScriptsRegisterNumericVariable("X11_VIOLETRED",
         MTR_CLR_X11_VIOLETRED);
        mtrScriptsRegisterNumericVariable("X11_MAGENTA", MTR_CLR_X11_MAGENTA);
        mtrScriptsRegisterNumericVariable("X11_VIOLET", MTR_CLR_X11_VIOLET);
        mtrScriptsRegisterNumericVariable("X11_PLUM", MTR_CLR_X11_PLUM);
        mtrScriptsRegisterNumericVariable("X11_ORCHID", MTR_CLR_X11_ORCHID);
        mtrScriptsRegisterNumericVariable("X11_MEDIUM_ORCHID",
         MTR_CLR_X11_MEDIUM_ORCHID);
        mtrScriptsRegisterNumericVariable("X11_MEDIUMORCHID",
         MTR_CLR_X11_MEDIUMORCHID);
        mtrScriptsRegisterNumericVariable("X11_DARK_ORCHID",
         MTR_CLR_X11_DARK_ORCHID);
        mtrScriptsRegisterNumericVariable("X11_DARKORCHID",
         MTR_CLR_X11_DARKORCHID);
        mtrScriptsRegisterNumericVariable("X11_DARK_VIOLET",
         MTR_CLR_X11_DARK_VIOLET);
        mtrScriptsRegisterNumericVariable("X11_DARKVIOLET",
         MTR_CLR_X11_DARKVIOLET);
        mtrScriptsRegisterNumericVariable("X11_BLUE_VIOLET",
         MTR_CLR_X11_BLUE_VIOLET);
        mtrScriptsRegisterNumericVariable("X11_BLUEVIOLET",
         MTR_CLR_X11_BLUEVIOLET);
        mtrScriptsRegisterNumericVariable("X11_PURPLE", MTR_CLR_X11_PURPLE);
        mtrScriptsRegisterNumericVariable("X11_MEDIUM_PURPLE",
         MTR_CLR_X11_MEDIUM_PURPLE);
        mtrScriptsRegisterNumericVariable("X11_MEDIUMPURPLE",
         MTR_CLR_X11_MEDIUMPURPLE);
        mtrScriptsRegisterNumericVariable("X11_THISTLE", MTR_CLR_X11_THISTLE);
        mtrScriptsRegisterNumericVariable("X11_SNOW1", MTR_CLR_X11_SNOW1);
        mtrScriptsRegisterNumericVariable("X11_SNOW2", MTR_CLR_X11_SNOW2);
        mtrScriptsRegisterNumericVariable("X11_SNOW3", MTR_CLR_X11_SNOW3);
        mtrScriptsRegisterNumericVariable("X11_SNOW4", MTR_CLR_X11_SNOW4);
        mtrScriptsRegisterNumericVariable("X11_SEASHELL1",
         MTR_CLR_X11_SEASHELL1);
        mtrScriptsRegisterNumericVariable("X11_SEASHELL2",
         MTR_CLR_X11_SEASHELL2);
        mtrScriptsRegisterNumericVariable("X11_SEASHELL3",
         MTR_CLR_X11_SEASHELL3);
        mtrScriptsRegisterNumericVariable("X11_SEASHELL4",
         MTR_CLR_X11_SEASHELL4);
        mtrScriptsRegisterNumericVariable("X11_ANTIQUEWHITE1",
         MTR_CLR_X11_ANTIQUEWHITE1);
        mtrScriptsRegisterNumericVariable("X11_ANTIQUEWHITE2",
         MTR_CLR_X11_ANTIQUEWHITE2);
        mtrScriptsRegisterNumericVariable("X11_ANTIQUEWHITE3",
         MTR_CLR_X11_ANTIQUEWHITE3);
        mtrScriptsRegisterNumericVariable("X11_ANTIQUEWHITE4",
         MTR_CLR_X11_ANTIQUEWHITE4);
        mtrScriptsRegisterNumericVariable("X11_BISQUE1", MTR_CLR_X11_BISQUE1);
        mtrScriptsRegisterNumericVariable("X11_BISQUE2", MTR_CLR_X11_BISQUE2);
        mtrScriptsRegisterNumericVariable("X11_BISQUE3", MTR_CLR_X11_BISQUE3);
        mtrScriptsRegisterNumericVariable("X11_BISQUE4", MTR_CLR_X11_BISQUE4);
        mtrScriptsRegisterNumericVariable("X11_PEACHPUFF1",
         MTR_CLR_X11_PEACHPUFF1);
        mtrScriptsRegisterNumericVariable("X11_PEACHPUFF2",
         MTR_CLR_X11_PEACHPUFF2);
        mtrScriptsRegisterNumericVariable("X11_PEACHPUFF3",
         MTR_CLR_X11_PEACHPUFF3);
        mtrScriptsRegisterNumericVariable("X11_PEACHPUFF4",
         MTR_CLR_X11_PEACHPUFF4);
        mtrScriptsRegisterNumericVariable("X11_NAVAJOWHITE1",
         MTR_CLR_X11_NAVAJOWHITE1);
        mtrScriptsRegisterNumericVariable("X11_NAVAJOWHITE2",
         MTR_CLR_X11_NAVAJOWHITE2);
        mtrScriptsRegisterNumericVariable("X11_NAVAJOWHITE3",
         MTR_CLR_X11_NAVAJOWHITE3);
        mtrScriptsRegisterNumericVariable("X11_NAVAJOWHITE4",
         MTR_CLR_X11_NAVAJOWHITE4);
        mtrScriptsRegisterNumericVariable("X11_LEMONCHIFFON1",
         MTR_CLR_X11_LEMONCHIFFON1);
        mtrScriptsRegisterNumericVariable("X11_LEMONCHIFFON2",
         MTR_CLR_X11_LEMONCHIFFON2);
        mtrScriptsRegisterNumericVariable("X11_LEMONCHIFFON3",
         MTR_CLR_X11_LEMONCHIFFON3);
        mtrScriptsRegisterNumericVariable("X11_LEMONCHIFFON4",
         MTR_CLR_X11_LEMONCHIFFON4);
        mtrScriptsRegisterNumericVariable("X11_CORNSILK1",
         MTR_CLR_X11_CORNSILK1);
        mtrScriptsRegisterNumericVariable("X11_CORNSILK2",
         MTR_CLR_X11_CORNSILK2);
        mtrScriptsRegisterNumericVariable("X11_CORNSILK3",
         MTR_CLR_X11_CORNSILK3);
        mtrScriptsRegisterNumericVariable("X11_CORNSILK4",
         MTR_CLR_X11_CORNSILK4);
        mtrScriptsRegisterNumericVariable("X11_IVORY1", MTR_CLR_X11_IVORY1);
        mtrScriptsRegisterNumericVariable("X11_IVORY2", MTR_CLR_X11_IVORY2);
        mtrScriptsRegisterNumericVariable("X11_IVORY3", MTR_CLR_X11_IVORY3);
        mtrScriptsRegisterNumericVariable("X11_IVORY4", MTR_CLR_X11_IVORY4);
        mtrScriptsRegisterNumericVariable("X11_HONEYDEW1",
         MTR_CLR_X11_HONEYDEW1);
        mtrScriptsRegisterNumericVariable("X11_HONEYDEW2",
         MTR_CLR_X11_HONEYDEW2);
        mtrScriptsRegisterNumericVariable("X11_HONEYDEW3",
         MTR_CLR_X11_HONEYDEW3);
        mtrScriptsRegisterNumericVariable("X11_HONEYDEW4",
         MTR_CLR_X11_HONEYDEW4);
        mtrScriptsRegisterNumericVariable("X11_LAVENDERBLUSH1",
         MTR_CLR_X11_LAVENDERBLUSH1);
        mtrScriptsRegisterNumericVariable("X11_LAVENDERBLUSH2",
         MTR_CLR_X11_LAVENDERBLUSH2);
        mtrScriptsRegisterNumericVariable("X11_LAVENDERBLUSH3",
         MTR_CLR_X11_LAVENDERBLUSH3);
        mtrScriptsRegisterNumericVariable("X11_LAVENDERBLUSH4",
         MTR_CLR_X11_LAVENDERBLUSH4);
        mtrScriptsRegisterNumericVariable("X11_MISTYROSE1",
         MTR_CLR_X11_MISTYROSE1);
        mtrScriptsRegisterNumericVariable("X11_MISTYROSE2",
         MTR_CLR_X11_MISTYROSE2);
        mtrScriptsRegisterNumericVariable("X11_MISTYROSE3",
         MTR_CLR_X11_MISTYROSE3);
        mtrScriptsRegisterNumericVariable("X11_MISTYROSE4",
         MTR_CLR_X11_MISTYROSE4);
        mtrScriptsRegisterNumericVariable("X11_AZURE1", MTR_CLR_X11_AZURE1);
        mtrScriptsRegisterNumericVariable("X11_AZURE2", MTR_CLR_X11_AZURE2);
        mtrScriptsRegisterNumericVariable("X11_AZURE3", MTR_CLR_X11_AZURE3);
        mtrScriptsRegisterNumericVariable("X11_AZURE4", MTR_CLR_X11_AZURE4);
        mtrScriptsRegisterNumericVariable("X11_SLATEBLUE1",
         MTR_CLR_X11_SLATEBLUE1);
        mtrScriptsRegisterNumericVariable("X11_SLATEBLUE2",
         MTR_CLR_X11_SLATEBLUE2);
        mtrScriptsRegisterNumericVariable("X11_SLATEBLUE3",
         MTR_CLR_X11_SLATEBLUE3);
        mtrScriptsRegisterNumericVariable("X11_SLATEBLUE4",
         MTR_CLR_X11_SLATEBLUE4);
        mtrScriptsRegisterNumericVariable("X11_ROYALBLUE1",
         MTR_CLR_X11_ROYALBLUE1);
        mtrScriptsRegisterNumericVariable("X11_ROYALBLUE2",
         MTR_CLR_X11_ROYALBLUE2);
        mtrScriptsRegisterNumericVariable("X11_ROYALBLUE3",
         MTR_CLR_X11_ROYALBLUE3);
        mtrScriptsRegisterNumericVariable("X11_ROYALBLUE4",
         MTR_CLR_X11_ROYALBLUE4);
        mtrScriptsRegisterNumericVariable("X11_BLUE1", MTR_CLR_X11_BLUE1);
        mtrScriptsRegisterNumericVariable("X11_BLUE2", MTR_CLR_X11_BLUE2);
        mtrScriptsRegisterNumericVariable("X11_BLUE3", MTR_CLR_X11_BLUE3);
        mtrScriptsRegisterNumericVariable("X11_BLUE4", MTR_CLR_X11_BLUE4);
        mtrScriptsRegisterNumericVariable("X11_DODGERBLUE1",
         MTR_CLR_X11_DODGERBLUE1);
        mtrScriptsRegisterNumericVariable("X11_DODGERBLUE2",
         MTR_CLR_X11_DODGERBLUE2);
        mtrScriptsRegisterNumericVariable("X11_DODGERBLUE3",
         MTR_CLR_X11_DODGERBLUE3);
        mtrScriptsRegisterNumericVariable("X11_DODGERBLUE4",
         MTR_CLR_X11_DODGERBLUE4);
        mtrScriptsRegisterNumericVariable("X11_STEELBLUE1",
         MTR_CLR_X11_STEELBLUE1);
        mtrScriptsRegisterNumericVariable("X11_STEELBLUE2",
         MTR_CLR_X11_STEELBLUE2);
        mtrScriptsRegisterNumericVariable("X11_STEELBLUE3",
         MTR_CLR_X11_STEELBLUE3);
        mtrScriptsRegisterNumericVariable("X11_STEELBLUE4",
         MTR_CLR_X11_STEELBLUE4);
        mtrScriptsRegisterNumericVariable("X11_DEEPSKYBLUE1",
         MTR_CLR_X11_DEEPSKYBLUE1);
        mtrScriptsRegisterNumericVariable("X11_DEEPSKYBLUE2",
         MTR_CLR_X11_DEEPSKYBLUE2);
        mtrScriptsRegisterNumericVariable("X11_DEEPSKYBLUE3",
         MTR_CLR_X11_DEEPSKYBLUE3);
        mtrScriptsRegisterNumericVariable("X11_DEEPSKYBLUE4",
         MTR_CLR_X11_DEEPSKYBLUE4);
        mtrScriptsRegisterNumericVariable("X11_SKYBLUE1", MTR_CLR_X11_SKYBLUE1);
        mtrScriptsRegisterNumericVariable("X11_SKYBLUE2", MTR_CLR_X11_SKYBLUE2);
        mtrScriptsRegisterNumericVariable("X11_SKYBLUE3", MTR_CLR_X11_SKYBLUE3);
        mtrScriptsRegisterNumericVariable("X11_SKYBLUE4", MTR_CLR_X11_SKYBLUE4);
        mtrScriptsRegisterNumericVariable("X11_LIGHTSKYBLUE1",
         MTR_CLR_X11_LIGHTSKYBLUE1);
        mtrScriptsRegisterNumericVariable("X11_LIGHTSKYBLUE2",
         MTR_CLR_X11_LIGHTSKYBLUE2);
        mtrScriptsRegisterNumericVariable("X11_LIGHTSKYBLUE3",
         MTR_CLR_X11_LIGHTSKYBLUE3);
        mtrScriptsRegisterNumericVariable("X11_LIGHTSKYBLUE4",
         MTR_CLR_X11_LIGHTSKYBLUE4);
        mtrScriptsRegisterNumericVariable("X11_SLATEGRAY1",
         MTR_CLR_X11_SLATEGRAY1);
        mtrScriptsRegisterNumericVariable("X11_SLATEGRAY2",
         MTR_CLR_X11_SLATEGRAY2);
        mtrScriptsRegisterNumericVariable("X11_SLATEGRAY3",
         MTR_CLR_X11_SLATEGRAY3);
        mtrScriptsRegisterNumericVariable("X11_SLATEGRAY4",
         MTR_CLR_X11_SLATEGRAY4);
        mtrScriptsRegisterNumericVariable("X11_LIGHTSTEELBLUE1",
         MTR_CLR_X11_LIGHTSTEELBLUE1);
        mtrScriptsRegisterNumericVariable("X11_LIGHTSTEELBLUE2",
         MTR_CLR_X11_LIGHTSTEELBLUE2);
        mtrScriptsRegisterNumericVariable("X11_LIGHTSTEELBLUE3",
         MTR_CLR_X11_LIGHTSTEELBLUE3);
        mtrScriptsRegisterNumericVariable("X11_LIGHTSTEELBLUE4",
         MTR_CLR_X11_LIGHTSTEELBLUE4);
        mtrScriptsRegisterNumericVariable("X11_LIGHTBLUE1",
         MTR_CLR_X11_LIGHTBLUE1);
        mtrScriptsRegisterNumericVariable("X11_LIGHTBLUE2",
         MTR_CLR_X11_LIGHTBLUE2);
        mtrScriptsRegisterNumericVariable("X11_LIGHTBLUE3",
         MTR_CLR_X11_LIGHTBLUE3);
        mtrScriptsRegisterNumericVariable("X11_LIGHTBLUE4",
         MTR_CLR_X11_LIGHTBLUE4);
        mtrScriptsRegisterNumericVariable("X11_LIGHTCYAN1",
         MTR_CLR_X11_LIGHTCYAN1);
        mtrScriptsRegisterNumericVariable("X11_LIGHTCYAN2",
         MTR_CLR_X11_LIGHTCYAN2);
        mtrScriptsRegisterNumericVariable("X11_LIGHTCYAN3",
         MTR_CLR_X11_LIGHTCYAN3);
        mtrScriptsRegisterNumericVariable("X11_LIGHTCYAN4",
         MTR_CLR_X11_LIGHTCYAN4);
        mtrScriptsRegisterNumericVariable("X11_PALETURQUOISE1",
         MTR_CLR_X11_PALETURQUOISE1);
        mtrScriptsRegisterNumericVariable("X11_PALETURQUOISE2",
         MTR_CLR_X11_PALETURQUOISE2);
        mtrScriptsRegisterNumericVariable("X11_PALETURQUOISE3",
         MTR_CLR_X11_PALETURQUOISE3);
        mtrScriptsRegisterNumericVariable("X11_PALETURQUOISE4",
         MTR_CLR_X11_PALETURQUOISE4);
        mtrScriptsRegisterNumericVariable("X11_CADETBLUE1",
         MTR_CLR_X11_CADETBLUE1);
        mtrScriptsRegisterNumericVariable("X11_CADETBLUE2",
         MTR_CLR_X11_CADETBLUE2);
        mtrScriptsRegisterNumericVariable("X11_CADETBLUE3",
         MTR_CLR_X11_CADETBLUE3);
        mtrScriptsRegisterNumericVariable("X11_CADETBLUE4",
         MTR_CLR_X11_CADETBLUE4);
        mtrScriptsRegisterNumericVariable("X11_TURQUOISE1",
         MTR_CLR_X11_TURQUOISE1);
        mtrScriptsRegisterNumericVariable("X11_TURQUOISE2",
         MTR_CLR_X11_TURQUOISE2);
        mtrScriptsRegisterNumericVariable("X11_TURQUOISE3",
         MTR_CLR_X11_TURQUOISE3);
        mtrScriptsRegisterNumericVariable("X11_TURQUOISE4",
         MTR_CLR_X11_TURQUOISE4);
        mtrScriptsRegisterNumericVariable("X11_CYAN1", MTR_CLR_X11_CYAN1);
        mtrScriptsRegisterNumericVariable("X11_CYAN2", MTR_CLR_X11_CYAN2);
        mtrScriptsRegisterNumericVariable("X11_CYAN3", MTR_CLR_X11_CYAN3);
        mtrScriptsRegisterNumericVariable("X11_CYAN4", MTR_CLR_X11_CYAN4);
        mtrScriptsRegisterNumericVariable("X11_DARKSLATEGRAY1",
         MTR_CLR_X11_DARKSLATEGRAY1);
        mtrScriptsRegisterNumericVariable("X11_DARKSLATEGRAY2",
         MTR_CLR_X11_DARKSLATEGRAY2);
        mtrScriptsRegisterNumericVariable("X11_DARKSLATEGRAY3",
         MTR_CLR_X11_DARKSLATEGRAY3);
        mtrScriptsRegisterNumericVariable("X11_DARKSLATEGRAY4",
         MTR_CLR_X11_DARKSLATEGRAY4);
        mtrScriptsRegisterNumericVariable("X11_AQUAMARINE1",
         MTR_CLR_X11_AQUAMARINE1);
        mtrScriptsRegisterNumericVariable("X11_AQUAMARINE2",
         MTR_CLR_X11_AQUAMARINE2);
        mtrScriptsRegisterNumericVariable("X11_AQUAMARINE3",
         MTR_CLR_X11_AQUAMARINE3);
        mtrScriptsRegisterNumericVariable("X11_AQUAMARINE4",
         MTR_CLR_X11_AQUAMARINE4);
        mtrScriptsRegisterNumericVariable("X11_DARKSEAGREEN1",
         MTR_CLR_X11_DARKSEAGREEN1);
        mtrScriptsRegisterNumericVariable("X11_DARKSEAGREEN2",
         MTR_CLR_X11_DARKSEAGREEN2);
        mtrScriptsRegisterNumericVariable("X11_DARKSEAGREEN3",
         MTR_CLR_X11_DARKSEAGREEN3);
        mtrScriptsRegisterNumericVariable("X11_DARKSEAGREEN4",
         MTR_CLR_X11_DARKSEAGREEN4);
        mtrScriptsRegisterNumericVariable("X11_SEAGREEN1",
         MTR_CLR_X11_SEAGREEN1);
        mtrScriptsRegisterNumericVariable("X11_SEAGREEN2",
         MTR_CLR_X11_SEAGREEN2);
        mtrScriptsRegisterNumericVariable("X11_SEAGREEN3",
         MTR_CLR_X11_SEAGREEN3);
        mtrScriptsRegisterNumericVariable("X11_SEAGREEN4",
         MTR_CLR_X11_SEAGREEN4);
        mtrScriptsRegisterNumericVariable("X11_PALEGREEN1",
         MTR_CLR_X11_PALEGREEN1);
        mtrScriptsRegisterNumericVariable("X11_PALEGREEN2",
         MTR_CLR_X11_PALEGREEN2);
        mtrScriptsRegisterNumericVariable("X11_PALEGREEN3",
         MTR_CLR_X11_PALEGREEN3);
        mtrScriptsRegisterNumericVariable("X11_PALEGREEN4",
         MTR_CLR_X11_PALEGREEN4);
        mtrScriptsRegisterNumericVariable("X11_SPRINGGREEN1",
         MTR_CLR_X11_SPRINGGREEN1);
        mtrScriptsRegisterNumericVariable("X11_SPRINGGREEN2",
         MTR_CLR_X11_SPRINGGREEN2);
        mtrScriptsRegisterNumericVariable("X11_SPRINGGREEN3",
         MTR_CLR_X11_SPRINGGREEN3);
        mtrScriptsRegisterNumericVariable("X11_SPRINGGREEN4",
         MTR_CLR_X11_SPRINGGREEN4);
        mtrScriptsRegisterNumericVariable("X11_GREEN1", MTR_CLR_X11_GREEN1);
        mtrScriptsRegisterNumericVariable("X11_GREEN2", MTR_CLR_X11_GREEN2);
        mtrScriptsRegisterNumericVariable("X11_GREEN3", MTR_CLR_X11_GREEN3);
        mtrScriptsRegisterNumericVariable("X11_GREEN4", MTR_CLR_X11_GREEN4);
        mtrScriptsRegisterNumericVariable("X11_CHARTREUSE1",
         MTR_CLR_X11_CHARTREUSE1);
        mtrScriptsRegisterNumericVariable("X11_CHARTREUSE2",
         MTR_CLR_X11_CHARTREUSE2);
        mtrScriptsRegisterNumericVariable("X11_CHARTREUSE3",
         MTR_CLR_X11_CHARTREUSE3);
        mtrScriptsRegisterNumericVariable("X11_CHARTREUSE4",
         MTR_CLR_X11_CHARTREUSE4);
        mtrScriptsRegisterNumericVariable("X11_OLIVEDRAB1",
         MTR_CLR_X11_OLIVEDRAB1);
        mtrScriptsRegisterNumericVariable("X11_OLIVEDRAB2",
         MTR_CLR_X11_OLIVEDRAB2);
        mtrScriptsRegisterNumericVariable("X11_OLIVEDRAB3",
         MTR_CLR_X11_OLIVEDRAB3);
        mtrScriptsRegisterNumericVariable("X11_OLIVEDRAB4",
         MTR_CLR_X11_OLIVEDRAB4);
        mtrScriptsRegisterNumericVariable("X11_DARKOLIVEGREEN1",
         MTR_CLR_X11_DARKOLIVEGREEN1);
        mtrScriptsRegisterNumericVariable("X11_DARKOLIVEGREEN2",
         MTR_CLR_X11_DARKOLIVEGREEN2);
        mtrScriptsRegisterNumericVariable("X11_DARKOLIVEGREEN3",
         MTR_CLR_X11_DARKOLIVEGREEN3);
        mtrScriptsRegisterNumericVariable("X11_DARKOLIVEGREEN4",
         MTR_CLR_X11_DARKOLIVEGREEN4);
        mtrScriptsRegisterNumericVariable("X11_KHAKI1", MTR_CLR_X11_KHAKI1);
        mtrScriptsRegisterNumericVariable("X11_KHAKI2", MTR_CLR_X11_KHAKI2);
        mtrScriptsRegisterNumericVariable("X11_KHAKI3", MTR_CLR_X11_KHAKI3);
        mtrScriptsRegisterNumericVariable("X11_KHAKI4", MTR_CLR_X11_KHAKI4);
        mtrScriptsRegisterNumericVariable("X11_LIGHTGOLDENROD1",
         MTR_CLR_X11_LIGHTGOLDENROD1);
        mtrScriptsRegisterNumericVariable("X11_LIGHTGOLDENROD2",
         MTR_CLR_X11_LIGHTGOLDENROD2);
        mtrScriptsRegisterNumericVariable("X11_LIGHTGOLDENROD3",
         MTR_CLR_X11_LIGHTGOLDENROD3);
        mtrScriptsRegisterNumericVariable("X11_LIGHTGOLDENROD4",
         MTR_CLR_X11_LIGHTGOLDENROD4);
        mtrScriptsRegisterNumericVariable("X11_LIGHTYELLOW1",
         MTR_CLR_X11_LIGHTYELLOW1);
        mtrScriptsRegisterNumericVariable("X11_LIGHTYELLOW2",
         MTR_CLR_X11_LIGHTYELLOW2);
        mtrScriptsRegisterNumericVariable("X11_LIGHTYELLOW3",
         MTR_CLR_X11_LIGHTYELLOW3);
        mtrScriptsRegisterNumericVariable("X11_LIGHTYELLOW4",
         MTR_CLR_X11_LIGHTYELLOW4);
        mtrScriptsRegisterNumericVariable("X11_YELLOW1", MTR_CLR_X11_YELLOW1);
        mtrScriptsRegisterNumericVariable("X11_YELLOW2", MTR_CLR_X11_YELLOW2);
        mtrScriptsRegisterNumericVariable("X11_YELLOW3", MTR_CLR_X11_YELLOW3);
        mtrScriptsRegisterNumericVariable("X11_YELLOW4", MTR_CLR_X11_YELLOW4);
        mtrScriptsRegisterNumericVariable("X11_GOLD1", MTR_CLR_X11_GOLD1);
        mtrScriptsRegisterNumericVariable("X11_GOLD2", MTR_CLR_X11_GOLD2);
        mtrScriptsRegisterNumericVariable("X11_GOLD3", MTR_CLR_X11_GOLD3);
        mtrScriptsRegisterNumericVariable("X11_GOLD4", MTR_CLR_X11_GOLD4);
        mtrScriptsRegisterNumericVariable("X11_GOLDENROD1",
         MTR_CLR_X11_GOLDENROD1);
        mtrScriptsRegisterNumericVariable("X11_GOLDENROD2",
         MTR_CLR_X11_GOLDENROD2);
        mtrScriptsRegisterNumericVariable("X11_GOLDENROD3",
         MTR_CLR_X11_GOLDENROD3);
        mtrScriptsRegisterNumericVariable("X11_GOLDENROD4",
         MTR_CLR_X11_GOLDENROD4);
        mtrScriptsRegisterNumericVariable("X11_DARKGOLDENROD1",
         MTR_CLR_X11_DARKGOLDENROD1);
        mtrScriptsRegisterNumericVariable("X11_DARKGOLDENROD2",
         MTR_CLR_X11_DARKGOLDENROD2);
        mtrScriptsRegisterNumericVariable("X11_DARKGOLDENROD3",
         MTR_CLR_X11_DARKGOLDENROD3);
        mtrScriptsRegisterNumericVariable("X11_DARKGOLDENROD4",
         MTR_CLR_X11_DARKGOLDENROD4);
        mtrScriptsRegisterNumericVariable("X11_ROSYBROWN1",
         MTR_CLR_X11_ROSYBROWN1);
        mtrScriptsRegisterNumericVariable("X11_ROSYBROWN2",
         MTR_CLR_X11_ROSYBROWN2);
        mtrScriptsRegisterNumericVariable("X11_ROSYBROWN3",
         MTR_CLR_X11_ROSYBROWN3);
        mtrScriptsRegisterNumericVariable("X11_ROSYBROWN4",
         MTR_CLR_X11_ROSYBROWN4);
        mtrScriptsRegisterNumericVariable("X11_INDIANRED1",
         MTR_CLR_X11_INDIANRED1);
        mtrScriptsRegisterNumericVariable("X11_INDIANRED2",
         MTR_CLR_X11_INDIANRED2);
        mtrScriptsRegisterNumericVariable("X11_INDIANRED3",
         MTR_CLR_X11_INDIANRED3);
        mtrScriptsRegisterNumericVariable("X11_INDIANRED4",
         MTR_CLR_X11_INDIANRED4);
        mtrScriptsRegisterNumericVariable("X11_SIENNA1", MTR_CLR_X11_SIENNA1);
        mtrScriptsRegisterNumericVariable("X11_SIENNA2", MTR_CLR_X11_SIENNA2);
        mtrScriptsRegisterNumericVariable("X11_SIENNA3", MTR_CLR_X11_SIENNA3);
        mtrScriptsRegisterNumericVariable("X11_SIENNA4", MTR_CLR_X11_SIENNA4);
        mtrScriptsRegisterNumericVariable("X11_BURLYWOOD1",
         MTR_CLR_X11_BURLYWOOD1);
        mtrScriptsRegisterNumericVariable("X11_BURLYWOOD2",
         MTR_CLR_X11_BURLYWOOD2);
        mtrScriptsRegisterNumericVariable("X11_BURLYWOOD3",
         MTR_CLR_X11_BURLYWOOD3);
        mtrScriptsRegisterNumericVariable("X11_BURLYWOOD4",
         MTR_CLR_X11_BURLYWOOD4);
        mtrScriptsRegisterNumericVariable("X11_WHEAT1", MTR_CLR_X11_WHEAT1);
        mtrScriptsRegisterNumericVariable("X11_WHEAT2", MTR_CLR_X11_WHEAT2);
        mtrScriptsRegisterNumericVariable("X11_WHEAT3", MTR_CLR_X11_WHEAT3);
        mtrScriptsRegisterNumericVariable("X11_WHEAT4", MTR_CLR_X11_WHEAT4);
        mtrScriptsRegisterNumericVariable("X11_TAN1", MTR_CLR_X11_TAN1);
        mtrScriptsRegisterNumericVariable("X11_TAN2", MTR_CLR_X11_TAN2);
        mtrScriptsRegisterNumericVariable("X11_TAN3", MTR_CLR_X11_TAN3);
        mtrScriptsRegisterNumericVariable("X11_TAN4", MTR_CLR_X11_TAN4);
        mtrScriptsRegisterNumericVariable("X11_CHOCOLATE1",
         MTR_CLR_X11_CHOCOLATE1);
        mtrScriptsRegisterNumericVariable("X11_CHOCOLATE2",
         MTR_CLR_X11_CHOCOLATE2);
        mtrScriptsRegisterNumericVariable("X11_CHOCOLATE3",
         MTR_CLR_X11_CHOCOLATE3);
        mtrScriptsRegisterNumericVariable("X11_CHOCOLATE4",
         MTR_CLR_X11_CHOCOLATE4);
        mtrScriptsRegisterNumericVariable("X11_FIREBRICK1",
         MTR_CLR_X11_FIREBRICK1);
        mtrScriptsRegisterNumericVariable("X11_FIREBRICK2",
         MTR_CLR_X11_FIREBRICK2);
        mtrScriptsRegisterNumericVariable("X11_FIREBRICK3",
         MTR_CLR_X11_FIREBRICK3);
        mtrScriptsRegisterNumericVariable("X11_FIREBRICK4",
         MTR_CLR_X11_FIREBRICK4);
        mtrScriptsRegisterNumericVariable("X11_BROWN1", MTR_CLR_X11_BROWN1);
        mtrScriptsRegisterNumericVariable("X11_BROWN2", MTR_CLR_X11_BROWN2);
        mtrScriptsRegisterNumericVariable("X11_BROWN3", MTR_CLR_X11_BROWN3);
        mtrScriptsRegisterNumericVariable("X11_BROWN4", MTR_CLR_X11_BROWN4);
        mtrScriptsRegisterNumericVariable("X11_SALMON1", MTR_CLR_X11_SALMON1);
        mtrScriptsRegisterNumericVariable("X11_SALMON2", MTR_CLR_X11_SALMON2);
        mtrScriptsRegisterNumericVariable("X11_SALMON3", MTR_CLR_X11_SALMON3);
        mtrScriptsRegisterNumericVariable("X11_SALMON4", MTR_CLR_X11_SALMON4);
        mtrScriptsRegisterNumericVariable("X11_LIGHTSALMON1",
         MTR_CLR_X11_LIGHTSALMON1);
        mtrScriptsRegisterNumericVariable("X11_LIGHTSALMON2",
         MTR_CLR_X11_LIGHTSALMON2);
        mtrScriptsRegisterNumericVariable("X11_LIGHTSALMON3",
         MTR_CLR_X11_LIGHTSALMON3);
        mtrScriptsRegisterNumericVariable("X11_LIGHTSALMON4",
         MTR_CLR_X11_LIGHTSALMON4);
        mtrScriptsRegisterNumericVariable("X11_ORANGE1", MTR_CLR_X11_ORANGE1);
        mtrScriptsRegisterNumericVariable("X11_ORANGE2", MTR_CLR_X11_ORANGE2);
        mtrScriptsRegisterNumericVariable("X11_ORANGE3", MTR_CLR_X11_ORANGE3);
        mtrScriptsRegisterNumericVariable("X11_ORANGE4", MTR_CLR_X11_ORANGE4);
        mtrScriptsRegisterNumericVariable("X11_DARKORANGE1",
         MTR_CLR_X11_DARKORANGE1);
        mtrScriptsRegisterNumericVariable("X11_DARKORANGE2",
         MTR_CLR_X11_DARKORANGE2);
        mtrScriptsRegisterNumericVariable("X11_DARKORANGE3",
         MTR_CLR_X11_DARKORANGE3);
        mtrScriptsRegisterNumericVariable("X11_DARKORANGE4",
         MTR_CLR_X11_DARKORANGE4);
        mtrScriptsRegisterNumericVariable("X11_CORAL1", MTR_CLR_X11_CORAL1);
        mtrScriptsRegisterNumericVariable("X11_CORAL2", MTR_CLR_X11_CORAL2);
        mtrScriptsRegisterNumericVariable("X11_CORAL3", MTR_CLR_X11_CORAL3);
        mtrScriptsRegisterNumericVariable("X11_CORAL4", MTR_CLR_X11_CORAL4);
        mtrScriptsRegisterNumericVariable("X11_TOMATO1", MTR_CLR_X11_TOMATO1);
        mtrScriptsRegisterNumericVariable("X11_TOMATO2", MTR_CLR_X11_TOMATO2);
        mtrScriptsRegisterNumericVariable("X11_TOMATO3", MTR_CLR_X11_TOMATO3);
        mtrScriptsRegisterNumericVariable("X11_TOMATO4", MTR_CLR_X11_TOMATO4);
        mtrScriptsRegisterNumericVariable("X11_ORANGERED1",
         MTR_CLR_X11_ORANGERED1);
        mtrScriptsRegisterNumericVariable("X11_ORANGERED2",
         MTR_CLR_X11_ORANGERED2);
        mtrScriptsRegisterNumericVariable("X11_ORANGERED3",
         MTR_CLR_X11_ORANGERED3);
        mtrScriptsRegisterNumericVariable("X11_ORANGERED4",
         MTR_CLR_X11_ORANGERED4);
        mtrScriptsRegisterNumericVariable("X11_RED1", MTR_CLR_X11_RED1);
        mtrScriptsRegisterNumericVariable("X11_RED2", MTR_CLR_X11_RED2);
        mtrScriptsRegisterNumericVariable("X11_RED3", MTR_CLR_X11_RED3);
        mtrScriptsRegisterNumericVariable("X11_RED4", MTR_CLR_X11_RED4);
        mtrScriptsRegisterNumericVariable("X11_DEEPPINK1",
         MTR_CLR_X11_DEEPPINK1);
        mtrScriptsRegisterNumericVariable("X11_DEEPPINK2",
         MTR_CLR_X11_DEEPPINK2);
        mtrScriptsRegisterNumericVariable("X11_DEEPPINK3",
         MTR_CLR_X11_DEEPPINK3);
        mtrScriptsRegisterNumericVariable("X11_DEEPPINK4",
         MTR_CLR_X11_DEEPPINK4);
        mtrScriptsRegisterNumericVariable("X11_HOTPINK1", MTR_CLR_X11_HOTPINK1);
        mtrScriptsRegisterNumericVariable("X11_HOTPINK2", MTR_CLR_X11_HOTPINK2);
        mtrScriptsRegisterNumericVariable("X11_HOTPINK3", MTR_CLR_X11_HOTPINK3);
        mtrScriptsRegisterNumericVariable("X11_HOTPINK4", MTR_CLR_X11_HOTPINK4);
        mtrScriptsRegisterNumericVariable("X11_PINK1", MTR_CLR_X11_PINK1);
        mtrScriptsRegisterNumericVariable("X11_PINK2", MTR_CLR_X11_PINK2);
        mtrScriptsRegisterNumericVariable("X11_PINK3", MTR_CLR_X11_PINK3);
        mtrScriptsRegisterNumericVariable("X11_PINK4", MTR_CLR_X11_PINK4);
        mtrScriptsRegisterNumericVariable("X11_LIGHTPINK1",
         MTR_CLR_X11_LIGHTPINK1);
        mtrScriptsRegisterNumericVariable("X11_LIGHTPINK2",
         MTR_CLR_X11_LIGHTPINK2);
        mtrScriptsRegisterNumericVariable("X11_LIGHTPINK3",
         MTR_CLR_X11_LIGHTPINK3);
        mtrScriptsRegisterNumericVariable("X11_LIGHTPINK4",
         MTR_CLR_X11_LIGHTPINK4);
        mtrScriptsRegisterNumericVariable("X11_PALEVIOLETRED1",
         MTR_CLR_X11_PALEVIOLETRED1);
        mtrScriptsRegisterNumericVariable("X11_PALEVIOLETRED2",
         MTR_CLR_X11_PALEVIOLETRED2);
        mtrScriptsRegisterNumericVariable("X11_PALEVIOLETRED3",
         MTR_CLR_X11_PALEVIOLETRED3);
        mtrScriptsRegisterNumericVariable("X11_PALEVIOLETRED4",
         MTR_CLR_X11_PALEVIOLETRED4);
        mtrScriptsRegisterNumericVariable("X11_MAROON1", MTR_CLR_X11_MAROON1);
        mtrScriptsRegisterNumericVariable("X11_MAROON2", MTR_CLR_X11_MAROON2);
        mtrScriptsRegisterNumericVariable("X11_MAROON3", MTR_CLR_X11_MAROON3);
        mtrScriptsRegisterNumericVariable("X11_MAROON4", MTR_CLR_X11_MAROON4);
        mtrScriptsRegisterNumericVariable("X11_VIOLETRED1",
         MTR_CLR_X11_VIOLETRED1);
        mtrScriptsRegisterNumericVariable("X11_VIOLETRED2",
         MTR_CLR_X11_VIOLETRED2);
        mtrScriptsRegisterNumericVariable("X11_VIOLETRED3",
         MTR_CLR_X11_VIOLETRED3);
        mtrScriptsRegisterNumericVariable("X11_VIOLETRED4",
         MTR_CLR_X11_VIOLETRED4);
        mtrScriptsRegisterNumericVariable("X11_MAGENTA1", MTR_CLR_X11_MAGENTA1);
        mtrScriptsRegisterNumericVariable("X11_MAGENTA2", MTR_CLR_X11_MAGENTA2);
        mtrScriptsRegisterNumericVariable("X11_MAGENTA3", MTR_CLR_X11_MAGENTA3);
        mtrScriptsRegisterNumericVariable("X11_MAGENTA4", MTR_CLR_X11_MAGENTA4);
        mtrScriptsRegisterNumericVariable("X11_ORCHID1", MTR_CLR_X11_ORCHID1);
        mtrScriptsRegisterNumericVariable("X11_ORCHID2", MTR_CLR_X11_ORCHID2);
        mtrScriptsRegisterNumericVariable("X11_ORCHID3", MTR_CLR_X11_ORCHID3);
        mtrScriptsRegisterNumericVariable("X11_ORCHID4", MTR_CLR_X11_ORCHID4);
        mtrScriptsRegisterNumericVariable("X11_PLUM1", MTR_CLR_X11_PLUM1);
        mtrScriptsRegisterNumericVariable("X11_PLUM2", MTR_CLR_X11_PLUM2);
        mtrScriptsRegisterNumericVariable("X11_PLUM3", MTR_CLR_X11_PLUM3);
        mtrScriptsRegisterNumericVariable("X11_PLUM4", MTR_CLR_X11_PLUM4);
        mtrScriptsRegisterNumericVariable("X11_MEDIUMORCHID1",
         MTR_CLR_X11_MEDIUMORCHID1);
        mtrScriptsRegisterNumericVariable("X11_MEDIUMORCHID2",
         MTR_CLR_X11_MEDIUMORCHID2);
        mtrScriptsRegisterNumericVariable("X11_MEDIUMORCHID3",
         MTR_CLR_X11_MEDIUMORCHID3);
        mtrScriptsRegisterNumericVariable("X11_MEDIUMORCHID4",
         MTR_CLR_X11_MEDIUMORCHID4);
        mtrScriptsRegisterNumericVariable("X11_DARKORCHID1",
         MTR_CLR_X11_DARKORCHID1);
        mtrScriptsRegisterNumericVariable("X11_DARKORCHID2",
         MTR_CLR_X11_DARKORCHID2);
        mtrScriptsRegisterNumericVariable("X11_DARKORCHID3",
         MTR_CLR_X11_DARKORCHID3);
        mtrScriptsRegisterNumericVariable("X11_DARKORCHID4",
         MTR_CLR_X11_DARKORCHID4);
        mtrScriptsRegisterNumericVariable("X11_PURPLE1", MTR_CLR_X11_PURPLE1);
        mtrScriptsRegisterNumericVariable("X11_PURPLE2", MTR_CLR_X11_PURPLE2);
        mtrScriptsRegisterNumericVariable("X11_PURPLE3", MTR_CLR_X11_PURPLE3);
        mtrScriptsRegisterNumericVariable("X11_PURPLE4", MTR_CLR_X11_PURPLE4);
        mtrScriptsRegisterNumericVariable("X11_MEDIUMPURPLE1",
         MTR_CLR_X11_MEDIUMPURPLE1);
        mtrScriptsRegisterNumericVariable("X11_MEDIUMPURPLE2",
         MTR_CLR_X11_MEDIUMPURPLE2);
        mtrScriptsRegisterNumericVariable("X11_MEDIUMPURPLE3",
         MTR_CLR_X11_MEDIUMPURPLE3);
        mtrScriptsRegisterNumericVariable("X11_MEDIUMPURPLE4",
         MTR_CLR_X11_MEDIUMPURPLE4);
        mtrScriptsRegisterNumericVariable("X11_THISTLE1", MTR_CLR_X11_THISTLE1);
        mtrScriptsRegisterNumericVariable("X11_THISTLE2", MTR_CLR_X11_THISTLE2);
        mtrScriptsRegisterNumericVariable("X11_THISTLE3", MTR_CLR_X11_THISTLE3);
        mtrScriptsRegisterNumericVariable("X11_THISTLE4", MTR_CLR_X11_THISTLE4);
        mtrScriptsRegisterNumericVariable("X11_GRAY0", MTR_CLR_X11_GRAY0);
        mtrScriptsRegisterNumericVariable("X11_GREY0", MTR_CLR_X11_GREY0);
        mtrScriptsRegisterNumericVariable("X11_GRAY1", MTR_CLR_X11_GRAY1);
        mtrScriptsRegisterNumericVariable("X11_GREY1", MTR_CLR_X11_GREY1);
        mtrScriptsRegisterNumericVariable("X11_GRAY2", MTR_CLR_X11_GRAY2);
        mtrScriptsRegisterNumericVariable("X11_GREY2", MTR_CLR_X11_GREY2);
        mtrScriptsRegisterNumericVariable("X11_GRAY3", MTR_CLR_X11_GRAY3);
        mtrScriptsRegisterNumericVariable("X11_GREY3", MTR_CLR_X11_GREY3);
        mtrScriptsRegisterNumericVariable("X11_GRAY4", MTR_CLR_X11_GRAY4);
        mtrScriptsRegisterNumericVariable("X11_GREY4", MTR_CLR_X11_GREY4);
        mtrScriptsRegisterNumericVariable("X11_GRAY5", MTR_CLR_X11_GRAY5);
        mtrScriptsRegisterNumericVariable("X11_GREY5", MTR_CLR_X11_GREY5);
        mtrScriptsRegisterNumericVariable("X11_GRAY6", MTR_CLR_X11_GRAY6);
        mtrScriptsRegisterNumericVariable("X11_GREY6", MTR_CLR_X11_GREY6);
        mtrScriptsRegisterNumericVariable("X11_GRAY7", MTR_CLR_X11_GRAY7);
        mtrScriptsRegisterNumericVariable("X11_GREY7", MTR_CLR_X11_GREY7);
        mtrScriptsRegisterNumericVariable("X11_GRAY8", MTR_CLR_X11_GRAY8);
        mtrScriptsRegisterNumericVariable("X11_GREY8", MTR_CLR_X11_GREY8);
        mtrScriptsRegisterNumericVariable("X11_GRAY9", MTR_CLR_X11_GRAY9);
        mtrScriptsRegisterNumericVariable("X11_GREY9", MTR_CLR_X11_GREY9);
        mtrScriptsRegisterNumericVariable("X11_GRAY10", MTR_CLR_X11_GRAY10);
        mtrScriptsRegisterNumericVariable("X11_GREY10", MTR_CLR_X11_GREY10);
        mtrScriptsRegisterNumericVariable("X11_GRAY11", MTR_CLR_X11_GRAY11);
        mtrScriptsRegisterNumericVariable("X11_GREY11", MTR_CLR_X11_GREY11);
        mtrScriptsRegisterNumericVariable("X11_GRAY12", MTR_CLR_X11_GRAY12);
        mtrScriptsRegisterNumericVariable("X11_GREY12", MTR_CLR_X11_GREY12);
        mtrScriptsRegisterNumericVariable("X11_GRAY13", MTR_CLR_X11_GRAY13);
        mtrScriptsRegisterNumericVariable("X11_GREY13", MTR_CLR_X11_GREY13);
        mtrScriptsRegisterNumericVariable("X11_GRAY14", MTR_CLR_X11_GRAY14);
        mtrScriptsRegisterNumericVariable("X11_GREY14", MTR_CLR_X11_GREY14);
        mtrScriptsRegisterNumericVariable("X11_GRAY15", MTR_CLR_X11_GRAY15);
        mtrScriptsRegisterNumericVariable("X11_GREY15", MTR_CLR_X11_GREY15);
        mtrScriptsRegisterNumericVariable("X11_GRAY16", MTR_CLR_X11_GRAY16);
        mtrScriptsRegisterNumericVariable("X11_GREY16", MTR_CLR_X11_GREY16);
        mtrScriptsRegisterNumericVariable("X11_GRAY17", MTR_CLR_X11_GRAY17);
        mtrScriptsRegisterNumericVariable("X11_GREY17", MTR_CLR_X11_GREY17);
        mtrScriptsRegisterNumericVariable("X11_GRAY18", MTR_CLR_X11_GRAY18);
        mtrScriptsRegisterNumericVariable("X11_GREY18", MTR_CLR_X11_GREY18);
        mtrScriptsRegisterNumericVariable("X11_GRAY19", MTR_CLR_X11_GRAY19);
        mtrScriptsRegisterNumericVariable("X11_GREY19", MTR_CLR_X11_GREY19);
        mtrScriptsRegisterNumericVariable("X11_GRAY20", MTR_CLR_X11_GRAY20);
        mtrScriptsRegisterNumericVariable("X11_GREY20", MTR_CLR_X11_GREY20);
        mtrScriptsRegisterNumericVariable("X11_GRAY21", MTR_CLR_X11_GRAY21);
        mtrScriptsRegisterNumericVariable("X11_GREY21", MTR_CLR_X11_GREY21);
        mtrScriptsRegisterNumericVariable("X11_GRAY22", MTR_CLR_X11_GRAY22);
        mtrScriptsRegisterNumericVariable("X11_GREY22", MTR_CLR_X11_GREY22);
        mtrScriptsRegisterNumericVariable("X11_GRAY23", MTR_CLR_X11_GRAY23);
        mtrScriptsRegisterNumericVariable("X11_GREY23", MTR_CLR_X11_GREY23);
        mtrScriptsRegisterNumericVariable("X11_GRAY24", MTR_CLR_X11_GRAY24);
        mtrScriptsRegisterNumericVariable("X11_GREY24", MTR_CLR_X11_GREY24);
        mtrScriptsRegisterNumericVariable("X11_GRAY25", MTR_CLR_X11_GRAY25);
        mtrScriptsRegisterNumericVariable("X11_GREY25", MTR_CLR_X11_GREY25);
        mtrScriptsRegisterNumericVariable("X11_GRAY26", MTR_CLR_X11_GRAY26);
        mtrScriptsRegisterNumericVariable("X11_GREY26", MTR_CLR_X11_GREY26);
        mtrScriptsRegisterNumericVariable("X11_GRAY27", MTR_CLR_X11_GRAY27);
        mtrScriptsRegisterNumericVariable("X11_GREY27", MTR_CLR_X11_GREY27);
        mtrScriptsRegisterNumericVariable("X11_GRAY28", MTR_CLR_X11_GRAY28);
        mtrScriptsRegisterNumericVariable("X11_GREY28", MTR_CLR_X11_GREY28);
        mtrScriptsRegisterNumericVariable("X11_GRAY29", MTR_CLR_X11_GRAY29);
        mtrScriptsRegisterNumericVariable("X11_GREY29", MTR_CLR_X11_GREY29);
        mtrScriptsRegisterNumericVariable("X11_GRAY30", MTR_CLR_X11_GRAY30);
        mtrScriptsRegisterNumericVariable("X11_GREY30", MTR_CLR_X11_GREY30);
        mtrScriptsRegisterNumericVariable("X11_GRAY31", MTR_CLR_X11_GRAY31);
        mtrScriptsRegisterNumericVariable("X11_GREY31", MTR_CLR_X11_GREY31);
        mtrScriptsRegisterNumericVariable("X11_GRAY32", MTR_CLR_X11_GRAY32);
        mtrScriptsRegisterNumericVariable("X11_GREY32", MTR_CLR_X11_GREY32);
        mtrScriptsRegisterNumericVariable("X11_GRAY33", MTR_CLR_X11_GRAY33);
        mtrScriptsRegisterNumericVariable("X11_GREY33", MTR_CLR_X11_GREY33);
        mtrScriptsRegisterNumericVariable("X11_GRAY34", MTR_CLR_X11_GRAY34);
        mtrScriptsRegisterNumericVariable("X11_GREY34", MTR_CLR_X11_GREY34);
        mtrScriptsRegisterNumericVariable("X11_GRAY35", MTR_CLR_X11_GRAY35);
        mtrScriptsRegisterNumericVariable("X11_GREY35", MTR_CLR_X11_GREY35);
        mtrScriptsRegisterNumericVariable("X11_GRAY36", MTR_CLR_X11_GRAY36);
        mtrScriptsRegisterNumericVariable("X11_GREY36", MTR_CLR_X11_GREY36);
        mtrScriptsRegisterNumericVariable("X11_GRAY37", MTR_CLR_X11_GRAY37);
        mtrScriptsRegisterNumericVariable("X11_GREY37", MTR_CLR_X11_GREY37);
        mtrScriptsRegisterNumericVariable("X11_GRAY38", MTR_CLR_X11_GRAY38);
        mtrScriptsRegisterNumericVariable("X11_GREY38", MTR_CLR_X11_GREY38);
        mtrScriptsRegisterNumericVariable("X11_GRAY39", MTR_CLR_X11_GRAY39);
        mtrScriptsRegisterNumericVariable("X11_GREY39", MTR_CLR_X11_GREY39);
        mtrScriptsRegisterNumericVariable("X11_GRAY40", MTR_CLR_X11_GRAY40);
        mtrScriptsRegisterNumericVariable("X11_GREY40", MTR_CLR_X11_GREY40);
        mtrScriptsRegisterNumericVariable("X11_GRAY41", MTR_CLR_X11_GRAY41);
        mtrScriptsRegisterNumericVariable("X11_GREY41", MTR_CLR_X11_GREY41);
        mtrScriptsRegisterNumericVariable("X11_GRAY42", MTR_CLR_X11_GRAY42);
        mtrScriptsRegisterNumericVariable("X11_GREY42", MTR_CLR_X11_GREY42);
        mtrScriptsRegisterNumericVariable("X11_GRAY43", MTR_CLR_X11_GRAY43);
        mtrScriptsRegisterNumericVariable("X11_GREY43", MTR_CLR_X11_GREY43);
        mtrScriptsRegisterNumericVariable("X11_GRAY44", MTR_CLR_X11_GRAY44);
        mtrScriptsRegisterNumericVariable("X11_GREY44", MTR_CLR_X11_GREY44);
        mtrScriptsRegisterNumericVariable("X11_GRAY45", MTR_CLR_X11_GRAY45);
        mtrScriptsRegisterNumericVariable("X11_GREY45", MTR_CLR_X11_GREY45);
        mtrScriptsRegisterNumericVariable("X11_GRAY46", MTR_CLR_X11_GRAY46);
        mtrScriptsRegisterNumericVariable("X11_GREY46", MTR_CLR_X11_GREY46);
        mtrScriptsRegisterNumericVariable("X11_GRAY47", MTR_CLR_X11_GRAY47);
        mtrScriptsRegisterNumericVariable("X11_GREY47", MTR_CLR_X11_GREY47);
        mtrScriptsRegisterNumericVariable("X11_GRAY48", MTR_CLR_X11_GRAY48);
        mtrScriptsRegisterNumericVariable("X11_GREY48", MTR_CLR_X11_GREY48);
        mtrScriptsRegisterNumericVariable("X11_GRAY49", MTR_CLR_X11_GRAY49);
        mtrScriptsRegisterNumericVariable("X11_GREY49", MTR_CLR_X11_GREY49);
        mtrScriptsRegisterNumericVariable("X11_GRAY50", MTR_CLR_X11_GRAY50);
        mtrScriptsRegisterNumericVariable("X11_GREY50", MTR_CLR_X11_GREY50);
        mtrScriptsRegisterNumericVariable("X11_GRAY51", MTR_CLR_X11_GRAY51);
        mtrScriptsRegisterNumericVariable("X11_GREY51", MTR_CLR_X11_GREY51);
        mtrScriptsRegisterNumericVariable("X11_GRAY52", MTR_CLR_X11_GRAY52);
        mtrScriptsRegisterNumericVariable("X11_GREY52", MTR_CLR_X11_GREY52);
        mtrScriptsRegisterNumericVariable("X11_GRAY53", MTR_CLR_X11_GRAY53);
        mtrScriptsRegisterNumericVariable("X11_GREY53", MTR_CLR_X11_GREY53);
        mtrScriptsRegisterNumericVariable("X11_GRAY54", MTR_CLR_X11_GRAY54);
        mtrScriptsRegisterNumericVariable("X11_GREY54", MTR_CLR_X11_GREY54);
        mtrScriptsRegisterNumericVariable("X11_GRAY55", MTR_CLR_X11_GRAY55);
        mtrScriptsRegisterNumericVariable("X11_GREY55", MTR_CLR_X11_GREY55);
        mtrScriptsRegisterNumericVariable("X11_GRAY56", MTR_CLR_X11_GRAY56);
        mtrScriptsRegisterNumericVariable("X11_GREY56", MTR_CLR_X11_GREY56);
        mtrScriptsRegisterNumericVariable("X11_GRAY57", MTR_CLR_X11_GRAY57);
        mtrScriptsRegisterNumericVariable("X11_GREY57", MTR_CLR_X11_GREY57);
        mtrScriptsRegisterNumericVariable("X11_GRAY58", MTR_CLR_X11_GRAY58);
        mtrScriptsRegisterNumericVariable("X11_GREY58", MTR_CLR_X11_GREY58);
        mtrScriptsRegisterNumericVariable("X11_GRAY59", MTR_CLR_X11_GRAY59);
        mtrScriptsRegisterNumericVariable("X11_GREY59", MTR_CLR_X11_GREY59);
        mtrScriptsRegisterNumericVariable("X11_GRAY60", MTR_CLR_X11_GRAY60);
        mtrScriptsRegisterNumericVariable("X11_GREY60", MTR_CLR_X11_GREY60);
        mtrScriptsRegisterNumericVariable("X11_GRAY61", MTR_CLR_X11_GRAY61);
        mtrScriptsRegisterNumericVariable("X11_GREY61", MTR_CLR_X11_GREY61);
        mtrScriptsRegisterNumericVariable("X11_GRAY62", MTR_CLR_X11_GRAY62);
        mtrScriptsRegisterNumericVariable("X11_GREY62", MTR_CLR_X11_GREY62);
        mtrScriptsRegisterNumericVariable("X11_GRAY63", MTR_CLR_X11_GRAY63);
        mtrScriptsRegisterNumericVariable("X11_GREY63", MTR_CLR_X11_GREY63);
        mtrScriptsRegisterNumericVariable("X11_GRAY64", MTR_CLR_X11_GRAY64);
        mtrScriptsRegisterNumericVariable("X11_GREY64", MTR_CLR_X11_GREY64);
        mtrScriptsRegisterNumericVariable("X11_GRAY65", MTR_CLR_X11_GRAY65);
        mtrScriptsRegisterNumericVariable("X11_GREY65", MTR_CLR_X11_GREY65);
        mtrScriptsRegisterNumericVariable("X11_GRAY66", MTR_CLR_X11_GRAY66);
        mtrScriptsRegisterNumericVariable("X11_GREY66", MTR_CLR_X11_GREY66);
        mtrScriptsRegisterNumericVariable("X11_GRAY67", MTR_CLR_X11_GRAY67);
        mtrScriptsRegisterNumericVariable("X11_GREY67", MTR_CLR_X11_GREY67);
        mtrScriptsRegisterNumericVariable("X11_GRAY68", MTR_CLR_X11_GRAY68);
        mtrScriptsRegisterNumericVariable("X11_GREY68", MTR_CLR_X11_GREY68);
        mtrScriptsRegisterNumericVariable("X11_GRAY69", MTR_CLR_X11_GRAY69);
        mtrScriptsRegisterNumericVariable("X11_GREY69", MTR_CLR_X11_GREY69);
        mtrScriptsRegisterNumericVariable("X11_GRAY70", MTR_CLR_X11_GRAY70);
        mtrScriptsRegisterNumericVariable("X11_GREY70", MTR_CLR_X11_GREY70);
        mtrScriptsRegisterNumericVariable("X11_GRAY71", MTR_CLR_X11_GRAY71);
        mtrScriptsRegisterNumericVariable("X11_GREY71", MTR_CLR_X11_GREY71);
        mtrScriptsRegisterNumericVariable("X11_GRAY72", MTR_CLR_X11_GRAY72);
        mtrScriptsRegisterNumericVariable("X11_GREY72", MTR_CLR_X11_GREY72);
        mtrScriptsRegisterNumericVariable("X11_GRAY73", MTR_CLR_X11_GRAY73);
        mtrScriptsRegisterNumericVariable("X11_GREY73", MTR_CLR_X11_GREY73);
        mtrScriptsRegisterNumericVariable("X11_GRAY74", MTR_CLR_X11_GRAY74);
        mtrScriptsRegisterNumericVariable("X11_GREY74", MTR_CLR_X11_GREY74);
        mtrScriptsRegisterNumericVariable("X11_GRAY75", MTR_CLR_X11_GRAY75);
        mtrScriptsRegisterNumericVariable("X11_GREY75", MTR_CLR_X11_GREY75);
        mtrScriptsRegisterNumericVariable("X11_GRAY76", MTR_CLR_X11_GRAY76);
        mtrScriptsRegisterNumericVariable("X11_GREY76", MTR_CLR_X11_GREY76);
        mtrScriptsRegisterNumericVariable("X11_GRAY77", MTR_CLR_X11_GRAY77);
        mtrScriptsRegisterNumericVariable("X11_GREY77", MTR_CLR_X11_GREY77);
        mtrScriptsRegisterNumericVariable("X11_GRAY78", MTR_CLR_X11_GRAY78);
        mtrScriptsRegisterNumericVariable("X11_GREY78", MTR_CLR_X11_GREY78);
        mtrScriptsRegisterNumericVariable("X11_GRAY79", MTR_CLR_X11_GRAY79);
        mtrScriptsRegisterNumericVariable("X11_GREY79", MTR_CLR_X11_GREY79);
        mtrScriptsRegisterNumericVariable("X11_GRAY80", MTR_CLR_X11_GRAY80);
        mtrScriptsRegisterNumericVariable("X11_GREY80", MTR_CLR_X11_GREY80);
        mtrScriptsRegisterNumericVariable("X11_GRAY81", MTR_CLR_X11_GRAY81);
        mtrScriptsRegisterNumericVariable("X11_GREY81", MTR_CLR_X11_GREY81);
        mtrScriptsRegisterNumericVariable("X11_GRAY82", MTR_CLR_X11_GRAY82);
        mtrScriptsRegisterNumericVariable("X11_GREY82", MTR_CLR_X11_GREY82);
        mtrScriptsRegisterNumericVariable("X11_GRAY83", MTR_CLR_X11_GRAY83);
        mtrScriptsRegisterNumericVariable("X11_GREY83", MTR_CLR_X11_GREY83);
        mtrScriptsRegisterNumericVariable("X11_GRAY84", MTR_CLR_X11_GRAY84);
        mtrScriptsRegisterNumericVariable("X11_GREY84", MTR_CLR_X11_GREY84);
        mtrScriptsRegisterNumericVariable("X11_GRAY85", MTR_CLR_X11_GRAY85);
        mtrScriptsRegisterNumericVariable("X11_GREY85", MTR_CLR_X11_GREY85);
        mtrScriptsRegisterNumericVariable("X11_GRAY86", MTR_CLR_X11_GRAY86);
        mtrScriptsRegisterNumericVariable("X11_GREY86", MTR_CLR_X11_GREY86);
        mtrScriptsRegisterNumericVariable("X11_GRAY87", MTR_CLR_X11_GRAY87);
        mtrScriptsRegisterNumericVariable("X11_GREY87", MTR_CLR_X11_GREY87);
        mtrScriptsRegisterNumericVariable("X11_GRAY88", MTR_CLR_X11_GRAY88);
        mtrScriptsRegisterNumericVariable("X11_GREY88", MTR_CLR_X11_GREY88);
        mtrScriptsRegisterNumericVariable("X11_GRAY89", MTR_CLR_X11_GRAY89);
        mtrScriptsRegisterNumericVariable("X11_GREY89", MTR_CLR_X11_GREY89);
        mtrScriptsRegisterNumericVariable("X11_GRAY90", MTR_CLR_X11_GRAY90);
        mtrScriptsRegisterNumericVariable("X11_GREY90", MTR_CLR_X11_GREY90);
        mtrScriptsRegisterNumericVariable("X11_GRAY91", MTR_CLR_X11_GRAY91);
        mtrScriptsRegisterNumericVariable("X11_GREY91", MTR_CLR_X11_GREY91);
        mtrScriptsRegisterNumericVariable("X11_GRAY92", MTR_CLR_X11_GRAY92);
        mtrScriptsRegisterNumericVariable("X11_GREY92", MTR_CLR_X11_GREY92);
        mtrScriptsRegisterNumericVariable("X11_GRAY93", MTR_CLR_X11_GRAY93);
        mtrScriptsRegisterNumericVariable("X11_GREY93", MTR_CLR_X11_GREY93);
        mtrScriptsRegisterNumericVariable("X11_GRAY94", MTR_CLR_X11_GRAY94);
        mtrScriptsRegisterNumericVariable("X11_GREY94", MTR_CLR_X11_GREY94);
        mtrScriptsRegisterNumericVariable("X11_GRAY95", MTR_CLR_X11_GRAY95);
        mtrScriptsRegisterNumericVariable("X11_GREY95", MTR_CLR_X11_GREY95);
        mtrScriptsRegisterNumericVariable("X11_GRAY96", MTR_CLR_X11_GRAY96);
        mtrScriptsRegisterNumericVariable("X11_GREY96", MTR_CLR_X11_GREY96);
        mtrScriptsRegisterNumericVariable("X11_GRAY97", MTR_CLR_X11_GRAY97);
        mtrScriptsRegisterNumericVariable("X11_GREY97", MTR_CLR_X11_GREY97);
        mtrScriptsRegisterNumericVariable("X11_GRAY98", MTR_CLR_X11_GRAY98);
        mtrScriptsRegisterNumericVariable("X11_GREY98", MTR_CLR_X11_GREY98);
        mtrScriptsRegisterNumericVariable("X11_GRAY99", MTR_CLR_X11_GRAY99);
        mtrScriptsRegisterNumericVariable("X11_GREY99", MTR_CLR_X11_GREY99);
        mtrScriptsRegisterNumericVariable("X11_GRAY100", MTR_CLR_X11_GRAY100);
        mtrScriptsRegisterNumericVariable("X11_GREY100", MTR_CLR_X11_GREY100);
        mtrScriptsRegisterNumericVariable("X11_DARK_GREY",
         MTR_CLR_X11_DARK_GREY);
        mtrScriptsRegisterNumericVariable("X11_DARKGREY", MTR_CLR_X11_DARKGREY);
        mtrScriptsRegisterNumericVariable("X11_DARK_GRAY",
         MTR_CLR_X11_DARK_GRAY);
        mtrScriptsRegisterNumericVariable("X11_DARKGRAY", MTR_CLR_X11_DARKGRAY);
        mtrScriptsRegisterNumericVariable("X11_DARK_BLUE",
         MTR_CLR_X11_DARK_BLUE);
        mtrScriptsRegisterNumericVariable("X11_DARKBLUE", MTR_CLR_X11_DARKBLUE);
        mtrScriptsRegisterNumericVariable("X11_DARK_CYAN",
         MTR_CLR_X11_DARK_CYAN);
        mtrScriptsRegisterNumericVariable("X11_DARKCYAN", MTR_CLR_X11_DARKCYAN);
        mtrScriptsRegisterNumericVariable("X11_DARK_MAGENTA",
         MTR_CLR_X11_DARK_MAGENTA);
        mtrScriptsRegisterNumericVariable("X11_DARKMAGENTA",
         MTR_CLR_X11_DARKMAGENTA);
        mtrScriptsRegisterNumericVariable("X11_DARK_RED", MTR_CLR_X11_DARK_RED);
        mtrScriptsRegisterNumericVariable("X11_DARKRED", MTR_CLR_X11_DARKRED);
        mtrScriptsRegisterNumericVariable("X11_LIGHT_GREEN",
         MTR_CLR_X11_LIGHT_GREEN);
        mtrScriptsRegisterNumericVariable("X11_LIGHTGREEN",
         MTR_CLR_X11_LIGHTGREEN);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_0",
         MTR_CLR_X11_SGI_GRAY_0);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY0", MTR_CLR_X11_SGIGRAY0);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_0",
         MTR_CLR_X11_SGI_GREY_0);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY0", MTR_CLR_X11_SGIGREY0);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_4",
         MTR_CLR_X11_SGI_GRAY_4);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY4", MTR_CLR_X11_SGIGRAY4);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_4",
         MTR_CLR_X11_SGI_GREY_4);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY4", MTR_CLR_X11_SGIGREY4);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_8",
         MTR_CLR_X11_SGI_GRAY_8);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY8", MTR_CLR_X11_SGIGRAY8);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_8",
         MTR_CLR_X11_SGI_GREY_8);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY8", MTR_CLR_X11_SGIGREY8);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_12",
         MTR_CLR_X11_SGI_GRAY_12);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY12",
         MTR_CLR_X11_SGIGRAY12);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_12",
         MTR_CLR_X11_SGI_GREY_12);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY12",
         MTR_CLR_X11_SGIGREY12);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_16",
         MTR_CLR_X11_SGI_GRAY_16);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY16",
         MTR_CLR_X11_SGIGRAY16);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_16",
         MTR_CLR_X11_SGI_GREY_16);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY16",
         MTR_CLR_X11_SGIGREY16);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_20",
         MTR_CLR_X11_SGI_GRAY_20);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY20",
         MTR_CLR_X11_SGIGRAY20);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_20",
         MTR_CLR_X11_SGI_GREY_20);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY20",
         MTR_CLR_X11_SGIGREY20);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_24",
         MTR_CLR_X11_SGI_GRAY_24);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY24",
         MTR_CLR_X11_SGIGRAY24);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_24",
         MTR_CLR_X11_SGI_GREY_24);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY24",
         MTR_CLR_X11_SGIGREY24);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_28",
         MTR_CLR_X11_SGI_GRAY_28);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY28",
         MTR_CLR_X11_SGIGRAY28);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_28",
         MTR_CLR_X11_SGI_GREY_28);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY28",
         MTR_CLR_X11_SGIGREY28);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_32",
         MTR_CLR_X11_SGI_GRAY_32);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY32",
         MTR_CLR_X11_SGIGRAY32);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_32",
         MTR_CLR_X11_SGI_GREY_32);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY32",
         MTR_CLR_X11_SGIGREY32);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_36",
         MTR_CLR_X11_SGI_GRAY_36);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY36",
         MTR_CLR_X11_SGIGRAY36);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_36",
         MTR_CLR_X11_SGI_GREY_36);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY36",
         MTR_CLR_X11_SGIGREY36);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_40",
         MTR_CLR_X11_SGI_GRAY_40);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY40",
         MTR_CLR_X11_SGIGRAY40);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_40",
         MTR_CLR_X11_SGI_GREY_40);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY40",
         MTR_CLR_X11_SGIGREY40);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_44",
         MTR_CLR_X11_SGI_GRAY_44);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY44",
         MTR_CLR_X11_SGIGRAY44);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_44",
         MTR_CLR_X11_SGI_GREY_44);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY44",
         MTR_CLR_X11_SGIGREY44);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_48",
         MTR_CLR_X11_SGI_GRAY_48);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY48",
         MTR_CLR_X11_SGIGRAY48);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_48",
         MTR_CLR_X11_SGI_GREY_48);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY48",
         MTR_CLR_X11_SGIGREY48);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_52",
         MTR_CLR_X11_SGI_GRAY_52);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY52",
         MTR_CLR_X11_SGIGRAY52);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_52",
         MTR_CLR_X11_SGI_GREY_52);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY52",
         MTR_CLR_X11_SGIGREY52);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_56",
         MTR_CLR_X11_SGI_GRAY_56);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY56",
         MTR_CLR_X11_SGIGRAY56);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_56",
         MTR_CLR_X11_SGI_GREY_56);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY56",
         MTR_CLR_X11_SGIGREY56);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_60",
         MTR_CLR_X11_SGI_GRAY_60);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY60",
         MTR_CLR_X11_SGIGRAY60);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_60",
         MTR_CLR_X11_SGI_GREY_60);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY60",
         MTR_CLR_X11_SGIGREY60);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_64",
         MTR_CLR_X11_SGI_GRAY_64);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY64",
         MTR_CLR_X11_SGIGRAY64);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_64",
         MTR_CLR_X11_SGI_GREY_64);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY64",
         MTR_CLR_X11_SGIGREY64);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_68",
         MTR_CLR_X11_SGI_GRAY_68);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY68",
         MTR_CLR_X11_SGIGRAY68);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_68",
         MTR_CLR_X11_SGI_GREY_68);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY68",
         MTR_CLR_X11_SGIGREY68);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_72",
         MTR_CLR_X11_SGI_GRAY_72);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY72",
         MTR_CLR_X11_SGIGRAY72);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_72",
         MTR_CLR_X11_SGI_GREY_72);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY72",
         MTR_CLR_X11_SGIGREY72);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_76",
         MTR_CLR_X11_SGI_GRAY_76);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY76",
         MTR_CLR_X11_SGIGRAY76);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_76",
         MTR_CLR_X11_SGI_GREY_76);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY76",
         MTR_CLR_X11_SGIGREY76);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_80",
         MTR_CLR_X11_SGI_GRAY_80);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY80",
         MTR_CLR_X11_SGIGRAY80);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_80",
         MTR_CLR_X11_SGI_GREY_80);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY80",
         MTR_CLR_X11_SGIGREY80);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_84",
         MTR_CLR_X11_SGI_GRAY_84);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY84",
         MTR_CLR_X11_SGIGRAY84);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_84",
         MTR_CLR_X11_SGI_GREY_84);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY84",
         MTR_CLR_X11_SGIGREY84);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_88",
         MTR_CLR_X11_SGI_GRAY_88);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY88",
         MTR_CLR_X11_SGIGRAY88);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_88",
         MTR_CLR_X11_SGI_GREY_88);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY88",
         MTR_CLR_X11_SGIGREY88);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_92",
         MTR_CLR_X11_SGI_GRAY_92);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY92",
         MTR_CLR_X11_SGIGRAY92);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_92",
         MTR_CLR_X11_SGI_GREY_92);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY92",
         MTR_CLR_X11_SGIGREY92);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_96",
         MTR_CLR_X11_SGI_GRAY_96);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY96",
         MTR_CLR_X11_SGIGRAY96);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_96",
         MTR_CLR_X11_SGI_GREY_96);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY96",
         MTR_CLR_X11_SGIGREY96);
        mtrScriptsRegisterNumericVariable("X11_SGI_GRAY_100",
         MTR_CLR_X11_SGI_GRAY_100);
        mtrScriptsRegisterNumericVariable("X11_SGIGRAY100",
         MTR_CLR_X11_SGIGRAY100);
        mtrScriptsRegisterNumericVariable("X11_SGI_GREY_100",
         MTR_CLR_X11_SGI_GREY_100);
        mtrScriptsRegisterNumericVariable("X11_SGIGREY100",
         MTR_CLR_X11_SGIGREY100);
        mtrScriptsRegisterNumericVariable("X11_SGI_LIGHT_BLUE",
         MTR_CLR_X11_SGI_LIGHT_BLUE);
        mtrScriptsRegisterNumericVariable("X11_SGILIGHTBLUE",
         MTR_CLR_X11_SGILIGHTBLUE);
        mtrScriptsRegisterNumericVariable("X11_SGI_DARK_GRAY",
         MTR_CLR_X11_SGI_DARK_GRAY);
        mtrScriptsRegisterNumericVariable("X11_SGIDARKGRAY",
         MTR_CLR_X11_SGIDARKGRAY);
        mtrScriptsRegisterNumericVariable("X11_SGI_DARK_GREY",
         MTR_CLR_X11_SGI_DARK_GREY);
        mtrScriptsRegisterNumericVariable("X11_SGIDARKGREY",
         MTR_CLR_X11_SGIDARKGREY);
        mtrScriptsRegisterNumericVariable("X11_SGI_SALMON",
         MTR_CLR_X11_SGI_SALMON);
        mtrScriptsRegisterNumericVariable("X11_SGISALMON",
         MTR_CLR_X11_SGISALMON);
        mtrScriptsRegisterNumericVariable("X11_SGI_CHARTREUSE",
         MTR_CLR_X11_SGI_CHARTREUSE);
        mtrScriptsRegisterNumericVariable("X11_SGICHARTREUSE",
         MTR_CLR_X11_SGICHARTREUSE);
        mtrScriptsRegisterNumericVariable("X11_SGI_OLIVE_DRAB",
         MTR_CLR_X11_SGI_OLIVE_DRAB);
        mtrScriptsRegisterNumericVariable("X11_SGIOLIVEDRAB",
         MTR_CLR_X11_SGIOLIVEDRAB);
        mtrScriptsRegisterNumericVariable("X11_SGI_SLATE_BLUE",
         MTR_CLR_X11_SGI_SLATE_BLUE);
        mtrScriptsRegisterNumericVariable("X11_SGISLATEBLUE",
         MTR_CLR_X11_SGISLATEBLUE);
        mtrScriptsRegisterNumericVariable("X11_SGI_BEET", MTR_CLR_X11_SGI_BEET);
        mtrScriptsRegisterNumericVariable("X11_SGIBEET", MTR_CLR_X11_SGIBEET);
        mtrScriptsRegisterNumericVariable("X11_SGI_TEAL", MTR_CLR_X11_SGI_TEAL);
        mtrScriptsRegisterNumericVariable("X11_SGITEAL", MTR_CLR_X11_SGITEAL);
        mtrScriptsRegisterNumericVariable("X11_SGI_LIGHT_GRAY",
         MTR_CLR_X11_SGI_LIGHT_GRAY);
        mtrScriptsRegisterNumericVariable("X11_SGILIGHTGRAY",
         MTR_CLR_X11_SGILIGHTGRAY);
        mtrScriptsRegisterNumericVariable("X11_SGI_LIGHT_GREY",
         MTR_CLR_X11_SGI_LIGHT_GREY);
        mtrScriptsRegisterNumericVariable("X11_SGILIGHTGREY",
         MTR_CLR_X11_SGILIGHTGREY);
        mtrScriptsRegisterNumericVariable("X11_SGI_VERY_LIGHT_GRAY",
         MTR_CLR_X11_SGI_VERY_LIGHT_GRAY);
        mtrScriptsRegisterNumericVariable("X11_SGIVERYLIGHTGRAY",
         MTR_CLR_X11_SGIVERYLIGHTGRAY);
        mtrScriptsRegisterNumericVariable("X11_SGI_VERY_LIGHT_GREY",
         MTR_CLR_X11_SGI_VERY_LIGHT_GREY);
        mtrScriptsRegisterNumericVariable("X11_SGIVERYLIGHTGREY",
         MTR_CLR_X11_SGIVERYLIGHTGREY);
        mtrScriptsRegisterNumericVariable("X11_SGI_MEDIUM_GRAY",
         MTR_CLR_X11_SGI_MEDIUM_GRAY);
        mtrScriptsRegisterNumericVariable("X11_SGIMEDIUMGRAY",
         MTR_CLR_X11_SGIMEDIUMGRAY);
        mtrScriptsRegisterNumericVariable("X11_SGI_MEDIUM_GREY",
         MTR_CLR_X11_SGI_MEDIUM_GREY);
        mtrScriptsRegisterNumericVariable("X11_SGIMEDIUMGREY",
         MTR_CLR_X11_SGIMEDIUMGREY);
        mtrScriptsRegisterNumericVariable("X11_SGI_VERY_DARK_GRAY",
         MTR_CLR_X11_SGI_VERY_DARK_GRAY);
        mtrScriptsRegisterNumericVariable("X11_SGIVERYDARKGRAY",
         MTR_CLR_X11_SGIVERYDARKGRAY);
        mtrScriptsRegisterNumericVariable("X11_SGI_VERY_DARK_GREY",
         MTR_CLR_X11_SGI_VERY_DARK_GREY);
        mtrScriptsRegisterNumericVariable("X11_SGIVERYDARKGREY",
         MTR_CLR_X11_SGIVERYDARKGREY);
        mtrScriptsRegisterNumericVariable("X11_SGI_BRIGHT_GRAY",
         MTR_CLR_X11_SGI_BRIGHT_GRAY);
        mtrScriptsRegisterNumericVariable("X11_SGIBRIGHTGRAY",
         MTR_CLR_X11_SGIBRIGHTGRAY);
        mtrScriptsRegisterNumericVariable("X11_SGI_BRIGHT_GREY",
         MTR_CLR_X11_SGI_BRIGHT_GREY);
        mtrScriptsRegisterNumericVariable("X11_SGIBRIGHTGREY",
         MTR_CLR_X11_SGIBRIGHTGREY);
        mtrScriptsRegisterNumericVariable("X11_INDIGO", MTR_CLR_X11_INDIGO);
        mtrScriptsRegisterNumericVariable("X11_INDIGO2", MTR_CLR_X11_INDIGO2);
        mtrScriptsRegisterNumericVariable("X11_CRIMSON", MTR_CLR_X11_CRIMSON);
        mtrScriptsRegisterFunction(mtrSF_ColorAssembleRGB,
         "ColorAssembleRGB");
        mtrScriptsRegisterFunction(mtrSF_ColorAssembleRGBA,
         "ColorAssembleRGBA");
        #ifdef lua_h
        mtrScriptsRegisterFunction(mtrSF_ColorSplitRGB, "ColorSplitRGB");
        mtrScriptsRegisterFunction(mtrSF_ColorSplitRGBA, "ColorSplitRGBA");
        #endif
        mtrScriptsRegisterFunction(mtrSF_ColorRGBGetR, "ColorRGBGetR");
        mtrScriptsRegisterFunction(mtrSF_ColorRGBGetG, "ColorRGBGetG");
        mtrScriptsRegisterFunction(mtrSF_ColorRGBGetB, "ColorRGBGetB");
        mtrScriptsRegisterFunction(mtrSF_ColorRGBSetR, "ColorRGBSetR");
        mtrScriptsRegisterFunction(mtrSF_ColorRGBSetG, "ColorRGBSetG");
        mtrScriptsRegisterFunction(mtrSF_ColorRGBSetB, "ColorRGBSetB");
        mtrScriptsRegisterFunction(mtrSF_ColorRGBAGetR, "ColorRGBAGetR");
        mtrScriptsRegisterFunction(mtrSF_ColorRGBAGetG, "ColorRGBAGetG");
        mtrScriptsRegisterFunction(mtrSF_ColorRGBAGetB, "ColorRGBAGetB");
        mtrScriptsRegisterFunction(mtrSF_ColorRGBAGetA, "ColorRGBAGetA");
        mtrScriptsRegisterFunction(mtrSF_ColorRGBASetR, "ColorRGBASetR");
        mtrScriptsRegisterFunction(mtrSF_ColorRGBASetB, "ColorRGBASetB");
        mtrScriptsRegisterFunction(mtrSF_ColorRGBASetA, "ColorRGBASetA");
        mtrScriptsRegisterFunction(mtrSF_ColorRGBtoRGBA, "ColorRGBtoRGBA");
        mtrScriptsRegisterFunction(mtrSF_ColorRGBAtoRGB, "ColorRGBAtoRGB");
    }
    else
    {
        mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
    }
}

#endif
