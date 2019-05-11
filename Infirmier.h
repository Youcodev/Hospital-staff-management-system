#ifndef INFIRMIER_H
#define INFIRMIER_H

#include <string>
#include <iostream>

class Infirmier
{
public:
	// Constructeur par défaut
	Infirmier();

	// Constructeur par paramètres
	Infirmier(const std::string& nom, const std::string& prenom, unsigned int nbChambre);

	// Destructeur
	~Infirmier();

	// Méthodes d'accès aux attributs
	std::string obtenirNom() const; 
	std::string obtenirPrenom() const;
	unsigned int obtenirNbChambre() const;
	/*****************************************************************
	* Fonction : obtenirNomComplet						    		 *
	* Description :	Retourne le prénom suivi du nom d'un infirmier   *
	* Paramètres : aucun                                		     *
	* Valeur de retour : string									     *
	*****************************************************************/
	std::string obtenirNomComplet() const;

	// Méthodes de modification des attributs
	void modifierNom(const std::string& nom);
	void modifierPrenom(const std::string& prenom);
	void modifierNbChambre(unsigned int nbChambre);

	// Surcharge d'opérateurs
	/**********************************************************************************************
	* Fonction : Surcharge de l'opérateur de flux de sortie <<									  *
	* Description : Permet d'afficher les informations d'un infirmier selon un format donné       *
	* Paramètres : Flux de sortie (stream) et l'infirmier dont les informations seront affichées  *
	* Valeur de retour : Référence au flux de sortie (appel en cascade)							  *
	**********************************************************************************************/
	friend std::ostream& operator<<(std::ostream&, const Infirmier&);

	/**********************************************************************************************
	* Fonction : Surcharge de l'opérateur de comparaison ==										  *
	* Paramètres : L'infirmier à comparer (avec celui qui sera appliqué à la fonction opérateur)  *
	* Description : Vérifie l'égalité entre deux infirmiers en comparant leurs noms et prénoms    *
	* Valeur de retour : Booléen; true si les deux infirmiers ont le même nom et le même prénom	  *
	**********************************************************************************************/
	bool operator==(const Infirmier&) const;

	/**************************************************************************
	* Fonction : Surcharge de l'opérateur de comparaison ==					  *
	* Description : Vérifie l'égalité entre un infirmier et un nom complet    *
	* Paramètres : Le nom complet auquel un infirmier sera comparé            *
	* Valeur de retour : Booléen; true si l'infirmier possède ce nom complet  *
	**************************************************************************/
	bool operator==(const std::string&) const;

	/*******************************************************************************
	* Fonction : Surcharge de l'opérateur de comparaison ==					       *
	* Description : Vérifie l'égalité entre un nom complet et un infirmier         *
	* Paramètres : Le nom complet et l'infirmier auquel il sera comparé            *
	* Valeur de retour : Booléen; true si le nom complet est celui de l'infirmier  *
	*******************************************************************************/
	friend bool operator==(const std::string&, const Infirmier&);

private:
	std::string nom_;
	std::string prenom_;
	unsigned int nbChambre_;
};

#endif
