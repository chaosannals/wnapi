#ifndef WNAPI_KERNEL32_PSAPI_H
#define WNAPI_KERNEL32_PSAPI_H

#include <Psapi.h>
#include <memory>
#include "../common.h"

namespace wnapi
{
    napi_value enum_processes(napi_env env, napi_callback_info args)
    {
        DWORD needCount;
        if (!EnumProcesses(nullptr, sizeof(DWORD), &needCount))
        {
            throw_exception(env);
        }
        DWORD length = needCount / sizeof(DWORD);
        std::unique_ptr<DWORD[]> buffer(new DWORD[length]);
        if (!EnumProcesses(buffer.get(), length, &needCount))
        {
            throw_exception(env);
        }
        napi_value result = new_array(env);
        napi_value push = get_property(env, result, "push");
        for (DWORD i = 0; i < needCount; ++i)
        {
            napi_value item = new_int32(env, buffer[i]);
            call_function(env, result, push, 1, &item);
        }
        return result;
    }
} // namespace wnapi

#endif
