#include "stdafx.h"
#include "Genome.h"
#include <string>
#include <list>
#include <iostream>
#include <fstream>
using namespace std;
Genome::Genome() {
	version = "1.1";
};
Genome::Genome(CString nomFichierGenome)
{
	ifstream fichier(nomFichierGenome, ios::in);
	if (fichier)
	{

		getline(fichier, version);
		if (!strstr(version.c_str(), ("MA v"))) {
			AfxMessageBox((CString)("Ce n'est pas un fichier correct!!\r\n"));
			fichier.close();
		}
		else {
			string mot;
			while (getline(fichier, mot)) {
				mots.insert(mot);
				TRACE(mot.c_str());

			}
			AfxMessageBox((CString)"Genome charge\r\n");
			fichier.close();
		}
	}
	else
	{
		AfxMessageBox((CString)("Impossible d'ouvrir le fichier!\r\n"));
	}
}



Genome::~Genome()
{
}

void Genome::afficher()
{
	cout << version << endl;
	multiset<string>::const_iterator
		msit(mots.begin()),
		msend(mots.end());
	for (; msit != msend; ++msit) {
		cout << *msit << endl;
	}
}

string Genome::getVersion()
{
	return version;
}