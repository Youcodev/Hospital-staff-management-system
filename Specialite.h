#ifndef SPECIALITE_H
#define SPECIALITE_H

#include <string>
#include <iostream>

class Specialite
{
public:
	// Constructeur par défaut
	Specialite();

	// Constructeur par paramètres
	Specialite(const std::string& domaine, unsigned int niveau);

	// Méthodes d'accès aux attributs
	std::string obtenirDomaine() const;
	unsigned int obtenirNiveau() const;

	// Méthodes de modification des attributs
	void modifierDomaine(const std::string& domaine);
	void modifierNiveau(unsigned int niveau);

	/************************************************************************************************
	* Fonction : Surcharge de l'opérateur de flux de sortie <<									    *
	* Description : Permet d'afficher les informations d'une spécialité selon un format donné       *
	* Paramètres : Flux de sortie (stream) et la spécialité dont les informations seront affichées  *
	* Valeur de retour : Référence au flux de sortie (appel en cascade)							    *
	************************************************************************************************/
	friend std::ostream& operator<<(std::ostream&, const Specialite&);

private:
	std::string domaine_;
	unsigned int niveau_;
};

#endif