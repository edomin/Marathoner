#ifndef MTR_MARATHONER_H
#define MTR_MARATHONER_H

#include "marathoner/version.h"
#include "marathoner/types.h"

#ifdef __EMSCRIPTEN__
    #include <dlfcn.h>
    #include <dirent.h>
#endif
#include <stdlib.h> /* for malloc */

/* TODO macro. Usage: TODO(message) */
/* Source: gcc.pdf - 6.62.12 Diagnostic Pragmas */
#define DO_PRAGMA(x) _Pragma (#x)
#define TODO(x) DO_PRAGMA(message ("TODO - " #x))

/* Hack for disabling warning about unused variable */
#define UNUSED(expr) do { (void)(expr); } while (0)

/* Get valid pointer fiven type from indexkeeper data array */
#define IK_GET_DATA(type, ik, num) (type)(&((type)ik->data)[num])

/* Report of loaded dll-plugin */
typedef struct mtrReport{
    char    *moduleID;
    uint32_t version;
    char    *subsystem;
    uint8_t  prereqsCount;
    char   **prereqs;
    uint8_t  prereqSubsystemsCount;
    char   **prereqSubsystems;
} mtrReport;

/* type of loaded dll-plugin data */
typedef struct mtrPlugin{
    mtrReport   *report;
    char        *filename;
    mtr_lhandler dll;
} mtrPlugin;

/* Pointers to engine functions */

typedef char *      (MTR_CALL * mtrConfigfileGetKeyNameFunc_t)(const char *,
 const char *, int);
typedef char *      (MTR_CALL * mtrConfigfileGetSectionNameFunc_t)(const char*,
 int);
typedef bool        (MTR_CALL * mtrConfigfileDeleteKeyFunc_t)(const char *,
 const char *, const char *);
typedef bool        (MTR_CALL * mtrConfigfileDeleteSectionFunc_t)(const char *,
 const char *);
typedef bool        (MTR_CALL * mtrConfigfileReadBoolFunc_t)(const char *,
 const char *, const char *, bool);
typedef int         (MTR_CALL * mtrConfigfileReadIntFunc_t)(const char *,
 const char *, const char *, int);
typedef float       (MTR_CALL * mtrConfigfileReadSingleFunc_t)(const char *,
 const char *, const char *, float);
typedef char *      (MTR_CALL * mtrConfigfileReadStringFunc_t)(const char *,
 const char *, const char *, const char *);
typedef bool        (MTR_CALL * mtrConfigfileWriteBoolFunc_t)(const char *,
 const char *, const char *, bool);
typedef bool        (MTR_CALL * mtrConfigfileWriteIntFunc_t)(const char *,
 const char *, const char *, int);
typedef bool        (MTR_CALL * mtrConfigfileWriteSingleFunc_t)(const char *,
 const char *, const char *, float);
typedef bool        (MTR_CALL * mtrConfigfileWriteStringFunc_t)(const char *,
 const char *, const char *, const char *);
typedef bool        (MTR_CALL * mtrConfigfileCreateSectionFunc_t)(const char *,
 const char *);

typedef void        (MTR_CALL * mtrLogWriteFunc_t)(const char *, uint8_t,
 uint8_t);
typedef void        (MTR_CALL * mtrLogWrite_sFunc_t)(const char *, uint8_t,
 uint8_t, const char *);
typedef void        (MTR_CALL * mtrLogWrite_iFunc_t)(const char *, uint8_t,
 uint8_t, int32_t);
typedef void        (MTR_CALL * mtrLogWrite_dFunc_t)(const char *, uint8_t,
 uint8_t, double);

typedef void        (MTR_CALL * mtrShowSimpleMessageBoxFunc_t)(uint8_t,
 const char *, const char *);
typedef bool        (MTR_CALL * mtrShowYesNoMessageBoxFunc_t)(const char *,
 const char *);
typedef bool        (MTR_CALL * mtrShowOkCancelMessageBoxFunc_t)(const char *,
 const char *);
typedef const char *(MTR_CALL * mtrShowInputDialogFunc_t)(const char *,
 const char *, const char *);
typedef const char *(MTR_CALL * mtrShowPasswordDialogFunc_t)(const char *,
 const char *);
typedef void        (MTR_CALL * mtrAddFileFilterFunc_t)(const char *);
typedef void        (MTR_CALL * mtrClearFileFiltersFunc_t)(void);
typedef const char *(MTR_CALL * mtrShowSaveFileDialogFunc_t)(const char *,
 const char *, const char *);
typedef const char *(MTR_CALL * mtrShowOpenFileDialogFunc_t)(const char *,
 const char *, const char *);
typedef const char *(MTR_CALL * mtrShowSelectFolderDialogFunc_t)(const char *,
 const char *);

typedef void        (MTR_CALL * mtrNotifyFunc_t)(const char *, uint8_t,
 uint8_t);

typedef void *      (MTR_CALL * mtrIndexkeeperCreateFunc_t)(uint32_t, uint32_t,
 size_t);
typedef uint32_t    (MTR_CALL * mtrIndexkeeperGetFreeIndexFunc_t)(void *);
typedef void        (MTR_CALL * mtrIndexkeeperFreeIndexFunc_t)(void *,
 uint32_t);
typedef bool        (MTR_CALL * mtrIndexkeeperIndexIsEmptyFunc_t)(void *,
 uint32_t);
typedef uint32_t    (MTR_CALL * mtrIndexkeeperGetReservedDataCountFunc_t)(
 void *);
typedef void        (MTR_CALL * mtrIndexkeeperDestroyFunc_t)(void *);

typedef size_t      (MTR_CALL * mtrEncodingUtf8ToUcs4Func_t)(const char *,
 uint32_t **);
typedef size_t      (MTR_CALL * mtrEncodingUtf8CodepointsFunc_t)(const char *);

typedef uint32_t    (MTR_CALL * mtrFileOpenFunc_t)(const char *, int);
typedef bool        (MTR_CALL * mtrFileCloseFunc_t)(uint32_t);
typedef size_t      (MTR_CALL * mtrFileReadFunc_t)(uint32_t, char **);
typedef bool        (MTR_CALL * mtrFileWriteFunc_t)(uint32_t, const char *);
typedef bool        (MTR_CALL * mtrFileWriteLineFunc_t)(uint32_t, const char *);
typedef void        (MTR_CALL * mtrFileWriteFastFunc_t)(const char *,
 const char *, int);
typedef void        (MTR_CALL * mtrFileWriteLineFastFunc_t)(const char *,
 const char *, int);

typedef bool        (MTR_CALL * mtrClipboardPutTextFunc_t)(const char *);
typedef char *      (MTR_CALL * mtrClipboardGetTextFunc_t)(void);

typedef uint32_t    (MTR_CALL * mtrStringBufferAddFunc_t)(const char *, int);
typedef void        (MTR_CALL * mtrStringBufferDeleteFunc_t)(uint32_t);
typedef void        (MTR_CALL * mtrStringBufferSetStringFunc_t)(uint32_t,
 const char *);
typedef char *      (MTR_CALL * mtrStringBufferGetStringFunc_t)(uint32_t);
typedef int         (MTR_CALL * mtrStringBufferGetMaxLenFunc_t)(uint32_t);

typedef bool        (MTR_CALL * mtrOptionsAliasFunc_t)(const char *,
 const char *);
typedef char *      (MTR_CALL * mtrOptionsGetFunc_t)(const char *);
typedef int         (MTR_CALL * mtrOptionsGet_iFunc_t)(const char *);
typedef long int    (MTR_CALL * mtrOptionsGet_lFunc_t)(const char *);
typedef float       (MTR_CALL * mtrOptionsGet_fFunc_t)(const char *);
typedef double      (MTR_CALL * mtrOptionsGet_dFunc_t)(const char *);

/* loaded dll-plugin data */
mtrPlugin *mtrPluginData;

/* Log Message Types */
#define MTR_LMT_INFO        0
#define MTR_LMT_NOTE        1
#define MTR_LMT_WARNING     2
#define MTR_LMT_ERROR       3
#define MTR_LMT_FATAL       4
#define MTR_LMT_DEBUG       5

/* Dialog Message Types */
#define MTR_DMT_INFO        0
#define MTR_DMT_NOTE        1
#define MTR_DMT_WARNING     2
#define MTR_DMT_ERROR       3
#define MTR_DMT_FATAL       4
#define MTR_DMT_DEBUG       5

/* Indexkeeper datamap size */
#define MTR_IKDM_SMALL      8
#define MTR_IKDM_MEDIUM     2048
#define MTR_IKDM_LARGE      134217728

/* File opening modes */
#define MTR_FM_READ   0
#define MTR_FM_WRITE  1
#define MTR_FM_APPEND 2
#define MTR_FM_MAX    3

/* Marathoner Keykodes */
#define MTR_KEY_A                   4
#define MTR_KEY_B                   5
#define MTR_KEY_C                   6
#define MTR_KEY_D                   7
#define MTR_KEY_E                   8
#define MTR_KEY_F                   9
#define MTR_KEY_G                   10
#define MTR_KEY_H                   11
#define MTR_KEY_I                   12
#define MTR_KEY_J                   13
#define MTR_KEY_K                   14
#define MTR_KEY_L                   15
#define MTR_KEY_M                   16
#define MTR_KEY_N                   17
#define MTR_KEY_O                   18
#define MTR_KEY_P                   19
#define MTR_KEY_Q                   20
#define MTR_KEY_R                   21
#define MTR_KEY_S                   22
#define MTR_KEY_T                   23
#define MTR_KEY_U                   24
#define MTR_KEY_V                   25
#define MTR_KEY_W                   26
#define MTR_KEY_X                   27
#define MTR_KEY_Y                   28
#define MTR_KEY_Z                   29

#define MTR_KEY_1                   30
#define MTR_KEY_2                   31
#define MTR_KEY_3                   32
#define MTR_KEY_4                   33
#define MTR_KEY_5                   34
#define MTR_KEY_6                   35
#define MTR_KEY_7                   36
#define MTR_KEY_8                   37
#define MTR_KEY_9                   38
#define MTR_KEY_0                   39

#define MTR_KEY_RETURN              40
#define MTR_KEY_ESCAPE              41
#define MTR_KEY_BACKSPACE           42
#define MTR_KEY_TAB                 43
#define MTR_KEY_SPACE               44

#define MTR_KEY_MINUS               45
#define MTR_KEY_EQUALS              46
#define MTR_KEY_LEFTBRACKET         47
#define MTR_KEY_RIGHTBRACKET        48
#define MTR_KEY_BACKSLASH           49
#define MTR_KEY_NONUSHASH           50
#define MTR_KEY_SEMICOLON           51
#define MTR_KEY_APOSTROPHE          52
#define MTR_KEY_GRAVE               53
#define MTR_KEY_COMMA               54
#define MTR_KEY_PERIOD              55
#define MTR_KEY_SLASH               56

#define MTR_KEY_CAPSLOCK            57

#define MTR_KEY_F1                  58
#define MTR_KEY_F2                  59
#define MTR_KEY_F3                  60
#define MTR_KEY_F4                  61
#define MTR_KEY_F5                  62
#define MTR_KEY_F6                  63
#define MTR_KEY_F7                  64
#define MTR_KEY_F8                  65
#define MTR_KEY_F9                  66
#define MTR_KEY_F10                 67
#define MTR_KEY_F11                 68
#define MTR_KEY_F12                 69

#define MTR_KEY_PRINTSCREEN         70
#define MTR_KEY_SCROLLLOCK          71
#define MTR_KEY_PAUSE               72
#define MTR_KEY_INSERT              73
#define MTR_KEY_HOME                74
#define MTR_KEY_PAGEUP              75
#define MTR_KEY_DELETE              76
#define MTR_KEY_END                 77
#define MTR_KEY_PAGEDOWN            78
#define MTR_KEY_RIGHT               79
#define MTR_KEY_LEFT                80
#define MTR_KEY_DOWN                81
#define MTR_KEY_UP                  82

#define MTR_KEY_NUMLOCKCLEAR        83
#define MTR_KEY_KP_DIVIDE           84
#define MTR_KEY_KP_MULTIPLY         85
#define MTR_KEY_KP_MINUS            86
#define MTR_KEY_KP_PLUS             87
#define MTR_KEY_KP_ENTER            88
#define MTR_KEY_KP_1                89
#define MTR_KEY_KP_2                90
#define MTR_KEY_KP_3                91
#define MTR_KEY_KP_4                92
#define MTR_KEY_KP_5                93
#define MTR_KEY_KP_6                94
#define MTR_KEY_KP_7                95
#define MTR_KEY_KP_8                96
#define MTR_KEY_KP_9                97
#define MTR_KEY_KP_0                98
#define MTR_KEY_KP_PERIOD           99

#define MTR_KEY_NONUSBACKSLASH      100
#define MTR_KEY_APPLICATION         101
#define MTR_KEY_POWER               102
#define MTR_KEY_KP_EQUALS           103
#define MTR_KEY_F13                 104
#define MTR_KEY_F14                 105
#define MTR_KEY_F15                 106
#define MTR_KEY_F16                 107
#define MTR_KEY_F17                 108
#define MTR_KEY_F18                 109
#define MTR_KEY_F19                 110
#define MTR_KEY_F20                 111
#define MTR_KEY_F21                 112
#define MTR_KEY_F22                 113
#define MTR_KEY_F23                 114
#define MTR_KEY_F24                 115
#define MTR_KEY_EXECUTE             116
#define MTR_KEY_HELP                117
#define MTR_KEY_MENU                118
#define MTR_KEY_SELECT              119
#define MTR_KEY_STOP                120
#define MTR_KEY_AGAIN               121
#define MTR_KEY_UNDO                122
#define MTR_KEY_CUT                 123
#define MTR_KEY_COPY                124
#define MTR_KEY_PASTE               125
#define MTR_KEY_FIND                126
#define MTR_KEY_MUTE                127
#define MTR_KEY_VOLUMEUP            128
#define MTR_KEY_VOLUMEDOWN          129

#define MTR_KEY_KP_COMMA            133
#define MTR_KEY_KP_EQUALSAS400      134

#define MTR_KEY_INTERNATIONAL1      135
#define MTR_KEY_INTERNATIONAL2      136
#define MTR_KEY_INTERNATIONAL3      137
#define MTR_KEY_INTERNATIONAL4      138
#define MTR_KEY_INTERNATIONAL5      139
#define MTR_KEY_INTERNATIONAL6      140
#define MTR_KEY_INTERNATIONAL7      141
#define MTR_KEY_INTERNATIONAL8      142
#define MTR_KEY_INTERNATIONAL9      143
#define MTR_KEY_LANG1               144
#define MTR_KEY_LANG2               145
#define MTR_KEY_LANG3               146
#define MTR_KEY_LANG4               147
#define MTR_KEY_LANG5               148
#define MTR_KEY_LANG6               149
#define MTR_KEY_LANG7               150
#define MTR_KEY_LANG8               151
#define MTR_KEY_LANG9               152

#define MTR_KEY_ALTERASE            153
#define MTR_KEY_SYSREQ              154
#define MTR_KEY_CANCEL              155
#define MTR_KEY_CLEAR               156
#define MTR_KEY_PRIOR               157
#define MTR_KEY_RETURN2             158
#define MTR_KEY_SEPARATOR           159
#define MTR_KEY_OUT                 160
#define MTR_KEY_OPER                161
#define MTR_KEY_CLEARAGAIN          162
#define MTR_KEY_CRSEL               163
#define MTR_KEY_EXSEL               164

#define MTR_KEY_KP_00               176
#define MTR_KEY_KP_000              177
#define MTR_KEY_THOUSANDSSEPARATOR  178
#define MTR_KEY_DECIMALSEPARATOR    179
#define MTR_KEY_CURRENCYUNIT        180
#define MTR_KEY_CURRENCYSUBUNIT     181
#define MTR_KEY_KP_LEFTPAREN        182
#define MTR_KEY_KP_RIGHTPAREN       183
#define MTR_KEY_KP_LEFTBRACE        184
#define MTR_KEY_KP_RIGHTBRACE       185
#define MTR_KEY_KP_TAB              186
#define MTR_KEY_KP_BACKSPACE        187
#define MTR_KEY_KP_A                188
#define MTR_KEY_KP_B                189
#define MTR_KEY_KP_C                190
#define MTR_KEY_KP_D                191
#define MTR_KEY_KP_E                192
#define MTR_KEY_KP_F                193
#define MTR_KEY_KP_XOR              194
#define MTR_KEY_KP_POWER            195
#define MTR_KEY_KP_PERCENT          196
#define MTR_KEY_KP_LESS             197
#define MTR_KEY_KP_GREATER          198
#define MTR_KEY_KP_AMPERSAND        199
#define MTR_KEY_KP_DBLAMPERSAND     200
#define MTR_KEY_KP_VERTICALBAR      201
#define MTR_KEY_KP_DBLVERTICALBAR   202
#define MTR_KEY_KP_COLON            203
#define MTR_KEY_KP_HASH             204
#define MTR_KEY_KP_SPACE            205
#define MTR_KEY_KP_AT               206
#define MTR_KEY_KP_EXCLAM           207
#define MTR_KEY_KP_MEMSTORE         208
#define MTR_KEY_KP_MEMRECALL        209
#define MTR_KEY_KP_MEMCLEAR         210
#define MTR_KEY_KP_MEMADD           211
#define MTR_KEY_KP_MEMSUBTRACT      212
#define MTR_KEY_KP_MEMMULTIPLY      213
#define MTR_KEY_KP_MEMDIVIDE        214
#define MTR_KEY_KP_PLUSMINUS        215
#define MTR_KEY_KP_CLEAR            216
#define MTR_KEY_KP_CLEARENTRY       217
#define MTR_KEY_KP_BINARY           218
#define MTR_KEY_KP_OCTAL            219
#define MTR_KEY_KP_DECIMAL          220
#define MTR_KEY_KP_HEXADECIMAL      221

#define MTR_KEY_LCTRL               224
#define MTR_KEY_LSHIFT              225
#define MTR_KEY_LALT                226
#define MTR_KEY_LGUI                227
#define MTR_KEY_RCTRL               228
#define MTR_KEY_RSHIFT              229
#define MTR_KEY_RALT                230
#define MTR_KEY_RGUI                231

#define MTR_KEY_MODE                257

#define MTR_KEY_AUDIONEXT           258
#define MTR_KEY_AUDIOPREV           259
#define MTR_KEY_AUDIOSTOP           260
#define MTR_KEY_AUDIOPLAY           261
#define MTR_KEY_AUDIOMUTE           262
#define MTR_KEY_MEDIASELECT         263
#define MTR_KEY_WWW                 264
#define MTR_KEY_MAIL                265
#define MTR_KEY_CALCULATOR          266
#define MTR_KEY_COMPUTER            267
#define MTR_KEY_AC_SEARCH           268
#define MTR_KEY_AC_HOME             269
#define MTR_KEY_AC_BACK             270
#define MTR_KEY_AC_FORWARD          271
#define MTR_KEY_AC_STOP             272
#define MTR_KEY_AC_REFRESH          273
#define MTR_KEY_AC_BOOKMARKS        274

#define MTR_KEY_BRIGHTNESSDOWN      275
#define MTR_KEY_BRIGHTNESSUP        276
#define MTR_KEY_DISPLAYSWITCH       277
#define MTR_KEY_KBDILLUMTOGGLE      278
#define MTR_KEY_KBDILLUMDOWN        279
#define MTR_KEY_KBDILLUMUP          280
#define MTR_KEY_EJECT               281
#define MTR_KEY_SLEEP               282

#define MTR_KEY_APP1                283
#define MTR_KEY_APP2                284

#define MTR_MOUSE_LEFT   1
#define MTR_MOUSE_RIGHT  2
#define MTR_MOUSE_MIDDLE 3
#define MTR_MOUSE_X1     4
#define MTR_MOUSE_X2     5

#define MTR_GUI_WINDOW_BORDER           0x0001
#define MTR_GUI_WINDOW_MOVABLE          0x0002
#define MTR_GUI_WINDOW_SCALABLE         0x0004
#define MTR_GUI_WINDOW_CLOSABLE         0x0008
#define MTR_GUI_WINDOW_MINIMIZABLE      0x0010
#define MTR_GUI_WINDOW_NO_SCROLLBAR     0x0020
#define MTR_GUI_WINDOW_TITLE            0x0040
#define MTR_GUI_WINDOW_SCROLL_AUTO_HIDE 0x0080
#define MTR_GUI_WINDOW_BACKGROUND       0x0100
#define MTR_GUI_WINDOW_SCALE_LEFT       0x0200

#define MTR_GUI_TEXT_ALIGN_LEFT     0x01
#define MTR_GUI_TEXT_ALIGN_CENTERED 0x02
#define MTR_GUI_TEXT_ALIGN_RIGHT    0x04
#define MTR_GUI_TEXT_ALIGN_TOP      0x08
#define MTR_GUI_TEXT_ALIGN_MIDDLE   0x10
#define MTR_GUI_TEXT_ALIGN_BOTTOM   0x20

#define MTR_GUI_SYMBOL_NONE           0
#define MTR_GUI_SYMBOL_X              1
#define MTR_GUI_SYMBOL_UNDERSCORE     2
#define MTR_GUI_SYMBOL_CIRCLE_SOLID   3
#define MTR_GUI_SYMBOL_CIRCLE_OUTLINE 4
#define MTR_GUI_SYMBOL_RECT_SOLID     5
#define MTR_GUI_SYMBOL_RECT_OUTLINE   6
#define MTR_GUI_SYMBOL_TRIANGLE_UP    7
#define MTR_GUI_SYMBOL_TRIANGLE_DOWN  8
#define MTR_GUI_SYMBOL_TRIANGLE_LEFT  9
#define MTR_GUI_SYMBOL_TRIANGLE_RIGHT 10
#define MTR_GUI_SYMBOL_PLUS           11
#define MTR_GUI_SYMBOL_MINUS          12

#endif
