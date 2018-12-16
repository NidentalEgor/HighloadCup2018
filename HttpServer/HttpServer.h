#ifndef HTTP_SERVER_H_INCLUDED
#define HTTP_SERVER_H_INCLUDED
#pragma once

#include <string>
#include <memory>

#include "IRequestProcessor.h"
#include "../Utils/Traceable.h"

namespace HttpServer
{

class HttpServer : public Traceable
{
public:
    HttpServer(
        const std::string& ip_address,
        const uint16_t port,
        const size_t threads_count,
        const bool is_local_launch );

    void Run();

private:
    bool is_local_launch_;
    std::string ip_address_;
    uint16_t port_;
    uint16_t threads_count_;
    std::shared_ptr<IRequestProcessor> request_processor_;
};

} // namespace HttpServer

#endif // HTTP_SERVER_H_INCLUDED