#pragma once
#include <list>
#include <set>
#include <iterator>
#include"Analyse.h"

using namespace std;

typedef string MALADIE;

typedef list<string> MOTS;
typedef MOTS::iterator MOTS_IT;

typedef map<MALADIE, MOTS> DICO;
typedef DICO::iterator DICO_IT;

typedef multiset<string>::iterator GENO_IT;


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
	void ParcoursGenome(DICO_IT tuple, Analyse& a);

	DICO dictionnaire;
	//genStart et genStop définissent les bornes du génome. Evite de les calculer ?chaque appel de ParcoursGenome.
	GENO_IT genStart;	
	GENO_IT genStop;

};

