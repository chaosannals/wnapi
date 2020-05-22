#ifndef WNAPI_COMMON_H
#define WNAPI_COMMON_H

#include <Windows.h>
#include <node_api.h>

namespace wnapi {
    void export_function(napi_env env, napi_value exports, const char* name, napi_callback method) {
        napi_status status;
        napi_value function;
        status = napi_create_function(env, nullptr, 0, method, nullptr, &function);
        if (status != napi_ok)
            return;

        status = napi_set_named_property(env, exports, name, function);
        if (status != napi_ok)
            return;
    }
}

#endif
