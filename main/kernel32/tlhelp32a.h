#ifndef WNAPI_KERNEL32_TLHELP32_A_H
#define WNAPI_KERNEL32_TLHELP32_A_H

#include <tlhelp32.h>
#include "../common.h"

namespace wnapi
{
    namespace a
    {
        napi_value process32_first(napi_env env, napi_callback_info args)
        {
            size_t argc = 1;
            napi_value argv[1];
            parse_argument(env, args, &argc, argv);

            HANDLE handle = reinterpret_cast<HANDLE>(get_int64(env, argv[0]));
            PROCESSENTRY32 entry;
            if (Process32First(handle, &entry))
            {
                napi_value result = new_object(env);
                set_property(env, result, "size", new_int32(env, entry.dwSize));
                set_property(env, result, "usage", new_int32(env, entry.cntUsage));
                set_property(env, result, "processId", new_int32(env, entry.th32ProcessID));
                return result;
            }
            return the_null(env);
        }

        napi_value process32_next(napi_env env, napi_callback_info args)
        {
            size_t argc = 1;
            napi_value argv[1];
            parse_argument(env, args, &argc, argv);

            HANDLE handle = reinterpret_cast<HANDLE>(get_int64(env, argv[0]));
            PROCESSENTRY32 entry;
            if (Process32Next(handle, &entry))
            {
                napi_value result = new_object(env);
                set_property(env, result, "size", new_int32(env, entry.dwSize));
                set_property(env, result, "usage", new_int32(env, entry.cntUsage));
                set_property(env, result, "processId", new_int32(env, entry.th32ProcessID));
                return result;
            }
            return the_null(env);
        }
    } // namespace a
} // namespace wnapi

#endif
