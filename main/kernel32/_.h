#ifndef WNAPI_KERNEL32_H
#define WNAPI_KERNEL32_H

#include "../common.h"

namespace wnapi
{
    /**
     * 获取当前线程 ID
     */
    napi_value get_current_thread_id(napi_env env, napi_callback_info args)
    {
        return new_int32(env, GetCurrentThreadId());
    }

    /**
     * 获取当前进程 ID
     * 
     */
    napi_value get_current_process_id(napi_env env, napi_callback_info args)
    {
        return new_int32(env,GetCurrentProcessId());
    }
} // namespace wnapi

#endif
