#ifndef WNAPI_KERNEL32_A_H
#define WNAPI_KERNEL32_A_H

#include <memory>

namespace wnapi
{
    namespace a
    {
        napi_value find_window(napi_env env, napi_callback_info args)
        {
            size_t argc = 2;
            napi_value argv[2];
            napi_status status;
            status = napi_get_cb_info(env, args, &argc, argv, 0, 0);
            if (status != napi_ok)
            {
                throw_exception(env);
            }

            size_t length = 0;
            std::unique_ptr<char[]> classname;
            napi_valuetype type;
            status = napi_typeof(env, argv[0], &type);
            if (status != napi_ok)
            {
                throw_exception(env);
            }
            if (type == napi_string)
            {
                classname.reset(new char[1024]);
                status = napi_get_value_string_utf8(env, argv[0], classname.get(), 1024, &length);
                if (status != napi_ok)
                {
                    throw_exception(env);
                }
            }
            std::unique_ptr<char[]> windowname;
            status = napi_typeof(env, argv[0], &type);
            if (status != napi_ok)
            {
                throw_exception(env);
            }
            if (type == napi_string)
            {
                windowname.reset(new char[1024]);
                status = napi_get_value_string_utf8(env, argv[1], windowname.get(), 1024, &length);
                if (status != napi_ok)
                {
                    throw_exception(env);
                }
            }

            napi_value result;
            int64_t hwnd = reinterpret_cast<int64_t>(FindWindowA(classname.get(), windowname.get()));
            status = napi_create_int64(env, hwnd, &result);
            if (status != napi_ok)
            {
                throw_exception(env);
            }

            return result;
        }
    } // namespace a
} // namespace wnapi

#endif
