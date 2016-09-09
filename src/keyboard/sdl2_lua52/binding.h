#ifndef MTR_KEYBOARD_SDL2_LUA52
#define MTR_KEYBOARD_SDL2_LUA52

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "SDL2/SDL.h"

#include "marathoner/plugin.h"

lua_State *mtrVm;

typedef lua_State* (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MTR_CALL * mtrScriptsRegisterNumericVariableFunc)(char *, double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

typedef bool (MTR_CALL * mtrKeyboardInitFunc)(void);
mtrKeyboardInitFunc mtrKeyboardInit;

typedef void (MTR_CALL * mtrKeyboardRefreshFunc)(void);
mtrKeyboardRefreshFunc mtrKeyboardRefresh;

typedef bool (MTR_CALL * mtrKeyboardPressFunc)(uint16_t);
mtrKeyboardPressFunc mtrKeyboardPress;

typedef bool (MTR_CALL * mtrKeyboardReleaseFunc)(uint16_t);
mtrKeyboardReleaseFunc mtrKeyboardRelease;

typedef bool (MTR_CALL * mtrKeyboardPressedFunc)(uint16_t);
mtrKeyboardPressedFunc mtrKeyboardPressed;

int mtrSF_KeyboardInit(lua_State* l);
int mtrSF_KeyboardRefresh(lua_State* l);
int mtrSF_KeyboardPress(lua_State* l);
int mtrSF_KeyboardRelease(lua_State* l);
int mtrSF_KeyboardPressed(lua_State* l);

#define MTR_KEY_A                   SDL_SCANCODE_A
#define MTR_KEY_B                   SDL_SCANCODE_B
#define MTR_KEY_C                   SDL_SCANCODE_C
#define MTR_KEY_D                   SDL_SCANCODE_D
#define MTR_KEY_E                   SDL_SCANCODE_E
#define MTR_KEY_F                   SDL_SCANCODE_F
#define MTR_KEY_G                   SDL_SCANCODE_G
#define MTR_KEY_H                   SDL_SCANCODE_H
#define MTR_KEY_I                   SDL_SCANCODE_I
#define MTR_KEY_J                   SDL_SCANCODE_J
#define MTR_KEY_K                   SDL_SCANCODE_K
#define MTR_KEY_L                   SDL_SCANCODE_L
#define MTR_KEY_M                   SDL_SCANCODE_M
#define MTR_KEY_N                   SDL_SCANCODE_N
#define MTR_KEY_O                   SDL_SCANCODE_O
#define MTR_KEY_P                   SDL_SCANCODE_P
#define MTR_KEY_Q                   SDL_SCANCODE_Q
#define MTR_KEY_R                   SDL_SCANCODE_R
#define MTR_KEY_S                   SDL_SCANCODE_S
#define MTR_KEY_T                   SDL_SCANCODE_T
#define MTR_KEY_U                   SDL_SCANCODE_U
#define MTR_KEY_V                   SDL_SCANCODE_V
#define MTR_KEY_W                   SDL_SCANCODE_W
#define MTR_KEY_X                   SDL_SCANCODE_X
#define MTR_KEY_Y                   SDL_SCANCODE_Y
#define MTR_KEY_Z                   SDL_SCANCODE_Z

#define MTR_KEY_1                   SDL_SCANCODE_1
#define MTR_KEY_2                   SDL_SCANCODE_2
#define MTR_KEY_3                   SDL_SCANCODE_3
#define MTR_KEY_4                   SDL_SCANCODE_4
#define MTR_KEY_5                   SDL_SCANCODE_5
#define MTR_KEY_6                   SDL_SCANCODE_6
#define MTR_KEY_7                   SDL_SCANCODE_7
#define MTR_KEY_8                   SDL_SCANCODE_8
#define MTR_KEY_9                   SDL_SCANCODE_9
#define MTR_KEY_0                   SDL_SCANCODE_0

#define MTR_KEY_RETURN              SDL_SCANCODE_RETURN
#define MTR_KEY_ESCAPE              SDL_SCANCODE_ESCAPE
#define MTR_KEY_BACKSPACE           SDL_SCANCODE_BACKSPACE
#define MTR_KEY_TAB                 SDL_SCANCODE_TAB
#define MTR_KEY_SPACE               SDL_SCANCODE_SPACE

#define MTR_KEY_MINUS               SDL_SCANCODE_MINUS
#define MTR_KEY_EQUALS              SDL_SCANCODE_EQUALS
#define MTR_KEY_LEFTBRACKET         SDL_SCANCODE_LEFTBRACKET
#define MTR_KEY_RIGHTBRACKET        SDL_SCANCODE_RIGHTBRACKET
#define MTR_KEY_BACKSLASH           SDL_SCANCODE_BACKSLASH
#define MTR_KEY_NONUSHASH           SDL_SCANCODE_NONUSHASH
#define MTR_KEY_SEMICOLON           SDL_SCANCODE_SEMICOLON
#define MTR_KEY_APOSTROPHE          SDL_SCANCODE_APOSTROPHE
#define MTR_KEY_GRAVE               SDL_SCANCODE_GRAVE
#define MTR_KEY_COMMA               SDL_SCANCODE_COMMA
#define MTR_KEY_PERIOD              SDL_SCANCODE_PERIOD
#define MTR_KEY_SLASH               SDL_SCANCODE_SLASH

#define MTR_KEY_CAPSLOCK            SDL_SCANCODE_CAPSLOCK

#define MTR_KEY_F1                  SDL_SCANCODE_F1
#define MTR_KEY_F2                  SDL_SCANCODE_F2
#define MTR_KEY_F3                  SDL_SCANCODE_F3
#define MTR_KEY_F4                  SDL_SCANCODE_F4
#define MTR_KEY_F5                  SDL_SCANCODE_F5
#define MTR_KEY_F6                  SDL_SCANCODE_F6
#define MTR_KEY_F7                  SDL_SCANCODE_F7
#define MTR_KEY_F8                  SDL_SCANCODE_F8
#define MTR_KEY_F9                  SDL_SCANCODE_F9
#define MTR_KEY_F10                 SDL_SCANCODE_F10
#define MTR_KEY_F11                 SDL_SCANCODE_F11
#define MTR_KEY_F12                 SDL_SCANCODE_F12

#define MTR_KEY_PRINTSCREEN         SDL_SCANCODE_PRINTSCREEN
#define MTR_KEY_SCROLLLOCK          SDL_SCANCODE_SCROLLLOCK
#define MTR_KEY_PAUSE               SDL_SCANCODE_PAUSE
#define MTR_KEY_INSERT              SDL_SCANCODE_INSERT
#define MTR_KEY_HOME                SDL_SCANCODE_HOME
#define MTR_KEY_PAGEUP              SDL_SCANCODE_PAGEUP
#define MTR_KEY_DELETE              SDL_SCANCODE_DELETE
#define MTR_KEY_END                 SDL_SCANCODE_END
#define MTR_KEY_PAGEDOWN            SDL_SCANCODE_PAGEDOWN
#define MTR_KEY_RIGHT               SDL_SCANCODE_RIGHT
#define MTR_KEY_LEFT                SDL_SCANCODE_LEFT
#define MTR_KEY_DOWN                SDL_SCANCODE_DOWN
#define MTR_KEY_UP                  SDL_SCANCODE_UP

#define MTR_KEY_NUMLOCKCLEAR        SDL_SCANCODE_NUMLOCKCLEAR
#define MTR_KEY_KP_DIVIDE           SDL_SCANCODE_KP_DIVIDE
#define MTR_KEY_KP_MULTIPLY         SDL_SCANCODE_KP_MULTIPLY
#define MTR_KEY_KP_MINUS            SDL_SCANCODE_KP_MINUS
#define MTR_KEY_KP_PLUS             SDL_SCANCODE_KP_PLUS
#define MTR_KEY_KP_ENTER            SDL_SCANCODE_KP_ENTER
#define MTR_KEY_KP_1                SDL_SCANCODE_KP_1
#define MTR_KEY_KP_2                SDL_SCANCODE_KP_2
#define MTR_KEY_KP_3                SDL_SCANCODE_KP_3
#define MTR_KEY_KP_4                SDL_SCANCODE_KP_4
#define MTR_KEY_KP_5                SDL_SCANCODE_KP_5
#define MTR_KEY_KP_6                SDL_SCANCODE_KP_6
#define MTR_KEY_KP_7                SDL_SCANCODE_KP_7
#define MTR_KEY_KP_8                SDL_SCANCODE_KP_8
#define MTR_KEY_KP_9                SDL_SCANCODE_KP_9
#define MTR_KEY_KP_0                SDL_SCANCODE_KP_0
#define MTR_KEY_KP_PERIOD           SDL_SCANCODE_KP_PERIOD

#define MTR_KEY_NONUSBACKSLASH      SDL_SCANCODE_NONUSBACKSLASH
#define MTR_KEY_APPLICATION         SDL_SCANCODE_APPLICATION
#define MTR_KEY_POWER               SDL_SCANCODE_POWER
#define MTR_KEY_KP_EQUALS           SDL_SCANCODE_KP_EQUALS
#define MTR_KEY_F13                 SDL_SCANCODE_F13
#define MTR_KEY_F14                 SDL_SCANCODE_F14
#define MTR_KEY_F15                 SDL_SCANCODE_F15
#define MTR_KEY_F16                 SDL_SCANCODE_F16
#define MTR_KEY_F17                 SDL_SCANCODE_F17
#define MTR_KEY_F18                 SDL_SCANCODE_F18
#define MTR_KEY_F19                 SDL_SCANCODE_F19
#define MTR_KEY_F20                 SDL_SCANCODE_F20
#define MTR_KEY_F21                 SDL_SCANCODE_F21
#define MTR_KEY_F22                 SDL_SCANCODE_F22
#define MTR_KEY_F23                 SDL_SCANCODE_F23
#define MTR_KEY_F24                 SDL_SCANCODE_F24
#define MTR_KEY_EXECUTE             SDL_SCANCODE_EXECUTE
#define MTR_KEY_HELP                SDL_SCANCODE_HELP
#define MTR_KEY_MENU                SDL_SCANCODE_MENU
#define MTR_KEY_SELECT              SDL_SCANCODE_SELECT
#define MTR_KEY_STOP                SDL_SCANCODE_STOP
#define MTR_KEY_AGAIN               SDL_SCANCODE_AGAIN
#define MTR_KEY_UNDO                SDL_SCANCODE_UNDO
#define MTR_KEY_CUT                 SDL_SCANCODE_CUT
#define MTR_KEY_COPY                SDL_SCANCODE_COPY
#define MTR_KEY_PASTE               SDL_SCANCODE_PASTE
#define MTR_KEY_FIND                SDL_SCANCODE_FIND
#define MTR_KEY_MUTE                SDL_SCANCODE_MUTE
#define MTR_KEY_VOLUMEUP            SDL_SCANCODE_VOLUMEUP
#define MTR_KEY_VOLUMEDOWN          SDL_SCANCODE_VOLUMEDOWN

#define MTR_KEY_KP_COMMA            SDL_SCANCODE_KP_COMMA
#define MTR_KEY_KP_EQUALSAS400      SDL_SCANCODE_KP_EQUALSAS400

#define MTR_KEY_INTERNATIONAL1      SDL_SCANCODE_INTERNATIONAL1
#define MTR_KEY_INTERNATIONAL2      SDL_SCANCODE_INTERNATIONAL2
#define MTR_KEY_INTERNATIONAL3      SDL_SCANCODE_INTERNATIONAL3
#define MTR_KEY_INTERNATIONAL4      SDL_SCANCODE_INTERNATIONAL4
#define MTR_KEY_INTERNATIONAL5      SDL_SCANCODE_INTERNATIONAL5
#define MTR_KEY_INTERNATIONAL6      SDL_SCANCODE_INTERNATIONAL6
#define MTR_KEY_INTERNATIONAL7      SDL_SCANCODE_INTERNATIONAL7
#define MTR_KEY_INTERNATIONAL8      SDL_SCANCODE_INTERNATIONAL8
#define MTR_KEY_INTERNATIONAL9      SDL_SCANCODE_INTERNATIONAL9
#define MTR_KEY_LANG1               SDL_SCANCODE_LANG1
#define MTR_KEY_LANG2               SDL_SCANCODE_LANG2
#define MTR_KEY_LANG3               SDL_SCANCODE_LANG3
#define MTR_KEY_LANG4               SDL_SCANCODE_LANG4
#define MTR_KEY_LANG5               SDL_SCANCODE_LANG5
#define MTR_KEY_LANG6               SDL_SCANCODE_LANG6
#define MTR_KEY_LANG7               SDL_SCANCODE_LANG7
#define MTR_KEY_LANG8               SDL_SCANCODE_LANG8
#define MTR_KEY_LANG9               SDL_SCANCODE_LANG9

#define MTR_KEY_ALTERASE            SDL_SCANCODE_ALTERASE
#define MTR_KEY_SYSREQ              SDL_SCANCODE_SYSREQ
#define MTR_KEY_CANCEL              SDL_SCANCODE_CANCEL
#define MTR_KEY_CLEAR               SDL_SCANCODE_CLEAR
#define MTR_KEY_PRIOR               SDL_SCANCODE_PRIOR
#define MTR_KEY_RETURN2             SDL_SCANCODE_RETURN2
#define MTR_KEY_SEPARATOR           SDL_SCANCODE_SEPARATOR
#define MTR_KEY_OUT                 SDL_SCANCODE_OUT
#define MTR_KEY_OPER                SDL_SCANCODE_OPER
#define MTR_KEY_CLEARAGAIN          SDL_SCANCODE_CLEARAGAIN
#define MTR_KEY_CRSEL               SDL_SCANCODE_CRSEL
#define MTR_KEY_EXSEL               SDL_SCANCODE_EXSEL

#define MTR_KEY_KP_00               SDL_SCANCODE_KP_00
#define MTR_KEY_KP_000              SDL_SCANCODE_KP_000
#define MTR_KEY_THOUSANDSSEPARATOR  SDL_SCANCODE_THOUSANDSSEPARATOR
#define MTR_KEY_DECIMALSEPARATOR    SDL_SCANCODE_DECIMALSEPARATOR
#define MTR_KEY_CURRENCYUNIT        SDL_SCANCODE_CURRENCYUNIT
#define MTR_KEY_CURRENCYSUBUNIT     SDL_SCANCODE_CURRENCYSUBUNIT
#define MTR_KEY_KP_LEFTPAREN        SDL_SCANCODE_KP_LEFTPAREN
#define MTR_KEY_KP_RIGHTPAREN       SDL_SCANCODE_KP_RIGHTPAREN
#define MTR_KEY_KP_LEFTBRACE        SDL_SCANCODE_KP_LEFTBRACE
#define MTR_KEY_KP_RIGHTBRACE       SDL_SCANCODE_KP_RIGHTBRACE
#define MTR_KEY_KP_TAB              SDL_SCANCODE_KP_TAB
#define MTR_KEY_KP_BACKSPACE        SDL_SCANCODE_KP_BACKSPACE
#define MTR_KEY_KP_A                SDL_SCANCODE_KP_A
#define MTR_KEY_KP_B                SDL_SCANCODE_KP_B
#define MTR_KEY_KP_C                SDL_SCANCODE_KP_C
#define MTR_KEY_KP_D                SDL_SCANCODE_KP_D
#define MTR_KEY_KP_E                SDL_SCANCODE_KP_E
#define MTR_KEY_KP_F                SDL_SCANCODE_KP_F
#define MTR_KEY_KP_XOR              SDL_SCANCODE_KP_XOR
#define MTR_KEY_KP_POWER            SDL_SCANCODE_KP_POWER
#define MTR_KEY_KP_PERCENT          SDL_SCANCODE_KP_PERCENT
#define MTR_KEY_KP_LESS             SDL_SCANCODE_KP_LESS
#define MTR_KEY_KP_GREATER          SDL_SCANCODE_KP_GREATER
#define MTR_KEY_KP_AMPERSAND        SDL_SCANCODE_KP_AMPERSAND
#define MTR_KEY_KP_DBLAMPERSAND     SDL_SCANCODE_KP_DBLAMPERSAND
#define MTR_KEY_KP_VERTICALBAR      SDL_SCANCODE_KP_VERTICALBAR
#define MTR_KEY_KP_DBLVERTICALBAR   SDL_SCANCODE_KP_DBLVERTICALBAR
#define MTR_KEY_KP_COLON            SDL_SCANCODE_KP_COLON
#define MTR_KEY_KP_HASH             SDL_SCANCODE_KP_HASH
#define MTR_KEY_KP_SPACE            SDL_SCANCODE_KP_SPACE
#define MTR_KEY_KP_AT               SDL_SCANCODE_KP_AT
#define MTR_KEY_KP_EXCLAM           SDL_SCANCODE_KP_EXCLAM
#define MTR_KEY_KP_MEMSTORE         SDL_SCANCODE_KP_MEMSTORE
#define MTR_KEY_KP_MEMRECALL        SDL_SCANCODE_KP_MEMRECALL
#define MTR_KEY_KP_MEMCLEAR         SDL_SCANCODE_KP_MEMCLEAR
#define MTR_KEY_KP_MEMADD           SDL_SCANCODE_KP_MEMADD
#define MTR_KEY_KP_MEMSUBTRACT      SDL_SCANCODE_KP_MEMSUBTRACT
#define MTR_KEY_KP_MEMMULTIPLY      SDL_SCANCODE_KP_MEMMULTIPLY
#define MTR_KEY_KP_MEMDIVIDE        SDL_SCANCODE_KP_MEMDIVIDE
#define MTR_KEY_KP_PLUSMINUS        SDL_SCANCODE_KP_PLUSMINUS
#define MTR_KEY_KP_CLEAR            SDL_SCANCODE_KP_CLEAR
#define MTR_KEY_KP_CLEARENTRY       SDL_SCANCODE_KP_CLEARENTRY
#define MTR_KEY_KP_BINARY           SDL_SCANCODE_KP_BINARY
#define MTR_KEY_KP_OCTAL            SDL_SCANCODE_KP_OCTAL
#define MTR_KEY_KP_DECIMAL          SDL_SCANCODE_KP_DECIMAL
#define MTR_KEY_KP_HEXADECIMAL      SDL_SCANCODE_KP_HEXADECIMAL

#define MTR_KEY_LCTRL               SDL_SCANCODE_LCTRL
#define MTR_KEY_LSHIFT              SDL_SCANCODE_LSHIFT
#define MTR_KEY_LALT                SDL_SCANCODE_LALT
#define MTR_KEY_LGUI                SDL_SCANCODE_LGUI
#define MTR_KEY_RCTRL               SDL_SCANCODE_RCTRL
#define MTR_KEY_RSHIFT              SDL_SCANCODE_RSHIFT
#define MTR_KEY_RALT                SDL_SCANCODE_RALT
#define MTR_KEY_RGUI                SDL_SCANCODE_RGUI

#define MTR_KEY_MODE                SDL_SCANCODE_MODE

#define MTR_KEY_AUDIONEXT           SDL_SCANCODE_AUDIONEXT
#define MTR_KEY_AUDIOPREV           SDL_SCANCODE_AUDIOPREV
#define MTR_KEY_AUDIOSTOP           SDL_SCANCODE_AUDIOSTOP
#define MTR_KEY_AUDIOPLAY           SDL_SCANCODE_AUDIOPLAY
#define MTR_KEY_AUDIOMUTE           SDL_SCANCODE_AUDIOMUTE
#define MTR_KEY_MEDIASELECT         SDL_SCANCODE_MEDIASELECT
#define MTR_KEY_WWW                 SDL_SCANCODE_WWW
#define MTR_KEY_MAIL                SDL_SCANCODE_MAIL
#define MTR_KEY_CALCULATOR          SDL_SCANCODE_CALCULATOR
#define MTR_KEY_COMPUTER            SDL_SCANCODE_COMPUTER
#define MTR_KEY_AC_SEARCH           SDL_SCANCODE_AC_SEARCH
#define MTR_KEY_AC_HOME             SDL_SCANCODE_AC_HOME
#define MTR_KEY_AC_BACK             SDL_SCANCODE_AC_BACK
#define MTR_KEY_AC_FORWARD          SDL_SCANCODE_AC_FORWARD
#define MTR_KEY_AC_STOP             SDL_SCANCODE_AC_STOP
#define MTR_KEY_AC_REFRESH          SDL_SCANCODE_AC_REFRESH
#define MTR_KEY_AC_BOOKMARKS        SDL_SCANCODE_AC_BOOKMARKS

#define MTR_KEY_BRIGHTNESSDOWN      SDL_SCANCODE_BRIGHTNESSDOWN
#define MTR_KEY_BRIGHTNESSUP        SDL_SCANCODE_BRIGHTNESSUP
#define MTR_KEY_DISPLAYSWITCH       SDL_SCANCODE_DISPLAYSWITCH
#define MTR_KEY_KBDILLUMTOGGLE      SDL_SCANCODE_KBDILLUMTOGGLE
#define MTR_KEY_KBDILLUMDOWN        SDL_SCANCODE_KBDILLUMDOWN
#define MTR_KEY_KBDILLUMUP          SDL_SCANCODE_KBDILLUMUP
#define MTR_KEY_EJECT               SDL_SCANCODE_EJECT
#define MTR_KEY_SLEEP               SDL_SCANCODE_SLEEP

#define MTR_KEY_APP1                SDL_SCANCODE_APP1
#define MTR_KEY_APP2                SDL_SCANCODE_APP2

#endif

