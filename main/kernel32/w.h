#ifndef WNAPI_KERNEL32_W_H
#define WNAPI_KERNEL32_W_H


#include <memory>
#include "../common.h"

namespace wnapi
{
    namespace w
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
            std::unique_ptr<wchar_t[]> classname;
            napi_valuetype type;
            status = napi_typeof(env, argv[0], &type);
            if (status != napi_ok)
            {
                throw_exception(env);
            }
            if (type == napi_string)
            {
                classname = get_utf16_string(env, argv[0]);
            }
            std::unique_ptr<wchar_t[]> windowname;
            status = napi_typeof(env, argv[1], &type);
            if (status != napi_ok)
            {
                throw_exception(env);
            }
            if (type == napi_string)
            {
                windowname = get_utf16_string(env, argv[1]);
            }

            napi_value result;
            int64_t hwnd = reinterpret_cast<int64_t>(FindWindowW(classname.get(), windowname.get()));
            status = napi_create_int64(env, hwnd, &result);
            if (status != napi_ok)
            {
                throw_exception(env);
            }

            return result;
        }
    } // namespace w
} // namespace wnapi

#endif
