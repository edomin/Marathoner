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
#endif /* _SQUIRREL_H_ */
#ifdef DUKTAPE_H_INCLUDED
    #define MTR_SCRIPT_FUNC(funcname)                duk_ret_t funcname(duk_context *ctx)

    #define MTR_SF_GET_BOOL(varname, stackpos)       varname = duk_to_boolean(mtrVm, stackpos - 1)
    #define MTR_SF_GET_INT(varname, stackpos)        varname = duk_to_int(mtrVm, stackpos - 1)
    #if (INT_MAX == LONG_MAX)
        #define MTR_SF_GET_LINT(varname, stackpos)   varname = duk_to_int(mtrVm, stackpos - 1)
    #else
        #define MTR_SF_GET_LINT(varname, stackpos)   varname = duk_to_number(mtrVm, stackpos - 1)
    #endif
    #define MTR_SF_GET_LLINT(varname, stackpos)      varname = duk_to_number(mtrVm, stackpos - 1)
    #define MTR_SF_GET_UINT(varname, stackpos)       varname = duk_to_uint(mtrVm, stackpos - 1)
    #define MTR_SF_GET_UINT8(varname, stackpos)      varname = duk_to_int(mtrVm, stackpos - 1)
    #define MTR_SF_GET_UINT32(varname, stackpos)     varname = duk_to_uint32(mtrVm, stackpos - 1)
    #define MTR_SF_GET_SINGLE(varname, stackpos)     varname = duk_to_number(mtrVm, stackpos - 1)
    #define MTR_SF_GET_DOUBLE(varname, stackpos)     varname = duk_to_number(mtrVm, stackpos - 1)
    #define MTR_SF_GET_STRING(varname, stackpos)     varname = duk_to_string(mtrVm, stackpos - 1)

    #define MTR_SF_PUSH_BOOL(value)                  duk_push_boolean(mtrVm, value)
    #define MTR_SF_PUSH_INT(value)                   duk_push_int(mtrVm, value)
    #if (INT_MAX == LONG_MAX)
        #define MTR_SF_PUSH_LINT(value)              duk_push_int(mtrVm, value)
    #else
        #define MTR_SF_PUSH_LINT(value)              duk_push_number(mtrVm, value)
    #endif
    #define MTR_SF_PUSH_LLINT(value)                 duk_push_number(mtrVm, value)
    #define MTR_SF_PUSH_INT16(value)                 duk_push_int(mtrVm, value)
    #define MTR_SF_PUSH_UINT8(value)                 duk_push_uint(mtrVm, value)
    #if (UINT32_MAX == UINT_MAX)
        #define MTR_SF_PUSH_UINT32(value)            duk_push_uint(mtrVm, value)
    #else
        #define MTR_SF_PUSH_UINT32(value)            duk_push_number(mtrVm, value)
    #endif
    #define MTR_SF_PUSH_SIZE(value)                  duk_push_number(mtrVm, value)
    #define MTR_SF_PUSH_SINGLE(value)                duk_push_number(mtrVm, value)
    #define MTR_SF_PUSH_DOUBLE(value)                duk_push_number(mtrVm, value)
    #define MTR_SF_PUSH_STRING(value)                duk_push_string(mtrVm, value)
    #define MTR_SF_PUSH_LSTRING(value, len)          duk_push_lstring(mtrVm, value, len)
    #define MTR_SF_PUSH_NIL()                        duk_push_null(mtrVm)
#endif /* DUKTAPE_H_INCLUDED */


#define MTR_SCRIPT_FUNC_V_V(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)               \
    {                                    \
        func();                          \
        return 0;                        \
    }

#define MTR_SCRIPT_FUNC_V_I1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        int i1;                           \
        MTR_SF_GET_INT(i1, 1);            \
        func(i1);                         \
        return 0;                         \
    }

#define MTR_SCRIPT_FUNC_V_UI1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                 \
    {                                      \
        unsigned int ui1;                  \
        MTR_SF_GET_UINT(ui1, 1);           \
        func(ui1);                         \
        return 0;                          \
    }

#define MTR_SCRIPT_FUNC_V_U8t3(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                  \
    {                                       \
        uint8_t u8_1;                       \
        uint8_t u8_2;                       \
        uint8_t u8_3;                       \
        MTR_SF_GET_UINT8(u8_1, 1);          \
        MTR_SF_GET_UINT8(u8_2, 2);          \
        MTR_SF_GET_UINT8(u8_3, 3);          \
        func(u8_1, u8_2, u8_3);             \
        return 0;                           \
    }

#define MTR_SCRIPT_FUNC_V_U8t4(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                  \
    {                                       \
        uint8_t u8_1;                       \
        uint8_t u8_2;                       \
        uint8_t u8_3;                       \
        uint8_t u8_4;                       \
        MTR_SF_GET_UINT8(u8_1, 1);          \
        MTR_SF_GET_UINT8(u8_2, 2);          \
        MTR_SF_GET_UINT8(u8_3, 3);          \
        MTR_SF_GET_UINT8(u8_4, 4);          \
        func(u8_1, u8_2, u8_3, u8_4);       \
        return 0;                           \
    }

#define MTR_SCRIPT_FUNC_V_U8t1S2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                    \
    {                                         \
        uint8_t u8_1;                         \
        const char *s1;                       \
        const char *s2;                       \
        MTR_SF_GET_UINT8(u8_1, 1);            \
        MTR_SF_GET_STRING(s1, 2);             \
        MTR_SF_GET_STRING(s2, 3);             \
        func(u8_1, s1, s2);                   \
        return 0;                             \
    }

#define MTR_SCRIPT_FUNC_V_U32t1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                   \
    {                                        \
        uint32_t u32_1;                      \
        MTR_SF_GET_UINT32(u32_1, 1);         \
        func(u32_1);                         \
        return 0;                            \
    }

#define MTR_SCRIPT_FUNC_V_U32t2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                   \
    {                                        \
        uint32_t u32_1;                      \
        uint32_t u32_2;                      \
        MTR_SF_GET_UINT32(u32_1, 1);         \
        MTR_SF_GET_UINT32(u32_2, 2);         \
        func(u32_1, u32_2);                  \
        return 0;                            \
    }

#define MTR_SCRIPT_FUNC_V_U32t1B1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        uint32_t u32_1;                        \
        bool b1;                               \
        MTR_SF_GET_UINT32(u32_1, 1);           \
        MTR_SF_GET_BOOL(b1, 2);                \
        func(u32_1, b1);                       \
        return 0;                              \
    }

#define MTR_SCRIPT_FUNC_V_U32t1I1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        uint32_t u32_1;                        \
        int i1;                                \
        MTR_SF_GET_UINT32(u32_1, 1);           \
        MTR_SF_GET_INT(i1, 2);                 \
        func(u32_1, i1);                       \
        return 0;                              \
    }

#define MTR_SCRIPT_FUNC_V_U32t1I4(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        uint32_t u32_1;                        \
        int i1;                                \
        int i2;                                \
        int i3;                                \
        int i4;                                \
        MTR_SF_GET_UINT32(u32_1, 1);           \
        MTR_SF_GET_INT(i1, 2);                 \
        MTR_SF_GET_INT(i2, 3);                 \
        MTR_SF_GET_INT(i3, 4);                 \
        MTR_SF_GET_INT(i4, 5);                 \
        func(u32_1, i1, i2, i3, i4);           \
        return 0;                              \
    }

#define MTR_SCRIPT_FUNC_V_U32t1I1F2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                       \
    {                                            \
        uint32_t u32_1;                          \
        int i1;                                  \
        float f1;                                \
        float f2;                                \
        MTR_SF_GET_UINT32(u32_1, 1);             \
        MTR_SF_GET_INT(i1, 2);                   \
        MTR_SF_GET_SINGLE(f1, 3);                \
        MTR_SF_GET_SINGLE(f2, 4);                \
        func(u32_1, i1, f1, f2);                 \
        return 0;                                \
    }

#define MTR_SCRIPT_FUNC_V_U32t1I1F3(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                       \
    {                                            \
        uint32_t u32_1;                          \
        int i1;                                  \
        float f1;                                \
        float f2;                                \
        float f3;                                \
        MTR_SF_GET_UINT32(u32_1, 1);             \
        MTR_SF_GET_INT(i1, 2);                   \
        MTR_SF_GET_SINGLE(f1, 3);                \
        MTR_SF_GET_SINGLE(f2, 4);                \
        MTR_SF_GET_SINGLE(f3, 5);                \
        func(u32_1, i1, f1, f2, f3);             \
        return 0;                                \
    }

#define MTR_SCRIPT_FUNC_V_U32t1I1F4(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                       \
    {                                            \
        uint32_t u32_1;                          \
        int i1;                                  \
        float f1;                                \
        float f2;                                \
        float f3;                                \
        float f4;                                \
        MTR_SF_GET_UINT32(u32_1, 1);             \
        MTR_SF_GET_INT(i1, 2);                   \
        MTR_SF_GET_SINGLE(f1, 3);                \
        MTR_SF_GET_SINGLE(f2, 4);                \
        MTR_SF_GET_SINGLE(f3, 5);                \
        MTR_SF_GET_SINGLE(f4, 6);                \
        func(u32_1, i1, f1, f2, f3, f4);         \
        return 0;                                \
    }

#define MTR_SCRIPT_FUNC_V_U32t1I1F2I1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                         \
    {                                              \
        uint32_t u32_1;                            \
        int i1;                                    \
        float f1;                                  \
        float f2;                                  \
        int i2;                                    \
        MTR_SF_GET_UINT32(u32_1, 1);               \
        MTR_SF_GET_INT(i1, 2);                     \
        MTR_SF_GET_SINGLE(f1, 3);                  \
        MTR_SF_GET_SINGLE(f2, 4);                  \
        MTR_SF_GET_INT(i2, 5);                     \
        func(u32_1, i1, f1, f2, i2);               \
        return 0;                                  \
    }

#define MTR_SCRIPT_FUNC_V_U32t1I1F5I1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                         \
    {                                              \
        uint32_t u32_1;                            \
        int i1;                                    \
        float f1;                                  \
        float f2;                                  \
        float f3;                                  \
        float f4;                                  \
        float f5;                                  \
        int i2;                                    \
        MTR_SF_GET_UINT32(u32_1, 1);               \
        MTR_SF_GET_INT(i1, 2);                     \
        MTR_SF_GET_SINGLE(f1, 3);                  \
        MTR_SF_GET_SINGLE(f2, 4);                  \
        MTR_SF_GET_SINGLE(f3, 5);                  \
        MTR_SF_GET_SINGLE(f4, 6);                  \
        MTR_SF_GET_SINGLE(f5, 7);                  \
        MTR_SF_GET_INT(i2, 8);                     \
        func(u32_1, i1, f1, f2, f3, f4, f5, i2);   \
        return 0;                                  \
    }

#define MTR_SCRIPT_FUNC_V_U32t1U8t1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                       \
    {                                            \
        uint32_t u32_1;                          \
        uint8_t u8_1;                            \
        MTR_SF_GET_UINT32(u32_1, 1);             \
        MTR_SF_GET_UINT8(u8_1, 2);               \
        func(u32_1, u8_1);                       \
        return 0;                                \
    }

#define MTR_SCRIPT_FUNC_V_U32t1U8t3(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                       \
    {                                            \
        uint32_t u32_1;                          \
        uint8_t u8_1;                            \
        uint8_t u8_2;                            \
        uint8_t u8_3;                            \
        MTR_SF_GET_UINT32(u32_1, 1);             \
        MTR_SF_GET_UINT8(u8_1, 2);               \
        MTR_SF_GET_UINT8(u8_2, 3);               \
        MTR_SF_GET_UINT8(u8_3, 4);               \
        func(u32_1, u8_1, u8_2, u8_3);           \
        return 0;                                \
    }

#define MTR_SCRIPT_FUNC_V_U32t1U8t4(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                       \
    {                                            \
        uint32_t u32_1;                          \
        uint8_t u8_1;                            \
        uint8_t u8_2;                            \
        uint8_t u8_3;                            \
        uint8_t u8_4;                            \
        MTR_SF_GET_UINT32(u32_1, 1);             \
        MTR_SF_GET_UINT8(u8_1, 2);               \
        MTR_SF_GET_UINT8(u8_2, 3);               \
        MTR_SF_GET_UINT8(u8_3, 4);               \
        MTR_SF_GET_UINT8(u8_4, 5);               \
        func(u32_1, u8_1, u8_2, u8_3, u8_4);     \
        return 0;                                \
    }

#define MTR_SCRIPT_FUNC_V_U32t1F1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        uint32_t u32_1;                        \
        float f1;                              \
        MTR_SF_GET_UINT32(u32_1, 1);           \
        MTR_SF_GET_SINGLE(f1, 2);              \
        func(u32_1, f1);                       \
        return 0;                              \
    }

#define MTR_SCRIPT_FUNC_V_U32t1F2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        uint32_t u32_1;                        \
        float f1;                              \
        float f2;                              \
        MTR_SF_GET_UINT32(u32_1, 1);           \
        MTR_SF_GET_SINGLE(f1, 2);              \
        MTR_SF_GET_SINGLE(f2, 3);              \
        func(u32_1, f1, f2);                   \
        return 0;                              \
    }

#define MTR_SCRIPT_FUNC_V_U32t1F6(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        uint32_t u32_1;                        \
        float f1;                              \
        float f2;                              \
        float f3;                              \
        float f4;                              \
        float f5;                              \
        float f6;                              \
        MTR_SF_GET_UINT32(u32_1, 1);           \
        MTR_SF_GET_SINGLE(f1, 2);              \
        MTR_SF_GET_SINGLE(f2, 3);              \
        MTR_SF_GET_SINGLE(f3, 4);              \
        MTR_SF_GET_SINGLE(f4, 5);              \
        MTR_SF_GET_SINGLE(f5, 6);              \
        MTR_SF_GET_SINGLE(f6, 7);              \
        func(u32_1, f1, f2, f3, f4, f5, f6);   \
        return 0;                              \
    }

#define MTR_SCRIPT_FUNC_V_U32t1F8(sfunc, func)       \
    MTR_SCRIPT_FUNC(sfunc)                           \
    {                                                \
        uint32_t u32_1;                              \
        float f1;                                    \
        float f2;                                    \
        float f3;                                    \
        float f4;                                    \
        float f5;                                    \
        float f6;                                    \
        float f7;                                    \
        float f8;                                    \
        MTR_SF_GET_UINT32(u32_1, 1);                 \
        MTR_SF_GET_SINGLE(f1, 2);                    \
        MTR_SF_GET_SINGLE(f2, 3);                    \
        MTR_SF_GET_SINGLE(f3, 4);                    \
        MTR_SF_GET_SINGLE(f4, 5);                    \
        MTR_SF_GET_SINGLE(f5, 6);                    \
        MTR_SF_GET_SINGLE(f6, 7);                    \
        MTR_SF_GET_SINGLE(f7, 8);                    \
        MTR_SF_GET_SINGLE(f8, 9);                    \
        func(u32_1, f1, f2, f3, f4, f5, f6, f7, f8); \
        return 0;                                    \
    }

#define MTR_SCRIPT_FUNC_V_U32t1F9(sfunc, func)           \
    MTR_SCRIPT_FUNC(sfunc)                               \
    {                                                    \
        uint32_t u32_1;                                  \
        float f1;                                        \
        float f2;                                        \
        float f3;                                        \
        float f4;                                        \
        float f5;                                        \
        float f6;                                        \
        float f7;                                        \
        float f8;                                        \
        float f9;                                        \
        MTR_SF_GET_UINT32(u32_1, 1);                     \
        MTR_SF_GET_SINGLE(f1, 2);                        \
        MTR_SF_GET_SINGLE(f2, 3);                        \
        MTR_SF_GET_SINGLE(f3, 4);                        \
        MTR_SF_GET_SINGLE(f4, 5);                        \
        MTR_SF_GET_SINGLE(f5, 6);                        \
        MTR_SF_GET_SINGLE(f6, 7);                        \
        MTR_SF_GET_SINGLE(f7, 8);                        \
        MTR_SF_GET_SINGLE(f8, 9);                        \
        MTR_SF_GET_SINGLE(f9, 10);                       \
        func(u32_1, f1, f2, f3, f4, f5, f6, f7, f8, f9); \
        return 0;                                        \
    }

#define MTR_SCRIPT_FUNC_V_U32t1F6I1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                       \
    {                                            \
        uint32_t u32_1;                          \
        float f1;                                \
        float f2;                                \
        float f3;                                \
        float f4;                                \
        float f5;                                \
        float f6;                                \
        int i1;                                  \
        MTR_SF_GET_UINT32(u32_1, 1);             \
        MTR_SF_GET_SINGLE(f1, 2);                \
        MTR_SF_GET_SINGLE(f2, 3);                \
        MTR_SF_GET_SINGLE(f3, 4);                \
        MTR_SF_GET_SINGLE(f4, 5);                \
        MTR_SF_GET_SINGLE(f5, 6);                \
        MTR_SF_GET_SINGLE(f6, 7);                \
        MTR_SF_GET_INT(i1, 8);                   \
        func(u32_1, f1, f2, f3, f4, f5, f6, i1); \
        return 0;                                \
    }

#define MTR_SCRIPT_FUNC_V_U32t1F11I1(sfunc, func)                      \
    MTR_SCRIPT_FUNC(sfunc)                                             \
    {                                                                  \
        uint32_t u32_1;                                                \
        float f1;                                                      \
        float f2;                                                      \
        float f3;                                                      \
        float f4;                                                      \
        float f5;                                                      \
        float f6;                                                      \
        float f7;                                                      \
        float f8;                                                      \
        float f9;                                                      \
        float f10;                                                     \
        float f11;                                                     \
        int i1;                                                        \
        MTR_SF_GET_UINT32(u32_1, 1);                                   \
        MTR_SF_GET_SINGLE(f1, 2);                                      \
        MTR_SF_GET_SINGLE(f2, 3);                                      \
        MTR_SF_GET_SINGLE(f3, 4);                                      \
        MTR_SF_GET_SINGLE(f4, 5);                                      \
        MTR_SF_GET_SINGLE(f5, 6);                                      \
        MTR_SF_GET_SINGLE(f6, 7);                                      \
        MTR_SF_GET_SINGLE(f7, 8);                                      \
        MTR_SF_GET_SINGLE(f8, 9);                                      \
        MTR_SF_GET_SINGLE(f9, 10);                                     \
        MTR_SF_GET_SINGLE(f10, 11);                                    \
        MTR_SF_GET_SINGLE(f11, 12);                                    \
        MTR_SF_GET_INT(i1, 13);                                        \
        func(u32_1, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, i1); \
        return 0;                                                      \
    }

#define MTR_SCRIPT_FUNC_V_U32t1S1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        uint32_t u32_1;                        \
        const char *s1;                        \
        MTR_SF_GET_UINT32(u32_1, 1);           \
        MTR_SF_GET_STRING(s1, 2);              \
        func(u32_1, s1);                       \
        return 0;                              \
    }

#define MTR_SCRIPT_FUNC_V_F1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        float f1;                         \
        MTR_SF_GET_SINGLE(f1, 1);         \
        func(f1);                         \
        return 0;                         \
    }

#define MTR_SCRIPT_FUNC_V_F2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        float f1;                         \
        float f2;                         \
        MTR_SF_GET_SINGLE(f1, 1);         \
        MTR_SF_GET_SINGLE(f2, 2);         \
        func(f1, f2);                     \
        return 0;                         \
    }

#define MTR_SCRIPT_FUNC_V_F1I1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                  \
    {                                       \
        float f1;                           \
        int i1;                             \
        MTR_SF_GET_SINGLE(f1, 1);           \
        MTR_SF_GET_INT(i1, 2);              \
        func(f1, i1);                       \
        return 0;                           \
    }

#define MTR_SCRIPT_FUNC_V_F1I2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                  \
    {                                       \
        float f1;                           \
        int i1;                             \
        int i2;                             \
        MTR_SF_GET_SINGLE(f1, 1);           \
        MTR_SF_GET_INT(i1, 2);              \
        MTR_SF_GET_INT(i2, 3);              \
        func(f1, i1, i2);                   \
        return 0;                           \
    }

#define MTR_SCRIPT_FUNC_V_F2U8t3(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                    \
    {                                         \
        float f1;                             \
        float f2;                             \
        uint8_t u8_1;                         \
        uint8_t u8_2;                         \
        uint8_t u8_3;                         \
        MTR_SF_GET_SINGLE(f1, 1);             \
        MTR_SF_GET_SINGLE(f2, 2);             \
        MTR_SF_GET_UINT8(u8_1, 3);            \
        MTR_SF_GET_UINT8(u8_2, 4);            \
        MTR_SF_GET_UINT8(u8_3, 5);            \
        func(f1, f2, u8_1, u8_2, u8_3);       \
        return 0;                             \
    }

#define MTR_SCRIPT_FUNC_V_F2U8t4(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                    \
    {                                         \
        float f1;                             \
        float f2;                             \
        uint8_t u8_1;                         \
        uint8_t u8_2;                         \
        uint8_t u8_3;                         \
        uint8_t u8_4;                         \
        MTR_SF_GET_SINGLE(f1, 1);             \
        MTR_SF_GET_SINGLE(f2, 2);             \
        MTR_SF_GET_UINT8(u8_1, 3);            \
        MTR_SF_GET_UINT8(u8_2, 4);            \
        MTR_SF_GET_UINT8(u8_3, 5);            \
        MTR_SF_GET_UINT8(u8_4, 6);            \
        func(f1, f2, u8_1, u8_2, u8_3, u8_4); \
        return 0;                             \
    }

#define MTR_SCRIPT_FUNC_V_F3U8t3(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                    \
    {                                         \
        float f1;                             \
        float f2;                             \
        float f3;                             \
        uint8_t u8_1;                         \
        uint8_t u8_2;                         \
        uint8_t u8_3;                         \
        MTR_SF_GET_SINGLE(f1, 1);             \
        MTR_SF_GET_SINGLE(f2, 2);             \
        MTR_SF_GET_SINGLE(f3, 3);             \
        MTR_SF_GET_UINT8(u8_1, 4);            \
        MTR_SF_GET_UINT8(u8_2, 5);            \
        MTR_SF_GET_UINT8(u8_3, 6);            \
        func(f1, f2, f3, u8_1, u8_2, u8_3);   \
        return 0;                             \
    }

#define MTR_SCRIPT_FUNC_V_F3U8t4(sfunc, func)     \
    MTR_SCRIPT_FUNC(sfunc)                        \
    {                                             \
        float f1;                                 \
        float f2;                                 \
        float f3;                                 \
        uint8_t u8_1;                             \
        uint8_t u8_2;                             \
        uint8_t u8_3;                             \
        uint8_t u8_4;                             \
        MTR_SF_GET_SINGLE(f1, 1);                 \
        MTR_SF_GET_SINGLE(f2, 2);                 \
        MTR_SF_GET_SINGLE(f3, 3);                 \
        MTR_SF_GET_UINT8(u8_1, 4);                \
        MTR_SF_GET_UINT8(u8_2, 5);                \
        MTR_SF_GET_UINT8(u8_3, 6);                \
        MTR_SF_GET_UINT8(u8_4, 7);                \
        func(f1, f2, f3, u8_1, u8_2, u8_3, u8_4); \
        return 0;                                 \
    }

#define MTR_SCRIPT_FUNC_V_F4U8t3(sfunc, func)   \
    MTR_SCRIPT_FUNC(sfunc)                      \
    {                                           \
        float f1;                               \
        float f2;                               \
        float f3;                               \
        float f4;                               \
        uint8_t u8_1;                           \
        uint8_t u8_2;                           \
        uint8_t u8_3;                           \
        MTR_SF_GET_SINGLE(f1, 1);               \
        MTR_SF_GET_SINGLE(f2, 2);               \
        MTR_SF_GET_SINGLE(f3, 3);               \
        MTR_SF_GET_SINGLE(f4, 4);               \
        MTR_SF_GET_UINT8(u8_1, 5);              \
        MTR_SF_GET_UINT8(u8_2, 6);              \
        MTR_SF_GET_UINT8(u8_3, 7);              \
        func(f1, f2, f3, f4, u8_1, u8_2, u8_3); \
        return 0;                               \
    }

#define MTR_SCRIPT_FUNC_V_F4U8t4(sfunc, func)         \
    MTR_SCRIPT_FUNC(sfunc)                            \
    {                                                 \
        float f1;                                     \
        float f2;                                     \
        float f3;                                     \
        float f4;                                     \
        uint8_t u8_1;                                 \
        uint8_t u8_2;                                 \
        uint8_t u8_3;                                 \
        uint8_t u8_4;                                 \
        MTR_SF_GET_SINGLE(f1, 1);                     \
        MTR_SF_GET_SINGLE(f2, 2);                     \
        MTR_SF_GET_SINGLE(f3, 3);                     \
        MTR_SF_GET_SINGLE(f4, 4);                     \
        MTR_SF_GET_UINT8(u8_1, 5);                    \
        MTR_SF_GET_UINT8(u8_2, 6);                    \
        MTR_SF_GET_UINT8(u8_3, 7);                    \
        MTR_SF_GET_UINT8(u8_4, 8);                    \
        func(f1, f2, f3, f4, u8_1, u8_2, u8_3, u8_4); \
        return 0;                                     \
    }

#define MTR_SCRIPT_FUNC_V_F5U8t3(sfunc, func)       \
    MTR_SCRIPT_FUNC(sfunc)                          \
    {                                               \
        float f1;                                   \
        float f2;                                   \
        float f3;                                   \
        float f4;                                   \
        float f5;                                   \
        uint8_t u8_1;                               \
        uint8_t u8_2;                               \
        uint8_t u8_3;                               \
        MTR_SF_GET_SINGLE(f1, 1);                   \
        MTR_SF_GET_SINGLE(f2, 2);                   \
        MTR_SF_GET_SINGLE(f3, 3);                   \
        MTR_SF_GET_SINGLE(f4, 4);                   \
        MTR_SF_GET_SINGLE(f5, 5);                   \
        MTR_SF_GET_UINT8(u8_1, 6);                  \
        MTR_SF_GET_UINT8(u8_2, 7);                  \
        MTR_SF_GET_UINT8(u8_3, 8);                  \
        func(f1, f2, f3, f4, f5, u8_1, u8_2, u8_3); \
        return 0;                                   \
    }

#define MTR_SCRIPT_FUNC_V_F5U8t4(sfunc, func)             \
    MTR_SCRIPT_FUNC(sfunc)                                \
    {                                                     \
        float f1;                                         \
        float f2;                                         \
        float f3;                                         \
        float f4;                                         \
        float f5;                                         \
        uint8_t u8_1;                                     \
        uint8_t u8_2;                                     \
        uint8_t u8_3;                                     \
        uint8_t u8_4;                                     \
        MTR_SF_GET_SINGLE(f1, 1);                         \
        MTR_SF_GET_SINGLE(f2, 2);                         \
        MTR_SF_GET_SINGLE(f3, 3);                         \
        MTR_SF_GET_SINGLE(f4, 4);                         \
        MTR_SF_GET_SINGLE(f5, 5);                         \
        MTR_SF_GET_UINT8(u8_1, 6);                        \
        MTR_SF_GET_UINT8(u8_2, 7);                        \
        MTR_SF_GET_UINT8(u8_3, 8);                        \
        MTR_SF_GET_UINT8(u8_4, 9);                        \
        func(f1, f2, f3, f4, f5, u8_1, u8_2, u8_3, u8_4); \
        return 0;                                         \
    }

#define MTR_SCRIPT_FUNC_V_F6U8t3(sfunc, func)           \
    MTR_SCRIPT_FUNC(sfunc)                              \
    {                                                   \
        float f1;                                       \
        float f2;                                       \
        float f3;                                       \
        float f4;                                       \
        float f5;                                       \
        float f6;                                       \
        uint8_t u8_1;                                   \
        uint8_t u8_2;                                   \
        uint8_t u8_3;                                   \
        MTR_SF_GET_SINGLE(f1, 1);                       \
        MTR_SF_GET_SINGLE(f2, 2);                       \
        MTR_SF_GET_SINGLE(f3, 3);                       \
        MTR_SF_GET_SINGLE(f4, 4);                       \
        MTR_SF_GET_SINGLE(f5, 5);                       \
        MTR_SF_GET_SINGLE(f6, 6);                       \
        MTR_SF_GET_UINT8(u8_1, 7);                      \
        MTR_SF_GET_UINT8(u8_2, 8);                      \
        MTR_SF_GET_UINT8(u8_3, 9);                      \
        func(f1, f2, f3, f4, f5, f6, u8_1, u8_2, u8_3); \
        return 0;                                       \
    }

#define MTR_SCRIPT_FUNC_V_F6U8t4(sfunc, func)                 \
    MTR_SCRIPT_FUNC(sfunc)                                    \
    {                                                         \
        float f1;                                             \
        float f2;                                             \
        float f3;                                             \
        float f4;                                             \
        float f5;                                             \
        float f6;                                             \
        uint8_t u8_1;                                         \
        uint8_t u8_2;                                         \
        uint8_t u8_3;                                         \
        uint8_t u8_4;                                         \
        MTR_SF_GET_SINGLE(f1, 1);                             \
        MTR_SF_GET_SINGLE(f2, 2);                             \
        MTR_SF_GET_SINGLE(f3, 3);                             \
        MTR_SF_GET_SINGLE(f4, 4);                             \
        MTR_SF_GET_SINGLE(f5, 5);                             \
        MTR_SF_GET_SINGLE(f6, 6);                             \
        MTR_SF_GET_UINT8(u8_1, 7);                            \
        MTR_SF_GET_UINT8(u8_2, 8);                            \
        MTR_SF_GET_UINT8(u8_3, 9);                            \
        MTR_SF_GET_UINT8(u8_4, 10);                           \
        func(f1, f2, f3, f4, f5, f6, u8_1, u8_2, u8_3, u8_4); \
        return 0;                                             \
    }

#define MTR_SCRIPT_FUNC_V_F2U32t1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        float f1;                              \
        float f2;                              \
        uint32_t u32_1;                        \
        MTR_SF_GET_SINGLE(f1, 1);              \
        MTR_SF_GET_SINGLE(f2, 2);              \
        MTR_SF_GET_UINT32(u32_1, 3);           \
        func(f1, f2, u32_1);                   \
        return 0;                              \
    }

#define MTR_SCRIPT_FUNC_V_F3U32t1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        float f1;                              \
        float f2;                              \
        float f3;                              \
        uint32_t u32_1;                        \
        MTR_SF_GET_SINGLE(f1, 1);              \
        MTR_SF_GET_SINGLE(f2, 2);              \
        MTR_SF_GET_SINGLE(f3, 3);              \
        MTR_SF_GET_UINT32(u32_1, 4);           \
        func(f1, f2, f3, u32_1);               \
        return 0;                              \
    }

#define MTR_SCRIPT_FUNC_V_F4U32t1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        float f1;                              \
        float f2;                              \
        float f3;                              \
        float f4;                              \
        uint32_t u32_1;                        \
        MTR_SF_GET_SINGLE(f1, 1);              \
        MTR_SF_GET_SINGLE(f2, 2);              \
        MTR_SF_GET_SINGLE(f3, 3);              \
        MTR_SF_GET_SINGLE(f4, 4);              \
        MTR_SF_GET_UINT32(u32_1, 5);           \
        func(f1, f2, f3, f4, u32_1);           \
        return 0;                              \
    }

#define MTR_SCRIPT_FUNC_V_F5U32t1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        float f1;                              \
        float f2;                              \
        float f3;                              \
        float f4;                              \
        float f5;                              \
        uint32_t u32_1;                        \
        MTR_SF_GET_SINGLE(f1, 1);              \
        MTR_SF_GET_SINGLE(f2, 2);              \
        MTR_SF_GET_SINGLE(f3, 3);              \
        MTR_SF_GET_SINGLE(f4, 4);              \
        MTR_SF_GET_SINGLE(f5, 5);              \
        MTR_SF_GET_UINT32(u32_1, 6);           \
        func(f1, f2, f3, f4, f5, u32_1);       \
        return 0;                              \
    }

#define MTR_SCRIPT_FUNC_V_F6U32t1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        float f1;                              \
        float f2;                              \
        float f3;                              \
        float f4;                              \
        float f5;                              \
        float f6;                              \
        uint32_t u32_1;                        \
        MTR_SF_GET_SINGLE(f1, 1);              \
        MTR_SF_GET_SINGLE(f2, 2);              \
        MTR_SF_GET_SINGLE(f3, 3);              \
        MTR_SF_GET_SINGLE(f4, 4);              \
        MTR_SF_GET_SINGLE(f5, 5);              \
        MTR_SF_GET_SINGLE(f6, 6);              \
        MTR_SF_GET_UINT32(u32_1, 7);           \
        func(f1, f2, f3, f4, f5, f6, u32_1);   \
        return 0;                              \
    }

#define MTR_SCRIPT_FUNC_V_S1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        const char *s1;                   \
        MTR_SF_GET_STRING(s1, 1);         \
        func(s1);                         \
        return 0;                         \
    }

#define MTR_SCRIPT_FUNC_V_S2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        const char *s1;                   \
        const char *s2;                   \
        MTR_SF_GET_STRING(s1, 1);         \
        MTR_SF_GET_STRING(s2, 2);         \
        func(s1, s2);                     \
        return 0;                         \
    }

#define MTR_SCRIPT_FUNC_V_S1I1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                  \
    {                                       \
        const char *s1;                     \
        int i1;                             \
        MTR_SF_GET_STRING(s1, 1);           \
        MTR_SF_GET_INT(i1, 2);              \
        func(s1, i1);                       \
        return 0;                           \
    }

#define MTR_SCRIPT_FUNC_V_S2I1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                  \
    {                                       \
        const char *s1;                     \
        const char *s2;                     \
        int i1;                             \
        MTR_SF_GET_STRING(s1, 1);           \
        MTR_SF_GET_STRING(s2, 2);           \
        MTR_SF_GET_INT(i1, 3);              \
        func(s1, s2, i1);                   \
        return 0;                           \
    }

#define MTR_SCRIPT_FUNC_V_S1I1U8t3(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                      \
    {                                           \
        const char *s1;                         \
        int i1;                                 \
        uint8_t u8_1;                           \
        uint8_t u8_2;                           \
        uint8_t u8_3;                           \
        MTR_SF_GET_STRING(s1, 1);               \
        MTR_SF_GET_INT(i1, 2);                  \
        MTR_SF_GET_UINT8(u8_1, 3);              \
        MTR_SF_GET_UINT8(u8_2, 4);              \
        MTR_SF_GET_UINT8(u8_3, 5);              \
        func(s1, i1, u8_1, u8_2, u8_3);         \
        return 0;                               \
    }

#define MTR_SCRIPT_FUNC_V_S1I1U8t4(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                      \
    {                                           \
        const char *s1;                         \
        int i1;                                 \
        uint8_t u8_1;                           \
        uint8_t u8_2;                           \
        uint8_t u8_3;                           \
        uint8_t u8_4;                           \
        MTR_SF_GET_STRING(s1, 1);               \
        MTR_SF_GET_INT(i1, 2);                  \
        MTR_SF_GET_UINT8(u8_1, 3);              \
        MTR_SF_GET_UINT8(u8_2, 4);              \
        MTR_SF_GET_UINT8(u8_3, 5);              \
        MTR_SF_GET_UINT8(u8_4, 6);              \
        func(s1, i1, u8_1, u8_2, u8_3, u8_4);   \
        return 0;                               \
    }

#define MTR_SCRIPT_FUNC_V_S1I1U32t1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                       \
    {                                            \
        const char *s1;                          \
        int i1;                                  \
        uint32_t u32_1;                          \
        MTR_SF_GET_STRING(s1, 1);                \
        MTR_SF_GET_INT(i1, 2);                   \
        MTR_SF_GET_UINT32(u32_1, 3);             \
        func(s1, i1, u32_1);                     \
        return 0;                                \
    }

#define MTR_SCRIPT_FUNC_V_S1U8t2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                    \
    {                                         \
        const char *s1;                       \
        uint8_t u8_1;                         \
        uint8_t u8_2;                         \
        MTR_SF_GET_STRING(s1, 1);             \
        MTR_SF_GET_UINT8(u8_1, 2);            \
        MTR_SF_GET_UINT8(u8_2, 3);            \
        func(s1, u8_1, u8_2);                 \
        return 0;                             \
    }

#define MTR_SCRIPT_FUNC_V_S1U8t3(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                    \
    {                                         \
        const char *s1;                       \
        uint8_t u8_1;                         \
        uint8_t u8_2;                         \
        uint8_t u8_3;                         \
        MTR_SF_GET_STRING(s1, 1);             \
        MTR_SF_GET_UINT8(u8_1, 2);            \
        MTR_SF_GET_UINT8(u8_2, 3);            \
        MTR_SF_GET_UINT8(u8_3, 4);            \
        func(s1, u8_1, u8_2, u8_3);           \
        return 0;                             \
    }

#define MTR_SCRIPT_FUNC_V_S1U8t4(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                    \
    {                                         \
        const char *s1;                       \
        uint8_t u8_1;                         \
        uint8_t u8_2;                         \
        uint8_t u8_3;                         \
        uint8_t u8_4;                         \
        MTR_SF_GET_STRING(s1, 1);             \
        MTR_SF_GET_UINT8(u8_1, 2);            \
        MTR_SF_GET_UINT8(u8_2, 3);            \
        MTR_SF_GET_UINT8(u8_3, 4);            \
        MTR_SF_GET_UINT8(u8_4, 5);            \
        func(s1, u8_1, u8_2, u8_3, u8_4);     \
        return 0;                             \
    }

#define MTR_SCRIPT_FUNC_V_S1U8t2I1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                      \
    {                                           \
        const char *s1;                         \
        uint8_t u8_1;                           \
        uint8_t u8_2;                           \
        int i1;                                 \
        MTR_SF_GET_STRING(s1, 1);               \
        MTR_SF_GET_UINT8(u8_1, 2);              \
        MTR_SF_GET_UINT8(u8_2, 3);              \
        MTR_SF_GET_INT(i1, 4);                  \
        func(s1, u8_1, u8_2, i1);               \
        return 0;                               \
    }

#define MTR_SCRIPT_FUNC_V_S1U8t2D1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                      \
    {                                           \
        const char *s1;                         \
        uint8_t u8_1;                           \
        uint8_t u8_2;                           \
        double d1;                              \
        MTR_SF_GET_STRING(s1, 1);               \
        MTR_SF_GET_UINT8(u8_1, 2);              \
        MTR_SF_GET_UINT8(u8_2, 3);              \
        MTR_SF_GET_DOUBLE(d1, 4);               \
        func(s1, u8_1, u8_2, d1);               \
        return 0;                               \
    }

#define MTR_SCRIPT_FUNC_V_S1U8t2S1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                      \
    {                                           \
        const char *s1;                         \
        uint8_t u8_1;                           \
        uint8_t u8_2;                           \
        const char *s2;                         \
        MTR_SF_GET_STRING(s1, 1);               \
        MTR_SF_GET_UINT8(u8_1, 2);              \
        MTR_SF_GET_UINT8(u8_2, 3);              \
        MTR_SF_GET_STRING(s2, 4);               \
        func(s1, u8_1, u8_2, s2);               \
        return 0;                               \
    }

#define MTR_SCRIPT_FUNC_V_S1U32t1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        const char *s1;                        \
        uint32_t u32_1;                        \
        MTR_SF_GET_STRING(s1, 1);              \
        MTR_SF_GET_UINT32(u32_1, 2);           \
        func(s1, u32_1);                       \
        return 0;                              \
    }

#define MTR_SCRIPT_FUNC_V_S1D1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                  \
    {                                       \
        const char *s1;                     \
        double d1;                          \
        MTR_SF_GET_STRING(s1, 1);           \
        MTR_SF_GET_DOUBLE(d1, 2);           \
        func(s1, d1);                       \
        return 0;                           \
    }

#define MTR_SCRIPT_FUNC_B_V(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)               \
    {                                    \
        bool result;                     \
        result = func();                 \
        MTR_SF_PUSH_BOOL(result);        \
        return 1;                        \
    }

#define MTR_SCRIPT_FUNC_B_I1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        int i1;                           \
        bool result;                      \
        MTR_SF_GET_INT(i1, 1);            \
        result = func(i1);                \
        MTR_SF_PUSH_BOOL(result);         \
        return 1;                         \
    }

#define MTR_SCRIPT_FUNC_B_I2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        int i1;                           \
        int i2;                           \
        bool result;                      \
        MTR_SF_GET_INT(i1, 1);            \
        MTR_SF_GET_INT(i2, 2);            \
        result = func(i1, i2);            \
        MTR_SF_PUSH_BOOL(result);         \
        return 1;                         \
    }

#define MTR_SCRIPT_FUNC_B_I2B1S1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                    \
    {                                         \
        int i1;                               \
        int i2;                               \
        bool b1;                              \
        const char *s1;                       \
        bool result;                          \
        MTR_SF_GET_INT(i1, 1);                \
        MTR_SF_GET_INT(i2, 2);                \
        MTR_SF_GET_BOOL(b1, 3);               \
        MTR_SF_GET_STRING(s1, 4);             \
        result = func(i1, i2, b1, s1);        \
        MTR_SF_PUSH_BOOL(result);             \
        return 1;                             \
    }

#define MTR_SCRIPT_FUNC_B_I1S1I1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                    \
    {                                         \
        int i1;                               \
        const char *s1;                       \
        int i2;                               \
        bool result;                          \
        MTR_SF_GET_INT(i1, 1);                \
        MTR_SF_GET_STRING(s1, 2);             \
        MTR_SF_GET_INT(i2, 3);                \
        result = func(i1, s1, i2);            \
        MTR_SF_PUSH_BOOL(result);             \
        return 1;                             \
    }

#define MTR_SCRIPT_FUNC_B_I1S1I2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                    \
    {                                         \
        int i1;                               \
        const char *s1;                       \
        int i2;                               \
        int i3;                               \
        bool result;                          \
        MTR_SF_GET_INT(i1, 1);                \
        MTR_SF_GET_STRING(s1, 2);             \
        MTR_SF_GET_INT(i2, 3);                \
        MTR_SF_GET_INT(i3, 4);                \
        result = func(i1, s1, i2, i3);        \
        MTR_SF_PUSH_BOOL(result);             \
        return 1;                             \
    }

#define MTR_SCRIPT_FUNC_B_U8t3(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                  \
    {                                       \
        uint8_t u8_1;                       \
        uint8_t u8_2;                       \
        uint8_t u8_3;                       \
        bool result;                        \
        MTR_SF_GET_UINT8(u8_1, 1);          \
        MTR_SF_GET_UINT8(u8_2, 2);          \
        MTR_SF_GET_UINT8(u8_3, 3);          \
        result = func(u8_1, u8_2, u8_3);    \
        MTR_SF_PUSH_BOOL(result);           \
        return 1;                           \
    }

#define MTR_SCRIPT_FUNC_B_U8t4(sfunc, func)    \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        uint8_t u8_1;                          \
        uint8_t u8_2;                          \
        uint8_t u8_3;                          \
        uint8_t u8_4;                          \
        bool result;                           \
        MTR_SF_GET_UINT8(u8_1, 1);             \
        MTR_SF_GET_UINT8(u8_2, 2);             \
        MTR_SF_GET_UINT8(u8_3, 3);             \
        MTR_SF_GET_UINT8(u8_4, 4);             \
        result = func(u8_1, u8_2, u8_3, u8_4); \
        MTR_SF_PUSH_BOOL(result);              \
        return 1;                              \
    }

#define MTR_SCRIPT_FUNC_B_U32t1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                   \
    {                                        \
        uint32_t u32_1;                      \
        bool result;                         \
        MTR_SF_GET_UINT32(u32_1, 1);         \
        result = func(u32_1);                \
        MTR_SF_PUSH_BOOL(result);            \
        return 1;                            \
    }

#define MTR_SCRIPT_FUNC_B_U32t2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                   \
    {                                        \
        uint32_t u32_1;                      \
        uint32_t u32_2;                      \
        bool result;                         \
        MTR_SF_GET_UINT32(u32_1, 1);         \
        MTR_SF_GET_UINT32(u32_2, 2);         \
        result = func(u32_1, u32_2);         \
        MTR_SF_PUSH_BOOL(result);            \
        return 1;                            \
    }

#define MTR_SCRIPT_FUNC_B_U32t5(sfunc, func)              \
    MTR_SCRIPT_FUNC(sfunc)                                \
    {                                                     \
        uint32_t u32_1;                                   \
        uint32_t u32_2;                                   \
        uint32_t u32_3;                                   \
        uint32_t u32_4;                                   \
        uint32_t u32_5;                                   \
        bool result;                                      \
        MTR_SF_GET_UINT32(u32_1, 1);                      \
        MTR_SF_GET_UINT32(u32_2, 2);                      \
        MTR_SF_GET_UINT32(u32_3, 3);                      \
        MTR_SF_GET_UINT32(u32_4, 4);                      \
        MTR_SF_GET_UINT32(u32_5, 5);                      \
        result = func(u32_1, u32_2, u32_3, u32_4, u32_5); \
        MTR_SF_PUSH_BOOL(result);                         \
        return 1;                                         \
    }

#define MTR_SCRIPT_FUNC_B_U32t7(sfunc, func)                            \
    MTR_SCRIPT_FUNC(sfunc)                                              \
    {                                                                   \
        uint32_t u32_1;                                                 \
        uint32_t u32_2;                                                 \
        uint32_t u32_3;                                                 \
        uint32_t u32_4;                                                 \
        uint32_t u32_5;                                                 \
        uint32_t u32_6;                                                 \
        uint32_t u32_7;                                                 \
        bool result;                                                    \
        MTR_SF_GET_UINT32(u32_1, 1);                                    \
        MTR_SF_GET_UINT32(u32_2, 2);                                    \
        MTR_SF_GET_UINT32(u32_3, 3);                                    \
        MTR_SF_GET_UINT32(u32_4, 4);                                    \
        MTR_SF_GET_UINT32(u32_5, 5);                                    \
        MTR_SF_GET_UINT32(u32_6, 6);                                    \
        MTR_SF_GET_UINT32(u32_7, 7);                                    \
        result = func(u32_1, u32_2, u32_3, u32_4, u32_5, u32_6, u32_7); \
        MTR_SF_PUSH_BOOL(result);                                       \
        return 1;                                                       \
    }

#define MTR_SCRIPT_FUNC_B_U32t4I3(sfunc, func)                 \
    MTR_SCRIPT_FUNC(sfunc)                                     \
    {                                                          \
        uint32_t u32_1;                                        \
        uint32_t u32_2;                                        \
        uint32_t u32_3;                                        \
        uint32_t u32_4;                                        \
        int i1;                                                \
        int i2;                                                \
        int i3;                                                \
        bool result;                                           \
        MTR_SF_GET_UINT32(u32_1, 1);                           \
        MTR_SF_GET_UINT32(u32_2, 2);                           \
        MTR_SF_GET_UINT32(u32_3, 3);                           \
        MTR_SF_GET_UINT32(u32_4, 4);                           \
        MTR_SF_GET_INT(i1, 5);                                 \
        MTR_SF_GET_INT(i2, 6);                                 \
        MTR_SF_GET_INT(i3, 7);                                 \
        result = func(u32_1, u32_2, u32_3, u32_4, i1, i2, i3); \
        MTR_SF_PUSH_BOOL(result);                              \
        return 1;                                              \
    }

#define MTR_SCRIPT_FUNC_B_U32t2UI1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                      \
    {                                           \
        uint32_t u32_1;                         \
        uint32_t u32_2;                         \
        unsigned int ui1;                       \
        bool result;                            \
        MTR_SF_GET_UINT32(u32_1, 1);            \
        MTR_SF_GET_UINT32(u32_2, 2);            \
        MTR_SF_GET_UINT32(ui1, 3);              \
        result = func(u32_1, u32_2, ui1);       \
        MTR_SF_PUSH_BOOL(result);               \
        return 1;                               \
    }

#define MTR_SCRIPT_FUNC_B_U32t2U8t3S1(sfunc, func)         \
    MTR_SCRIPT_FUNC(sfunc)                                 \
    {                                                      \
        uint32_t u32_1;                                    \
        uint32_t u32_2;                                    \
        uint8_t u8_1;                                      \
        uint8_t u8_2;                                      \
        uint8_t u8_3;                                      \
        const char *s1;                                    \
        bool result;                                       \
        MTR_SF_GET_UINT32(u32_1, 1);                       \
        MTR_SF_GET_UINT32(u32_2, 2);                       \
        MTR_SF_GET_UINT8(u8_1, 3);                         \
        MTR_SF_GET_UINT8(u8_2, 4);                         \
        MTR_SF_GET_UINT8(u8_3, 5);                         \
        MTR_SF_GET_STRING(s1, 6);                          \
        result = func(u32_1, u32_2, u8_1, u8_2, u8_3, s1); \
        MTR_SF_PUSH_BOOL(result);                          \
        return 1;                                          \
    }

#define MTR_SCRIPT_FUNC_B_U32t1F2S1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                       \
    {                                            \
        uint32_t u32_1;                          \
        float f1;                                \
        float f2;                                \
        const char *s1;                          \
        bool result;                             \
        MTR_SF_GET_UINT32(u32_1, 1);             \
        MTR_SF_GET_SINGLE(f1, 2);                \
        MTR_SF_GET_SINGLE(f2, 3);                \
        MTR_SF_GET_STRING(s1, 4);                \
        result = func(u32_1, f1, f2, s1);        \
        MTR_SF_PUSH_BOOL(result);                \
        return 1;                                \
    }

#define MTR_SCRIPT_FUNC_B_U32t1S1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        uint32_t u32_1;                        \
        const char *s1;                        \
        bool result;                           \
        MTR_SF_GET_UINT32(u32_1, 1);           \
        MTR_SF_GET_STRING(s1, 2);              \
        result = func(u32_1, s1);              \
        MTR_SF_PUSH_BOOL(result);              \
        return 1;                              \
    }

#define MTR_SCRIPT_FUNC_B_U32t1S1B2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                       \
    {                                            \
        uint32_t u32_1;                          \
        const char *s1;                          \
        bool b1;                                 \
        bool b2;                                 \
        bool result;                             \
        MTR_SF_GET_UINT32(u32_1, 1);             \
        MTR_SF_GET_STRING(s1, 2);                \
        MTR_SF_GET_BOOL(b1, 3);                  \
        MTR_SF_GET_BOOL(b2, 4);                  \
        result = func(u32_1, s1, b1, b2);        \
        MTR_SF_PUSH_BOOL(result);                \
        return 1;                                \
    }

#define MTR_SCRIPT_FUNC_B_U32t1S1I1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                       \
    {                                            \
        uint32_t u32_1;                          \
        const char *s1;                          \
        int i1;                                  \
        bool result;                             \
        MTR_SF_GET_UINT32(u32_1, 1);             \
        MTR_SF_GET_STRING(s1, 2);                \
        MTR_SF_GET_INT(i1, 3);                   \
        result = func(u32_1, s1, i1);            \
        MTR_SF_PUSH_BOOL(result);                \
        return 1;                                \
    }

#define MTR_SCRIPT_FUNC_B_U32t1S1I2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                       \
    {                                            \
        uint32_t u32_1;                          \
        const char *s1;                          \
        int i1;                                  \
        int i2;                                  \
        bool result;                             \
        MTR_SF_GET_UINT32(u32_1, 1);             \
        MTR_SF_GET_STRING(s1, 2);                \
        MTR_SF_GET_INT(i1, 3);                   \
        MTR_SF_GET_INT(i2, 4);                   \
        result = func(u32_1, s1, i1, i2);        \
        MTR_SF_PUSH_BOOL(result);                \
        return 1;                                \
    }

#define MTR_SCRIPT_FUNC_B_U32t1S1I2B1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                         \
    {                                              \
        uint32_t u32_1;                            \
        const char *s1;                            \
        int i1;                                    \
        int i2;                                    \
        bool b1;                                   \
        bool result;                               \
        MTR_SF_GET_UINT32(u32_1, 1);               \
        MTR_SF_GET_STRING(s1, 2);                  \
        MTR_SF_GET_INT(i1, 3);                     \
        MTR_SF_GET_INT(i2, 4);                     \
        MTR_SF_GET_BOOL(b1, 5);                    \
        result = func(u32_1, s1, i1, i2, b1);      \
        MTR_SF_PUSH_BOOL(result);                  \
        return 1;                                  \
    }

#define MTR_SCRIPT_FUNC_B_S1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        const char *s1;                   \
        bool result;                      \
        MTR_SF_GET_STRING(s1, 1);         \
        result = func(s1);                \
        MTR_SF_PUSH_BOOL(result);         \
        return 1;                         \
    }

#define MTR_SCRIPT_FUNC_B_S2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        const char *s1;                   \
        const char *s2;                   \
        bool result;                      \
        MTR_SF_GET_STRING(s1, 1);         \
        MTR_SF_GET_STRING(s2, 2);         \
        result = func(s1, s2);            \
        MTR_SF_PUSH_BOOL(result);         \
        return 1;                         \
    }

#define MTR_SCRIPT_FUNC_B_S3(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        const char *s1;                   \
        const char *s2;                   \
        const char *s3;                   \
        bool result;                      \
        MTR_SF_GET_STRING(s1, 1);         \
        MTR_SF_GET_STRING(s2, 2);         \
        MTR_SF_GET_STRING(s3, 3);         \
        result = func(s1, s2, s3);        \
        MTR_SF_PUSH_BOOL(result);         \
        return 1;                         \
    }

#define MTR_SCRIPT_FUNC_B_S4(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        const char *s1;                   \
        const char *s2;                   \
        const char *s3;                   \
        const char *s4;                   \
        bool result;                      \
        MTR_SF_GET_STRING(s1, 1);         \
        MTR_SF_GET_STRING(s2, 2);         \
        MTR_SF_GET_STRING(s3, 3);         \
        MTR_SF_GET_STRING(s4, 4);         \
        result = func(s1, s2, s3, s4);    \
        MTR_SF_PUSH_BOOL(result);         \
        return 1;                         \
    }

#define MTR_SCRIPT_FUNC_B_S1B1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                  \
    {                                       \
        const char *s1;                     \
        bool b1;                            \
        bool result;                        \
        MTR_SF_GET_STRING(s1, 1);           \
        MTR_SF_GET_BOOL(b1, 2);             \
        result = func(s1, b1);              \
        MTR_SF_PUSH_BOOL(result);           \
        return 1;                           \
    }

#define MTR_SCRIPT_FUNC_B_S3B1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                  \
    {                                       \
        const char *s1;                     \
        const char *s2;                     \
        const char *s3;                     \
        bool b1;                             \
        bool result;                        \
        MTR_SF_GET_STRING(s1, 1);           \
        MTR_SF_GET_STRING(s2, 2);           \
        MTR_SF_GET_STRING(s3, 3);           \
        MTR_SF_GET_BOOL(b1, 4);              \
        result = func(s1, s2, s3, b1);      \
        MTR_SF_PUSH_BOOL(result);           \
        return 1;                           \
    }

#define MTR_SCRIPT_FUNC_B_S1I1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                  \
    {                                       \
        const char *s1;                     \
        int i1;                             \
        bool result;                        \
        MTR_SF_GET_STRING(s1, 1);           \
        MTR_SF_GET_INT(i1, 2);              \
        result = func(s1, i1);              \
        MTR_SF_PUSH_BOOL(result);           \
        return 1;                           \
    }

#define MTR_SCRIPT_FUNC_B_S3I1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                  \
    {                                       \
        const char *s1;                     \
        const char *s2;                     \
        const char *s3;                     \
        int i1;                             \
        bool result;                        \
        MTR_SF_GET_STRING(s1, 1);           \
        MTR_SF_GET_STRING(s2, 2);           \
        MTR_SF_GET_STRING(s3, 3);           \
        MTR_SF_GET_INT(i1, 4);              \
        result = func(s1, s2, s3, i1);      \
        MTR_SF_PUSH_BOOL(result);           \
        return 1;                           \
    }

#define MTR_SCRIPT_FUNC_B_S1I1B1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                    \
    {                                         \
        const char *s1;                       \
        int i1;                               \
        bool b1;                              \
        bool result;                          \
        MTR_SF_GET_STRING(s1, 1);             \
        MTR_SF_GET_INT(i1, 2);                \
        MTR_SF_GET_BOOL(b1, 3);               \
        result = func(s1, i1, b1);            \
        MTR_SF_PUSH_BOOL(result);             \
        return 1;                             \
    }

#define MTR_SCRIPT_FUNC_B_S1I1B2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                    \
    {                                         \
        const char *s1;                       \
        int i1;                               \
        bool b1;                              \
        bool b2;                              \
        bool result;                          \
        MTR_SF_GET_STRING(s1, 1);             \
        MTR_SF_GET_INT(i1, 2);                \
        MTR_SF_GET_BOOL(b1, 3);               \
        MTR_SF_GET_BOOL(b2, 4);               \
        result = func(s1, i1, b1, b2);        \
        MTR_SF_PUSH_BOOL(result);             \
        return 1;                             \
    }

#define MTR_SCRIPT_FUNC_B_S3F1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                  \
    {                                       \
        const char *s1;                     \
        const char *s2;                     \
        const char *s3;                     \
        float f1;                           \
        bool result;                        \
        MTR_SF_GET_STRING(s1, 1);           \
        MTR_SF_GET_STRING(s2, 2);           \
        MTR_SF_GET_STRING(s3, 3);           \
        MTR_SF_GET_SINGLE(f1, 4);           \
        result = func(s1, s2, s3, f1);      \
        MTR_SF_PUSH_BOOL(result);           \
        return 1;                           \
    }

#define MTR_SCRIPT_FUNC_B_S1F4I1(sfunc, func)  \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        const char *s1;                        \
        float f1;                              \
        float f2;                              \
        float f3;                              \
        float f4;                              \
        int i1;                                \
        bool result;                           \
        MTR_SF_GET_STRING(s1, 1);              \
        MTR_SF_GET_SINGLE(f1, 2);              \
        MTR_SF_GET_SINGLE(f2, 3);              \
        MTR_SF_GET_SINGLE(f3, 4);              \
        MTR_SF_GET_SINGLE(f4, 5);              \
        MTR_SF_GET_INT(i1, 6);                 \
        result = func(s1, f1, f2, f3, f4, i1); \
        MTR_SF_PUSH_BOOL(result);              \
        return 1;                              \
    }

#define MTR_SCRIPT_FUNC_I_V(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)               \
    {                                    \
        int result;                      \
        result = func();                 \
        MTR_SF_PUSH_INT(result);         \
        return 1;                        \
    }

#define MTR_SCRIPT_FUNC_I_I1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        int i1;                           \
        int result;                       \
        MTR_SF_GET_INT(i1, 1);            \
        result = func(i1);                \
        MTR_SF_PUSH_INT(result);          \
        return 1;                         \
    }

#define MTR_SCRIPT_FUNC_I_I2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        int i1;                           \
        int i2;                           \
        int result;                       \
        MTR_SF_GET_INT(i1, 1);            \
        MTR_SF_GET_INT(i2, 2);            \
        result = func(i1, i2);            \
        MTR_SF_PUSH_INT(result);          \
        return 1;                         \
    }

#define MTR_SCRIPT_FUNC_I_U32t1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                   \
    {                                        \
        uint32_t u32_1;                      \
        int result;                          \
        MTR_SF_GET_UINT32(u32_1, 1);         \
        result = func(u32_1);                \
        MTR_SF_PUSH_INT(result);             \
        return 1;                            \
    }

#define MTR_SCRIPT_FUNC_I_U32t1S1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        uint32_t u32_1;                        \
        const char *s1;                        \
        int result;                            \
        MTR_SF_GET_UINT32(u32_1, 1);           \
        MTR_SF_GET_STRING(s1, 2);              \
        result = func(u32_1, s1);              \
        MTR_SF_PUSH_INT(result);               \
        return 1;                              \
    }

#define MTR_SCRIPT_FUNC_I_S3I1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        const char *s1;                   \
        const char *s2;                   \
        const char *s3;                   \
        int i1;                           \
        int result;                       \
        MTR_SF_GET_STRING(s1, 1);         \
        MTR_SF_GET_STRING(s2, 2);         \
        MTR_SF_GET_STRING(s3, 3);         \
        MTR_SF_GET_INT(i1, 4);            \
        result = func(s1, s2, s3, i1);                \
        MTR_SF_PUSH_INT(result);          \
        return 1;                         \
    }

#define MTR_SCRIPT_FUNC_L_L1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        long int l1;                      \
        long int result;                  \
        MTR_SF_GET_LINT(l1, 1);           \
        result = func(l1);                \
        MTR_SF_PUSH_LINT(result);         \
        return 1;                         \
    }

#define MTR_SCRIPT_FUNC_L_L2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        long int l1;                      \
        long int l2;                      \
        long int result;                  \
        MTR_SF_GET_LINT(l1, 1);           \
        MTR_SF_GET_LINT(l2, 2);           \
        result = func(l1, l2);            \
        MTR_SF_PUSH_LINT(result);         \
        return 1;                         \
    }

#define MTR_SCRIPT_FUNC_LL_LL1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                  \
    {                                       \
        long long int ll1;                  \
        long long int result;               \
        MTR_SF_GET_LLINT(ll1, 1);           \
        result = func(ll1);                 \
        MTR_SF_PUSH_LLINT(result);          \
        return 1;                           \
    }

#define MTR_SCRIPT_FUNC_LL_LL2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                  \
    {                                       \
        long long int ll1;                  \
        long long int ll2;                  \
        long long int result;               \
        MTR_SF_GET_LLINT(ll1, 1);           \
        MTR_SF_GET_LLINT(ll2, 2);           \
        result = func(ll1, ll2);            \
        MTR_SF_PUSH_LLINT(result);          \
        return 1;                           \
    }

#define MTR_SCRIPT_FUNC_S16t_I2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                   \
    {                                        \
        int i1;                              \
        int i2;                              \
        int16_t result;                      \
        MTR_SF_GET_INT(i1, 1);               \
        MTR_SF_GET_INT(i2, 2);               \
        result = func(i1, i2);               \
        MTR_SF_PUSH_INT16(result);           \
        return 1;                            \
    }

#define MTR_SCRIPT_FUNC_U8t_I2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                  \
    {                                       \
        int i1;                             \
        int i2;                             \
        uint8_t result;                     \
        MTR_SF_GET_INT(i1, 1);              \
        MTR_SF_GET_INT(i2, 2);              \
        result = func(i1, i2);              \
        MTR_SF_PUSH_UINT8(result);          \
        return 1;                           \
    }

#define MTR_SCRIPT_FUNC_U32t_V(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                  \
    {                                       \
        uint32_t result;                    \
        result = func();                    \
        MTR_SF_PUSH_UINT32(result);         \
        return 1;                           \
    }

#define MTR_SCRIPT_FUNC_U32t_U8t3(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        uint8_t u8_1;                          \
        uint8_t u8_2;                          \
        uint8_t u8_3;                          \
        uint32_t result;                       \
        MTR_SF_GET_UINT8(u8_1, 1);             \
        MTR_SF_GET_UINT8(u8_2, 2);             \
        MTR_SF_GET_UINT8(u8_3, 3);             \
        result = func(u8_1, u8_2, u8_3);       \
        MTR_SF_PUSH_UINT32(result);            \
        return 1;                              \
    }

#define MTR_SCRIPT_FUNC_U32t_U8t4(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        uint8_t u8_1;                          \
        uint8_t u8_2;                          \
        uint8_t u8_3;                          \
        uint8_t u8_4;                          \
        uint32_t result;                       \
        MTR_SF_GET_UINT8(u8_1, 1);             \
        MTR_SF_GET_UINT8(u8_2, 2);             \
        MTR_SF_GET_UINT8(u8_3, 3);             \
        MTR_SF_GET_UINT8(u8_4, 4);             \
        result = func(u8_1, u8_2, u8_3, u8_4); \
        MTR_SF_PUSH_UINT32(result);            \
        return 1;                              \
    }

#define MTR_SCRIPT_FUNC_U32t_U32t1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                      \
    {                                           \
        uint32_t u32_1;                         \
        uint32_t result;                        \
        MTR_SF_GET_UINT32(u32_1, 1);            \
        result = func(u32_1);                   \
        MTR_SF_PUSH_UINT32(result);             \
        return 1;                               \
    }

#define MTR_SCRIPT_FUNC_U32t_U32t2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                      \
    {                                           \
        uint32_t u32_1;                         \
        uint32_t u32_2;                         \
        uint32_t result;                        \
        MTR_SF_GET_UINT32(u32_1, 1);            \
        MTR_SF_GET_UINT32(u32_2, 2);            \
        result = func(u32_1, u32_2);            \
        MTR_SF_PUSH_UINT32(result);             \
        return 1;                               \
    }

#define MTR_SCRIPT_FUNC_U32t_U32t1B1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                        \
    {                                             \
        uint32_t u32_1;                           \
        bool b1;                                  \
        uint32_t result;                          \
        MTR_SF_GET_UINT32(u32_1, 1);              \
        MTR_SF_GET_BOOL(b1, 2);                   \
        result = func(u32_1, b1);                 \
        MTR_SF_PUSH_UINT32(result);               \
        return 1;                                 \
    }

#define MTR_SCRIPT_FUNC_U32t_U32t1I1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                        \
    {                                             \
        uint32_t u32_1;                           \
        int i1;                                   \
        uint32_t result;                          \
        MTR_SF_GET_UINT32(u32_1, 1);              \
        MTR_SF_GET_INT(i1, 2);                    \
        result = func(u32_1, i1);                 \
        MTR_SF_PUSH_UINT32(result);               \
        return 1;                                 \
    }

#define MTR_SCRIPT_FUNC_U32t_U32t1I4(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                        \
    {                                             \
        uint32_t u32_1;                           \
        int i1;                                   \
        int i2;                                   \
        int i3;                                   \
        int i4;                                   \
        uint32_t result;                          \
        MTR_SF_GET_UINT32(u32_1, 1);              \
        MTR_SF_GET_INT(i1, 2);                    \
        MTR_SF_GET_INT(i2, 3);                    \
        MTR_SF_GET_INT(i3, 4);                    \
        MTR_SF_GET_INT(i4, 5);                    \
        result = func(u32_1, i1, i2, i3, i4);     \
        MTR_SF_PUSH_UINT32(result);               \
        return 1;                                 \
    }

#define MTR_SCRIPT_FUNC_U32t_U32t1D1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                        \
    {                                             \
        uint32_t u32_1;                           \
        double d1;                                \
        uint32_t result;                          \
        MTR_SF_GET_UINT32(u32_1, 1);              \
        MTR_SF_GET_DOUBLE(d1, 2);                 \
        result = func(u32_1, d1);                 \
        MTR_SF_PUSH_UINT32(result);               \
        return 1;                                 \
    }

#define MTR_SCRIPT_FUNC_U32t_U32t1S1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                        \
    {                                             \
        uint32_t u32_1;                           \
        const char *s1;                           \
        uint32_t result;                          \
        MTR_SF_GET_UINT32(u32_1, 1);              \
        MTR_SF_GET_STRING(s1, 2);                 \
        result = func(u32_1, s1);                 \
        MTR_SF_PUSH_UINT32(result);               \
        return 1;                                 \
    }

#define MTR_SCRIPT_FUNC_U32t_U32t1S2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                        \
    {                                             \
        uint32_t u32_1;                           \
        const char *s1;                           \
        const char *s2;                           \
        uint32_t result;                          \
        MTR_SF_GET_UINT32(u32_1, 1);              \
        MTR_SF_GET_STRING(s1, 2);                 \
        MTR_SF_GET_STRING(s2, 3);                 \
        result = func(u32_1, s1, s2);             \
        MTR_SF_PUSH_UINT32(result);               \
        return 1;                                 \
    }

#define MTR_SCRIPT_FUNC_U32t_U32t1S1B1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                          \
    {                                               \
        uint32_t u32_1;                             \
        const char *s1;                             \
        bool b1;                                    \
        uint32_t result;                            \
        MTR_SF_GET_UINT32(u32_1, 1);                \
        MTR_SF_GET_STRING(s1, 2);                   \
        MTR_SF_GET_BOOL(b1, 3);                     \
        result = func(u32_1, s1, b1);               \
        MTR_SF_PUSH_UINT32(result);                 \
        return 1;                                   \
    }

#define MTR_SCRIPT_FUNC_U32t_U32t1S1U32t1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                             \
    {                                                  \
        uint32_t u32_1;                                \
        const char *s1;                                \
        uint32_t u32_2;                                \
        uint32_t result;                               \
        MTR_SF_GET_UINT32(u32_1, 1);                   \
        MTR_SF_GET_STRING(s1, 2);                      \
        MTR_SF_GET_UINT32(u32_2, 3);                   \
        result = func(u32_1, s1, u32_2);               \
        MTR_SF_PUSH_UINT32(result);                    \
        return 1;                                      \
    }

#define MTR_SCRIPT_FUNC_U32t_U32t1S1D1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                          \
    {                                               \
        uint32_t u32_1;                             \
        const char *s1;                             \
        double d1;                                  \
        uint32_t result;                            \
        MTR_SF_GET_UINT32(u32_1, 1);                \
        MTR_SF_GET_STRING(s1, 2);                   \
        MTR_SF_GET_DOUBLE(d1, 3);                   \
        result = func(u32_1, s1, d1);               \
        MTR_SF_PUSH_UINT32(result);                 \
        return 1;                                   \
    }

#define MTR_SCRIPT_FUNC_U32t_S1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                   \
    {                                        \
        const char *s1;                      \
        uint32_t result;                     \
        MTR_SF_GET_STRING(s1, 1);            \
        result = func(s1);                   \
        MTR_SF_PUSH_UINT32(result);          \
        return 1;                            \
    }

#define MTR_SCRIPT_FUNC_U32t_S2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                   \
    {                                        \
        const char *s1;                      \
        const char *s2;                      \
        uint32_t result;                     \
        MTR_SF_GET_STRING(s1, 1);            \
        MTR_SF_GET_STRING(s2, 2);            \
        result = func(s1, s2);               \
        MTR_SF_PUSH_UINT32(result);          \
        return 1;                            \
    }

#define MTR_SCRIPT_FUNC_U32t_S1B1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        const char *s1;                        \
        bool b1;                               \
        uint32_t result;                       \
        MTR_SF_GET_STRING(s1, 1);              \
        MTR_SF_GET_BOOL(b1, 2);                \
        result = func(s1, b1);                 \
        MTR_SF_PUSH_UINT32(result);            \
        return 1;                              \
    }

#define MTR_SCRIPT_FUNC_U32t_S1I1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        const char *s1;                        \
        int i1;                                \
        uint32_t result;                       \
        MTR_SF_GET_STRING(s1, 1);              \
        MTR_SF_GET_INT(i1, 2);                 \
        result = func(s1, i1);                 \
        MTR_SF_PUSH_UINT32(result);            \
        return 1;                              \
    }

#define MTR_SCRIPT_FUNC_U32t_S1I2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        const char *s1;                        \
        int i1;                                \
        int i2;                                \
        uint32_t result;                       \
        MTR_SF_GET_STRING(s1, 1);              \
        MTR_SF_GET_INT(i1, 2);                 \
        MTR_SF_GET_INT(i2, 3);                 \
        result = func(s1, i1, i2);             \
        MTR_SF_PUSH_UINT32(result);            \
        return 1;                              \
    }

#define MTR_SCRIPT_FUNC_U32t_S1I3(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        const char *s1;                        \
        int i1;                                \
        int i2;                                \
        int i3;                                \
        uint32_t result;                       \
        MTR_SF_GET_STRING(s1, 1);              \
        MTR_SF_GET_INT(i1, 2);                 \
        MTR_SF_GET_INT(i2, 3);                 \
        MTR_SF_GET_INT(i3, 4);                 \
        result = func(s1, i1, i2, i3);         \
        MTR_SF_PUSH_UINT32(result);            \
        return 1;                              \
    }

#define MTR_SCRIPT_FUNC_U32t_S1I7(sfunc, func)         \
    MTR_SCRIPT_FUNC(sfunc)                             \
    {                                                  \
        const char *s1;                                \
        int i1;                                        \
        int i2;                                        \
        int i3;                                        \
        int i4;                                        \
        int i5;                                        \
        int i6;                                        \
        int i7;                                        \
        uint32_t result;                               \
        MTR_SF_GET_STRING(s1, 1);                      \
        MTR_SF_GET_INT(i1, 2);                         \
        MTR_SF_GET_INT(i2, 3);                         \
        MTR_SF_GET_INT(i3, 4);                         \
        MTR_SF_GET_INT(i4, 5);                         \
        MTR_SF_GET_INT(i5, 6);                         \
        MTR_SF_GET_INT(i6, 7);                         \
        MTR_SF_GET_INT(i7, 8);                         \
        result = func(s1, i1, i2, i3, i4, i5, i6, i7); \
        MTR_SF_PUSH_UINT32(result);                    \
        return 1;                                      \
    }

#define MTR_SCRIPT_FUNC_U32t_S1U32t1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                        \
    {                                             \
        const char *s1;                           \
        uint32_t u32_1;                           \
        uint32_t result;                          \
        MTR_SF_GET_STRING(s1, 1);                 \
        MTR_SF_GET_UINT32(u32_1, 2);              \
        result = func(s1, u32_1);                 \
        MTR_SF_PUSH_UINT32(result);               \
        return 1;                                 \
    }

#define MTR_SCRIPT_FUNC_U32t_S1D1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                     \
    {                                          \
        const char *s1;                        \
        double d1;                             \
        uint32_t result;                       \
        MTR_SF_GET_STRING(s1, 1);              \
        MTR_SF_GET_DOUBLE(d1, 2);              \
        result = func(s1, d1);                 \
        MTR_SF_PUSH_UINT32(result);            \
        return 1;                              \
    }

#define MTR_SCRIPT_FUNC_F_I2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        int i1;                           \
        int i2;                           \
        float result;                     \
        MTR_SF_GET_INT(i1, 1);            \
        MTR_SF_GET_INT(i2, 2);            \
        result = func(i1, i2);            \
        MTR_SF_PUSH_SINGLE(result);       \
        return 1;                         \
    }

#define MTR_SCRIPT_FUNC_F_F1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        float f1;                         \
        float result;                     \
        MTR_SF_GET_SINGLE(f1, 1);         \
        result = func(f1);                \
        MTR_SF_PUSH_SINGLE(result);       \
        return 1;                         \
    }

#define MTR_SCRIPT_FUNC_F_F2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        float f1;                         \
        float f2;                         \
        float result;                     \
        MTR_SF_GET_SINGLE(f1, 1);         \
        MTR_SF_GET_SINGLE(f2, 2);         \
        result = func(f1, f2);            \
        MTR_SF_PUSH_SINGLE(result);       \
        return 1;                         \
    }

#define MTR_SCRIPT_FUNC_F_S3F1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                  \
    {                                       \
        const char *s1;                     \
        const char *s2;                     \
        const char *s3;                     \
        float f1;                           \
        float result;                       \
        MTR_SF_GET_STRING(s1, 1);           \
        MTR_SF_GET_STRING(s2, 2);           \
        MTR_SF_GET_STRING(s3, 3);           \
        MTR_SF_GET_SINGLE(f1, 4);           \
        result = func(s1, s2, s3, f1);      \
        MTR_SF_PUSH_SINGLE(result);         \
        return 1;                           \
    }

#define MTR_SCRIPT_FUNC_D_D1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        double d1;                        \
        double result;                    \
        MTR_SF_GET_DOUBLE(d1, 1);         \
        result = func(d1);                \
        MTR_SF_PUSH_DOUBLE(result);       \
        return 1;                         \
    }

#define MTR_SCRIPT_FUNC_D_D2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        double d1;                        \
        double d2;                        \
        double result;                    \
        MTR_SF_GET_DOUBLE(d1, 1);         \
        MTR_SF_GET_DOUBLE(d2, 2);         \
        result = func(d1, d2);            \
        MTR_SF_PUSH_DOUBLE(result);       \
        return 1;                         \
    }

#define MTR_SCRIPT_FUNC_S_V(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)               \
    {                                    \
        const char *result;              \
        result = func();                 \
        if (result != NULL)              \
            MTR_SF_PUSH_STRING(result);  \
        else                             \
            MTR_SF_PUSH_NIL();           \
        return 1;                        \
    }

#define MTR_SCRIPT_FUNC_S_U32t1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                   \
    {                                        \
        uint32_t u32_1;                      \
        const char *result;                  \
        MTR_SF_GET_UINT32(u32_1, 1);         \
        result = func(u32_1);                \
        if (result != NULL)                  \
            MTR_SF_PUSH_STRING(result);      \
        else                                 \
            MTR_SF_PUSH_NIL();               \
        return 1;                            \
    }

#define MTR_SCRIPT_FUNC_S_S2(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        const char *s1;                   \
        const char *s2;                   \
        const char *result;               \
        MTR_SF_GET_STRING(s1, 1);         \
        MTR_SF_GET_STRING(s2, 2);         \
        result = func(s1, s2);            \
        if (result != NULL)               \
            MTR_SF_PUSH_STRING(result);   \
        else                              \
            MTR_SF_PUSH_NIL();            \
        return 1;                         \
    }

#define MTR_SCRIPT_FUNC_S_S3(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                \
    {                                     \
        const char *s1;                   \
        const char *s2;                   \
        const char *s3;                   \
        const char *result;               \
        MTR_SF_GET_STRING(s1, 1);         \
        MTR_SF_GET_STRING(s2, 2);         \
        MTR_SF_GET_STRING(s3, 3);         \
        result = func(s1, s2, s3);        \
        if (result != NULL)               \
            MTR_SF_PUSH_STRING(result);   \
        else                              \
            MTR_SF_PUSH_NIL();            \
        return 1;                         \
    }

#define MTR_SCRIPT_FUNC_S_S1I1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                  \
    {                                       \
        const char *s1;                     \
        int i1;                             \
        const char *result;                 \
        MTR_SF_GET_STRING(s1, 1);           \
        MTR_SF_GET_INT(i1, 2);              \
        result = func(s1, i1);              \
        if (result != NULL)                 \
            MTR_SF_PUSH_STRING(result);     \
        else                                \
            MTR_SF_PUSH_NIL();              \
        return 1;                           \
    }

#define MTR_SCRIPT_FUNC_S_S2I1(sfunc, func) \
    MTR_SCRIPT_FUNC(sfunc)                  \
    {                                       \
        const char *s1;                     \
        const char *s2;                     \
        int i1;                             \
        const char *result;                 \
        MTR_SF_GET_STRING(s1, 1);           \
        MTR_SF_GET_STRING(s2, 2);           \
        MTR_SF_GET_INT(i1, 3);              \
        result = func(s1, s2, i1);          \
        if (result != NULL)                 \
            MTR_SF_PUSH_STRING(result);     \
        else                                \
            MTR_SF_PUSH_NIL();              \
        return 1;                           \
    }

#endif
