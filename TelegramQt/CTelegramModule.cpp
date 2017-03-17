#include "CTelegramModule.hpp"
#include "CTelegramDispatcher.hpp"

CTelegramModule::CTelegramModule(QObject *parent) :
    QObject(parent),
    m_dispatcher(nullptr)
{
}

void CTelegramModule::setDispatcher(CTelegramDispatcher *dispatcher)
{
    m_dispatcher = dispatcher;
}

void CTelegramModule::clear()
{
}

bool CTelegramModule::setWantedDc(quint32 dcId)
{
    return m_dispatcher->setWantedDc(dcId);
}

CTelegramConnection *CTelegramModule::activeConnection() const
{
    if (!m_dispatcher) {
        return nullptr;
    }
    return m_dispatcher->activeConnection();
}

CTelegramConnection *CTelegramModule::getExtraConnection(quint32 dc)
{
    if (!m_dispatcher) {
        return nullptr;
    }
    return m_dispatcher->getExtraConnection(dc);
}

void CTelegramModule::onConnectionAuthChanged(CTelegramConnection *connection, int newState)
{
    Q_UNUSED(connection)
    Q_UNUSED(newState)
}

void CTelegramModule::onNewConnection(CTelegramConnection *connection)
{
    Q_UNUSED(connection)
}

bool CTelegramModule::getUserInfo(Telegram::UserInfo *userInfo, quint32 userId) const
{
    return m_dispatcher->getUserInfo(userInfo, userId);
}

bool CTelegramModule::getChatInfo(Telegram::GroupChat *outputChat, quint32 chatId) const
{
    return m_dispatcher->getChatInfo(outputChat, chatId);
}

bool CTelegramModule::getChatParticipants(QVector<quint32> *participants, quint32 chatId)
{
    return m_dispatcher->getChatParticipants(participants, chatId);
}

const TLUser *CTelegramModule::getUser(quint32 userId) const
{
    return m_dispatcher->getUser(userId);
}

const TLMessage *CTelegramModule::getMessage(quint32 messageId) const
{
    return m_dispatcher->getMessage(messageId);
}

TLInputPeer CTelegramModule::publicPeerToInputPeer(const Telegram::Peer &peer) const
{
    return m_dispatcher->publicPeerToInputPeer(peer);
}

Telegram::Peer CTelegramModule::peerToPublicPeer(const TLInputPeer &inputPeer) const
{
    return m_dispatcher->peerToPublicPeer(inputPeer);
}

Telegram::Peer CTelegramModule::peerToPublicPeer(const TLPeer &peer) const
{
    return m_dispatcher->peerToPublicPeer(peer);
}

TLInputUser CTelegramModule::userIdToInputUser(quint32 id) const
{
    return m_dispatcher->userIdToInputUser(id);
}
