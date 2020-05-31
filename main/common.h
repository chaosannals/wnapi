#ifndef WNAPI_COMMON_H
#define WNAPI_COMMON_H

#include <Windows.h>
#include <node_api.h>

namespace wnapi
{
    /**
     * 抛出异常。
     * 
     */
    void throw_exception(napi_env env)
    {
        const napi_extended_error_info *info;
        napi_status status = napi_get_last_error_info(env, &info);
        if (status == napi_ok)
        {
            napi_throw_error(env, "-2000", info->error_message);
        }
        else
        {
            napi_throw_error(env, "-1000", "error message miss.");
        }
    }

    /**
     * 导出函数。
     * 
     */
    void export_function(napi_env env, napi_value exports, const char *name, napi_callback method)
    {
        napi_status status;
        napi_value function;
        status = napi_create_function(env, nullptr, 0, method, nullptr, &function);
        if (status != napi_ok)
        {
            throw_exception(env);
        }

        status = napi_set_named_property(env, exports, name, function);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
    }
} // namespace wnapi

#endif
