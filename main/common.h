﻿#ifndef WNAPI_COMMON_H
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

    napi_value the_null(napi_env env)
    {
        napi_value result;
        napi_status status = napi_get_null(env, &result);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        return result;
    }

    /**
     * 新建对象。
     * 
     */
    napi_value new_object(napi_env env)
    {
        napi_value result;
        napi_status status = napi_create_object(env, &result);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        return result;
    }

    napi_value new_array(napi_env env)
    {
        napi_value result;
        napi_status status = napi_create_array(env, &result);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        return result;
    }

    napi_value new_int32(napi_env env, int32_t value)
    {
        napi_value result;
        napi_status status = napi_create_int32(env, value, &result);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        return result;
    }

    napi_value new_int64(napi_env env, int64_t value)
    {
        napi_value result;
        napi_status status = napi_create_int64(env, value, &result);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        return result;
    }

    napi_value get_property(napi_env env, napi_value target, const char *name)
    {
        napi_value result;
        napi_status status = napi_get_named_property(env, target, name, &result);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        return result;
    }

    /**
     * 设置属性。
     * 
     */
    void set_property(napi_env env, napi_value target, const char *name, napi_value value)
    {
        napi_status status = napi_set_named_property(env, target, name, value);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
    }

    void set_element(napi_env env, napi_value target, uint32_t index, napi_value value)
    {
        napi_status status = napi_set_element(env, target, index, value);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
    }

    napi_value call_function(napi_env env, napi_value recv, napi_value func, size_t argc, const napi_value *argv)
    {
        napi_value result;
        napi_status status = napi_call_function(env, recv, func, argc, argv, &result);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        return result;
    }

    /**
     * 解析参数。
     * 
     */
    void parse_argument(napi_env env, napi_callback_info args, size_t *argc, napi_value *argv)
    {
        napi_status status = napi_get_cb_info(env, args, argc, argv, 0, 0);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
    }

    /**
     * 获取值类型。
     * 
     */
    napi_valuetype get_type(napi_env env, napi_value value)
    {
        napi_valuetype type;
        napi_status status = napi_typeof(env, value, &type);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        return type;
    }

    int32_t get_int32(napi_env env, napi_value value)
    {
        int32_t result;
        napi_status status = napi_get_value_int32(env, value, &result);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        return result;
    }

    int64_t get_int64(napi_env env, napi_value value)
    {
        int64_t result;
        napi_status status = napi_get_value_int64(env, value, &result);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        return result;
    }

    /**
     * 获取 UTF8 字符串。
     * 
     */
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

    /**
     * 获取 UTF16 字符串。
     * 
     */
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

    /**
     * 转换成 UTF8 字符串。
     * 
     */
    std::unique_ptr<char[]> as_utf8_string(napi_env env, napi_value text)
    {
        std::unique_ptr<char[]> result;
        napi_valuetype type = get_type(env, text);
        if (type == napi_string)
        {
            result = get_utf8_string(env, text);
        }
        return result;
    }

    /**
     * 转换成 UTF16 字符出。
     */
    std::unique_ptr<wchar_t[]> as_utf16_string(napi_env env, napi_value text)
    {
        std::unique_ptr<wchar_t[]> result;
        napi_valuetype type = get_type(env, text);
        if (type == napi_string)
        {
            result = get_utf16_string(env, text);
        }
        return result;
    }
} // namespace wnapi

#endif
