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
	// Inutile de l'impl�menter dans ce cas car le compilateur en fournit un pareil
	// On consid�re une relation d'agr�gation Medecin-Specialite
	// i.e. une sp�cialit� peut-�tre partag�e par plusieurs m�decins

	// Si l'on avait cependant consid�r� une relation de composition Medecin-Specialite
	// le constructeur par copie serait d�fini comme suit :
	// Medecin::Medecin(const Medecin& medecin) : nom_(medecin.nom_), horaires_(medecin.horaires_), specialite_(nullptr)
	// { 
	//	specialite_ = new Specialite(*(medecin.specialite_));
	// }
}

Medecin::~Medecin()
{
	// Si l'on avait consid�r� une relation de composition Medecin-Specialite
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
	if (this != &medecin) { // Pour �viter l'autoaffectation de l'objet
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
