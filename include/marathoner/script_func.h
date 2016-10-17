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
