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

#define MTR_FIND_AND_REGISTER_ALL()                                \
    MTR_FIND_FUNCTION(mtrScriptsRegisterFunction, _SCRIPT_MODULE); \
    MTR_FIND_FUNCTION(mtrScriptsRegisterNumericVariable,           \
     _SCRIPT_MODULE);                                              \
    MTR_FIND_FUNCTION(mtrScriptsGetVm, _SCRIPT_MODULE);            \
    if (ok)                                                        \
        mtrScriptsRegisterAll();

#ifdef lua_h
    #define MTR_PLUGIN_INIT()                                       \
        MTR_EXPORT void MTR_CALL mtrPluginInit(void)                \
        {                                                           \
            bool ok = true;                                         \
            mtrLogWrite_s("Reporting Lua compile-time version:", 3, \
             MTR_LMT_INFO, LUA_RELEASE);                            \
            MTR_FIND_AND_REGISTER_ALL();                            \
        }
#endif /* lua_h */
#ifdef _SQUIRREL_H_
    #define MTR_PLUGIN_INIT()                                            \
        MTR_EXPORT void MTR_CALL mtrPluginInit(void)                     \
        {                                                                \
            bool ok = true;                                              \
            mtrLogWrite_s("Reporting Squirrel compile-time version:", 1, \
             MTR_LMT_INFO, SQUIRREL_VERSION);                            \
            mtrLogWrite_i("Reporting Squirrel linked version:", 1,       \
             MTR_LMT_INFO, sq_getversion());                             \
            MTR_FIND_AND_REGISTER_ALL();                                 \
        }
#endif /* _SQUIRREL_H_ */
#ifdef DUKTAPE_H_INCLUDED
    #define MTR_PLUGIN_INIT()                                           \
        MTR_EXPORT void MTR_CALL mtrPluginInit(void)                    \
        {                                                               \
            long int verMajor;                                          \
            long int verMinor;                                          \
            long int verPatch;                                          \
            bool ok = true;                                             \
            verMajor = DUK_VERSION / 10000;                             \
            verMinor = (DUK_VERSION - verMajor * 10000) / 100;          \
            verPatch = DUK_VERSION - verMajor * 10000 - verMinor * 100; \
            mtrLogWrite("Reporting Duktape compile-time version:", 3,   \
             MTR_LMT_INFO);                                             \
            mtrLogWrite_i("Major:", 4, MTR_LMT_INFO, verMajor);         \
            mtrLogWrite_i("Minor:", 4, MTR_LMT_INFO, verMinor);         \
            mtrLogWrite_i("Patch:", 4, MTR_LMT_INFO, verPatch);         \
            MTR_FIND_AND_REGISTER_ALL();                                \
        }
#endif /* DUKTAPE_H_INCLUDED */

#define MTR_BINDING_COMMON_CODE(_moduleID, _version, _prereq0)           \
    MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)                 \
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

#define MTR_BINDING_COMMON_HEADER()                                          \
    _VM mtrVm;                                                               \
    typedef _VM (MTR_CALL * mtrScriptsGetVmFunc)(void);                      \
    mtrScriptsGetVmFunc mtrScriptsGetVm;                                     \
    typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(_CFUNCTION,     \
     char *);                                                                \
    mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;               \
    typedef void (MTR_CALL * mtrScriptsRegisterNumericVariableFunc)(         \
     const char *name, double value);                                        \
    mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

#define MTR_FIND_AND_ADD_FUNCTION(module, function)                         \
    mtr ## function = (mtr ## function ## Func)mtrFindFunction(module,      \
     MTR_SRINGIFY(mtr ## function));                              \
    if (mtr ## function == NULL)                                            \
    {                                                                       \
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,          \
         MTR_SRINGIFY(mtr ## function));                          \
        mtrLogWrite_s("Function not added: ", 3, MTR_LMT_ERROR, #function); \
    }                                                                       \
    else                                                                    \
        mtrScriptsRegisterFunction(mtrSF_ ## function, #function);

#endif /* MTR_BINDING_COMMON_H */
