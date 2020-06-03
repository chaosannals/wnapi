#ifndef WNAPI_USER32_A_H
#define WNAPI_USER32_A_H

#include "../common.h"

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

            std::unique_ptr<char[]> classname;
            napi_valuetype type = get_type(env, argv[0]);
            if (type == napi_string)
            {
                classname = get_utf8_string(env, argv[0]);
            }
            std::unique_ptr<char[]> windowname;
            type = get_type(env, argv[1]);
            if (type == napi_string)
            {
                windowname = get_utf8_string(env, argv[1]);
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
