// ServerListener.cpp? fichier d'implémentation
//

#include "stdafx.h"
#include "AnalyseGenome.h"
#include "ListenerSocket.h"
#include "ConnectedSocket.h"

// ServerListener

ListenerSocket::ListenerSocket()
{
}

ListenerSocket::ListenerSocket(ServiceAnalyse * service)
{
	this->service = service;
}

ListenerSocket::~ListenerSocket()
{
}

void ListenerSocket::OnAccept(int nErrorCode)
{
	TRACE("connection established\r\n");
	ConnectedSocket* pConnectedSock = new ConnectedSocket(service);

	CString strPeerName;
	UINT uiPort;

	if (Accept(*pConnectedSock))
	{
		pConnectedSock->GetPeerName(strPeerName, uiPort);
	}

	CAsyncSocket::OnAccept(nErrorCode);
}
