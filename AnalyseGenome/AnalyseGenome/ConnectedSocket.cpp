// ClientSocket.cpp? fichier d'implémentation
//

#include "stdafx.h"
#include "AnalyseGenome.h"
#include "ConnectedSocket.h"

using namespace std;

ConnectedSocket::ConnectedSocket()
{
}

ConnectedSocket::~ConnectedSocket()
{
}

ConnectedSocket::ConnectedSocket(ServiceAnalyse* service)
{
	this->service = service;
}

void ConnectedSocket::OnReceive(int nErrorCode)
{
	TRACE("Msg received: \r\n");
	const int BUFF_LEN = 2048;
	char szBuff[BUFF_LEN];

	int nReceivedSize = Receive(szBuff, BUFF_LEN);

	if (nReceivedSize <= 0)
		return;

	szBuff[nReceivedSize - 1] = '\0';
	TRACE(szBuff);

	if (strstr(szBuff, "GET DISEASES"))
	{
		UtilParser paser;
		Send(paser.prepareMsgListMaladies(this->service->getListeMaladies()), BUFF_LEN);
	}

	CAsyncSocket::OnReceive(nErrorCode);
}
