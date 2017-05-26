#pragma once
#include <string>
#include <map>
#include "Genome.h"
using namespace std;
class Analyse
{
public:
	Analyse();
	Analyse(Genome genome, string type);
	~Analyse();

	friend ostream& operator<<(ostream &flux, Analyse const& analyse);
	void afficher(ostream &flux) const;
	string getVersion();

public:
	map<string, bool> resultats;
	Genome genome;
	string type;

private :
	string version;

};

