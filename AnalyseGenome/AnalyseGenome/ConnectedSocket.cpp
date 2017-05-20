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

	CAsyncSocket::OnReceive(nErrorCode);
}
