/*
   Copyright (C) 2018 Alexander Akulich <akulichalexander@gmail.com>

   This file is a part of TelegramQt library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

 */

#include "HelpOperationFactory.hpp"

#include "RpcOperationFactory_p.hpp"
// TODO: Instead of this include, add a generated cpp with all needed template instances
#include "ServerRpcOperation_p.hpp"

#include "ServerApi.hpp"
#include "ServerRpcLayer.hpp"
#include "TelegramServerUser.hpp"

#include "Debug_p.hpp"
#include "RpcError.hpp"
#include "RpcProcessingContext.hpp"
#include "Utils.hpp"

#include "CTelegramStreamExtraOperators.hpp"
#include "FunctionStreamOperators.hpp"

#include <QLoggingCategory>

namespace Telegram {

namespace Server {

// Generated process methods
bool HelpRpcOperation::processGetAppChangelog(RpcProcessingContext &context)
{
    setRunMethod(&HelpRpcOperation::runGetAppChangelog);
    context.inputStream() >> m_getAppChangelog;
    return !context.inputStream().error();
}

bool HelpRpcOperation::processGetAppUpdate(RpcProcessingContext &context)
{
    setRunMethod(&HelpRpcOperation::runGetAppUpdate);
    context.inputStream() >> m_getAppUpdate;
    return !context.inputStream().error();
}

bool HelpRpcOperation::processGetConfig(RpcProcessingContext &context)
{
    setRunMethod(&HelpRpcOperation::runGetConfig);
    context.inputStream() >> m_getConfig;
    return !context.inputStream().error();
}

bool HelpRpcOperation::processGetInviteText(RpcProcessingContext &context)
{
    setRunMethod(&HelpRpcOperation::runGetInviteText);
    context.inputStream() >> m_getInviteText;
    return !context.inputStream().error();
}

bool HelpRpcOperation::processGetNearestDc(RpcProcessingContext &context)
{
    setRunMethod(&HelpRpcOperation::runGetNearestDc);
    context.inputStream() >> m_getNearestDc;
    return !context.inputStream().error();
}

bool HelpRpcOperation::processGetSupport(RpcProcessingContext &context)
{
    setRunMethod(&HelpRpcOperation::runGetSupport);
    context.inputStream() >> m_getSupport;
    return !context.inputStream().error();
}

bool HelpRpcOperation::processGetTermsOfService(RpcProcessingContext &context)
{
    setRunMethod(&HelpRpcOperation::runGetTermsOfService);
    context.inputStream() >> m_getTermsOfService;
    return !context.inputStream().error();
}

bool HelpRpcOperation::processSaveAppLog(RpcProcessingContext &context)
{
    setRunMethod(&HelpRpcOperation::runSaveAppLog);
    context.inputStream() >> m_saveAppLog;
    return !context.inputStream().error();
}
// End of generated process methods

// Generated run methods
void HelpRpcOperation::runGetAppChangelog()
{
    qWarning() << Q_FUNC_INFO << "The method is not implemented!";
    TLHelpAppChangelog result;
    sendRpcReply(result);
}

void HelpRpcOperation::runGetAppUpdate()
{
    qWarning() << Q_FUNC_INFO << "The method is not implemented!";
    TLHelpAppUpdate result;
    sendRpcReply(result);
}

void HelpRpcOperation::runGetConfig()
{
    qWarning() << Q_FUNC_INFO << "The method is not implemented!";
    TLConfig result;
    sendRpcReply(result);
}

void HelpRpcOperation::runGetInviteText()
{
    qWarning() << Q_FUNC_INFO << "The method is not implemented!";
    TLHelpInviteText result;
    sendRpcReply(result);
}

void HelpRpcOperation::runGetNearestDc()
{
    qWarning() << Q_FUNC_INFO << "The method is not implemented!";
    TLNearestDc result;
    sendRpcReply(result);
}

void HelpRpcOperation::runGetSupport()
{
    qWarning() << Q_FUNC_INFO << "The method is not implemented!";
    TLHelpSupport result;
    sendRpcReply(result);
}

void HelpRpcOperation::runGetTermsOfService()
{
    qWarning() << Q_FUNC_INFO << "The method is not implemented!";
    TLHelpTermsOfService result;
    sendRpcReply(result);
}

void HelpRpcOperation::runSaveAppLog()
{
    qWarning() << Q_FUNC_INFO << "The method is not implemented!";
    bool result;
    sendRpcReply(result);
}
// End of generated run methods

void HelpRpcOperation::setRunMethod(HelpRpcOperation::RunMethod method)
{
    m_runMethod = method;
}

HelpRpcOperation::ProcessingMethod HelpRpcOperation::getMethodForRpcFunction(TLValue function)
{
    switch (function) {
    // Generated methodForRpcFunction cases
    case TLValue::HelpGetAppChangelog:
        return &HelpRpcOperation::processGetAppChangelog;
    case TLValue::HelpGetAppUpdate:
        return &HelpRpcOperation::processGetAppUpdate;
    case TLValue::HelpGetConfig:
        return &HelpRpcOperation::processGetConfig;
    case TLValue::HelpGetInviteText:
        return &HelpRpcOperation::processGetInviteText;
    case TLValue::HelpGetNearestDc:
        return &HelpRpcOperation::processGetNearestDc;
    case TLValue::HelpGetSupport:
        return &HelpRpcOperation::processGetSupport;
    case TLValue::HelpGetTermsOfService:
        return &HelpRpcOperation::processGetTermsOfService;
    case TLValue::HelpSaveAppLog:
        return &HelpRpcOperation::processSaveAppLog;
    // End of generated methodForRpcFunction cases
    default:
        return nullptr;
    }
}

RpcOperation *HelpOperationFactory::processRpcCall(RpcLayer *layer, RpcProcessingContext &context)
{
    return processRpcCallImpl<HelpRpcOperation>(layer, context);
}

} // Server

} // Telegram