#pragma once

#include <QNetworkAccessManager>
#include <QThread>

class NetworkManager
{
public:
    static QThread workerThread;
    static QNetworkAccessManager accessManager;

    static void init();
    static void deinit();
};
