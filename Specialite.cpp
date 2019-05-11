#include "Specialite.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

Specialite::Specialite(): domaine_(" "), niveau_(0)
{
}

Specialite::Specialite(const std::string & domaine, unsigned int niveau): domaine_(domaine), niveau_(niveau)
{
}

std::string Specialite::obtenirDomaine() const
{
	return domaine_;
}

unsigned int Specialite::obtenirNiveau() const
{
	return niveau_;
}

void Specialite::modifierDomaine(const std::string & domaine)
{
	domaine_ = domaine;
}

void Specialite::modifierNiveau(unsigned int niveau)
{
	niveau_ = niveau;
}

std::ostream& operator<<(std::ostream& os, const Specialite& specialite)
{
	os << " | " << specialite.domaine_ << AFFICHER_ESPACE(espace_domaine - specialite.domaine_.size());
	os << " | " << AFFICHER_ESPACE(espace_niveau - std::to_string(specialite.niveau_).size()) << specialite.niveau_;
	os << AFFICHER_ESPACE(espace_niveau) << " | ";
	return os;
}
