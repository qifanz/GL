#include "stdafx.h"
#include "Analyse.h"
#include <iostream>
using namespace std;


Analyse::Analyse(Genome genome, string type, string version) : genome(genome), type(type), version(version)
{
}


Analyse::~Analyse()
{
}

void Analyse::addResult(string maladie, bool resultat)
{
	map<string, bool>::iterator it;
	it = resultats.find(maladie);
	if (it != resultats.end()) {
		it->second = resultat;
	}
	else {
		resultats.insert(pair<string, bool>(maladie, resultat));
	}
}

void Analyse::afficher()
{
	cout << version << endl << type << endl;
	for (map<string, bool>::iterator it = resultats.begin(); it != resultats.end(); ++it)
	{
		cout << it->first << " : ";
		if (it->second) {
			cout << "oui" << endl;
		}
		else {
			cout << "non" << endl;
		}
	}
}

Genome Analyse::getGenome()
{
	return genome;
}
