#include "stdafx.h"
#include "ServiceAnalyse.h"

// POUR LES ANALYSES :  Pour chaque pair parcouru, comparer la list de mots correspondante avec find() dans le multiset du génome. Rajouter un resultat dans l'analyse avec addResult(String maladie) pour chaque mot trouvé dans le génome. Seul le parcours change selon le type d'analyse.

void ServiceAnalyse::AnalyseCiblee(Analyse& a, string maladie)
{
	//Utiliser find pour trouver le pair<maladie,mots> pour la maladie donnée dans la map.
	genStart = a.genome.mots.begin;
	genStop = a.genome.mots.end;
	DICO_IT tuple = dictionnaire.find(maladie);
	ParcoursGenome(tuple, a);
}

void ServiceAnalyse::AnalyseGenerale(Analyse& a)
{
	//Utiliser un iterator pour parcourir toute la map. Pour chaque pair, lancer une analyse
	genStart = a.genome.mots.begin;
	genStop = a.genome.mots.end;
	for (DICO_IT tuple = dictionnaire.begin; tuple != dictionnaire.end; tuple++) 
	{
		ParcoursGenome(tuple, a);
	}
}

void ServiceAnalyse::ParcoursGenome(DICO_IT tuple, Analyse& a) {
	for (MOTS_IT i = (*tuple).second.begin; i != (*tuple).second.end; i++) 
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
	for(DICO_IT i = dictionnaire.begin; i!=dictionnaire.end; i++)
	{
		listeMaladies.insert((*i).first);
	}
	return listeMaladies;
}

ServiceAnalyse::ServiceAnalyse()
{
}


ServiceAnalyse::~ServiceAnalyse()
{
}
