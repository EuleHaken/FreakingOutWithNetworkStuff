#include "NetworkResult.hpp"

NetworkResult::NetworkResult(const QByteArray &data, int status)
    : _data{data}, _status{status} {}

QJsonDocument NetworkResult::jsonDocument() const {
  auto doc = QJsonDocument::fromJson(this->_data);
  return doc;
}

QJsonObject NetworkResult::jsonObject() const {
  auto doc = QJsonDocument::fromJson(this->_data);
  return doc.object();
}

const QByteArray &NetworkResult::getData() const { return this->_data; }
