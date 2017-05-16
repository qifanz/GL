#include "stdafx.h"
#include "ApplicationMedicin.h"
#include <string>
#include <map>
#include <list>
#include "InterfaceHM.h"
#include "InterfaceClient.h"
using namespace std;


InterfaceHM::InterfaceHM()
{

}
InterfaceHM::~InterfaceHM()
{
}
void InterfaceHM::consulterResultatAnalyse(Analyse analyse) {
	/*analyse.afficher();*/
}
void InterfaceHM::consulterListAnalyse(std::list<Analyse> listanalyse) {
	/*list<Analyse>::const_iterator iterator;
	lit(listanalyse.begin()),
	lend(listanalyse.end());
	for (; lit != lend; ++lit) {
		lit.afficher();
	}*/
}

void InterfaceHM::demanderAnalyseGenerale(Analyse analyse) {

	interfaceClient.prepareMsgAnalyse(analyse);
}

void InterfaceHM : demanderAnalyseCiblee(Analyse analyse, string maladie);

	interfaceClient.prepareMsgAnalyse(analyse);
}
map<list<string>, string>  listerMaladies()  {
	/*map<list<string>, string>::iterator p;
	for (p = m.begin(); p != m.end(); p++)
	{	
		list<string> l = p->first;
		list<string>::const_iterator
			lit(l.begin()),
			lend(l.end());
		for (; lit != lend; ++lit) {
			cout << *lit << endl;
		}
		cout << p->second < endl;
		
	}*/
	interfaceClient.retournerListeMaladies();
}
