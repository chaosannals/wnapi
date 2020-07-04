#ifndef WNAPI_KERNEL32_H
#define WNAPI_KERNEL32_H

#include "../common.h"

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
} // namespace wnapi

#endif
