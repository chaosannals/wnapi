#ifndef WNAPI_COMMON_H
#define WNAPI_COMMON_H

#include <memory>
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

    std::unique_ptr<char[]> get_utf8_string(napi_env env, napi_value text)
    {
        size_t length = 0;
        napi_status status = napi_get_value_string_utf8(env, text, nullptr, 0, &length);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        std::unique_ptr<char[]> result(new char[length]);
        status = napi_get_value_string_utf8(env, text, result.get(), length, &length);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        return result;
    }

    std::unique_ptr<wchar_t[]> get_utf16_string(napi_env env, napi_value text)
    {
        size_t length = 0;
        napi_status status = napi_get_value_string_utf8(env, text, nullptr, 0, &length);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        std::unique_ptr<char[]> content(new char[length]);
        status = napi_get_value_string_utf8(env, text, content.get(), length, &length);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        DWORD size = MultiByteToWideChar(CP_UTF8, 0, content.get(), length, NULL, 0);
        std::unique_ptr<wchar_t[]> result(new wchar_t[size]);
        MultiByteToWideChar(CP_UTF8, 0, content.get(), length, result.get(), size);
        return result;
    }
} // namespace wnapi

#endif
