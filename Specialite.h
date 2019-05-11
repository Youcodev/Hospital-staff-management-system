#ifndef SPECIALITE_H
#define SPECIALITE_H

#include <string>
#include <iostream>

class Specialite
{
public:
	// Constructeur par d�faut
	Specialite();

	// Constructeur par param�tres
	Specialite(const std::string& domaine, unsigned int niveau);

	// M�thodes d'acc�s aux attributs
	std::string obtenirDomaine() const;
	unsigned int obtenirNiveau() const;

	// M�thodes de modification des attributs
	void modifierDomaine(const std::string& domaine);
	void modifierNiveau(unsigned int niveau);

	/************************************************************************************************
	* Fonction : Surcharge de l'op�rateur de flux de sortie <<									    *
	* Description : Permet d'afficher les informations d'une sp�cialit� selon un format donn�       *
	* Param�tres : Flux de sortie (stream) et la sp�cialit� dont les informations seront affich�es  *
	* Valeur de retour : R�f�rence au flux de sortie (appel en cascade)							    *
	************************************************************************************************/
	friend std::ostream& operator<<(std::ostream&, const Specialite&);

private:
	std::string domaine_;
	unsigned int niveau_;
};

#endif