#include "stdafx.h"
#include "ServiceAnalyse.h"

// POUR LES ANALYSES :  Pour chaque pair parcouru, comparer la list de mots correspondante avec find() dans le multiset du génome. Rajouter un resultat dans l'analyse avec addResult(String maladie) pour chaque mot trouvé dans le génome. Seul le parcours change selon le type d'analyse.

void AnalyseCiblee(Analyse& a, string maladie)
{
	//Utiliser find pour trouver le pair<maladie,mots> pour la maladie donnée dans la map.
}

void AnalyseGenerale(Analyse& a)
{
	//Utiliser un iterator pour parcourir toute la map. Pour chaque pair, lancer une analyse ciblée
}

set<String> getListeMaladies()
{
	//Utiliser un iterator pour parcourir toute la map. Renvoie un set correspondant a la liste des maladies.
}

ServiceAnalyse::ServiceAnalyse()
{
}


ServiceAnalyse::~ServiceAnalyse()
{
}
