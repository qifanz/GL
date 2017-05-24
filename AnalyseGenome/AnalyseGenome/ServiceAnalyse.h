#pragma once
#include <list>
#include <set>
#include"Analyse.h"

using namespace std;

typedef string MALADIE;

typedef list<string> MOTS;

typedef map<MALADIE, MOTS> DICO;


class ServiceAnalyse
{
public:
	
	void AnalyseCiblee(Analyse& a, string maladie);
	void AnalyseGenerale(Analyse& a);
	set<string> getListeMaladies();
	ServiceAnalyse();
	~ServiceAnalyse();

	void initialise(CString dicoFile);

private :

	DICO dictionnaire;
};

