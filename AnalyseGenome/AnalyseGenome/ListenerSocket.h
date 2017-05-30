#pragma once
#include "ServiceAnalyse.h"
#include <list>
#include "ConnectedSocket.h"
// Cible de la commande ServerListener

class ListenerSocket : public CAsyncSocket
{
public:
	ListenerSocket();
	ListenerSocket(ServiceAnalyse* service);
	virtual ~ListenerSocket();
	virtual void OnAccept(int nErrorCode);
	

private:
	ServiceAnalyse* service;
	list<ConnectedSocket*> listSockets;
};


