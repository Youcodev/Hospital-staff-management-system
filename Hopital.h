#ifndef HOPITAL_H
#define HOPITAL_H

#include <string>
#include "Personnel.h"

class Hopital {
public:
	// Constructeur par paramètres
	Hopital(string, Personnel*);

	// Méthodes d'accès aux attributs
	string obtenirNom() const;
	Personnel* obtenirPersonnel() const;

	// Méthodes de modification des attributs
	void modifierNom(string);
	void modifierPersonnel(Personnel*);

	// Méthode d'affichage
	/***********************************************************************************************
	* Fonction : surcharge de l'opérateur de flux de sortie <<									   *
	* Description : Permet d'afficher les informations d'un hôpital selon un format donné          *
	* Paramètres : Flux de sortie (stream) et l'hôpital dont les informations seront affichées     *
	* Valeur de retour : Référence au flux de sortie (appel en cascade)							   *
	***********************************************************************************************/
	friend ostream& operator<<(ostream&, const Hopital&);

private:
	string nom_;
	Personnel* personnel_;
};



#endif