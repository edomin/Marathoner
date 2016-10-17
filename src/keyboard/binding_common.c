#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC(mtrSF_KeyboardInit)
{
    bool success;

    success = mtrKeyboardInit();

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_KeyboardRefresh)
{
    mtrKeyboardRefresh();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_KeyboardPress)
{
    int  key;
    bool result;

    MTR_SF_GET_INT(key, 1);
    result = mtrKeyboardPress(key);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_KeyboardRelease)
{
    int  key;
    bool result;

    MTR_SF_GET_INT(key, 1);
    result = mtrKeyboardRelease(key);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_KeyboardPressed)
{
    int  key;
    bool result;

    MTR_SF_GET_INT(key, 1);
    result = mtrKeyboardPressed(key);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}
