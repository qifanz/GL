#pragma once
#include <string>
#include <set>

using namespace std;
class Genome
{
public:
	Genome(string nomFichierGenome);
	~Genome();
public:
	void afficher();
public:
	string version;
	multiset<string> mots;
};

