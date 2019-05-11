#include "Medecin.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

Medecin::Medecin(const string& nom): nom_(nom), horaires_(0), specialite_(nullptr)
{
}

Medecin::Medecin(const string& nom, int horaires, Specialite* specialite): 
	nom_(nom), horaires_(horaires), specialite_(specialite)
{
}

Medecin::Medecin(const Medecin& medecin) : nom_(medecin.nom_), horaires_(medecin.horaires_), specialite_(medecin.specialite_)
{
	// Inutile de l'implémenter dans ce cas car le compilateur en fournit un pareil
	// On considère une relation d'agrégation Medecin-Specialite
	// i.e. une spécialité peut-être partagée par plusieurs médecins

	// Si l'on avait cependant considéré une relation de composition Medecin-Specialite
	// le constructeur par copie serait défini comme suit :
	// Medecin::Medecin(const Medecin& medecin) : nom_(medecin.nom_), horaires_(medecin.horaires_), specialite_(nullptr)
	// { 
	//	specialite_ = new Specialite(*(medecin.specialite_));
	// }
}

Medecin::~Medecin()
{
	// Si l'on avait considéré une relation de composition Medecin-Specialite
	// le destructeur aurait contenu l'instruction suivante :
	// delete specialite_;
}

string Medecin::obtenirNom() const
{
	return nom_;
}

int Medecin::obtenirHoraires() const
{
	return horaires_;
}

Specialite Medecin::obtenirSpecialite() const
{
	return *specialite_;
}

void Medecin::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Medecin::modifierHoraires(int horaires)
{
	horaires_ = horaires;
}

void Medecin::modifierSpecialite(Specialite* specialite)
{
	specialite_ = specialite;
}

ostream& operator<<(ostream& os, const Medecin& medecin)
{
	os << "| " << medecin.nom_ << AFFICHER_ESPACE(espace_nom - medecin.nom_.size());
	os << " | " << AFFICHER_ESPACE(espace_horaires - std::to_string(medecin.horaires_).size()) << medecin.horaires_;
	os << AFFICHER_ESPACE(espace_horaires) << medecin.obtenirSpecialite();
	os << endl;
	return os;
}

Medecin& Medecin::operator=(const Medecin& medecin)
{
	if (this != &medecin) { // Pour éviter l'autoaffectation de l'objet
		nom_ = medecin.nom_;
		horaires_ = medecin.horaires_;
		specialite_ = medecin.specialite_; // La classe Medecin n'est pas responsable de la destruction de la classe											Specialite
	}
	return *this;
}

bool Medecin::operator==(const Medecin& medecin) const {
	return(nom_ == medecin.nom_);
}

bool Medecin::operator==(const std::string& nom) const {
	return(nom_ == nom);
}

bool operator==(const std::string& nom, const Medecin& medecin) {
	return(medecin == nom);
}
