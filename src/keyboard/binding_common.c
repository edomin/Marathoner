#ifndef MTR_KEYBOARD_BINDING_COMMON_C
#define MTR_KEYBOARD_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_KeyboardFunctionSupported,
 MTR_KeyboardFunctionSupported)
MTR_SCRIPT_FUNC_B_V(MTR_SF_KeyboardInit, MTR_KeyboardInit)
MTR_SCRIPT_FUNC_V_V(MTR_SF_KeyboardRefresh, MTR_KeyboardRefresh)
MTR_SCRIPT_FUNC_B_I1(MTR_SF_KeyboardPress, MTR_KeyboardPress)
MTR_SCRIPT_FUNC_B_I1(MTR_SF_KeyboardRelease, MTR_KeyboardRelease)
MTR_SCRIPT_FUNC_B_I1(MTR_SF_KeyboardPressed, MTR_KeyboardPressed)

#ifdef lua_h
MTR_SCRIPT_FUNC(MTR_SF_KeyboardArrowsGetAxes)
{
    int keyUp;
    int keyDown;
    int keyLeft;
    int keyRight;
    int hsign;
    int vsign;

    MTR_SF_GET_INT(keyUp, 1);
    MTR_SF_GET_INT(keyDown, 2);
    MTR_SF_GET_INT(keyLeft, 3);
    MTR_SF_GET_INT(keyRight, 4);
    MTR_KeyboardArrowsGetAxes(keyUp, keyDown, keyLeft, keyRight, &hsign,
     &vsign);

    MTR_SF_PUSH_INT(hsign);
    MTR_SF_PUSH_INT(vsign);

    return 2;
}
#endif

MTR_SCRIPT_FUNC_I_I2(MTR_SF_KeyboardArrowsGetAxis,
 MTR_KeyboardArrowsGetAxis)
MTR_SCRIPT_FUNC_I_I4(MTR_SF_KeyboardArrowsGetDirection,
 MTR_KeyboardArrowsGetDirection)

MTR_SCRIPT_FUNC(MTR_SF_KeyboardInputChar)
{
    char *utf8char;

    utf8char = MTR_KeyboardInputChar();
    if (utf8char == NULL)
        MTR_SF_PUSH_NIL();
    else
        MTR_SF_PUSH_STRING(utf8char);

    return 1;
}

void MTR_ScriptsRegisterAll(void)
{
    #ifdef MTR_MOD_PLUGIN
    mtrVm = MTR_ScriptsGetVm();
    #endif

    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, KeyboardFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, KeyboardInit);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, KeyboardRefresh);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, KeyboardPress);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, KeyboardRelease);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, KeyboardPressed);
    #ifdef lua_h
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, KeyboardArrowsGetAxes);
    #endif
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, KeyboardArrowsGetAxis);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, KeyboardArrowsGetDirection);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, KeyboardInputChar);

    MTR_ScriptsRegisterVariable_i("KEY_A", MTR_KEY_A);
    MTR_ScriptsRegisterVariable_i("KEY_B", MTR_KEY_B);
    MTR_ScriptsRegisterVariable_i("KEY_C", MTR_KEY_C);
    MTR_ScriptsRegisterVariable_i("KEY_D", MTR_KEY_D);
    MTR_ScriptsRegisterVariable_i("KEY_E", MTR_KEY_E);
    MTR_ScriptsRegisterVariable_i("KEY_F", MTR_KEY_F);
    MTR_ScriptsRegisterVariable_i("KEY_G", MTR_KEY_G);
    MTR_ScriptsRegisterVariable_i("KEY_H", MTR_KEY_H);
    MTR_ScriptsRegisterVariable_i("KEY_I", MTR_KEY_I);
    MTR_ScriptsRegisterVariable_i("KEY_J", MTR_KEY_J);
    MTR_ScriptsRegisterVariable_i("KEY_K", MTR_KEY_K);
    MTR_ScriptsRegisterVariable_i("KEY_L", MTR_KEY_L);
    MTR_ScriptsRegisterVariable_i("KEY_M", MTR_KEY_M);
    MTR_ScriptsRegisterVariable_i("KEY_N", MTR_KEY_N);
    MTR_ScriptsRegisterVariable_i("KEY_O", MTR_KEY_O);
    MTR_ScriptsRegisterVariable_i("KEY_P", MTR_KEY_P);
    MTR_ScriptsRegisterVariable_i("KEY_Q", MTR_KEY_Q);
    MTR_ScriptsRegisterVariable_i("KEY_R", MTR_KEY_R);
    MTR_ScriptsRegisterVariable_i("KEY_S", MTR_KEY_S);
    MTR_ScriptsRegisterVariable_i("KEY_T", MTR_KEY_T);
    MTR_ScriptsRegisterVariable_i("KEY_U", MTR_KEY_U);
    MTR_ScriptsRegisterVariable_i("KEY_V", MTR_KEY_V);
    MTR_ScriptsRegisterVariable_i("KEY_W", MTR_KEY_W);
    MTR_ScriptsRegisterVariable_i("KEY_X", MTR_KEY_X);
    MTR_ScriptsRegisterVariable_i("KEY_Y", MTR_KEY_Y);
    MTR_ScriptsRegisterVariable_i("KEY_Z", MTR_KEY_Z);

    MTR_ScriptsRegisterVariable_i("KEY_1", MTR_KEY_1);
    MTR_ScriptsRegisterVariable_i("KEY_2", MTR_KEY_2);
    MTR_ScriptsRegisterVariable_i("KEY_3", MTR_KEY_3);
    MTR_ScriptsRegisterVariable_i("KEY_4", MTR_KEY_4);
    MTR_ScriptsRegisterVariable_i("KEY_5", MTR_KEY_5);
    MTR_ScriptsRegisterVariable_i("KEY_6", MTR_KEY_6);
    MTR_ScriptsRegisterVariable_i("KEY_7", MTR_KEY_7);
    MTR_ScriptsRegisterVariable_i("KEY_8", MTR_KEY_8);
    MTR_ScriptsRegisterVariable_i("KEY_9", MTR_KEY_9);
    MTR_ScriptsRegisterVariable_i("KEY_0", MTR_KEY_0);

    MTR_ScriptsRegisterVariable_i("KEY_RETURN", MTR_KEY_RETURN);
    MTR_ScriptsRegisterVariable_i("KEY_ESCAPE", MTR_KEY_ESCAPE);
    MTR_ScriptsRegisterVariable_i("KEY_BACKSPACE", MTR_KEY_BACKSPACE);
    MTR_ScriptsRegisterVariable_i("KEY_TAB", MTR_KEY_TAB);
    MTR_ScriptsRegisterVariable_i("KEY_SPACE", MTR_KEY_SPACE);

    MTR_ScriptsRegisterVariable_i("KEY_MINUS", MTR_KEY_MINUS);
    MTR_ScriptsRegisterVariable_i("KEY_EQUALS", MTR_KEY_EQUALS);
    MTR_ScriptsRegisterVariable_i("KEY_LEFTBRACKET", MTR_KEY_LEFTBRACKET);
    MTR_ScriptsRegisterVariable_i("KEY_RIGHTBRACKET", MTR_KEY_RIGHTBRACKET);
    MTR_ScriptsRegisterVariable_i("KEY_BACKSLASH", MTR_KEY_BACKSLASH);
    MTR_ScriptsRegisterVariable_i("KEY_NONUSHASH", MTR_KEY_NONUSHASH);
    MTR_ScriptsRegisterVariable_i("KEY_SEMICOLON", MTR_KEY_SEMICOLON);
    MTR_ScriptsRegisterVariable_i("KEY_APOSTROPHE", MTR_KEY_APOSTROPHE);
    MTR_ScriptsRegisterVariable_i("KEY_GRAVE", MTR_KEY_GRAVE);
    MTR_ScriptsRegisterVariable_i("KEY_COMMA", MTR_KEY_COMMA);
    MTR_ScriptsRegisterVariable_i("KEY_PERIOD", MTR_KEY_PERIOD);
    MTR_ScriptsRegisterVariable_i("KEY_SLASH", MTR_KEY_SLASH);

    MTR_ScriptsRegisterVariable_i("KEY_CAPSLOCK", MTR_KEY_CAPSLOCK);

    MTR_ScriptsRegisterVariable_i("KEY_F1", MTR_KEY_F1);
    MTR_ScriptsRegisterVariable_i("KEY_F2", MTR_KEY_F2);
    MTR_ScriptsRegisterVariable_i("KEY_F3", MTR_KEY_F3);
    MTR_ScriptsRegisterVariable_i("KEY_F4", MTR_KEY_F4);
    MTR_ScriptsRegisterVariable_i("KEY_F5", MTR_KEY_F5);
    MTR_ScriptsRegisterVariable_i("KEY_F6", MTR_KEY_F6);
    MTR_ScriptsRegisterVariable_i("KEY_F7", MTR_KEY_F7);
    MTR_ScriptsRegisterVariable_i("KEY_F8", MTR_KEY_F8);
    MTR_ScriptsRegisterVariable_i("KEY_F9", MTR_KEY_F9);
    MTR_ScriptsRegisterVariable_i("KEY_F10", MTR_KEY_F10);
    MTR_ScriptsRegisterVariable_i("KEY_F11", MTR_KEY_F11);
    MTR_ScriptsRegisterVariable_i("KEY_F12", MTR_KEY_F12);

    MTR_ScriptsRegisterVariable_i("KEY_PRINTSCREEN", MTR_KEY_PRINTSCREEN);
    MTR_ScriptsRegisterVariable_i("KEY_SCROLLLOCK", MTR_KEY_SCROLLLOCK);
    MTR_ScriptsRegisterVariable_i("KEY_PAUSE", MTR_KEY_PAUSE);
    MTR_ScriptsRegisterVariable_i("KEY_INSERT", MTR_KEY_INSERT);
    MTR_ScriptsRegisterVariable_i("KEY_HOME", MTR_KEY_HOME);
    MTR_ScriptsRegisterVariable_i("KEY_PAGEUP", MTR_KEY_PAGEUP);
    MTR_ScriptsRegisterVariable_i("KEY_DELETE", MTR_KEY_DELETE);
    MTR_ScriptsRegisterVariable_i("KEY_END", MTR_KEY_END);
    MTR_ScriptsRegisterVariable_i("KEY_PAGEDOWN", MTR_KEY_PAGEDOWN);
    MTR_ScriptsRegisterVariable_i("KEY_RIGHT", MTR_KEY_RIGHT);
    MTR_ScriptsRegisterVariable_i("KEY_LEFT", MTR_KEY_LEFT);
    MTR_ScriptsRegisterVariable_i("KEY_DOWN", MTR_KEY_DOWN);
    MTR_ScriptsRegisterVariable_i("KEY_UP", MTR_KEY_UP);

    MTR_ScriptsRegisterVariable_i("KEY_NUMLOCKCLEAR", MTR_KEY_NUMLOCKCLEAR);
    MTR_ScriptsRegisterVariable_i("KEY_KP_DIVIDE", MTR_KEY_KP_DIVIDE);
    MTR_ScriptsRegisterVariable_i("KEY_KP_MULTIPLY", MTR_KEY_KP_MULTIPLY);
    MTR_ScriptsRegisterVariable_i("KEY_KP_MINUS", MTR_KEY_KP_MINUS);
    MTR_ScriptsRegisterVariable_i("KEY_KP_PLUS", MTR_KEY_KP_PLUS);
    MTR_ScriptsRegisterVariable_i("KEY_KP_ENTER", MTR_KEY_KP_ENTER);
    MTR_ScriptsRegisterVariable_i("KEY_KP_1", MTR_KEY_KP_1);
    MTR_ScriptsRegisterVariable_i("KEY_KP_2", MTR_KEY_KP_2);
    MTR_ScriptsRegisterVariable_i("KEY_KP_3", MTR_KEY_KP_3);
    MTR_ScriptsRegisterVariable_i("KEY_KP_4", MTR_KEY_KP_4);
    MTR_ScriptsRegisterVariable_i("KEY_KP_5", MTR_KEY_KP_5);
    MTR_ScriptsRegisterVariable_i("KEY_KP_6", MTR_KEY_KP_6);
    MTR_ScriptsRegisterVariable_i("KEY_KP_7", MTR_KEY_KP_7);
    MTR_ScriptsRegisterVariable_i("KEY_KP_8", MTR_KEY_KP_8);
    MTR_ScriptsRegisterVariable_i("KEY_KP_9", MTR_KEY_KP_9);
    MTR_ScriptsRegisterVariable_i("KEY_KP_0", MTR_KEY_KP_0);
    MTR_ScriptsRegisterVariable_i("KEY_KP_PERIOD", MTR_KEY_KP_PERIOD);

    MTR_ScriptsRegisterVariable_i("KEY_NONUSBACKSLASH", MTR_KEY_NONUSBACKSLASH);
    MTR_ScriptsRegisterVariable_i("KEY_APPLICATION", MTR_KEY_APPLICATION);
    MTR_ScriptsRegisterVariable_i("KEY_POWER", MTR_KEY_POWER);
    MTR_ScriptsRegisterVariable_i("KEY_KP_EQUALS", MTR_KEY_KP_EQUALS);
    MTR_ScriptsRegisterVariable_i("KEY_F13", MTR_KEY_F13);
    MTR_ScriptsRegisterVariable_i("KEY_F14", MTR_KEY_F14);
    MTR_ScriptsRegisterVariable_i("KEY_F15", MTR_KEY_F15);
    MTR_ScriptsRegisterVariable_i("KEY_F16", MTR_KEY_F16);
    MTR_ScriptsRegisterVariable_i("KEY_F17", MTR_KEY_F17);
    MTR_ScriptsRegisterVariable_i("KEY_F18", MTR_KEY_F18);
    MTR_ScriptsRegisterVariable_i("KEY_F19", MTR_KEY_F19);
    MTR_ScriptsRegisterVariable_i("KEY_F20", MTR_KEY_F20);
    MTR_ScriptsRegisterVariable_i("KEY_F21", MTR_KEY_F21);
    MTR_ScriptsRegisterVariable_i("KEY_F22", MTR_KEY_F22);
    MTR_ScriptsRegisterVariable_i("KEY_F23", MTR_KEY_F23);
    MTR_ScriptsRegisterVariable_i("KEY_F24", MTR_KEY_F24);
    MTR_ScriptsRegisterVariable_i("KEY_EXECUTE", MTR_KEY_EXECUTE);
    MTR_ScriptsRegisterVariable_i("KEY_HELP", MTR_KEY_HELP);
    MTR_ScriptsRegisterVariable_i("KEY_MENU", MTR_KEY_MENU);
    MTR_ScriptsRegisterVariable_i("KEY_SELECT", MTR_KEY_SELECT);
    MTR_ScriptsRegisterVariable_i("KEY_STOP", MTR_KEY_STOP);
    MTR_ScriptsRegisterVariable_i("KEY_AGAIN", MTR_KEY_AGAIN);
    MTR_ScriptsRegisterVariable_i("KEY_UNDO", MTR_KEY_UNDO);
    MTR_ScriptsRegisterVariable_i("KEY_CUT", MTR_KEY_CUT);
    MTR_ScriptsRegisterVariable_i("KEY_COPY", MTR_KEY_COPY);
    MTR_ScriptsRegisterVariable_i("KEY_PASTE", MTR_KEY_PASTE);
    MTR_ScriptsRegisterVariable_i("KEY_FIND", MTR_KEY_FIND);
    MTR_ScriptsRegisterVariable_i("KEY_MUTE", MTR_KEY_MUTE);
    MTR_ScriptsRegisterVariable_i("KEY_VOLUMEUP", MTR_KEY_VOLUMEUP);
    MTR_ScriptsRegisterVariable_i("KEY_VOLUMEDOWN", MTR_KEY_VOLUMEDOWN);

    MTR_ScriptsRegisterVariable_i("KEY_KP_COMMA", MTR_KEY_KP_COMMA);
    MTR_ScriptsRegisterVariable_i("KEY_KP_EQUALSAS400", MTR_KEY_KP_EQUALSAS400);

    MTR_ScriptsRegisterVariable_i("KEY_INTERNATIONAL1", MTR_KEY_INTERNATIONAL1);
    MTR_ScriptsRegisterVariable_i("KEY_INTERNATIONAL2", MTR_KEY_INTERNATIONAL2);
    MTR_ScriptsRegisterVariable_i("KEY_INTERNATIONAL3", MTR_KEY_INTERNATIONAL3);
    MTR_ScriptsRegisterVariable_i("KEY_INTERNATIONAL4", MTR_KEY_INTERNATIONAL4);
    MTR_ScriptsRegisterVariable_i("KEY_INTERNATIONAL5", MTR_KEY_INTERNATIONAL5);
    MTR_ScriptsRegisterVariable_i("KEY_INTERNATIONAL6", MTR_KEY_INTERNATIONAL6);
    MTR_ScriptsRegisterVariable_i("KEY_INTERNATIONAL7", MTR_KEY_INTERNATIONAL7);
    MTR_ScriptsRegisterVariable_i("KEY_INTERNATIONAL8", MTR_KEY_INTERNATIONAL8);
    MTR_ScriptsRegisterVariable_i("KEY_INTERNATIONAL9", MTR_KEY_INTERNATIONAL9);
    MTR_ScriptsRegisterVariable_i("KEY_LANG1", MTR_KEY_LANG1);
    MTR_ScriptsRegisterVariable_i("KEY_LANG2", MTR_KEY_LANG2);
    MTR_ScriptsRegisterVariable_i("KEY_LANG3", MTR_KEY_LANG3);
    MTR_ScriptsRegisterVariable_i("KEY_LANG4", MTR_KEY_LANG4);
    MTR_ScriptsRegisterVariable_i("KEY_LANG5", MTR_KEY_LANG5);
    MTR_ScriptsRegisterVariable_i("KEY_LANG6", MTR_KEY_LANG6);
    MTR_ScriptsRegisterVariable_i("KEY_LANG7", MTR_KEY_LANG7);
    MTR_ScriptsRegisterVariable_i("KEY_LANG8", MTR_KEY_LANG8);
    MTR_ScriptsRegisterVariable_i("KEY_LANG9", MTR_KEY_LANG9);

    MTR_ScriptsRegisterVariable_i("KEY_ALTERASE", MTR_KEY_ALTERASE);
    MTR_ScriptsRegisterVariable_i("KEY_SYSREQ", MTR_KEY_SYSREQ);
    MTR_ScriptsRegisterVariable_i("KEY_CANCEL", MTR_KEY_CANCEL);
    MTR_ScriptsRegisterVariable_i("KEY_CLEAR", MTR_KEY_CLEAR);
    MTR_ScriptsRegisterVariable_i("KEY_PRIOR", MTR_KEY_PRIOR);
    MTR_ScriptsRegisterVariable_i("KEY_RETURN2", MTR_KEY_RETURN2);
    MTR_ScriptsRegisterVariable_i("KEY_SEPARATOR", MTR_KEY_SEPARATOR);
    MTR_ScriptsRegisterVariable_i("KEY_OUT", MTR_KEY_OUT);
    MTR_ScriptsRegisterVariable_i("KEY_OPER", MTR_KEY_OPER);
    MTR_ScriptsRegisterVariable_i("KEY_CLEARAGAIN", MTR_KEY_CLEARAGAIN);
    MTR_ScriptsRegisterVariable_i("KEY_CRSEL", MTR_KEY_CRSEL);
    MTR_ScriptsRegisterVariable_i("KEY_EXSEL", MTR_KEY_EXSEL);

    MTR_ScriptsRegisterVariable_i("KEY_KP_00", MTR_KEY_KP_00);
    MTR_ScriptsRegisterVariable_i("KEY_KP_000", MTR_KEY_KP_000);
    MTR_ScriptsRegisterVariable_i("KEY_THOUSANDSSEPARATOR",
     MTR_KEY_THOUSANDSSEPARATOR);
    MTR_ScriptsRegisterVariable_i("KEY_DECIMALSEPARATOR",
     MTR_KEY_DECIMALSEPARATOR);
    MTR_ScriptsRegisterVariable_i("KEY_CURRENCYUNIT", MTR_KEY_CURRENCYUNIT);
    MTR_ScriptsRegisterVariable_i("KEY_CURRENCYSUBUNIT",
     MTR_KEY_CURRENCYSUBUNIT);
    MTR_ScriptsRegisterVariable_i("KEY_KP_LEFTPAREN", MTR_KEY_KP_LEFTPAREN);
    MTR_ScriptsRegisterVariable_i("KEY_KP_RIGHTPAREN", MTR_KEY_KP_RIGHTPAREN);
    MTR_ScriptsRegisterVariable_i("KEY_KP_LEFTBRACE", MTR_KEY_KP_LEFTBRACE);
    MTR_ScriptsRegisterVariable_i("KEY_KP_RIGHTBRACE", MTR_KEY_KP_RIGHTBRACE);
    MTR_ScriptsRegisterVariable_i("KEY_KP_TAB", MTR_KEY_KP_TAB);
    MTR_ScriptsRegisterVariable_i("KEY_KP_BACKSPACE", MTR_KEY_KP_BACKSPACE);
    MTR_ScriptsRegisterVariable_i("KEY_KP_A", MTR_KEY_KP_A);
    MTR_ScriptsRegisterVariable_i("KEY_KP_B", MTR_KEY_KP_B);
    MTR_ScriptsRegisterVariable_i("KEY_KP_C", MTR_KEY_KP_C);
    MTR_ScriptsRegisterVariable_i("KEY_KP_D", MTR_KEY_KP_D);
    MTR_ScriptsRegisterVariable_i("KEY_KP_E", MTR_KEY_KP_E);
    MTR_ScriptsRegisterVariable_i("KEY_KP_F", MTR_KEY_KP_F);
    MTR_ScriptsRegisterVariable_i("KEY_KP_XOR", MTR_KEY_KP_XOR);
    MTR_ScriptsRegisterVariable_i("KEY_KP_POWER", MTR_KEY_KP_POWER);
    MTR_ScriptsRegisterVariable_i("KEY_KP_PERCENT", MTR_KEY_KP_PERCENT);
    MTR_ScriptsRegisterVariable_i("KEY_KP_LESS", MTR_KEY_KP_LESS);
    MTR_ScriptsRegisterVariable_i("KEY_KP_GREATER", MTR_KEY_KP_GREATER);
    MTR_ScriptsRegisterVariable_i("KEY_KP_AMPERSAND", MTR_KEY_KP_AMPERSAND);
    MTR_ScriptsRegisterVariable_i("KEY_KP_DBLAMPERSAND",
     MTR_KEY_KP_DBLAMPERSAND);
    MTR_ScriptsRegisterVariable_i("KEY_KP_VERTICALBAR", MTR_KEY_KP_VERTICALBAR);
    MTR_ScriptsRegisterVariable_i("KEY_KP_DBLVERTICALBAR",
     MTR_KEY_KP_DBLVERTICALBAR);
    MTR_ScriptsRegisterVariable_i("KEY_KP_COLON", MTR_KEY_KP_COLON);
    MTR_ScriptsRegisterVariable_i("KEY_KP_HASH", MTR_KEY_KP_HASH);
    MTR_ScriptsRegisterVariable_i("KEY_KP_SPACE", MTR_KEY_KP_SPACE);
    MTR_ScriptsRegisterVariable_i("KEY_KP_AT", MTR_KEY_KP_AT);
    MTR_ScriptsRegisterVariable_i("KEY_KP_EXCLAM", MTR_KEY_KP_EXCLAM);
    MTR_ScriptsRegisterVariable_i("KEY_KP_MEMSTORE", MTR_KEY_KP_MEMSTORE);
    MTR_ScriptsRegisterVariable_i("KEY_KP_MEMRECALL", MTR_KEY_KP_MEMRECALL);
    MTR_ScriptsRegisterVariable_i("KEY_KP_MEMCLEAR", MTR_KEY_KP_MEMCLEAR);
    MTR_ScriptsRegisterVariable_i("KEY_KP_MEMADD", MTR_KEY_KP_MEMADD);
    MTR_ScriptsRegisterVariable_i("KEY_KP_MEMSUBTRACT", MTR_KEY_KP_MEMSUBTRACT);
    MTR_ScriptsRegisterVariable_i("KEY_KP_MEMMULTIPLY", MTR_KEY_KP_MEMMULTIPLY);
    MTR_ScriptsRegisterVariable_i("KEY_KP_MEMDIVIDE", MTR_KEY_KP_MEMDIVIDE);
    MTR_ScriptsRegisterVariable_i("KEY_KP_PLUSMINUS", MTR_KEY_KP_PLUSMINUS);
    MTR_ScriptsRegisterVariable_i("KEY_KP_CLEAR", MTR_KEY_KP_CLEAR);
    MTR_ScriptsRegisterVariable_i("KEY_KP_CLEARENTRY", MTR_KEY_KP_CLEARENTRY);
    MTR_ScriptsRegisterVariable_i("KEY_KP_BINARY", MTR_KEY_KP_BINARY);
    MTR_ScriptsRegisterVariable_i("KEY_KP_OCTAL", MTR_KEY_KP_OCTAL);
    MTR_ScriptsRegisterVariable_i("KEY_KP_DECIMAL", MTR_KEY_KP_DECIMAL);
    MTR_ScriptsRegisterVariable_i("KEY_KP_HEXADECIMAL", MTR_KEY_KP_HEXADECIMAL);

    MTR_ScriptsRegisterVariable_i("KEY_LCTRL", MTR_KEY_LCTRL);
    MTR_ScriptsRegisterVariable_i("KEY_LSHIFT", MTR_KEY_LSHIFT);
    MTR_ScriptsRegisterVariable_i("KEY_LALT", MTR_KEY_LALT);
    MTR_ScriptsRegisterVariable_i("KEY_LGUI", MTR_KEY_LGUI);
    MTR_ScriptsRegisterVariable_i("KEY_RCTRL", MTR_KEY_RCTRL);
    MTR_ScriptsRegisterVariable_i("KEY_RSHIFT", MTR_KEY_RSHIFT);
    MTR_ScriptsRegisterVariable_i("KEY_RALT", MTR_KEY_RALT);
    MTR_ScriptsRegisterVariable_i("KEY_RGUI", MTR_KEY_RGUI);

    MTR_ScriptsRegisterVariable_i("KEY_MODE", MTR_KEY_MODE);

    MTR_ScriptsRegisterVariable_i("KEY_AUDIONEXT", MTR_KEY_AUDIONEXT);
    MTR_ScriptsRegisterVariable_i("KEY_AUDIOPREV", MTR_KEY_AUDIOPREV);
    MTR_ScriptsRegisterVariable_i("KEY_AUDIOSTOP", MTR_KEY_AUDIOSTOP);
    MTR_ScriptsRegisterVariable_i("KEY_AUDIOPLAY", MTR_KEY_AUDIOPLAY);
    MTR_ScriptsRegisterVariable_i("KEY_AUDIOMUTE", MTR_KEY_AUDIOMUTE);
    MTR_ScriptsRegisterVariable_i("KEY_MEDIASELECT", MTR_KEY_MEDIASELECT);
    MTR_ScriptsRegisterVariable_i("KEY_WWW", MTR_KEY_WWW);
    MTR_ScriptsRegisterVariable_i("KEY_MAIL", MTR_KEY_MAIL);
    MTR_ScriptsRegisterVariable_i("KEY_CALCULATOR", MTR_KEY_CALCULATOR);
    MTR_ScriptsRegisterVariable_i("KEY_COMPUTER", MTR_KEY_COMPUTER);
    MTR_ScriptsRegisterVariable_i("KEY_AC_SEARCH", MTR_KEY_AC_SEARCH);
    MTR_ScriptsRegisterVariable_i("KEY_AC_HOME", MTR_KEY_AC_HOME);
    MTR_ScriptsRegisterVariable_i("KEY_AC_BACK", MTR_KEY_AC_BACK);
    MTR_ScriptsRegisterVariable_i("KEY_AC_FORWARD", MTR_KEY_AC_FORWARD);
    MTR_ScriptsRegisterVariable_i("KEY_AC_STOP", MTR_KEY_AC_STOP);
    MTR_ScriptsRegisterVariable_i("KEY_AC_REFRESH", MTR_KEY_AC_REFRESH);
    MTR_ScriptsRegisterVariable_i("KEY_AC_BOOKMARKS", MTR_KEY_AC_BOOKMARKS);

    MTR_ScriptsRegisterVariable_i("KEY_BRIGHTNESSDOWN", MTR_KEY_BRIGHTNESSDOWN);
    MTR_ScriptsRegisterVariable_i("KEY_BRIGHTNESSUP", MTR_KEY_BRIGHTNESSUP);
    MTR_ScriptsRegisterVariable_i("KEY_DISPLAYSWITCH", MTR_KEY_DISPLAYSWITCH);
    MTR_ScriptsRegisterVariable_i("KEY_KBDILLUMTOGGLE", MTR_KEY_KBDILLUMTOGGLE);
    MTR_ScriptsRegisterVariable_i("KEY_KBDILLUMDOWN", MTR_KEY_KBDILLUMDOWN);
    MTR_ScriptsRegisterVariable_i("KEY_KBDILLUMUP", MTR_KEY_KBDILLUMUP);
    MTR_ScriptsRegisterVariable_i("KEY_EJECT", MTR_KEY_EJECT);
    MTR_ScriptsRegisterVariable_i("KEY_SLEEP", MTR_KEY_SLEEP);

    MTR_ScriptsRegisterVariable_i("KEY_APP1", MTR_KEY_APP1);
    MTR_ScriptsRegisterVariable_i("KEY_APP2", MTR_KEY_APP2);
}

#endif
