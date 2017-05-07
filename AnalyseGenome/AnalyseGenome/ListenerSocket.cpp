// ServerListener.cpp? fichier d'impl�mentation
//

#include "stdafx.h"
#include "AnalyseGenome.h"
#include "ListenerSocket.h"
#include "ConnectedSocket.h"

// ServerListener

ListenerSocket::ListenerSocket()
{
}

ListenerSocket::~ListenerSocket()
{
}

void ListenerSocket::OnAccept(int nErrorCode)
{
	TRACE("1\r\n");
	ConnectedSocket* pConnectedSock = new ConnectedSocket();

	CString strPeerName;
	UINT uiPort;

	if (Accept(*pConnectedSock))
	{
		pConnectedSock->GetPeerName(strPeerName, uiPort);
	}

	CAsyncSocket::OnAccept(nErrorCode);
}
