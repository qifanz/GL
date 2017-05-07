#pragma once
#include <string>
#include <list>
using namespace std;
class Genome
{
public:
	Genome(string nomFichierGenome);
	~Genome();
public :
	void afficher();
public:
	string version;
	list<string> genome;
};

