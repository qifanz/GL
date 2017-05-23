#include "stdafx.h"
#include "ServiceAnalyse.h"
#include <fstream>
#include <string>
using namespace std;
ServiceAnalyse::ServiceAnalyse()
{
}



ServiceAnalyse::~ServiceAnalyse()
{
}

void ServiceAnalyse::initialise(CString nomFichierGenome)
//uniquement pour les tests, initialise le serveur avec un dictionnaire
{

	ifstream fichier(nomFichierGenome, ios::in);
	if (fichier)
	{
		string version;
		getline(fichier, version);
		string line;
		while (getline(fichier, line)) {
			list<string> mots;
			string mot;
			int pos = line.find(";");
			string maladie = line.substr(0, pos);
			for (int i = pos+1; i < line.length(); i += 5)
			{
				mot = line.substr(i, 4);
				mots.push_back(mot);
				TRACE(mot.c_str());
			}
			dictionnaire.insert(pair<string, list<string>>(maladie, mots));

		}
		TRACE("Genome cr����\r\n");
		fichier.close();
	}
	else
	{
		TRACE("Impossible d'ouvrir le fichier!\r\n");
	}
	/**
	list<string> mots;
	mots.push_back("AAAT");
	mots.push_back("GCGC");
	
	dictionnaire.insert(pair <string, list<string>>("AIDS", mots));
	
	list<string> mots2;
	mots2.push_back("AAAT");
	mots2.push_back("BBBB");

	dictionnaire.insert(pair <string, list<string>>("H5N1", mots2));
	
	list<string> mots3;
	mots3.push_back("AAAT");
	mots3.push_back("CCCG");
	dictionnaire.insert(pair <string, list<string>>("H5N2", mots3));
	**/

}

// POUR LES ANALYSES :  Pour chaque pair parcouru, comparer la list de mots correspondante avec find() dans le multiset du g�nome. Rajouter un resultat dans l'analyse avec addResult(String maladie) pour chaque mot trouv?dans le g�nome. Seul le parcours change selon le type d'analyse.

void ServiceAnalyse::AnalyseCiblee(Analyse& a, string maladie)
//Utiliser find pour trouver le pair<maladie,mots> pour la maladie donn�e dans la map.
{
	/**
	genStart = a.getGenome().mots.begin();
	genStop = a.getGenome().mots.end();
	DICO_IT tuple = dictionnaire.find(maladie);
	ParcoursGenome(tuple, a);**/
	list<string> genome= dictionnaire.find(maladie)->second;
	bool result = true;
	for (auto g:genome)
	{
		if (a.genome.mots.find(g) == a.genome.mots.end())
		{
			result = false;
			break;
		}
	}
	a.resultats.insert(pair<string, bool>(maladie, result));

}

void ServiceAnalyse::AnalyseGenerale(Analyse& a)
//Utiliser un iterator pour parcourir toute la map. Pour chaque pair, lancer une analyse
{
	/**
	genStart = a.getGenome().mots.begin();
	genStop = a.getGenome().mots.end();
	for (DICO_IT tuple = dictionnaire.begin(); tuple != dictionnaire.end(); tuple++) 
	{
		ParcoursGenome(tuple, a);
	}**/
	bool result = true;
	for (auto dic : dictionnaire)
	{
		result = true;
		for (auto mot : dic.second)
		{
			if (a.genome.mots.find(mot) == a.genome.mots.end())
			{
				result = false;
			}
		}
		a.resultats.insert(pair<string, bool>(dic.first, result));
	}
}

void ServiceAnalyse::ParcoursGenome(DICO_IT tuple, Analyse& a) {
	for (MOTS_IT i = (*tuple).second.begin(); i != (*tuple).second.end(); i++) 
	{
		for (GENO_IT gen = genStart; gen != genStop; gen++) 
		{
			if ((*i) == (*gen)) 
			{
				a.addResult((*tuple).first);
			}
		}
	}
}

set<string> ServiceAnalyse::getListeMaladies()
{
	//Utiliser un iterator pour parcourir toute la map. Renvoie un set correspondant a la liste des maladies.
	set<string> listeMaladies;
	for(DICO_IT i = dictionnaire.begin(); i!=dictionnaire.end(); i++)
	{
		listeMaladies.insert((*i).first);
	}
	return listeMaladies;
}


