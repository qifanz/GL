#pragma once

#include <string>
#include "ServiceAnalyse.h"
#include "UtilParser.h"

class ConnectedSocket : public CAsyncSocket
{
public:
	ConnectedSocket();
	ConnectedSocket(ServiceAnalyse* service);
	virtual ~ConnectedSocket();
	virtual void OnReceive(int nErrorCode);
	void logger(char * msg);
private:
	ServiceAnalyse* service;
	UtilParser paser;
};
