#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>

#pragma once

class NetworkResult {
  Q_DISABLE_COPY(NetworkResult)

public:
  explicit NetworkResult(const QByteArray& data, int status);

  QJsonDocument jsonDocument() const;
  QJsonObject jsonObject() const;

  const QByteArray &getData() const;

private:
  QByteArray _data;
  int _status;
};
