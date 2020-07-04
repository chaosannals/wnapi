#include <Windows.h>
#include <node_api.h>
#include "common.h"
#include "kernel32/_.h"
#include "kernel32/a.h"
#include "kernel32/w.h"
#include "kernel32/tlhelp32a.h"
#include "kernel32/tlhelp32w.h"

namespace wnapi
{
    napi_value init(napi_env env, napi_value exports)
    {
        export_function(env, exports, "getCurrentThreadId", get_current_thread_id);
        export_function(env, exports, "getCurrentProcessId", get_current_process_id);

        return exports;
    }

    NAPI_MODULE(NODE_GYP_MODULE_NAME, init)
} // namespace wnapi