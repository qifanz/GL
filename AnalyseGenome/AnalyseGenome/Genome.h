#pragma once
#include <string>
#include <set>

using namespace std;
class Genome
{
public:
	Genome();
	Genome(string nomFichierGenome);
	Genome(const Genome& g);
	~Genome();
public:
	friend ostream& operator<<(ostream &flux, Genome const& genome);
	void afficher(ostream &flux) const;
public:
	string version;
	multiset<string> mots;
};

