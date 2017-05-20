#include "stdafx.h"
#include "UtilParser.h"


UtilParser::UtilParser()
{
}


UtilParser::~UtilParser()
{
}

const char * UtilParser::prepareMsgListMaladies(set<string> listeMaladies)
{
	string msgToSend;
	msgToSend += "MA v1.0\r\nDESEASES\r\n";
	for (auto maladie : listeMaladies)
	{
		msgToSend += maladie;
		msgToSend += "\r\n";
	}
	msgToSend += "\r\n";
	TRACE(msgToSend.c_str());
	char msg [BUFF_LEN];
	strcpy_s(msg, msgToSend.c_str());
	return msg;
}
