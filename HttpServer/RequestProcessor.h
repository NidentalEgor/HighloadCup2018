#ifndef REQUEST_PROCESSOR_H_INCLUDED
#define REQUEST_PROCESSOR_H_INCLUDED
#pragma once

#include "IRequestProcessor.h"

namespace HttpServer
{

static const std::string not_found_response(
        "HTTP/1.1 404 Not Found\r\n"
        "S: b\r\n"
        "C: k\r\n"
        "B: a\r\n"
        "Content-Length: 0\r\n"
        "\r\n");

// temp
#include <iostream>
// temp

class RequestProcessor : public IRequestProcessor
{
public:
RequestProcessingResult ProcessRequest(
        const char* message,
        const size_t message_size) const override
{
    return std::make_pair(
            RequestProcessingStatus::NotFound,
            std::make_unique<std::string>(
                not_found_response ) );
}

};

} // namespace HttpServer

#endif // REQUEST_PROCESSOR_H_INCLUDED