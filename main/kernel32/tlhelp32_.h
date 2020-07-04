#ifndef WNAPI_KERNEL32_TLHELP32_H
#define WNAPI_KERNEL32_TLHELP32_H

#include <tlhelp32.h>
#include "../common.h"

namespace wnapi
{
    napi_value createToolhelp32Snapshot(napi_env env, napi_callback_info args)
    {
        size_t argc = 2;
        napi_value argv[2];
        napi_status status;
        parse_argument(env, args, &argc, argv);

        int32_t flags = get_int32(env, argv[0]);
        int32_t pid = get_int32(env, argv[1]);

        int64_t handle = reinterpret_cast<int64_t>(CreateToolhelp32Snapshot(flags, pid));
        napi_value result;
        status = napi_create_int64(env, handle, &result);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        return result;
    }
} // namespace wnapi

#endif
