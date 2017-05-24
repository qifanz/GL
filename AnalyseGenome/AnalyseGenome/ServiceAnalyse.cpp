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
		TRACE("Genome cr¨¦¨¦\r\n");
		fichier.close();
	}
	else
	{
		TRACE("Impossible d'ouvrir le fichier!\r\n");
	}
}


void ServiceAnalyse::AnalyseCiblee(Analyse& a, string maladie)
//Utiliser find pour trouver le pair<maladie,mots> pour la maladie donnée dans la map.
{
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
//Utiliser un auto pour parcourir toute la map. Pour chaque pair, lancer une analyse
{
	bool result;
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

set<string> ServiceAnalyse::getListeMaladies()
{
	//Utiliser un auto pour parcourir toute la map. Renvoie un set correspondant a la liste des maladies.
	set<string> listeMaladies;
	for (auto maladie : dictionnaire)
	{
		listeMaladies.insert(maladie.first);
	}
	return listeMaladies;
}


