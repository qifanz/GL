#pragma once
#include<set>

using namespace std;
class UtilParser
{
public:
	const static int BUFF_LEN = 2048;
	UtilParser();
	~UtilParser();
	const char* prepareMsgListMaladies(set<string> listeMaladies);
};

