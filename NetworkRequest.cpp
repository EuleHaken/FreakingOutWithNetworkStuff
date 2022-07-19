#include "NetworkRequest.hpp"
#include "NetworkManager.hpp"
#include "NetworkWorker.hpp"

#include <QNetworkReply>

NetworkRequest::NetworkRequest(const QString& url)
{
    this->_data.request.setUrl(QUrl(url));
}

NetworkRequest& NetworkRequest::onSuccess(
    const std::function<void(NetworkResult&)>& cb)
{
    this->_data.onSuccess = cb;
    return *this;
}

NetworkRequest& NetworkRequest::onError(
    const std::function<void(NetworkResult&)>& cb)
{
    this->_data.onError = cb;
    return *this;
}

void NetworkRequest::execute()
{
    this->execute(this->_data);
}

void NetworkRequest::execute(const NetworkData& data)
{
    NetworkWorker worker;
    worker.moveToThread(&NetworkManager::workerThread);

    auto onUrlRequested = [data]() {
        auto reply = [&]() -> QNetworkReply* {
            return NetworkManager::accessManager.get(data.request);
        }();

        if (reply == nullptr)
        {
            qInfo() << "sus";
            return;
        }

        QByteArray bytes = reply->readAll();
        qInfo() << bytes;

        // Here, if successful, I would call data.onSuccess, e.g.
    };

    QObject::connect(&worker, &NetworkWorker::requestUrl, &worker,
                     onUrlRequested);

    emit worker.requestUrl();
}
