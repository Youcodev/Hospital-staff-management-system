#include "Infirmier.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

Infirmier::Infirmier(): nom_(" "), prenom_(" "), nbChambre_(0)
{
}

Infirmier::Infirmier(const std::string & nom, const std::string & prenom, unsigned int nbChambre): 
	nom_(nom), prenom_(prenom), nbChambre_(nbChambre)
{
}

Infirmier::~Infirmier()
{
}

std::string Infirmier::obtenirNom() const
{
	return nom_;
}

std::string Infirmier::obtenirPrenom() const
{
	return prenom_;
}

unsigned int Infirmier::obtenirNbChambre() const
{
	return nbChambre_;
}

std::string Infirmier::obtenirNomComplet() const {
	return(prenom_ + " " + nom_);
}

void Infirmier::modifierNom(const std::string & nom)
{
	nom_ = nom;
}

void Infirmier::modifierPrenom(const std::string & prenom)
{
	prenom_ = prenom;
}

void Infirmier::modifierNbChambre(unsigned int nbChambre)
{
	nbChambre_ = nbChambre;
}

std::ostream& operator<<(std::ostream& os, const Infirmier& infirmier)
{
	os << "| " << infirmier.obtenirNomComplet() << AFFICHER_ESPACE(espace_nom - infirmier.obtenirNomComplet().size());
	os << " | " << AFFICHER_ESPACE(espace_chambre - std::to_string(infirmier.nbChambre_).size()/2);
	os << infirmier.nbChambre_ << AFFICHER_ESPACE(espace_chambre);
	os << "|" << std::endl;
	return os;
}

bool Infirmier::operator==(const Infirmier& infirmier) const {
	return(nom_ == infirmier.nom_ && prenom_ == infirmier.prenom_);
}

bool Infirmier::operator==(const std::string& nc) const {
	return(obtenirNomComplet() == nc);
}

bool operator==(const std::string& nc, const Infirmier& infirmier) {
	return(infirmier == nc);
}