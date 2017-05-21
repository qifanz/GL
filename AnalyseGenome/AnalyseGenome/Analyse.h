#pragma once
#include <string>
#include <map>
#include "Genome.h"
using namespace std;
class Analyse
{
public:
	Analyse();
	Analyse(Genome genome, string type, string version);
	Analyse(const Analyse& analyse);
	~Analyse();

public:
	void addResult(string maladie);
	friend ostream& operator<<(ostream &flux, Analyse const& analyse);
	void afficher(ostream &flux) const;
	Genome getGenome();

public:
	string type;
	string version;
	map<string, bool> resultats;
	Genome genome;
};

