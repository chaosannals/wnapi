﻿#include <Windows.h>
#include <node_api.h>
#include "common.h"

namespace wnapi
{
    napi_value get_current_thread_id(napi_env env, napi_callback_info args)
    {
        napi_value result;
        napi_status status;
        status = napi_create_int32(env, GetCurrentThreadId(), &result);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        return result;
    }

    napi_value get_current_process_id(napi_env env, napi_callback_info args)
    {
        napi_value result;
        napi_status status;
        status = napi_create_int32(env, GetCurrentProcessId(), &result);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        return result;
    }

    napi_value init(napi_env env, napi_value exports)
    {
        export_function(env, exports, "getCurrentThreadId", get_current_thread_id);
        export_function(env, exports, "getCurrentProcessId", get_current_process_id);

        return exports;
    }

    NAPI_MODULE(NODE_GYP_MODULE_NAME, init)
} // namespace wnapi