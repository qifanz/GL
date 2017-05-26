#pragma once
#include <string>
#include <set>

using namespace std;
class Genome
{
public:
	Genome();
	Genome(CString nomFichierGenome);
	~Genome();
	void afficher();
	string getVersion();

public:
	multiset<string> mots;
	
private :
	string version;
};
