#include "ServerRpcOperation.hpp"

#include "ServerRpcLayer.hpp"
#include "MTProto/Stream.hpp"

#ifdef DEVELOPER_BUILD
#include "MTProto/TLTypesDebug.hpp"
#endif

namespace Telegram {

namespace Server {

template<typename TLType>
bool RpcOperation::sendRpcReply(const TLType &reply)
{
    CTelegramStream output(CTelegramStream::WriteOnly);
    output << reply;
#ifdef DEVELOPER_BUILD
    qDebug() << this << reply;
#endif
    return layer()->sendRpcReply(output.getData(), m_requestId);
}

} // Server namespace

} //Telegram namespace
