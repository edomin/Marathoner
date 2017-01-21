#ifndef SCRIPT_FUNC_H
#define SCRIPT_FUNC_H

#ifdef lua_h
    #define MTR_SCRIPT_FUNC(funcname)                int funcname(lua_State* l)

    #define MTR_SF_GET_BOOL(varname, stackpos)       varname = lua_toboolean(mtrVm, stackpos)
    #define MTR_SF_GET_INT(varname, stackpos)        varname = lua_tointeger(mtrVm, stackpos)
    #define MTR_SF_GET_UINT8(varname, stackpos)      varname = (uint8_t)lua_tointeger(mtrVm, stackpos)
    #define MTR_SF_GET_UINT32(varname, stackpos)     varname = (uint32_t)lua_tonumber(mtrVm, stackpos)
    #define MTR_SF_GET_SINGLE(varname, stackpos)     varname = (float)lua_tonumber(mtrVm, stackpos)
    #define MTR_SF_GET_DOUBLE(varname, stackpos)     varname = lua_tonumber(mtrVm, stackpos)
    #define MTR_SF_GET_STRING(varname, stackpos)     varname = lua_tostring(mtrVm, stackpos)

    #define MTR_SF_PUSH_BOOL(value)                  lua_pushboolean(mtrVm, value)
    #define MTR_SF_PUSH_INT(value)                   lua_pushinteger(mtrVm, value)
    #define MTR_SF_PUSH_UINT8(value)                 lua_pushinteger(mtrVm, (int)value)
    #define MTR_SF_PUSH_UINT32(value)                lua_pushnumber(mtrVm, (double)value)
    #define MTR_SF_PUSH_SINGLE(value)                lua_pushnumber(mtrVm, (double)value)
    #define MTR_SF_PUSH_DOUBLE(value)                lua_pushnumber(mtrVm, value)
    #define MTR_SF_PUSH_STRING(value)                lua_pushstring(mtrVm, value)
    #define MTR_SF_PUSH_NIL()                        lua_pushnil(mtrVm)
#endif
#ifdef _SQUIRREL_H_
    #include <limits.h>
    #if defined (SQUSEDOUBLE)
        double  mtrSfFloatTemp;
    #else
        float   mtrSfFloatTemp;
    #endif
    SQBool      mtrSfBoolTemp;
    int         mtrSfIntTemp;
    #if ((defined (_SQ64)) && (LLONG_MAX == INT64_MAX))
        int64_t mtrSFInt64Temp;
    #endif

    #define MTR_SCRIPT_FUNC(funcname)                SQInteger funcname(HSQUIRRELVM v)

    #define MTR_SF_GET_BOOL(varname, stackpos)       sq_getbool(mtrVm, stackpos + 1, &mtrSfBoolTemp); \
                                                     varname = (bool)mtrSfBoolTemp;
    #if ((defined (_SQ64)) && (LLONG_MAX == INT64_MAX))
        #define MTR_SF_GET_INT(varname, stackpos)    sq_getinteger(mtrVm, stackpos + 1, &mtrSFInt64Temp); \
                                                     varname = (int)mtrSfIntTemp;
        #define MTR_SF_GET_UINT8(varname, stackpos)  sq_getinteger(mtrVm, stackpos + 1, &mtrSFInt64Temp); \
                                                     varname = (uint8_t)mtrSfIntTemp;
        #define MTR_SF_GET_UINT32(varname, stackpos) sq_getinteger(mtrVm, stackpos + 1, &mtrSFInt64Temp); \
                                                     varname = (uint32_t)mtrSFInt64Temp;
    #else
        #define MTR_SF_GET_INT(varname, stackpos)    sq_getinteger(mtrVm, stackpos + 1, &varname)
        #define MTR_SF_GET_UINT8(varname, stackpos)  sq_getinteger(mtrVm, stackpos + 1, &mtrSfIntTemp); \
                                                     varname = (uint8_t)mtrSfIntTemp;
        #define MTR_SF_GET_UINT32(varname, stackpos) sq_getfloat(mtrVm, stackpos + 1, &mtrSfFloatTemp); \
                                                     varname = (uint32_t)mtrSfFloatTemp;
    #endif
    #if defined (SQUSEDOUBLE)
        #define MTR_SF_GET_SINGLE(varname, stackpos) sq_getfloat(mtrVm, stackpos + 1, &mtrSfFloatTemp); \
                                                     varname = (float)mtrSfFloatTemp;
        #define MTR_SF_GET_DOUBLE(varname, stackpos) sq_getfloat(mtrVm, stackpos + 1, &varname)
    #else
        #define MTR_SF_GET_SINGLE(varname, stackpos) sq_getfloat(mtrVm, stackpos + 1, &varname)
        #define MTR_SF_GET_DOUBLE(varname, stackpos) sq_getfloat(mtrVm, stackpos + 1, &mtrSfFloatTemp); \
                                                     varname = (double)mtrSfFloatTemp;
    #endif
    #define MTR_SF_GET_STRING(varname, stackpos)     sq_getstring(mtrVm, stackpos + 1, &varname)

    #define MTR_SF_PUSH_BOOL(value)                  mtrSfBoolTemp = value + UINT_MAX + 1; \
                                                     sq_pushbool(mtrVm, mtrSfBoolTemp);
    #define MTR_SF_PUSH_INT(value)                   sq_pushinteger(mtrVm, value)
    #define MTR_SF_PUSH_UINT8(value)                 sq_pushinteger(mtrVm, (int)value)
    #if ((defined (_SQ64)) && (LLONG_MAX == INT64_MAX))
        #define MTR_SF_PUSH_UINT32(value)            sq_pushinteger(mtrVm, value)
    #else
        #if defined (SQUSEDOUBLE)
            #define MTR_SF_PUSH_UINT32(value)        sq_pushfloat(mtrVm, (double)value)
        #else
            #define MTR_SF_PUSH_UINT32(value)        sq_pushfloat(mtrVm, (float)value)
        #endif
    #endif
    #if defined (SQUSEDOUBLE)
        #define MTR_SF_PUSH_SINGLE(value)            sq_pushfloat(mtrVm, (double)value)
        #define MTR_SF_PUSH_DOUBLE(value)            sq_pushfloat(mtrVm, value)
    #else
        #define MTR_SF_PUSH_SINGLE(value)            sq_pushfloat(mtrVm, value)
        #define MTR_SF_PUSH_DOUBLE(value)            sq_pushfloat(mtrVm, (float)value)
    #endif
    #define MTR_SF_PUSH_STRING(value)                sq_pushstring(mtrVm, value, -1)
    #define MTR_SF_PUSH_NIL()                        sq_pushnull(mtrVm)
#endif

#endif
