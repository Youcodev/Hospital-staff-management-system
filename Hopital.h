#ifndef HOPITAL_H
#define HOPITAL_H

#include <string>
#include "Personnel.h"

class Hopital {
public:
	// Constructeur par param�tres
	Hopital(string, Personnel*);

	// M�thodes d'acc�s aux attributs
	string obtenirNom() const;
	Personnel* obtenirPersonnel() const;

	// M�thodes de modification des attributs
	void modifierNom(string);
	void modifierPersonnel(Personnel*);

	// M�thode d'affichage
	/***********************************************************************************************
	* Fonction : surcharge de l'op�rateur de flux de sortie <<									   *
	* Description : Permet d'afficher les informations d'un h�pital selon un format donn�          *
	* Param�tres : Flux de sortie (stream) et l'h�pital dont les informations seront affich�es     *
	* Valeur de retour : R�f�rence au flux de sortie (appel en cascade)							   *
	***********************************************************************************************/
	friend ostream& operator<<(ostream&, const Hopital&);

private:
	string nom_;
	Personnel* personnel_;
};



#endif