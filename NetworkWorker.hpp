#pragma once

#include <QObject>

class NetworkWorker : public QObject
{
    Q_OBJECT

signals:
    void requestUrl();
};
