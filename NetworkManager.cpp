#include "NetworkManager.hpp"

QThread NetworkManager::workerThread;
QNetworkAccessManager NetworkManager::accessManager;

void NetworkManager::init()
{
    NetworkManager::accessManager.moveToThread(&NetworkManager::workerThread);
    NetworkManager::workerThread.start();
}

void NetworkManager::deinit()
{
    NetworkManager::workerThread.quit();
    NetworkManager::workerThread.wait();
}
