#ifndef MTR_KEYBOARD_BINDING_COMMON_C
#define MTR_KEYBOARD_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(mtrSF_KeyboardFunctionSupported,
 mtrKeyboardFunctionSupported)
MTR_SCRIPT_FUNC_B_V(mtrSF_KeyboardInit, mtrKeyboardInit)
MTR_SCRIPT_FUNC_V_V(mtrSF_KeyboardRefresh, mtrKeyboardRefresh)
MTR_SCRIPT_FUNC_B_I1(mtrSF_KeyboardPress, mtrKeyboardPress)
MTR_SCRIPT_FUNC_B_I1(mtrSF_KeyboardRelease, mtrKeyboardRelease)
MTR_SCRIPT_FUNC_B_I1(mtrSF_KeyboardPressed, mtrKeyboardPressed)

MTR_SCRIPT_FUNC(mtrSF_KeyboardInputChar)
{
    char *utf8char;

    utf8char = mtrKeyboardInputChar();
    if (utf8char == NULL)
        MTR_SF_PUSH_NIL();
    else
        MTR_SF_PUSH_STRING(utf8char);

    return 1;
}

void mtrScriptsRegisterAll(void)
{
    mtrVm = mtrScriptsGetVm();

    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, KeyboardFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, KeyboardInit);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, KeyboardRefresh);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, KeyboardPress);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, KeyboardRelease);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, KeyboardPressed);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, KeyboardInputChar);

    mtrScriptsRegisterVariable_i("KEY_A", MTR_KEY_A);
    mtrScriptsRegisterVariable_i("KEY_B", MTR_KEY_B);
    mtrScriptsRegisterVariable_i("KEY_C", MTR_KEY_C);
    mtrScriptsRegisterVariable_i("KEY_D", MTR_KEY_D);
    mtrScriptsRegisterVariable_i("KEY_E", MTR_KEY_E);
    mtrScriptsRegisterVariable_i("KEY_F", MTR_KEY_F);
    mtrScriptsRegisterVariable_i("KEY_G", MTR_KEY_G);
    mtrScriptsRegisterVariable_i("KEY_H", MTR_KEY_H);
    mtrScriptsRegisterVariable_i("KEY_I", MTR_KEY_I);
    mtrScriptsRegisterVariable_i("KEY_J", MTR_KEY_J);
    mtrScriptsRegisterVariable_i("KEY_K", MTR_KEY_K);
    mtrScriptsRegisterVariable_i("KEY_L", MTR_KEY_L);
    mtrScriptsRegisterVariable_i("KEY_M", MTR_KEY_M);
    mtrScriptsRegisterVariable_i("KEY_N", MTR_KEY_N);
    mtrScriptsRegisterVariable_i("KEY_O", MTR_KEY_O);
    mtrScriptsRegisterVariable_i("KEY_P", MTR_KEY_P);
    mtrScriptsRegisterVariable_i("KEY_Q", MTR_KEY_Q);
    mtrScriptsRegisterVariable_i("KEY_R", MTR_KEY_R);
    mtrScriptsRegisterVariable_i("KEY_S", MTR_KEY_S);
    mtrScriptsRegisterVariable_i("KEY_T", MTR_KEY_T);
    mtrScriptsRegisterVariable_i("KEY_U", MTR_KEY_U);
    mtrScriptsRegisterVariable_i("KEY_V", MTR_KEY_V);
    mtrScriptsRegisterVariable_i("KEY_W", MTR_KEY_W);
    mtrScriptsRegisterVariable_i("KEY_X", MTR_KEY_X);
    mtrScriptsRegisterVariable_i("KEY_Y", MTR_KEY_Y);
    mtrScriptsRegisterVariable_i("KEY_Z", MTR_KEY_Z);

    mtrScriptsRegisterVariable_i("KEY_1", MTR_KEY_1);
    mtrScriptsRegisterVariable_i("KEY_2", MTR_KEY_2);
    mtrScriptsRegisterVariable_i("KEY_3", MTR_KEY_3);
    mtrScriptsRegisterVariable_i("KEY_4", MTR_KEY_4);
    mtrScriptsRegisterVariable_i("KEY_5", MTR_KEY_5);
    mtrScriptsRegisterVariable_i("KEY_6", MTR_KEY_6);
    mtrScriptsRegisterVariable_i("KEY_7", MTR_KEY_7);
    mtrScriptsRegisterVariable_i("KEY_8", MTR_KEY_8);
    mtrScriptsRegisterVariable_i("KEY_9", MTR_KEY_9);
    mtrScriptsRegisterVariable_i("KEY_0", MTR_KEY_0);

    mtrScriptsRegisterVariable_i("KEY_RETURN", MTR_KEY_RETURN);
    mtrScriptsRegisterVariable_i("KEY_ESCAPE", MTR_KEY_ESCAPE);
    mtrScriptsRegisterVariable_i("KEY_BACKSPACE", MTR_KEY_BACKSPACE);
    mtrScriptsRegisterVariable_i("KEY_TAB", MTR_KEY_TAB);
    mtrScriptsRegisterVariable_i("KEY_SPACE", MTR_KEY_SPACE);

    mtrScriptsRegisterVariable_i("KEY_MINUS", MTR_KEY_MINUS);
    mtrScriptsRegisterVariable_i("KEY_EQUALS", MTR_KEY_EQUALS);
    mtrScriptsRegisterVariable_i("KEY_LEFTBRACKET", MTR_KEY_LEFTBRACKET);
    mtrScriptsRegisterVariable_i("KEY_RIGHTBRACKET", MTR_KEY_RIGHTBRACKET);
    mtrScriptsRegisterVariable_i("KEY_BACKSLASH", MTR_KEY_BACKSLASH);
    mtrScriptsRegisterVariable_i("KEY_NONUSHASH", MTR_KEY_NONUSHASH);
    mtrScriptsRegisterVariable_i("KEY_SEMICOLON", MTR_KEY_SEMICOLON);
    mtrScriptsRegisterVariable_i("KEY_APOSTROPHE", MTR_KEY_APOSTROPHE);
    mtrScriptsRegisterVariable_i("KEY_GRAVE", MTR_KEY_GRAVE);
    mtrScriptsRegisterVariable_i("KEY_COMMA", MTR_KEY_COMMA);
    mtrScriptsRegisterVariable_i("KEY_PERIOD", MTR_KEY_PERIOD);
    mtrScriptsRegisterVariable_i("KEY_SLASH", MTR_KEY_SLASH);

    mtrScriptsRegisterVariable_i("KEY_CAPSLOCK", MTR_KEY_CAPSLOCK);

    mtrScriptsRegisterVariable_i("KEY_F1", MTR_KEY_F1);
    mtrScriptsRegisterVariable_i("KEY_F2", MTR_KEY_F2);
    mtrScriptsRegisterVariable_i("KEY_F3", MTR_KEY_F3);
    mtrScriptsRegisterVariable_i("KEY_F4", MTR_KEY_F4);
    mtrScriptsRegisterVariable_i("KEY_F5", MTR_KEY_F5);
    mtrScriptsRegisterVariable_i("KEY_F6", MTR_KEY_F6);
    mtrScriptsRegisterVariable_i("KEY_F7", MTR_KEY_F7);
    mtrScriptsRegisterVariable_i("KEY_F8", MTR_KEY_F8);
    mtrScriptsRegisterVariable_i("KEY_F9", MTR_KEY_F9);
    mtrScriptsRegisterVariable_i("KEY_F10", MTR_KEY_F10);
    mtrScriptsRegisterVariable_i("KEY_F11", MTR_KEY_F11);
    mtrScriptsRegisterVariable_i("KEY_F12", MTR_KEY_F12);

    mtrScriptsRegisterVariable_i("KEY_PRINTSCREEN", MTR_KEY_PRINTSCREEN);
    mtrScriptsRegisterVariable_i("KEY_SCROLLLOCK", MTR_KEY_SCROLLLOCK);
    mtrScriptsRegisterVariable_i("KEY_PAUSE", MTR_KEY_PAUSE);
    mtrScriptsRegisterVariable_i("KEY_INSERT", MTR_KEY_INSERT);
    mtrScriptsRegisterVariable_i("KEY_HOME", MTR_KEY_HOME);
    mtrScriptsRegisterVariable_i("KEY_PAGEUP", MTR_KEY_PAGEUP);
    mtrScriptsRegisterVariable_i("KEY_DELETE", MTR_KEY_DELETE);
    mtrScriptsRegisterVariable_i("KEY_END", MTR_KEY_END);
    mtrScriptsRegisterVariable_i("KEY_PAGEDOWN", MTR_KEY_PAGEDOWN);
    mtrScriptsRegisterVariable_i("KEY_RIGHT", MTR_KEY_RIGHT);
    mtrScriptsRegisterVariable_i("KEY_LEFT", MTR_KEY_LEFT);
    mtrScriptsRegisterVariable_i("KEY_DOWN", MTR_KEY_DOWN);
    mtrScriptsRegisterVariable_i("KEY_UP", MTR_KEY_UP);

    mtrScriptsRegisterVariable_i("KEY_NUMLOCKCLEAR", MTR_KEY_NUMLOCKCLEAR);
    mtrScriptsRegisterVariable_i("KEY_KP_DIVIDE", MTR_KEY_KP_DIVIDE);
    mtrScriptsRegisterVariable_i("KEY_KP_MULTIPLY", MTR_KEY_KP_MULTIPLY);
    mtrScriptsRegisterVariable_i("KEY_KP_MINUS", MTR_KEY_KP_MINUS);
    mtrScriptsRegisterVariable_i("KEY_KP_PLUS", MTR_KEY_KP_PLUS);
    mtrScriptsRegisterVariable_i("KEY_KP_ENTER", MTR_KEY_KP_ENTER);
    mtrScriptsRegisterVariable_i("KEY_KP_1", MTR_KEY_KP_1);
    mtrScriptsRegisterVariable_i("KEY_KP_2", MTR_KEY_KP_2);
    mtrScriptsRegisterVariable_i("KEY_KP_3", MTR_KEY_KP_3);
    mtrScriptsRegisterVariable_i("KEY_KP_4", MTR_KEY_KP_4);
    mtrScriptsRegisterVariable_i("KEY_KP_5", MTR_KEY_KP_5);
    mtrScriptsRegisterVariable_i("KEY_KP_6", MTR_KEY_KP_6);
    mtrScriptsRegisterVariable_i("KEY_KP_7", MTR_KEY_KP_7);
    mtrScriptsRegisterVariable_i("KEY_KP_8", MTR_KEY_KP_8);
    mtrScriptsRegisterVariable_i("KEY_KP_9", MTR_KEY_KP_9);
    mtrScriptsRegisterVariable_i("KEY_KP_0", MTR_KEY_KP_0);
    mtrScriptsRegisterVariable_i("KEY_KP_PERIOD", MTR_KEY_KP_PERIOD);

    mtrScriptsRegisterVariable_i("KEY_NONUSBACKSLASH", MTR_KEY_NONUSBACKSLASH);
    mtrScriptsRegisterVariable_i("KEY_APPLICATION", MTR_KEY_APPLICATION);
    mtrScriptsRegisterVariable_i("KEY_POWER", MTR_KEY_POWER);
    mtrScriptsRegisterVariable_i("KEY_KP_EQUALS", MTR_KEY_KP_EQUALS);
    mtrScriptsRegisterVariable_i("KEY_F13", MTR_KEY_F13);
    mtrScriptsRegisterVariable_i("KEY_F14", MTR_KEY_F14);
    mtrScriptsRegisterVariable_i("KEY_F15", MTR_KEY_F15);
    mtrScriptsRegisterVariable_i("KEY_F16", MTR_KEY_F16);
    mtrScriptsRegisterVariable_i("KEY_F17", MTR_KEY_F17);
    mtrScriptsRegisterVariable_i("KEY_F18", MTR_KEY_F18);
    mtrScriptsRegisterVariable_i("KEY_F19", MTR_KEY_F19);
    mtrScriptsRegisterVariable_i("KEY_F20", MTR_KEY_F20);
    mtrScriptsRegisterVariable_i("KEY_F21", MTR_KEY_F21);
    mtrScriptsRegisterVariable_i("KEY_F22", MTR_KEY_F22);
    mtrScriptsRegisterVariable_i("KEY_F23", MTR_KEY_F23);
    mtrScriptsRegisterVariable_i("KEY_F24", MTR_KEY_F24);
    mtrScriptsRegisterVariable_i("KEY_EXECUTE", MTR_KEY_EXECUTE);
    mtrScriptsRegisterVariable_i("KEY_HELP", MTR_KEY_HELP);
    mtrScriptsRegisterVariable_i("KEY_MENU", MTR_KEY_MENU);
    mtrScriptsRegisterVariable_i("KEY_SELECT", MTR_KEY_SELECT);
    mtrScriptsRegisterVariable_i("KEY_STOP", MTR_KEY_STOP);
    mtrScriptsRegisterVariable_i("KEY_AGAIN", MTR_KEY_AGAIN);
    mtrScriptsRegisterVariable_i("KEY_UNDO", MTR_KEY_UNDO);
    mtrScriptsRegisterVariable_i("KEY_CUT", MTR_KEY_CUT);
    mtrScriptsRegisterVariable_i("KEY_COPY", MTR_KEY_COPY);
    mtrScriptsRegisterVariable_i("KEY_PASTE", MTR_KEY_PASTE);
    mtrScriptsRegisterVariable_i("KEY_FIND", MTR_KEY_FIND);
    mtrScriptsRegisterVariable_i("KEY_MUTE", MTR_KEY_MUTE);
    mtrScriptsRegisterVariable_i("KEY_VOLUMEUP", MTR_KEY_VOLUMEUP);
    mtrScriptsRegisterVariable_i("KEY_VOLUMEDOWN", MTR_KEY_VOLUMEDOWN);

    mtrScriptsRegisterVariable_i("KEY_KP_COMMA", MTR_KEY_KP_COMMA);
    mtrScriptsRegisterVariable_i("KEY_KP_EQUALSAS400", MTR_KEY_KP_EQUALSAS400);

    mtrScriptsRegisterVariable_i("KEY_INTERNATIONAL1", MTR_KEY_INTERNATIONAL1);
    mtrScriptsRegisterVariable_i("KEY_INTERNATIONAL2", MTR_KEY_INTERNATIONAL2);
    mtrScriptsRegisterVariable_i("KEY_INTERNATIONAL3", MTR_KEY_INTERNATIONAL3);
    mtrScriptsRegisterVariable_i("KEY_INTERNATIONAL4", MTR_KEY_INTERNATIONAL4);
    mtrScriptsRegisterVariable_i("KEY_INTERNATIONAL5", MTR_KEY_INTERNATIONAL5);
    mtrScriptsRegisterVariable_i("KEY_INTERNATIONAL6", MTR_KEY_INTERNATIONAL6);
    mtrScriptsRegisterVariable_i("KEY_INTERNATIONAL7", MTR_KEY_INTERNATIONAL7);
    mtrScriptsRegisterVariable_i("KEY_INTERNATIONAL8", MTR_KEY_INTERNATIONAL8);
    mtrScriptsRegisterVariable_i("KEY_INTERNATIONAL9", MTR_KEY_INTERNATIONAL9);
    mtrScriptsRegisterVariable_i("KEY_LANG1", MTR_KEY_LANG1);
    mtrScriptsRegisterVariable_i("KEY_LANG2", MTR_KEY_LANG2);
    mtrScriptsRegisterVariable_i("KEY_LANG3", MTR_KEY_LANG3);
    mtrScriptsRegisterVariable_i("KEY_LANG4", MTR_KEY_LANG4);
    mtrScriptsRegisterVariable_i("KEY_LANG5", MTR_KEY_LANG5);
    mtrScriptsRegisterVariable_i("KEY_LANG6", MTR_KEY_LANG6);
    mtrScriptsRegisterVariable_i("KEY_LANG7", MTR_KEY_LANG7);
    mtrScriptsRegisterVariable_i("KEY_LANG8", MTR_KEY_LANG8);
    mtrScriptsRegisterVariable_i("KEY_LANG9", MTR_KEY_LANG9);

    mtrScriptsRegisterVariable_i("KEY_ALTERASE", MTR_KEY_ALTERASE);
    mtrScriptsRegisterVariable_i("KEY_SYSREQ", MTR_KEY_SYSREQ);
    mtrScriptsRegisterVariable_i("KEY_CANCEL", MTR_KEY_CANCEL);
    mtrScriptsRegisterVariable_i("KEY_CLEAR", MTR_KEY_CLEAR);
    mtrScriptsRegisterVariable_i("KEY_PRIOR", MTR_KEY_PRIOR);
    mtrScriptsRegisterVariable_i("KEY_RETURN2", MTR_KEY_RETURN2);
    mtrScriptsRegisterVariable_i("KEY_SEPARATOR", MTR_KEY_SEPARATOR);
    mtrScriptsRegisterVariable_i("KEY_OUT", MTR_KEY_OUT);
    mtrScriptsRegisterVariable_i("KEY_OPER", MTR_KEY_OPER);
    mtrScriptsRegisterVariable_i("KEY_CLEARAGAIN", MTR_KEY_CLEARAGAIN);
    mtrScriptsRegisterVariable_i("KEY_CRSEL", MTR_KEY_CRSEL);
    mtrScriptsRegisterVariable_i("KEY_EXSEL", MTR_KEY_EXSEL);

    mtrScriptsRegisterVariable_i("KEY_KP_00", MTR_KEY_KP_00);
    mtrScriptsRegisterVariable_i("KEY_KP_000", MTR_KEY_KP_000);
    mtrScriptsRegisterVariable_i("KEY_THOUSANDSSEPARATOR",
     MTR_KEY_THOUSANDSSEPARATOR);
    mtrScriptsRegisterVariable_i("KEY_DECIMALSEPARATOR",
     MTR_KEY_DECIMALSEPARATOR);
    mtrScriptsRegisterVariable_i("KEY_CURRENCYUNIT", MTR_KEY_CURRENCYUNIT);
    mtrScriptsRegisterVariable_i("KEY_CURRENCYSUBUNIT",
     MTR_KEY_CURRENCYSUBUNIT);
    mtrScriptsRegisterVariable_i("KEY_KP_LEFTPAREN", MTR_KEY_KP_LEFTPAREN);
    mtrScriptsRegisterVariable_i("KEY_KP_RIGHTPAREN", MTR_KEY_KP_RIGHTPAREN);
    mtrScriptsRegisterVariable_i("KEY_KP_LEFTBRACE", MTR_KEY_KP_LEFTBRACE);
    mtrScriptsRegisterVariable_i("KEY_KP_RIGHTBRACE", MTR_KEY_KP_RIGHTBRACE);
    mtrScriptsRegisterVariable_i("KEY_KP_TAB", MTR_KEY_KP_TAB);
    mtrScriptsRegisterVariable_i("KEY_KP_BACKSPACE", MTR_KEY_KP_BACKSPACE);
    mtrScriptsRegisterVariable_i("KEY_KP_A", MTR_KEY_KP_A);
    mtrScriptsRegisterVariable_i("KEY_KP_B", MTR_KEY_KP_B);
    mtrScriptsRegisterVariable_i("KEY_KP_C", MTR_KEY_KP_C);
    mtrScriptsRegisterVariable_i("KEY_KP_D", MTR_KEY_KP_D);
    mtrScriptsRegisterVariable_i("KEY_KP_E", MTR_KEY_KP_E);
    mtrScriptsRegisterVariable_i("KEY_KP_F", MTR_KEY_KP_F);
    mtrScriptsRegisterVariable_i("KEY_KP_XOR", MTR_KEY_KP_XOR);
    mtrScriptsRegisterVariable_i("KEY_KP_POWER", MTR_KEY_KP_POWER);
    mtrScriptsRegisterVariable_i("KEY_KP_PERCENT", MTR_KEY_KP_PERCENT);
    mtrScriptsRegisterVariable_i("KEY_KP_LESS", MTR_KEY_KP_LESS);
    mtrScriptsRegisterVariable_i("KEY_KP_GREATER", MTR_KEY_KP_GREATER);
    mtrScriptsRegisterVariable_i("KEY_KP_AMPERSAND", MTR_KEY_KP_AMPERSAND);
    mtrScriptsRegisterVariable_i("KEY_KP_DBLAMPERSAND",
     MTR_KEY_KP_DBLAMPERSAND);
    mtrScriptsRegisterVariable_i("KEY_KP_VERTICALBAR", MTR_KEY_KP_VERTICALBAR);
    mtrScriptsRegisterVariable_i("KEY_KP_DBLVERTICALBAR",
     MTR_KEY_KP_DBLVERTICALBAR);
    mtrScriptsRegisterVariable_i("KEY_KP_COLON", MTR_KEY_KP_COLON);
    mtrScriptsRegisterVariable_i("KEY_KP_HASH", MTR_KEY_KP_HASH);
    mtrScriptsRegisterVariable_i("KEY_KP_SPACE", MTR_KEY_KP_SPACE);
    mtrScriptsRegisterVariable_i("KEY_KP_AT", MTR_KEY_KP_AT);
    mtrScriptsRegisterVariable_i("KEY_KP_EXCLAM", MTR_KEY_KP_EXCLAM);
    mtrScriptsRegisterVariable_i("KEY_KP_MEMSTORE", MTR_KEY_KP_MEMSTORE);
    mtrScriptsRegisterVariable_i("KEY_KP_MEMRECALL", MTR_KEY_KP_MEMRECALL);
    mtrScriptsRegisterVariable_i("KEY_KP_MEMCLEAR", MTR_KEY_KP_MEMCLEAR);
    mtrScriptsRegisterVariable_i("KEY_KP_MEMADD", MTR_KEY_KP_MEMADD);
    mtrScriptsRegisterVariable_i("KEY_KP_MEMSUBTRACT", MTR_KEY_KP_MEMSUBTRACT);
    mtrScriptsRegisterVariable_i("KEY_KP_MEMMULTIPLY", MTR_KEY_KP_MEMMULTIPLY);
    mtrScriptsRegisterVariable_i("KEY_KP_MEMDIVIDE", MTR_KEY_KP_MEMDIVIDE);
    mtrScriptsRegisterVariable_i("KEY_KP_PLUSMINUS", MTR_KEY_KP_PLUSMINUS);
    mtrScriptsRegisterVariable_i("KEY_KP_CLEAR", MTR_KEY_KP_CLEAR);
    mtrScriptsRegisterVariable_i("KEY_KP_CLEARENTRY", MTR_KEY_KP_CLEARENTRY);
    mtrScriptsRegisterVariable_i("KEY_KP_BINARY", MTR_KEY_KP_BINARY);
    mtrScriptsRegisterVariable_i("KEY_KP_OCTAL", MTR_KEY_KP_OCTAL);
    mtrScriptsRegisterVariable_i("KEY_KP_DECIMAL", MTR_KEY_KP_DECIMAL);
    mtrScriptsRegisterVariable_i("KEY_KP_HEXADECIMAL", MTR_KEY_KP_HEXADECIMAL);

    mtrScriptsRegisterVariable_i("KEY_LCTRL", MTR_KEY_LCTRL);
    mtrScriptsRegisterVariable_i("KEY_LSHIFT", MTR_KEY_LSHIFT);
    mtrScriptsRegisterVariable_i("KEY_LALT", MTR_KEY_LALT);
    mtrScriptsRegisterVariable_i("KEY_LGUI", MTR_KEY_LGUI);
    mtrScriptsRegisterVariable_i("KEY_RCTRL", MTR_KEY_RCTRL);
    mtrScriptsRegisterVariable_i("KEY_RSHIFT", MTR_KEY_RSHIFT);
    mtrScriptsRegisterVariable_i("KEY_RALT", MTR_KEY_RALT);
    mtrScriptsRegisterVariable_i("KEY_RGUI", MTR_KEY_RGUI);

    mtrScriptsRegisterVariable_i("KEY_MODE", MTR_KEY_MODE);

    mtrScriptsRegisterVariable_i("KEY_AUDIONEXT", MTR_KEY_AUDIONEXT);
    mtrScriptsRegisterVariable_i("KEY_AUDIOPREV", MTR_KEY_AUDIOPREV);
    mtrScriptsRegisterVariable_i("KEY_AUDIOSTOP", MTR_KEY_AUDIOSTOP);
    mtrScriptsRegisterVariable_i("KEY_AUDIOPLAY", MTR_KEY_AUDIOPLAY);
    mtrScriptsRegisterVariable_i("KEY_AUDIOMUTE", MTR_KEY_AUDIOMUTE);
    mtrScriptsRegisterVariable_i("KEY_MEDIASELECT", MTR_KEY_MEDIASELECT);
    mtrScriptsRegisterVariable_i("KEY_WWW", MTR_KEY_WWW);
    mtrScriptsRegisterVariable_i("KEY_MAIL", MTR_KEY_MAIL);
    mtrScriptsRegisterVariable_i("KEY_CALCULATOR", MTR_KEY_CALCULATOR);
    mtrScriptsRegisterVariable_i("KEY_COMPUTER", MTR_KEY_COMPUTER);
    mtrScriptsRegisterVariable_i("KEY_AC_SEARCH", MTR_KEY_AC_SEARCH);
    mtrScriptsRegisterVariable_i("KEY_AC_HOME", MTR_KEY_AC_HOME);
    mtrScriptsRegisterVariable_i("KEY_AC_BACK", MTR_KEY_AC_BACK);
    mtrScriptsRegisterVariable_i("KEY_AC_FORWARD", MTR_KEY_AC_FORWARD);
    mtrScriptsRegisterVariable_i("KEY_AC_STOP", MTR_KEY_AC_STOP);
    mtrScriptsRegisterVariable_i("KEY_AC_REFRESH", MTR_KEY_AC_REFRESH);
    mtrScriptsRegisterVariable_i("KEY_AC_BOOKMARKS", MTR_KEY_AC_BOOKMARKS);

    mtrScriptsRegisterVariable_i("KEY_BRIGHTNESSDOWN", MTR_KEY_BRIGHTNESSDOWN);
    mtrScriptsRegisterVariable_i("KEY_BRIGHTNESSUP", MTR_KEY_BRIGHTNESSUP);
    mtrScriptsRegisterVariable_i("KEY_DISPLAYSWITCH", MTR_KEY_DISPLAYSWITCH);
    mtrScriptsRegisterVariable_i("KEY_KBDILLUMTOGGLE", MTR_KEY_KBDILLUMTOGGLE);
    mtrScriptsRegisterVariable_i("KEY_KBDILLUMDOWN", MTR_KEY_KBDILLUMDOWN);
    mtrScriptsRegisterVariable_i("KEY_KBDILLUMUP", MTR_KEY_KBDILLUMUP);
    mtrScriptsRegisterVariable_i("KEY_EJECT", MTR_KEY_EJECT);
    mtrScriptsRegisterVariable_i("KEY_SLEEP", MTR_KEY_SLEEP);

    mtrScriptsRegisterVariable_i("KEY_APP1", MTR_KEY_APP1);
    mtrScriptsRegisterVariable_i("KEY_APP2", MTR_KEY_APP2);
}

#endif
