#ifndef MTR_BINDING_COMMON_H
#define MTR_BINDING_COMMON_H

#if defined(lua_h)
    #define _SCRIPT_MODULE "Script_Lua"
    #define _VM lua_State *
    #define _CFUNCTION lua_CFunction
#elif defined(_SQUIRREL_H_)
    #define _SCRIPT_MODULE "Script_Squirrel"
    #define _VM HSQUIRRELVM
    #define _CFUNCTION SQFUNCTION
#elif defined(DUKTAPE_H_INCLUDED)
    #define _SCRIPT_MODULE "Script_Duktape"
    #define _VM duk_context *
    #define _CFUNCTION duk_c_function
#endif

#define _PREREQ1 _SCRIPT_MODULE

#define MTR_FIND_AND_REGISTER_ALL()                                   \
    MTR_FIND_FUNCTION(MTR_ScriptsRegisterFunction, _SCRIPT_MODULE);   \
    MTR_FIND_FUNCTION(MTR_ScriptsRegisterVariable_b, _SCRIPT_MODULE); \
    MTR_FIND_FUNCTION(MTR_ScriptsRegisterVariable_i, _SCRIPT_MODULE); \
    MTR_FIND_FUNCTION(MTR_ScriptsRegisterVariable_u, _SCRIPT_MODULE); \
    MTR_FIND_FUNCTION(MTR_ScriptsRegisterVariable_f, _SCRIPT_MODULE); \
    MTR_FIND_FUNCTION(MTR_ScriptsRegisterVariable_d, _SCRIPT_MODULE); \
    MTR_FIND_FUNCTION(MTR_ScriptsRegisterVariable_s, _SCRIPT_MODULE); \
    MTR_FIND_FUNCTION(MTR_ScriptsGetVm, _SCRIPT_MODULE);              \
    if (ok)                                                           \
        MTR_ScriptsRegisterAll();

#ifdef lua_h
    #define MTR_PLUGIN_INIT()                                        \
        MTR_DCLSPC void MTR_CALL MTR_PluginInit(void)                \
        {                                                            \
            bool ok = true;                                          \
            MTR_LogWrite_s("Reporting Lua compile-time version:", 3, \
             MTR_LMT_INFO, LUA_RELEASE);                             \
            MTR_FIND_AND_REGISTER_ALL();                             \
        }
#endif /* lua_h */
#ifdef _SQUIRREL_H_
    #define MTR_PLUGIN_INIT()                                             \
        MTR_DCLSPC void MTR_CALL MTR_PluginInit(void)                     \
        {                                                                 \
            bool ok = true;                                               \
            MTR_LogWrite_s("Reporting Squirrel compile-time version:", 1, \
             MTR_LMT_INFO, SQUIRREL_VERSION);                             \
            MTR_LogWrite_i("Reporting Squirrel linked version:", 1,       \
             MTR_LMT_INFO, sq_getversion());                              \
            MTR_FIND_AND_REGISTER_ALL();                                  \
        }
#endif /* _SQUIRREL_H_ */
#ifdef DUKTAPE_H_INCLUDED
    #define MTR_PLUGIN_INIT()                                           \
        MTR_DCLSPC void MTR_CALL MTR_PluginInit(void)                   \
        {                                                               \
            long int verMajor;                                          \
            long int verMinor;                                          \
            long int verPatch;                                          \
            bool ok = true;                                             \
            verMajor = DUK_VERSION / 10000;                             \
            verMinor = (DUK_VERSION - verMajor * 10000) / 100;          \
            verPatch = DUK_VERSION - verMajor * 10000 - verMinor * 100; \
            MTR_LogWrite("Reporting Duktape compile-time version:", 3,  \
             MTR_LMT_INFO);                                             \
            MTR_LogWrite_i("Major:", 4, MTR_LMT_INFO, verMajor);        \
            MTR_LogWrite_i("Minor:", 4, MTR_LMT_INFO, verMinor);        \
            MTR_LogWrite_i("Patch:", 4, MTR_LMT_INFO, verPatch);        \
            MTR_FIND_AND_REGISTER_ALL();                                \
        }
#endif /* DUKTAPE_H_INCLUDED */

#define MTR_BINDING_COMMON_CODE(_moduleID, _version, _prereq0)           \
    MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)                \
    {                                                                    \
        mtrReport *report;                                               \
        report = malloc(sizeof(mtrReport));                              \
        if (report == NULL)                                              \
            return NULL;                                                 \
        report->moduleID = _moduleID;                                    \
        report->version = _version;                                      \
        report->subsystem = "binding";                                   \
        report->prereqsCount = 2;                                        \
        report->prereqs = malloc(sizeof(char *) * report->prereqsCount); \
        if (report->prereqs == NULL)                                     \
        {                                                                \
            free(report);                                                \
            return NULL;                                                 \
        }                                                                \
        report->prereqs[0] = _prereq0;                                   \
        report->prereqs[1] = _PREREQ1;                                   \
        report->prereqSubsystemsCount = 0;                               \
        report->prereqSubsystems = NULL;                                 \
        return report;                                                   \
    }                                                                    \
    MTR_PLUGIN_INIT()

#define MTR_BINDING_COMMON_HEADER()                                       \
    _VM mtrVm;                                                            \
    typedef _VM (MTR_CALL * MTR_ScriptsGetVmFunc)(void);                  \
    MTR_ScriptsGetVmFunc MTR_ScriptsGetVm;                                \
    typedef void (MTR_CALL * MTR_ScriptsRegisterFunctionFunc)(_CFUNCTION, \
     char *);                                                             \
    MTR_ScriptsRegisterFunctionFunc MTR_ScriptsRegisterFunction;          \
    typedef void (MTR_CALL * MTR_ScriptsRegisterVariable_bFunc)(          \
     const char *name, bool value);                                       \
    MTR_ScriptsRegisterVariable_bFunc MTR_ScriptsRegisterVariable_b;      \
    typedef void (MTR_CALL * MTR_ScriptsRegisterVariable_iFunc)(          \
     const char *name, int value);                                        \
    MTR_ScriptsRegisterVariable_iFunc MTR_ScriptsRegisterVariable_i;      \
    typedef void (MTR_CALL * MTR_ScriptsRegisterVariable_uFunc)(          \
     const char *name, unsigned int value);                               \
    MTR_ScriptsRegisterVariable_uFunc MTR_ScriptsRegisterVariable_u;      \
    typedef void (MTR_CALL * MTR_ScriptsRegisterVariable_fFunc)(          \
     const char *name, float value);                                      \
    MTR_ScriptsRegisterVariable_fFunc MTR_ScriptsRegisterVariable_f;      \
    typedef void (MTR_CALL * MTR_ScriptsRegisterVariable_dFunc)(          \
     const char *name, double value);                                     \
    MTR_ScriptsRegisterVariable_dFunc MTR_ScriptsRegisterVariable_d;      \
    typedef void (MTR_CALL * MTR_ScriptsRegisterVariable_sFunc)(          \
     const char *name, const char *value);                                \
    MTR_ScriptsRegisterVariable_sFunc MTR_ScriptsRegisterVariable_s;

#define MTR_FIND_AND_ADD_FUNCTION(module, function)                          \
    MTR_ ## function = (MTR_ ## function ## Func)MTR_FindFunction(module,    \
     MTR_SRINGIFY(MTR_ ## function));                                        \
    if (MTR_ ## function == NULL)                                            \
    {                                                                        \
        MTR_LogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,          \
         MTR_SRINGIFY(MTR_ ## function));                                    \
        MTR_LogWrite_s("Function not added: ", 3, MTR_LMT_ERROR, #function); \
    }                                                                        \
    else                                                                     \
        MTR_ScriptsRegisterFunction(MTR_SF_ ## function, #function);

#endif /* MTR_BINDING_COMMON_H */
