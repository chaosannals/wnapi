#include <Windows.h>
#include <node_api.h>
#include "common.h"
#include "user32/_.h"
#include "user32/a.h"
#include "user32/w.h"

namespace wnapi
{
    napi_value init(napi_env env, napi_value exports)
    {
        napi_value a = new_object(env);
        export_function(env, a, "findWindow", a::find_window);
        set_property(env, exports, "a", a);

        napi_value w = new_object(env);
        export_function(env, w, "findWindow", w::find_window);
        set_property(env, exports, "w", w);

        export_function(env, exports, "getAsyncKeyState", get_async_key_state);
        return exports;
    }

    NAPI_MODULE(NODE_GYP_MODULE_NAME, init)
} // namespace wnapi