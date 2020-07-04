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
        napi_status status;
        napi_value a;
        status = napi_create_object(env, &a);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        export_function(env, a, "findWindow", a::find_window);
        status = napi_set_named_property(env, exports, "a", a);
        if (status != napi_ok)
        {
            throw_exception(env);
        }

        napi_value w;
        status = napi_create_object(env, &w);
        if (status != napi_ok)
        {
            throw_exception(env);
        }
        export_function(env, w, "findWindow", w::find_window);
        status = napi_set_named_property(env, exports, "w", w);
        if (status != napi_ok)
        {
            throw_exception(env);
        }

        export_function(env, exports, "getAsyncKeyState", get_async_key_state);
        return exports;
    }

    NAPI_MODULE(NODE_GYP_MODULE_NAME, init)
} // namespace wnapi