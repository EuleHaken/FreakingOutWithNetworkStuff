#pragma once

#include "NetworkRequestType.hpp"
#include "NetworkResult.hpp"

#include <QNetworkRequest>
#include <functional>

struct NetworkData {
  std::function<void(NetworkResult &)> onSuccess;
  std::function<void(NetworkResult &)> onError;

  NetworkRequestType type;

  QNetworkRequest request;
};
