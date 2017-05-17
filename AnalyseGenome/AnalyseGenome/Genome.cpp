#include "stdafx.h"
#include "Genome.h"
#include <string>
#include <list>
#include <iostream>
#include <fstream>
using namespace std;

Genome::Genome()
{
}

Genome::Genome(string nomFichierGenome)
{
	ifstream fichier(nomFichierGenome, ios::in);
	if (fichier)
	{
		getline(fichier, version);
		string mot;
		while (getline(fichier, mot)) {
			mots.insert(mot);
		}
		cout << "Genome créé" << endl;
		fichier.close();
	}
	else
	{
		cerr << "Impossible d'ouvrir le fichier!" << endl;
	}
}


Genome::~Genome()
{
}

ostream & operator<<(ostream & flux, Genome const & genome)
{
	genome.afficher(flux);
	return flux;
}

void Genome::afficher(ostream &flux) const
{
	flux << version << endl;
	multiset<string>::const_iterator
		msit(mots.begin()),
		msend(mots.end());
	for (; msit != msend; ++msit) {
		flux << *msit << endl;
	}
}

