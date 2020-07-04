#include <Windows.h>
#include <node_api.h>
#include "common.h"
#include "kernel32/_.h"
#include "kernel32/a.h"
#include "kernel32/w.h"
#include "kernel32/tlhelp32_.h"
#include "kernel32/tlhelp32a.h"
#include "kernel32/tlhelp32w.h"

namespace wnapi
{
    napi_value init(napi_env env, napi_value exports)
    {
        export_function(env, exports, "getCurrentThreadId", get_current_thread_id);
        export_function(env, exports, "getCurrentProcessId", get_current_process_id);
        export_function(env, exports, "createToolhelp32Snapshot", create_toolhelp32_snapshot);

        napi_value a = new_object(env);
        export_function(env, a, "process32First", a::process32_first);
        export_function(env, a, "process32Next", a::process32_next);
        set_property(env, exports, "a", a);

        return exports;
    }

    NAPI_MODULE(NODE_GYP_MODULE_NAME, init)
} // namespace wnapi