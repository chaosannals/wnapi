#ifndef WNAPI_USER32_W_H
#define WNAPI_USER32_W_H

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
            parse_argument(env, args, &argc, argv);

            std::unique_ptr<wchar_t[]> classname = as_utf16_string(env, argv[0]);
            std::unique_ptr<wchar_t[]> windowname = as_utf16_string(env, argv[1]);

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