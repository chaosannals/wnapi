#ifndef WNAPI_USER32_H
#define WNAPI_USER32_H

#include "../common.h"

namespace wnapi
{
    /**
     * 获取按键状态。
     * 
     */
    napi_value get_async_key_state(napi_env env, napi_callback_info args)
    {
        size_t argc = 1;
        napi_value argv[1];
        parse_argument(env, args, &argc, argv);

        int32_t key = get_int32(env, argv[0]);
        return new_int32(env, GetAsyncKeyState(key));
    }
} // namespace wnapi

#endif
