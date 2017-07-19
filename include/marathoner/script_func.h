#ifndef SCRIPT_FUNC_H
#define SCRIPT_FUNC_H

#ifdef lua_h
    #define MTR_SCRIPT_FUNC(funcname)                int funcname(lua_State* l)

    #define MTR_SF_GET_BOOL(varname, stackpos)       varname = lua_toboolean(mtrVm, stackpos)
    #define MTR_SF_GET_INT(varname, stackpos)        varname = lua_tointeger(mtrVm, stackpos)
    #define MTR_SF_GET_LINT(varname, stackpos)       varname = lua_tointeger(mtrVm, stackpos)
    #define MTR_SF_GET_LLINT(varname, stackpos)      varname = lua_tointeger(mtrVm, stackpos)
    #if (UINT_MAX <= PTRDIFF_MAX)
        #define MTR_SF_GET_UINT(varname, stackpos)   varname = lua_tointeger(mtrVm, stackpos)
    #else
        #define MTR_SF_GET_UINT(varname, stackpos)   varname = lua_tonumber(mtrVm, stackpos)
    #endif
    #define MTR_SF_GET_UINT8(varname, stackpos)      varname = lua_tointeger(mtrVm, stackpos)
    #if (UINT32_MAX <= PTRDIFF_MAX)
        #define MTR_SF_GET_UINT32(varname, stackpos) varname = lua_tointeger(mtrVm, stackpos)
    #else
        #define MTR_SF_GET_UINT32(varname, stackpos) varname = lua_tonumber(mtrVm, stackpos)
    #endif
    #define MTR_SF_GET_SINGLE(varname, stackpos)     varname = lua_tonumber(mtrVm, stackpos)
    #define MTR_SF_GET_DOUBLE(varname, stackpos)     varname = lua_tonumber(mtrVm, stackpos)
    #define MTR_SF_GET_STRING(varname, stackpos)     varname = lua_tostring(mtrVm, stackpos)

    #define MTR_SF_PUSH_BOOL(value)                  lua_pushboolean(mtrVm, value)
    #define MTR_SF_PUSH_INT(value)                   lua_pushinteger(mtrVm, value)
    #define MTR_SF_PUSH_LINT(value)                  lua_pushinteger(mtrVm, value)
    #define MTR_SF_PUSH_LLINT(value)                 lua_pushinteger(mtrVm, value)
    #define MTR_SF_PUSH_INT16(value)                 lua_pushinteger(mtrVm, value)
    #define MTR_SF_PUSH_UINT8(value)                 lua_pushinteger(mtrVm, value)
    #if (UINT32_MAX <= PTRDIFF_MAX)
        #define MTR_SF_PUSH_UINT32(value)            lua_pushinteger(mtrVm, (double)value)
    #else
        #define MTR_SF_PUSH_UINT32(value)            lua_pushnumber(mtrVm, (double)value)
    #endif
    #define MTR_SF_PUSH_SIZE(value)                  lua_pushnumber(mtrVm, (double)value)
    #define MTR_SF_PUSH_SINGLE(value)                lua_pushnumber(mtrVm, (double)value)
    #define MTR_SF_PUSH_DOUBLE(value)                lua_pushnumber(mtrVm, value)
    #define MTR_SF_PUSH_STRING(value)                lua_pushstring(mtrVm, value)
    #define MTR_SF_PUSH_LSTRING(value, len)          lua_pushlstring(mtrVm, value, len)
    #define MTR_SF_PUSH_NIL()                        lua_pushnil(mtrVm)
#endif /* lua_h */
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

    #define MTR_SCRIPT_FUNC(funcname)                  SQInteger funcname(HSQUIRRELVM v)

    #define MTR_SF_GET_BOOL(varname, stackpos)         sq_getbool(mtrVm, stackpos + 1, &mtrSfBoolTemp); \
                                                       varname = mtrSfBoolTemp;
    #if ((defined (_SQ64)) && (LLONG_MAX == INT64_MAX))
        #define MTR_SF_GET_INT(varname, stackpos)      sq_getinteger(mtrVm, stackpos + 1, &mtrSFInt64Temp); \
                                                       varname = mtrSfIntTemp;
        #define MTR_SF_GET_UINT(varname, stackpos)     sq_getinteger(mtrVm, stackpos + 1, &mtrSFInt64Temp); \
                                                       varname = mtrSFInt64Temp;
        #define MTR_SF_GET_UINT8(varname, stackpos)    sq_getinteger(mtrVm, stackpos + 1, &mtrSFInt64Temp); \
                                                       varname = mtrSfIntTemp;
        #define MTR_SF_GET_UINT32(varname, stackpos)   sq_getinteger(mtrVm, stackpos + 1, &mtrSFInt64Temp); \
                                                       varname = mtrSFInt64Temp;
    #else
        #define MTR_SF_GET_INT(varname, stackpos)      sq_getinteger(mtrVm, stackpos + 1, &varname)
        #define MTR_SF_GET_UINT(varname, stackpos)     sq_getfloat(mtrVm, stackpos + 1, &mtrSfFloatTemp); \
                                                       varname = mtrSfFloatTemp;
        #define MTR_SF_GET_UINT8(varname, stackpos)    sq_getinteger(mtrVm, stackpos + 1, &mtrSfIntTemp); \
                                                       varname = mtrSfIntTemp;
        #define MTR_SF_GET_UINT32(varname, stackpos)   sq_getfloat(mtrVm, stackpos + 1, &mtrSfFloatTemp); \
                                                       varname = mtrSfFloatTemp;
    #endif
    #if defined(_SQ64)
        #define MTR_SF_GET_LINT(varname, stackpos)     sq_getinteger(mtrVm, stackpos + 1, &mtrSFInt64Temp); \
                                                       varname = mtrSfIntTemp;
        #define MTR_SF_GET_LLINT(varname, stackpos)    sq_getinteger(mtrVm, stackpos + 1, &varname)
    #else
        #if LONG_MAX == INT_MAX
            #define MTR_SF_GET_LINT(varname, stackpos) sq_getinteger(mtrVm, stackpos + 1, (int *)&varname)
        #else
            #define MTR_SF_GET_LINT(varname, stackpos) sq_getfloat(mtrVm, stackpos + 1, &mtrSfFloatTemp); \
                                                       varname = mtrSfFloatTemp;
        #endif
        #define MTR_SF_GET_LLINT(varname, stackpos)    sq_getfloat(mtrVm, stackpos + 1, &mtrSfFloatTemp); \
                                                       varname = mtrSfFloatTemp;
    #endif

    #if defined (SQUSEDOUBLE)
        #define MTR_SF_GET_SINGLE(varname, stackpos)   sq_getfloat(mtrVm, stackpos + 1, &mtrSfFloatTemp); \
                                                       varname = mtrSfFloatTemp;
        #define MTR_SF_GET_DOUBLE(varname, stackpos)   sq_getfloat(mtrVm, stackpos + 1, &varname)
    #else
        #define MTR_SF_GET_SINGLE(varname, stackpos)   sq_getfloat(mtrVm, stackpos + 1, &varname)
        #define MTR_SF_GET_DOUBLE(varname, stackpos)   sq_getfloat(mtrVm, stackpos + 1, &mtrSfFloatTemp); \
                                                       varname = mtrSfFloatTemp;
    #endif
    #define MTR_SF_GET_STRING(varname, stackpos)       sq_getstring(mtrVm, stackpos + 1, &varname)

    #define MTR_SF_PUSH_BOOL(value)                    mtrSfBoolTemp = value + UINT_MAX + 1; \
                                                       sq_pushbool(mtrVm, mtrSfBoolTemp);
    #define MTR_SF_PUSH_INT(value)                     sq_pushinteger(mtrVm, value)
    #define MTR_SF_PUSH_INT16(value)                   sq_pushinteger(mtrVm, (int)value)
    #define MTR_SF_PUSH_UINT8(value)                   sq_pushinteger(mtrVm, (int)value)
    #if ((defined (_SQ64)) && (LLONG_MAX == INT64_MAX))
        #define MTR_SF_PUSH_UINT32(value)              sq_pushinteger(mtrVm, value)
        #define MTR_SF_PUSH_SIZE(value)                sq_pushinteger(mtrVm, value)
    #else
        #if defined (SQUSEDOUBLE)
            #define MTR_SF_PUSH_UINT32(value)          sq_pushfloat(mtrVm, (double)value)
            #define MTR_SF_PUSH_SIZE(value)            sq_pushfloat(mtrVm, (double)value)
        #else
            #define MTR_SF_PUSH_UINT32(value)          sq_pushfloat(mtrVm, (float)value)
            #define MTR_SF_PUSH_SIZE(value)            sq_pushfloat(mtrVm, (float)value)
        #endif
    #endif
    #if defined(_SQ64)
        #define MTR_SF_PUSH_LINT(value)                sq_pushinteger(mtrVm, value)
        #define MTR_SF_PUSH_LLINT(value)               sq_pushinteger(mtrVm, value)
    #else
        #if LONG_MAX == INT_MAX
            #define MTR_SF_PUSH_LINT(value)            sq_pushinteger(mtrVm, value)
        #else
            #if defined (SQUSEDOUBLE)
                #define MTR_SF_PUSH_LINT(value)        sq_pushfloat(mtrVm, (double)value)
            #else
                #define MTR_SF_PUSH_LINT(value)        sq_pushfloat(mtrVm, (float)value)
            #endif
        #endif
        #if defined (SQUSEDOUBLE)
            #define MTR_SF_PUSH_LLINT(value)           sq_pushfloat(mtrVm, (double)value)
        #else
            #define MTR_SF_PUSH_LLINT(value)           sq_pushfloat(mtrVm, (float)value)
        #endif
    #endif
    #if defined (SQUSEDOUBLE)
        #define MTR_SF_PUSH_SINGLE(value)              sq_pushfloat(mtrVm, (double)value)
        #define MTR_SF_PUSH_DOUBLE(value)              sq_pushfloat(mtrVm, value)
    #else
        #define MTR_SF_PUSH_SINGLE(value)              sq_pushfloat(mtrVm, value)
        #define MTR_SF_PUSH_DOUBLE(value)              sq_pushfloat(mtrVm, (float)value)
    #endif
    #define MTR_SF_PUSH_STRING(value)                  sq_pushstring(mtrVm, value, -1)
    #define MTR_SF_PUSH_NIL()                          sq_pushnull(mtrVm)
#endif

#endif
