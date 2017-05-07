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
	TRACE("2\r\n");
	const int BUFF_LEN = 2048;
	char szBuff[BUFF_LEN];

	int nReceivedSize = Receive(szBuff, BUFF_LEN);
	TRACE(szBuff);
	TRACE("\r\n");
	if (nReceivedSize <= 0)
		return;

	szBuff[nReceivedSize] = '\0';

	string strResponse = "hello\n";

	int nSentBytes = 0;
	const char* pszBuff = strResponse.c_str();
	int nResponseSize = strResponse.length();

	while (nSentBytes < nResponseSize)
	{
		nSentBytes = Send(pszBuff, nResponseSize);
		nResponseSize = nResponseSize - nSentBytes;
		pszBuff = pszBuff + nSentBytes;
	}

	CAsyncSocket::OnReceive(nErrorCode);
}
