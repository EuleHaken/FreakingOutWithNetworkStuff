#pragma once

#include "NetworkData.hpp"
#include "NetworkResult.hpp"

#include <functional>

class NetworkRequest
{
public:
    NetworkRequest(const QString& url);

    NetworkRequest& onSuccess(const std::function<void(NetworkResult&)>& cb);
    NetworkRequest& onError(const std::function<void(NetworkResult&)>& cb);

    void execute();

private:
    void execute(const NetworkData& data);

private:
    NetworkData _data;
};
