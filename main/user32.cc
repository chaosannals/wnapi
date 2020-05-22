#include <Windows.h>
#include <node_api.h>

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
            return nullptr;
        status = napi_get_value_int32(env, argv[0], &key);
        if (status != napi_ok)
            return nullptr;
        status = napi_create_int32(env, GetAsyncKeyState(key), &result);
        if (status != napi_ok)
            return nullptr;
        return result;
    }

    napi_value init(napi_env env, napi_value exports)
    {
        napi_status status;
        napi_value fn_get_async_key_state;

        status = napi_create_function(env, nullptr, 0, get_async_key_state, nullptr, &fn_get_async_key_state);
        if (status != napi_ok)
            return nullptr;

        status = napi_set_named_property(env, exports, "getAsyncKeyState", fn_get_async_key_state);
        if (status != napi_ok)
            return nullptr;

        return exports;
    }

    NAPI_MODULE(NODE_GYP_MODULE_NAME, init)
}