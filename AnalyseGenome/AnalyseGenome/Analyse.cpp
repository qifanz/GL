#include "stdafx.h"
#include "Analyse.h"
#include <iostream>
using namespace std;


Analyse::Analyse()
{
	version = "1.0";
}

Analyse::Analyse(Genome genome, string type, string version) : genome(genome), type(type), version(version)
{
}

Analyse::Analyse(const Analyse & analyse):type(analyse.type),version(analyse.version),genome(analyse.genome)
{
	for (auto res : analyse.resultats)
	{
		resultats.insert(res);
	}
}


Analyse::~Analyse()
{
}


ostream & operator<<(ostream & flux, Analyse const & analyse)
{
	analyse.afficher(flux);
	return flux;
}

void Analyse::afficher(ostream &flux) const
{
	flux << version << endl << type << endl;
	for (map<string, bool>::const_iterator it = resultats.begin(); it != resultats.end(); ++it)
	{
		flux << it->first << " : ";
		if (it->second) {
			flux << "oui" << endl;
		}
		else {
			flux << "non" << endl;
		}
	}
}

Genome Analyse::getGenome()
{
	return genome;
}

