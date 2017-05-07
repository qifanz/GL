#pragma once
#include <string>
#include <map>
#include "Genome.h"
using namespace std;
class Analyse
{
public:
	Analyse(Genome genome, string type, string version);
	~Analyse();

public:
	void addResult(string maladie, bool resultat);
	void afficher();

public:
	string type;
	string version;
	map<string, bool> resultats;
	Genome genome;
};

