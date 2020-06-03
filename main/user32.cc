#include <Windows.h>
#include <node_api.h>
#include "common.h"
#include "user32/a.h"
#include "user32/w.h"

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

    napi_value init(napi_env env, napi_value exports)
    {
        napi_value a;
        napi_status status;
        status = napi_create_object(env, &a);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        export_function(env, a, "findWindow", a::find_window);
        status = napi_set_named_property(env, exports, "a", a);
        if (status != napi_ok)
        {
            throw_exception(env);
        }

        export_function(env, exports, "getAsyncKeyState", get_async_key_state);
        return exports;
    }

    NAPI_MODULE(NODE_GYP_MODULE_NAME, init)
} // namespace wnapi