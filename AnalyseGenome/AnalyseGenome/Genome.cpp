#include "stdafx.h"
#include "Genome.h"
#include <string>
#include <list>
#include <iostream>
#include <fstream>
using namespace std;

Genome::Genome(string nomFichierGenome)
{
	ifstream fichier(nomFichierGenome, ios::in);
	if (fichier)
	{
		getline(fichier, version);
		string mot;
		while (getline(fichier, mot)) {
			genome.push_back(mot);
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

void Genome::afficher()
{
	cout << version << endl;
	list<string>::const_iterator
		lit(genome.begin()),
		lend(genome.end());
	for (; lit != lend; ++lit) {
		cout << *lit << endl;
	}
}

