#include "stdafx.h"
#include "UtilParser.h"

using namespace std;
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

Analyse* UtilParser::traiteMsgAnalyseCiblee(const char * msgReceived)
{
	
	Analyse *a=new Analyse;
	string msg(msgReceived);
	int pos = msg.find('\r');
	
	pos = msg.find('\r', pos + 1);
	
	int pos1 = msg.find('\r', pos + 1);
	
	string maladie = msg.substr(pos+2, pos1-pos-2);
	a->type = maladie;

	int gstart=pos1+1;
	int gend=0;
	
	while (true)
	{
		gend = msg.find(";", gstart+1);
		a->genome.mots.insert(msg.substr(gstart+1,gend-gstart-1));
		gstart = gend;
		if (gend >= msg.size() - 3)
			break;
	}
	
	//test

	
	return a;

}

Analyse* UtilParser::traiteMsgAnalyseGenerale(const char * msgReceived)
{
	return nullptr;
}

