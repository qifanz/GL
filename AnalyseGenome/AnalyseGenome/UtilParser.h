#pragma once
#include<set>
#include "Analyse.h"
#include "string"
#include "Genome.h"

using namespace std;
class UtilParser
{
public:
	const static int BUFF_LEN = 2048;
	UtilParser();
	~UtilParser();
	const char* prepareMsgListMaladies(set<string> listeMaladies);
	Analyse* traiteMsgAnalyseCiblee(const char* msgReceived);
	Analyse* traiteMsgAnalyseGenerale(const char* msgReceived);
};

