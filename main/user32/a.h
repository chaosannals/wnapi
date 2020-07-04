#ifndef WNAPI_USER32_A_H
#define WNAPI_USER32_A_H

#include "../common.h"

namespace wnapi
{
    namespace a
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

            std::unique_ptr<char[]> classname = as_utf8_string(env, argv[0]);
            std::unique_ptr<char[]> windowname = as_utf8_string(env, argv[1]);

            int64_t hwnd = reinterpret_cast<int64_t>(FindWindowA(classname.get(), windowname.get()));
            return new_int64(env, hwnd);
        }
    } // namespace a

} // namespace wnapi

#endif
