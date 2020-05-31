#ifndef WNAPI_EXCEPTION_H
#define WNAPI_EXCEPTION_H

#include <exception>
#include <node_api.h>

namespace wnapi
{
    class wnapi_error : public std::exception
    {
        napi_status status;
        const napi_extended_error_info *info;

    public:
        wnapi_error(napi_env env)
        {
            status = napi_get_last_error_info(env, &info);
        }

        const char *what() const throw()
        {
            return status == napi_ok ? info->error_message : "error message miss.";
        }
    };
} // namespace wnapi

#endif
