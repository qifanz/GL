#pragma once
#include <map>
#include <list>
#include <string>
#include"Analyse.h"

using namespace std;

class ServiceAnalyse
{
public:

	void AnalyseCiblee(Analyse& a, string maladie);
	void AnalyseGenerale(Analyse& a);
	ServiceAnalyse();
	~ServiceAnalyse();

private :
	map< string maladie, list<string> mot >;
	Genome genomeTemp;

};

