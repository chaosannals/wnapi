#include <Windows.h>
#include <node_api.h>

namespace wnapi
{
    napi_value get_current_thread_id(napi_env env, napi_callback_info args)
    {
        napi_value result;
        napi_status status;
        status = napi_create_int32(env, GetCurrentThreadId(), &result);
        if (status != napi_ok)
            return nullptr;
        return result;
    }

    napi_value get_current_process_id(napi_env env, napi_callback_info args)
    {
        napi_value result;
        napi_status status;
        status = napi_create_int32(env, GetCurrentProcessId(), &result);
        if (status != napi_ok)
            return nullptr;
        return result;
    }

    napi_value init(napi_env env, napi_value exports)
    {
        napi_status status;
        napi_value fn_get_current_thread_id;
        napi_value fn_get_current_process_id;

        status = napi_create_function(env, nullptr, 0, get_current_thread_id, nullptr, &fn_get_current_thread_id);
        if (status != napi_ok)
            return nullptr;

        status = napi_set_named_property(env, exports, "getCurrentThreadId", fn_get_current_thread_id);
        if (status != napi_ok)
            return nullptr;

        status = napi_create_function(env, nullptr, 0, get_current_process_id, nullptr, &fn_get_current_process_id);
        if (status != napi_ok)
            return nullptr;

        status = napi_set_named_property(env, exports, "getCurrentProcessId", fn_get_current_process_id);
        if (status != napi_ok)
            return nullptr;

        return exports;
    }

    NAPI_MODULE(NODE_GYP_MODULE_NAME, init)
} // namespace wnapi