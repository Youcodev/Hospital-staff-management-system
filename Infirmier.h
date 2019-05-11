#ifndef INFIRMIER_H
#define INFIRMIER_H

#include <string>
#include <iostream>

class Infirmier
{
public:
	// Constructeur par d�faut
	Infirmier();

	// Constructeur par param�tres
	Infirmier(const std::string& nom, const std::string& prenom, unsigned int nbChambre);

	// Destructeur
	~Infirmier();

	// M�thodes d'acc�s aux attributs
	std::string obtenirNom() const; 
	std::string obtenirPrenom() const;
	unsigned int obtenirNbChambre() const;
	/*****************************************************************
	* Fonction : obtenirNomComplet						    		 *
	* Description :	Retourne le pr�nom suivi du nom d'un infirmier   *
	* Param�tres : aucun                                		     *
	* Valeur de retour : string									     *
	*****************************************************************/
	std::string obtenirNomComplet() const;

	// M�thodes de modification des attributs
	void modifierNom(const std::string& nom);
	void modifierPrenom(const std::string& prenom);
	void modifierNbChambre(unsigned int nbChambre);

	// Surcharge d'op�rateurs
	/**********************************************************************************************
	* Fonction : Surcharge de l'op�rateur de flux de sortie <<									  *
	* Description : Permet d'afficher les informations d'un infirmier selon un format donn�       *
	* Param�tres : Flux de sortie (stream) et l'infirmier dont les informations seront affich�es  *
	* Valeur de retour : R�f�rence au flux de sortie (appel en cascade)							  *
	**********************************************************************************************/
	friend std::ostream& operator<<(std::ostream&, const Infirmier&);

	/**********************************************************************************************
	* Fonction : Surcharge de l'op�rateur de comparaison ==										  *
	* Param�tres : L'infirmier � comparer (avec celui qui sera appliqu� � la fonction op�rateur)  *
	* Description : V�rifie l'�galit� entre deux infirmiers en comparant leurs noms et pr�noms    *
	* Valeur de retour : Bool�en; true si les deux infirmiers ont le m�me nom et le m�me pr�nom	  *
	**********************************************************************************************/
	bool operator==(const Infirmier&) const;

	/**************************************************************************
	* Fonction : Surcharge de l'op�rateur de comparaison ==					  *
	* Description : V�rifie l'�galit� entre un infirmier et un nom complet    *
	* Param�tres : Le nom complet auquel un infirmier sera compar�            *
	* Valeur de retour : Bool�en; true si l'infirmier poss�de ce nom complet  *
	**************************************************************************/
	bool operator==(const std::string&) const;

	/*******************************************************************************
	* Fonction : Surcharge de l'op�rateur de comparaison ==					       *
	* Description : V�rifie l'�galit� entre un nom complet et un infirmier         *
	* Param�tres : Le nom complet et l'infirmier auquel il sera compar�            *
	* Valeur de retour : Bool�en; true si le nom complet est celui de l'infirmier  *
	*******************************************************************************/
	friend bool operator==(const std::string&, const Infirmier&);

private:
	std::string nom_;
	std::string prenom_;
	unsigned int nbChambre_;
};

#endif
