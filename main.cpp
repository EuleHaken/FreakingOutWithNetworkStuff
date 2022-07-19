#include "NetworkManager.hpp"
#include "NetworkRequest.hpp"
#include "NetworkWorker.hpp"

#include <QCoreApplication>
#include <QObject>
#include <QThread>

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  NetworkManager::init();

  NetworkRequest("https://supinic.com/api/bot/user/resolve/name/eulehaken")
      .onSuccess([](NetworkResult &result) { qInfo() << result.getData(); })
      .onError([](NetworkResult &result) { qInfo() << result.getData(); })
      .execute();

  qInfo() << "Done!";

  a.exec();
  NetworkManager::deinit();
  return 0;
}
