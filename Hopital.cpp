#include "Hopital.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

Hopital::Hopital(string nom, Personnel* personnel) : nom_(nom), personnel_(personnel) {}

string Hopital::obtenirNom() const { return nom_; }
Personnel* Hopital::obtenirPersonnel() const { return personnel_; }

void Hopital::modifierNom(string nom) { nom_ = nom; }
void Hopital::modifierPersonnel(Personnel* personnel) { personnel_ = personnel; }

ostream& operator<<(ostream& os, const Hopital& hopital) {
	os << endl << endl << endl;
	os << AFFICHER_ESPACE(espacement_hopital / 2) << hopital.nom_
		<< AFFICHER_ESPACE(espacement_hopital / 2) << endl;
	os << AFFICHER_EGALE(espacement_hopital + hopital.nom_.size()) << endl;
	os << *(hopital.personnel_) << endl;
	os << AFFICHER_EGALE(espacement_hopital + hopital.nom_.size()) << endl;
	return os;
}