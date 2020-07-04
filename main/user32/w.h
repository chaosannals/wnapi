#ifndef WNAPI_USER32_W_H
#define WNAPI_USER32_W_H

#include "../common.h"

namespace wnapi
{
    namespace w
    {
        /**
         * 查找窗口。
         * 
         */
        napi_value find_window(napi_env env, napi_callback_info args)
        {
            size_t argc = 2;
            napi_value argv[2];
            parse_argument(env, args, &argc, argv);

            std::unique_ptr<wchar_t[]> classname = as_utf16_string(env, argv[0]);
            std::unique_ptr<wchar_t[]> windowname = as_utf16_string(env, argv[1]);

            int64_t hwnd = reinterpret_cast<int64_t>(FindWindowW(classname.get(), windowname.get()));
            return new_int64(env, hwnd);
        }
    } // namespace w

} // namespace wnapi

#endif