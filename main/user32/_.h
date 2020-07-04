#ifndef WNAPI_USER32_H
#define WNAPI_USER32_H

#include "../common.h"

namespace wnapi
{
    napi_value get_async_key_state(napi_env env, napi_callback_info args)
    {
        size_t argc = 1;
        int key = 0;
        napi_value argv[1];
        napi_value result;
        napi_status status;

        status = napi_get_cb_info(env, args, &argc, argv, 0, 0);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        status = napi_get_value_int32(env, argv[0], &key);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        status = napi_create_int32(env, GetAsyncKeyState(key), &result);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        return result;
    }
} // namespace wapi

#endif
