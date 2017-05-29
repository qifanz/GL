// ClientSocket.cpp? fichier d'impl¨¦mentation
//

#include "stdafx.h"
#include "AnalyseGenome.h"
#include "ConnectedSocket.h"
#include <fstream>

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
	TRACE("%s\r\n", szBuff);
	logger(szBuff);
	//AfxMessageBox(CString(szBuff));
	if (strstr(szBuff, "GET DISEASES"))
	{
		UtilParser paser;
		Send(paser.prepareMsgListMaladies(this->service->getListeMaladies()), BUFF_LEN);
	}
	else if (strstr(szBuff, "CHECK DISEASE")) {
		UtilParser paser;
		Analyse *a = (paser.traiteMsgAnalyseCiblee(szBuff));


		TRACE("version %s\r\n", a->getVersion().c_str());
		TRACE("type %s\r\n", a->type.c_str());
		for (auto it : a->genome.mots)
		{
			TRACE("%s\r\n", it.c_str());
		}


		service->AnalyseCiblee(*a, a->type);

		Send(paser.prepareMsgResultatCiblee(a), BUFF_LEN);


	}
	else if (strstr(szBuff, "CHECK ALL"))
	{
		UtilParser paser;
		Analyse *a = (paser.traiteMsgAnalyseGenerale(szBuff));
		TRACE("version %s\r\n", a->getVersion().c_str());
		TRACE("type %s\r\n", a->type.c_str());
		for (auto it : a->genome.mots)
		{
			TRACE("%s\r\n", it.c_str());
		}

		service->AnalyseGenerale(*a);
		for (auto it : a->resultats) {
			TRACE("disease %s : \r\n", it.first.c_str());
			if (it.second)
				TRACE("yes\r\n");
			else
				TRACE("no\r\n");
		}
		Send(paser.prepareMsgResultatGenerale(a), BUFF_LEN);

	}

	CAsyncSocket::OnReceive(nErrorCode);
}

void ConnectedSocket::logger(char * msg)
{

	{
		ofstream fichier("res/log.txt", ios::out | ios::app);

		if (fichier)
		{
			fichier << msg << endl;
			fichier.close();
		}
		else
			AfxMessageBox((CString)("Impossible d'ouvrir le fichier log.txt!\r\n"));

	}

}