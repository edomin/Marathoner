#ifndef MTR_KEYBOARD_BINDING_COMMON_C
#define MTR_KEYBOARD_BINDING_COMMON_C

#include "marathoner/script_func.h"

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
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();

    MTR_FIND_FUNCTION(mtrKeyboardInit, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrKeyboardRefresh, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrKeyboardPress, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrKeyboardRelease, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrKeyboardPressed, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrKeyboardInputChar, MTR_SOURCE_MODULE);

    if (ok)
    {
        mtrScriptsRegisterNumericVariable("KEY_A", MTR_KEY_A);
        mtrScriptsRegisterNumericVariable("KEY_B", MTR_KEY_B);
        mtrScriptsRegisterNumericVariable("KEY_C", MTR_KEY_C);
        mtrScriptsRegisterNumericVariable("KEY_D", MTR_KEY_D);
        mtrScriptsRegisterNumericVariable("KEY_E", MTR_KEY_E);
        mtrScriptsRegisterNumericVariable("KEY_F", MTR_KEY_F);
        mtrScriptsRegisterNumericVariable("KEY_G", MTR_KEY_G);
        mtrScriptsRegisterNumericVariable("KEY_H", MTR_KEY_H);
        mtrScriptsRegisterNumericVariable("KEY_I", MTR_KEY_I);
        mtrScriptsRegisterNumericVariable("KEY_J", MTR_KEY_J);
        mtrScriptsRegisterNumericVariable("KEY_K", MTR_KEY_K);
        mtrScriptsRegisterNumericVariable("KEY_L", MTR_KEY_L);
        mtrScriptsRegisterNumericVariable("KEY_M", MTR_KEY_M);
        mtrScriptsRegisterNumericVariable("KEY_N", MTR_KEY_N);
        mtrScriptsRegisterNumericVariable("KEY_O", MTR_KEY_O);
        mtrScriptsRegisterNumericVariable("KEY_P", MTR_KEY_P);
        mtrScriptsRegisterNumericVariable("KEY_Q", MTR_KEY_Q);
        mtrScriptsRegisterNumericVariable("KEY_R", MTR_KEY_R);
        mtrScriptsRegisterNumericVariable("KEY_S", MTR_KEY_S);
        mtrScriptsRegisterNumericVariable("KEY_T", MTR_KEY_T);
        mtrScriptsRegisterNumericVariable("KEY_U", MTR_KEY_U);
        mtrScriptsRegisterNumericVariable("KEY_V", MTR_KEY_V);
        mtrScriptsRegisterNumericVariable("KEY_W", MTR_KEY_W);
        mtrScriptsRegisterNumericVariable("KEY_X", MTR_KEY_X);
        mtrScriptsRegisterNumericVariable("KEY_Y", MTR_KEY_Y);
        mtrScriptsRegisterNumericVariable("KEY_Z", MTR_KEY_Z);

        mtrScriptsRegisterNumericVariable("KEY_1", MTR_KEY_1);
        mtrScriptsRegisterNumericVariable("KEY_2", MTR_KEY_2);
        mtrScriptsRegisterNumericVariable("KEY_3", MTR_KEY_3);
        mtrScriptsRegisterNumericVariable("KEY_4", MTR_KEY_4);
        mtrScriptsRegisterNumericVariable("KEY_5", MTR_KEY_5);
        mtrScriptsRegisterNumericVariable("KEY_6", MTR_KEY_6);
        mtrScriptsRegisterNumericVariable("KEY_7", MTR_KEY_7);
        mtrScriptsRegisterNumericVariable("KEY_8", MTR_KEY_8);
        mtrScriptsRegisterNumericVariable("KEY_9", MTR_KEY_9);
        mtrScriptsRegisterNumericVariable("KEY_0", MTR_KEY_0);

        mtrScriptsRegisterNumericVariable("KEY_RETURN", MTR_KEY_RETURN);
        mtrScriptsRegisterNumericVariable("KEY_ESCAPE", MTR_KEY_ESCAPE);
        mtrScriptsRegisterNumericVariable("KEY_BACKSPACE", MTR_KEY_BACKSPACE);
        mtrScriptsRegisterNumericVariable("KEY_TAB", MTR_KEY_TAB);
        mtrScriptsRegisterNumericVariable("KEY_SPACE", MTR_KEY_SPACE);

        mtrScriptsRegisterNumericVariable("KEY_MINUS", MTR_KEY_MINUS);
        mtrScriptsRegisterNumericVariable("KEY_EQUALS", MTR_KEY_EQUALS);
        mtrScriptsRegisterNumericVariable("KEY_LEFTBRACKET", MTR_KEY_LEFTBRACKET);
        mtrScriptsRegisterNumericVariable("KEY_RIGHTBRACKET", MTR_KEY_RIGHTBRACKET);
        mtrScriptsRegisterNumericVariable("KEY_BACKSLASH", MTR_KEY_BACKSLASH);
        mtrScriptsRegisterNumericVariable("KEY_NONUSHASH", MTR_KEY_NONUSHASH);
        mtrScriptsRegisterNumericVariable("KEY_SEMICOLON", MTR_KEY_SEMICOLON);
        mtrScriptsRegisterNumericVariable("KEY_APOSTROPHE", MTR_KEY_APOSTROPHE);
        mtrScriptsRegisterNumericVariable("KEY_GRAVE", MTR_KEY_GRAVE);
        mtrScriptsRegisterNumericVariable("KEY_COMMA", MTR_KEY_COMMA);
        mtrScriptsRegisterNumericVariable("KEY_PERIOD", MTR_KEY_PERIOD);
        mtrScriptsRegisterNumericVariable("KEY_SLASH", MTR_KEY_SLASH);

        mtrScriptsRegisterNumericVariable("KEY_CAPSLOCK", MTR_KEY_CAPSLOCK);

        mtrScriptsRegisterNumericVariable("KEY_F1", MTR_KEY_F1);
        mtrScriptsRegisterNumericVariable("KEY_F2", MTR_KEY_F2);
        mtrScriptsRegisterNumericVariable("KEY_F3", MTR_KEY_F3);
        mtrScriptsRegisterNumericVariable("KEY_F4", MTR_KEY_F4);
        mtrScriptsRegisterNumericVariable("KEY_F5", MTR_KEY_F5);
        mtrScriptsRegisterNumericVariable("KEY_F6", MTR_KEY_F6);
        mtrScriptsRegisterNumericVariable("KEY_F7", MTR_KEY_F7);
        mtrScriptsRegisterNumericVariable("KEY_F8", MTR_KEY_F8);
        mtrScriptsRegisterNumericVariable("KEY_F9", MTR_KEY_F9);
        mtrScriptsRegisterNumericVariable("KEY_F10", MTR_KEY_F10);
        mtrScriptsRegisterNumericVariable("KEY_F11", MTR_KEY_F11);
        mtrScriptsRegisterNumericVariable("KEY_F12", MTR_KEY_F12);

        mtrScriptsRegisterNumericVariable("KEY_PRINTSCREEN", MTR_KEY_PRINTSCREEN);
        mtrScriptsRegisterNumericVariable("KEY_SCROLLLOCK", MTR_KEY_SCROLLLOCK);
        mtrScriptsRegisterNumericVariable("KEY_PAUSE", MTR_KEY_PAUSE);
        mtrScriptsRegisterNumericVariable("KEY_INSERT", MTR_KEY_INSERT);
        mtrScriptsRegisterNumericVariable("KEY_HOME", MTR_KEY_HOME);
        mtrScriptsRegisterNumericVariable("KEY_PAGEUP", MTR_KEY_PAGEUP);
        mtrScriptsRegisterNumericVariable("KEY_DELETE", MTR_KEY_DELETE);
        mtrScriptsRegisterNumericVariable("KEY_END", MTR_KEY_END);
        mtrScriptsRegisterNumericVariable("KEY_PAGEDOWN", MTR_KEY_PAGEDOWN);
        mtrScriptsRegisterNumericVariable("KEY_RIGHT", MTR_KEY_RIGHT);
        mtrScriptsRegisterNumericVariable("KEY_LEFT", MTR_KEY_LEFT);
        mtrScriptsRegisterNumericVariable("KEY_DOWN", MTR_KEY_DOWN);
        mtrScriptsRegisterNumericVariable("KEY_UP", MTR_KEY_UP);

        mtrScriptsRegisterNumericVariable("KEY_NUMLOCKCLEAR", MTR_KEY_NUMLOCKCLEAR);
        mtrScriptsRegisterNumericVariable("KEY_KP_DIVIDE", MTR_KEY_KP_DIVIDE);
        mtrScriptsRegisterNumericVariable("KEY_KP_MULTIPLY", MTR_KEY_KP_MULTIPLY);
        mtrScriptsRegisterNumericVariable("KEY_KP_MINUS", MTR_KEY_KP_MINUS);
        mtrScriptsRegisterNumericVariable("KEY_KP_PLUS", MTR_KEY_KP_PLUS);
        mtrScriptsRegisterNumericVariable("KEY_KP_ENTER", MTR_KEY_KP_ENTER);
        mtrScriptsRegisterNumericVariable("KEY_KP_1", MTR_KEY_KP_1);
        mtrScriptsRegisterNumericVariable("KEY_KP_2", MTR_KEY_KP_2);
        mtrScriptsRegisterNumericVariable("KEY_KP_3", MTR_KEY_KP_3);
        mtrScriptsRegisterNumericVariable("KEY_KP_4", MTR_KEY_KP_4);
        mtrScriptsRegisterNumericVariable("KEY_KP_5", MTR_KEY_KP_5);
        mtrScriptsRegisterNumericVariable("KEY_KP_6", MTR_KEY_KP_6);
        mtrScriptsRegisterNumericVariable("KEY_KP_7", MTR_KEY_KP_7);
        mtrScriptsRegisterNumericVariable("KEY_KP_8", MTR_KEY_KP_8);
        mtrScriptsRegisterNumericVariable("KEY_KP_9", MTR_KEY_KP_9);
        mtrScriptsRegisterNumericVariable("KEY_KP_0", MTR_KEY_KP_0);
        mtrScriptsRegisterNumericVariable("KEY_KP_PERIOD", MTR_KEY_KP_PERIOD);

        mtrScriptsRegisterNumericVariable("KEY_NONUSBACKSLASH", MTR_KEY_NONUSBACKSLASH);
        mtrScriptsRegisterNumericVariable("KEY_APPLICATION", MTR_KEY_APPLICATION);
        mtrScriptsRegisterNumericVariable("KEY_POWER", MTR_KEY_POWER);
        mtrScriptsRegisterNumericVariable("KEY_KP_EQUALS", MTR_KEY_KP_EQUALS);
        mtrScriptsRegisterNumericVariable("KEY_F13", MTR_KEY_F13);
        mtrScriptsRegisterNumericVariable("KEY_F14", MTR_KEY_F14);
        mtrScriptsRegisterNumericVariable("KEY_F15", MTR_KEY_F15);
        mtrScriptsRegisterNumericVariable("KEY_F16", MTR_KEY_F16);
        mtrScriptsRegisterNumericVariable("KEY_F17", MTR_KEY_F17);
        mtrScriptsRegisterNumericVariable("KEY_F18", MTR_KEY_F18);
        mtrScriptsRegisterNumericVariable("KEY_F19", MTR_KEY_F19);
        mtrScriptsRegisterNumericVariable("KEY_F20", MTR_KEY_F20);
        mtrScriptsRegisterNumericVariable("KEY_F21", MTR_KEY_F21);
        mtrScriptsRegisterNumericVariable("KEY_F22", MTR_KEY_F22);
        mtrScriptsRegisterNumericVariable("KEY_F23", MTR_KEY_F23);
        mtrScriptsRegisterNumericVariable("KEY_F24", MTR_KEY_F24);
        mtrScriptsRegisterNumericVariable("KEY_EXECUTE", MTR_KEY_EXECUTE);
        mtrScriptsRegisterNumericVariable("KEY_HELP", MTR_KEY_HELP);
        mtrScriptsRegisterNumericVariable("KEY_MENU", MTR_KEY_MENU);
        mtrScriptsRegisterNumericVariable("KEY_SELECT", MTR_KEY_SELECT);
        mtrScriptsRegisterNumericVariable("KEY_STOP", MTR_KEY_STOP);
        mtrScriptsRegisterNumericVariable("KEY_AGAIN", MTR_KEY_AGAIN);
        mtrScriptsRegisterNumericVariable("KEY_UNDO", MTR_KEY_UNDO);
        mtrScriptsRegisterNumericVariable("KEY_CUT", MTR_KEY_CUT);
        mtrScriptsRegisterNumericVariable("KEY_COPY", MTR_KEY_COPY);
        mtrScriptsRegisterNumericVariable("KEY_PASTE", MTR_KEY_PASTE);
        mtrScriptsRegisterNumericVariable("KEY_FIND", MTR_KEY_FIND);
        mtrScriptsRegisterNumericVariable("KEY_MUTE", MTR_KEY_MUTE);
        mtrScriptsRegisterNumericVariable("KEY_VOLUMEUP", MTR_KEY_VOLUMEUP);
        mtrScriptsRegisterNumericVariable("KEY_VOLUMEDOWN", MTR_KEY_VOLUMEDOWN);

        mtrScriptsRegisterNumericVariable("KEY_KP_COMMA", MTR_KEY_KP_COMMA);
        mtrScriptsRegisterNumericVariable("KEY_KP_EQUALSAS400", MTR_KEY_KP_EQUALSAS400);

        mtrScriptsRegisterNumericVariable("KEY_INTERNATIONAL1", MTR_KEY_INTERNATIONAL1);
        mtrScriptsRegisterNumericVariable("KEY_INTERNATIONAL2", MTR_KEY_INTERNATIONAL2);
        mtrScriptsRegisterNumericVariable("KEY_INTERNATIONAL3", MTR_KEY_INTERNATIONAL3);
        mtrScriptsRegisterNumericVariable("KEY_INTERNATIONAL4", MTR_KEY_INTERNATIONAL4);
        mtrScriptsRegisterNumericVariable("KEY_INTERNATIONAL5", MTR_KEY_INTERNATIONAL5);
        mtrScriptsRegisterNumericVariable("KEY_INTERNATIONAL6", MTR_KEY_INTERNATIONAL6);
        mtrScriptsRegisterNumericVariable("KEY_INTERNATIONAL7", MTR_KEY_INTERNATIONAL7);
        mtrScriptsRegisterNumericVariable("KEY_INTERNATIONAL8", MTR_KEY_INTERNATIONAL8);
        mtrScriptsRegisterNumericVariable("KEY_INTERNATIONAL9", MTR_KEY_INTERNATIONAL9);
        mtrScriptsRegisterNumericVariable("KEY_LANG1", MTR_KEY_LANG1);
        mtrScriptsRegisterNumericVariable("KEY_LANG2", MTR_KEY_LANG2);
        mtrScriptsRegisterNumericVariable("KEY_LANG3", MTR_KEY_LANG3);
        mtrScriptsRegisterNumericVariable("KEY_LANG4", MTR_KEY_LANG4);
        mtrScriptsRegisterNumericVariable("KEY_LANG5", MTR_KEY_LANG5);
        mtrScriptsRegisterNumericVariable("KEY_LANG6", MTR_KEY_LANG6);
        mtrScriptsRegisterNumericVariable("KEY_LANG7", MTR_KEY_LANG7);
        mtrScriptsRegisterNumericVariable("KEY_LANG8", MTR_KEY_LANG8);
        mtrScriptsRegisterNumericVariable("KEY_LANG9", MTR_KEY_LANG9);

        mtrScriptsRegisterNumericVariable("KEY_ALTERASE", MTR_KEY_ALTERASE);
        mtrScriptsRegisterNumericVariable("KEY_SYSREQ", MTR_KEY_SYSREQ);
        mtrScriptsRegisterNumericVariable("KEY_CANCEL", MTR_KEY_CANCEL);
        mtrScriptsRegisterNumericVariable("KEY_CLEAR", MTR_KEY_CLEAR);
        mtrScriptsRegisterNumericVariable("KEY_PRIOR", MTR_KEY_PRIOR);
        mtrScriptsRegisterNumericVariable("KEY_RETURN2", MTR_KEY_RETURN2);
        mtrScriptsRegisterNumericVariable("KEY_SEPARATOR", MTR_KEY_SEPARATOR);
        mtrScriptsRegisterNumericVariable("KEY_OUT", MTR_KEY_OUT);
        mtrScriptsRegisterNumericVariable("KEY_OPER", MTR_KEY_OPER);
        mtrScriptsRegisterNumericVariable("KEY_CLEARAGAIN", MTR_KEY_CLEARAGAIN);
        mtrScriptsRegisterNumericVariable("KEY_CRSEL", MTR_KEY_CRSEL);
        mtrScriptsRegisterNumericVariable("KEY_EXSEL", MTR_KEY_EXSEL);

        mtrScriptsRegisterNumericVariable("KEY_KP_00", MTR_KEY_KP_00);
        mtrScriptsRegisterNumericVariable("KEY_KP_000", MTR_KEY_KP_000);
        mtrScriptsRegisterNumericVariable("KEY_THOUSANDSSEPARATOR", MTR_KEY_THOUSANDSSEPARATOR);
        mtrScriptsRegisterNumericVariable("KEY_DECIMALSEPARATOR", MTR_KEY_DECIMALSEPARATOR);
        mtrScriptsRegisterNumericVariable("KEY_CURRENCYUNIT", MTR_KEY_CURRENCYUNIT);
        mtrScriptsRegisterNumericVariable("KEY_CURRENCYSUBUNIT", MTR_KEY_CURRENCYSUBUNIT);
        mtrScriptsRegisterNumericVariable("KEY_KP_LEFTPAREN", MTR_KEY_KP_LEFTPAREN);
        mtrScriptsRegisterNumericVariable("KEY_KP_RIGHTPAREN", MTR_KEY_KP_RIGHTPAREN);
        mtrScriptsRegisterNumericVariable("KEY_KP_LEFTBRACE", MTR_KEY_KP_LEFTBRACE);
        mtrScriptsRegisterNumericVariable("KEY_KP_RIGHTBRACE", MTR_KEY_KP_RIGHTBRACE);
        mtrScriptsRegisterNumericVariable("KEY_KP_TAB", MTR_KEY_KP_TAB);
        mtrScriptsRegisterNumericVariable("KEY_KP_BACKSPACE", MTR_KEY_KP_BACKSPACE);
        mtrScriptsRegisterNumericVariable("KEY_KP_A", MTR_KEY_KP_A);
        mtrScriptsRegisterNumericVariable("KEY_KP_B", MTR_KEY_KP_B);
        mtrScriptsRegisterNumericVariable("KEY_KP_C", MTR_KEY_KP_C);
        mtrScriptsRegisterNumericVariable("KEY_KP_D", MTR_KEY_KP_D);
        mtrScriptsRegisterNumericVariable("KEY_KP_E", MTR_KEY_KP_E);
        mtrScriptsRegisterNumericVariable("KEY_KP_F", MTR_KEY_KP_F);
        mtrScriptsRegisterNumericVariable("KEY_KP_XOR", MTR_KEY_KP_XOR);
        mtrScriptsRegisterNumericVariable("KEY_KP_POWER", MTR_KEY_KP_POWER);
        mtrScriptsRegisterNumericVariable("KEY_KP_PERCENT", MTR_KEY_KP_PERCENT);
        mtrScriptsRegisterNumericVariable("KEY_KP_LESS", MTR_KEY_KP_LESS);
        mtrScriptsRegisterNumericVariable("KEY_KP_GREATER", MTR_KEY_KP_GREATER);
        mtrScriptsRegisterNumericVariable("KEY_KP_AMPERSAND", MTR_KEY_KP_AMPERSAND);
        mtrScriptsRegisterNumericVariable("KEY_KP_DBLAMPERSAND", MTR_KEY_KP_DBLAMPERSAND);
        mtrScriptsRegisterNumericVariable("KEY_KP_VERTICALBAR", MTR_KEY_KP_VERTICALBAR);
        mtrScriptsRegisterNumericVariable("KEY_KP_DBLVERTICALBAR", MTR_KEY_KP_DBLVERTICALBAR);
        mtrScriptsRegisterNumericVariable("KEY_KP_COLON", MTR_KEY_KP_COLON);
        mtrScriptsRegisterNumericVariable("KEY_KP_HASH", MTR_KEY_KP_HASH);
        mtrScriptsRegisterNumericVariable("KEY_KP_SPACE", MTR_KEY_KP_SPACE);
        mtrScriptsRegisterNumericVariable("KEY_KP_AT", MTR_KEY_KP_AT);
        mtrScriptsRegisterNumericVariable("KEY_KP_EXCLAM", MTR_KEY_KP_EXCLAM);
        mtrScriptsRegisterNumericVariable("KEY_KP_MEMSTORE", MTR_KEY_KP_MEMSTORE);
        mtrScriptsRegisterNumericVariable("KEY_KP_MEMRECALL", MTR_KEY_KP_MEMRECALL);
        mtrScriptsRegisterNumericVariable("KEY_KP_MEMCLEAR", MTR_KEY_KP_MEMCLEAR);
        mtrScriptsRegisterNumericVariable("KEY_KP_MEMADD", MTR_KEY_KP_MEMADD);
        mtrScriptsRegisterNumericVariable("KEY_KP_MEMSUBTRACT", MTR_KEY_KP_MEMSUBTRACT);
        mtrScriptsRegisterNumericVariable("KEY_KP_MEMMULTIPLY", MTR_KEY_KP_MEMMULTIPLY);
        mtrScriptsRegisterNumericVariable("KEY_KP_MEMDIVIDE", MTR_KEY_KP_MEMDIVIDE);
        mtrScriptsRegisterNumericVariable("KEY_KP_PLUSMINUS", MTR_KEY_KP_PLUSMINUS);
        mtrScriptsRegisterNumericVariable("KEY_KP_CLEAR", MTR_KEY_KP_CLEAR);
        mtrScriptsRegisterNumericVariable("KEY_KP_CLEARENTRY", MTR_KEY_KP_CLEARENTRY);
        mtrScriptsRegisterNumericVariable("KEY_KP_BINARY", MTR_KEY_KP_BINARY);
        mtrScriptsRegisterNumericVariable("KEY_KP_OCTAL", MTR_KEY_KP_OCTAL);
        mtrScriptsRegisterNumericVariable("KEY_KP_DECIMAL", MTR_KEY_KP_DECIMAL);
        mtrScriptsRegisterNumericVariable("KEY_KP_HEXADECIMAL", MTR_KEY_KP_HEXADECIMAL);

        mtrScriptsRegisterNumericVariable("KEY_LCTRL", MTR_KEY_LCTRL);
        mtrScriptsRegisterNumericVariable("KEY_LSHIFT", MTR_KEY_LSHIFT);
        mtrScriptsRegisterNumericVariable("KEY_LALT", MTR_KEY_LALT);
        mtrScriptsRegisterNumericVariable("KEY_LGUI", MTR_KEY_LGUI);
        mtrScriptsRegisterNumericVariable("KEY_RCTRL", MTR_KEY_RCTRL);
        mtrScriptsRegisterNumericVariable("KEY_RSHIFT", MTR_KEY_RSHIFT);
        mtrScriptsRegisterNumericVariable("KEY_RALT", MTR_KEY_RALT);
        mtrScriptsRegisterNumericVariable("KEY_RGUI", MTR_KEY_RGUI);

        mtrScriptsRegisterNumericVariable("KEY_MODE", MTR_KEY_MODE);

        mtrScriptsRegisterNumericVariable("KEY_AUDIONEXT", MTR_KEY_AUDIONEXT);
        mtrScriptsRegisterNumericVariable("KEY_AUDIOPREV", MTR_KEY_AUDIOPREV);
        mtrScriptsRegisterNumericVariable("KEY_AUDIOSTOP", MTR_KEY_AUDIOSTOP);
        mtrScriptsRegisterNumericVariable("KEY_AUDIOPLAY", MTR_KEY_AUDIOPLAY);
        mtrScriptsRegisterNumericVariable("KEY_AUDIOMUTE", MTR_KEY_AUDIOMUTE);
        mtrScriptsRegisterNumericVariable("KEY_MEDIASELECT", MTR_KEY_MEDIASELECT);
        mtrScriptsRegisterNumericVariable("KEY_WWW", MTR_KEY_WWW);
        mtrScriptsRegisterNumericVariable("KEY_MAIL", MTR_KEY_MAIL);
        mtrScriptsRegisterNumericVariable("KEY_CALCULATOR", MTR_KEY_CALCULATOR);
        mtrScriptsRegisterNumericVariable("KEY_COMPUTER", MTR_KEY_COMPUTER);
        mtrScriptsRegisterNumericVariable("KEY_AC_SEARCH", MTR_KEY_AC_SEARCH);
        mtrScriptsRegisterNumericVariable("KEY_AC_HOME", MTR_KEY_AC_HOME);
        mtrScriptsRegisterNumericVariable("KEY_AC_BACK", MTR_KEY_AC_BACK);
        mtrScriptsRegisterNumericVariable("KEY_AC_FORWARD", MTR_KEY_AC_FORWARD);
        mtrScriptsRegisterNumericVariable("KEY_AC_STOP", MTR_KEY_AC_STOP);
        mtrScriptsRegisterNumericVariable("KEY_AC_REFRESH", MTR_KEY_AC_REFRESH);
        mtrScriptsRegisterNumericVariable("KEY_AC_BOOKMARKS", MTR_KEY_AC_BOOKMARKS);

        mtrScriptsRegisterNumericVariable("KEY_BRIGHTNESSDOWN", MTR_KEY_BRIGHTNESSDOWN);
        mtrScriptsRegisterNumericVariable("KEY_BRIGHTNESSUP", MTR_KEY_BRIGHTNESSUP);
        mtrScriptsRegisterNumericVariable("KEY_DISPLAYSWITCH", MTR_KEY_DISPLAYSWITCH);
        mtrScriptsRegisterNumericVariable("KEY_KBDILLUMTOGGLE", MTR_KEY_KBDILLUMTOGGLE);
        mtrScriptsRegisterNumericVariable("KEY_KBDILLUMDOWN", MTR_KEY_KBDILLUMDOWN);
        mtrScriptsRegisterNumericVariable("KEY_KBDILLUMUP", MTR_KEY_KBDILLUMUP);
        mtrScriptsRegisterNumericVariable("KEY_EJECT", MTR_KEY_EJECT);
        mtrScriptsRegisterNumericVariable("KEY_SLEEP", MTR_KEY_SLEEP);

        mtrScriptsRegisterNumericVariable("KEY_APP1", MTR_KEY_APP1);
        mtrScriptsRegisterNumericVariable("KEY_APP2", MTR_KEY_APP2);

        mtrScriptsRegisterFunction(mtrSF_KeyboardInit, "KeyboardInit");
        mtrScriptsRegisterFunction(mtrSF_KeyboardRefresh, "KeyboardRefresh");
        mtrScriptsRegisterFunction(mtrSF_KeyboardPress, "KeyboardPress");
        mtrScriptsRegisterFunction(mtrSF_KeyboardRelease, "KeyboardRelease");
        mtrScriptsRegisterFunction(mtrSF_KeyboardPressed, "KeyboardPressed");
        mtrScriptsRegisterFunction(mtrSF_KeyboardInputChar, "KeyboardInputChar");
    }
    else
    {
        mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
    }
}

#endif
