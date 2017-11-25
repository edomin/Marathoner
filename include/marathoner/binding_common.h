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

#define MTR_FIND_ALL()                                                \
    MTR_FIND_FUNCTION(MTR_ScriptsRegisterFunction, _SCRIPT_MODULE);   \
    MTR_FIND_FUNCTION(MTR_ScriptsRegisterVariable_b, _SCRIPT_MODULE); \
    MTR_FIND_FUNCTION(MTR_ScriptsRegisterVariable_i, _SCRIPT_MODULE); \
    MTR_FIND_FUNCTION(MTR_ScriptsRegisterVariable_u, _SCRIPT_MODULE); \
    MTR_FIND_FUNCTION(MTR_ScriptsRegisterVariable_f, _SCRIPT_MODULE); \
    MTR_FIND_FUNCTION(MTR_ScriptsRegisterVariable_d, _SCRIPT_MODULE); \
    MTR_FIND_FUNCTION(MTR_ScriptsRegisterVariable_s, _SCRIPT_MODULE); \
    MTR_FIND_FUNCTION(MTR_ScriptsGetVm, _SCRIPT_MODULE);

#if defined(MTR_MOD_PLUGIN)
    #define MTR_FIND_AND_REGISTER_ALL(_moduleID) \
        MTR_FIND_ALL();                 \
        if (ok)                         \
            MTR_ScriptsRegisterAll();
#else
    #if defined(MTR_BINDING)
        #define MTR_FIND_AND_REGISTER_ALL(_moduleID) MTR_ ## _moduleID ## RegisterAll();
    #else
        #define MTR_FIND_AND_REGISTER_ALL(_moduleID) MTR_ScriptsRegisterAll();
    #endif
#endif

#if defined(MTR_MOD_PLUGIN)
    #define MTR_BINDING_OK_VAR() bool ok = true;
#else
    #define MTR_BINDING_OK_VAR()
#endif

#ifdef lua_h
    #define MTR_PLUGIN_INIT(_moduleID)                                 \
        MTR_DCLSPC void MTR_CALL MTR_ ## _moduleID ## PluginInit(void) \
        {                                                              \
            MTR_BINDING_OK_VAR();                                      \
            MTR_LogWrite_s("Reporting Lua compile-time version:", 3,   \
             MTR_LMT_INFO, LUA_RELEASE);                               \
            MTR_FIND_AND_REGISTER_ALL(_moduleID);                      \
        }
#endif /* lua_h */
#ifdef _SQUIRREL_H_
    #define MTR_PLUGIN_INIT(_moduleID)                                    \
        MTR_DCLSPC void MTR_CALL MTR_ ## _moduleID ## PluginInit(void)    \
        {                                                                 \
            MTR_BINDING_OK_VAR();                                         \
            MTR_LogWrite_s("Reporting Squirrel compile-time version:", 1, \
             MTR_LMT_INFO, SQUIRREL_VERSION);                             \
            MTR_LogWrite_i("Reporting Squirrel linked version:", 1,       \
             MTR_LMT_INFO, sq_getversion());                              \
            MTR_FIND_AND_REGISTER_ALL(_moduleID);                         \
        }
#endif /* _SQUIRREL_H_ */
#ifdef DUKTAPE_H_INCLUDED
    #define MTR_PLUGIN_INIT(_moduleID)                                  \
        MTR_DCLSPC void MTR_CALL MTR_ ## _moduleID ## PluginInit(void)  \
        {                                                               \
            long int verMajor;                                          \
            long int verMinor;                                          \
            long int verPatch;                                          \
            MTR_BINDING_OK_VAR();                                       \
            verMajor = DUK_VERSION / 10000;                             \
            verMinor = (DUK_VERSION - verMajor * 10000) / 100;          \
            verPatch = DUK_VERSION - verMajor * 10000 - verMinor * 100; \
            MTR_LogWrite("Reporting Duktape compile-time version:", 3,  \
             MTR_LMT_INFO);                                             \
            MTR_LogWrite_i("Major:", 4, MTR_LMT_INFO, verMajor);        \
            MTR_LogWrite_i("Minor:", 4, MTR_LMT_INFO, verMinor);        \
            MTR_LogWrite_i("Patch:", 4, MTR_LMT_INFO, verPatch);        \
            MTR_FIND_AND_REGISTER_ALL(_moduleID);                       \
        }
#endif /* DUKTAPE_H_INCLUDED */

#define MTR_BINDING_CREATE_REPORT(_moduleID, _version, _prereq0)         \
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
    }

#if defined(MTR_MOD_PLUGIN)
    #define MTR_BINDING_COMMON_CODE(_moduleID, _version, _prereq0) \
        MTR_BINDING_CREATE_REPORT(#_moduleID, _version, _prereq0)  \
        MTR_PLUGIN_INIT(_moduleID)
#else
    #define MTR_BINDING_COMMON_CODE(_moduleID, _version, _prereq0) \
        MTR_PLUGIN_INIT(_moduleID)
#endif

#define MTR_BINDING_COMMON_HEADER()                                  \
    MTR_EXTERN _VM mtrVm;                                            \
    MTR_FUNC(_VM, MTR_ScriptsGetVm, void);                           \
    MTR_FUNC(void, MTR_ScriptsRegisterFunction, _CFUNCTION, char *); \
    MTR_FUNC(bool, MTR_ScriptsRegisterVariable_b, const char *name,  \
     bool value);                                                    \
    MTR_FUNC(bool, MTR_ScriptsRegisterVariable_i, const char *name,  \
     int value);                                                     \
    MTR_FUNC(bool, MTR_ScriptsRegisterVariable_u, const char *name,  \
     unsigned int value);                                            \
    MTR_FUNC(bool, MTR_ScriptsRegisterVariable_f, const char *name,  \
     float value);                                                   \
    MTR_FUNC(bool, MTR_ScriptsRegisterVariable_d, const char *name,  \
     double value);                                                  \
    MTR_FUNC(bool, MTR_ScriptsRegisterVariable_s, const char *name,  \
     const char *value);

#if defined(MTR_MOD_PLUGIN)
    #define MTR_FIND_AND_ADD_FUNCTION(module, function)                       \
        MTR_ ## function = (MTR_ ## function ## Func)MTR_FindFunction(module, \
         MTR_SRINGIFY(MTR_ ## function));                                     \
        if (MTR_ ## function == NULL)                                         \
        {                                                                     \
            MTR_LogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,       \
             MTR_SRINGIFY(MTR_ ## function));                                 \
            MTR_LogWrite_s("Function not added: ", 3, MTR_LMT_ERROR,          \
             #function);                                                      \
        }                                                                     \
        else                                                                  \
            MTR_ScriptsRegisterFunction(MTR_SF_ ## function, #function);
#else
    #define MTR_FIND_AND_ADD_FUNCTION(module, function) \
     MTR_ScriptsRegisterFunction(MTR_SF_ ## function, #function);
#endif

#endif /* MTR_BINDING_COMMON_H */
