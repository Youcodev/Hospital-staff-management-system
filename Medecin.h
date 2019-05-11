#ifndef MEDECIN_H
#define MEDECIN_H

#include <string>
#include "Specialite.h"

using namespace std;

class Medecin 
{
public:
	// Constructeurs par paramètres
	Medecin(const string& nom);
	Medecin(const string& nom, int horaires, Specialite* specialite);

	// Contructeur par copie
	Medecin(const Medecin&);

	// Destructeur
	~Medecin();
	
	// Méthodes d'accès aux attributs
	string obtenirNom() const;
	int obtenirHoraires() const;
	Specialite obtenirSpecialite() const;
	
	// Méthodes de modification des attributs
	void modifierNom(const string& nom);
	void modifierHoraires(int horaires);
	void modifierSpecialite(Specialite* specialite);

	// Srucharge d'opérateurs
	/*********************************************************************************************
	* Fonction : surcharge de l'opérateur de flux de sortie <<									 *
	* Description : Permet d'afficher les informations d'un médecin selon un format donné        *
	* Paramètres : Flux de sortie (stream) et le médecin dont les informations seront affichées  *
	* Valeur de retour : Référence au flux de sortie (appel en cascade)							 *
	*********************************************************************************************/
	friend ostream& operator<<(ostream&, const Medecin&);

	/***********************************************************************************************************
	* Fonction : surcharge de l'opérateur d'affectation =    									               *
	* Description : Affecte un médecin à un autre                                                              *
	* Paramètres : Le médecin qui sera affecté (à celui se trouvant à gauche de l'égalité)                     *
	* Valeur de retour : Référence au flux de sortie (appel en cascade)	                                       *
	* Note : Lors d'une affectation, l'objet à gauche de l'égalité sera écrasé par celui à droite de celle-ci  *
	***********************************************************************************************************/
	Medecin& operator=(const Medecin&);

	/***************************************************************************************************
	* Fonction : Surcharge de l'opérateur de comparaison ==										       *
	* Description : Vérifie l'égalité entre deux médecins en comparant leurs noms respectifs           *
	* Paramètres : Le médecin à comparer (avec celui qui sera appliqué à la fonction; objet de gauche) *
	* Valeur de retour : Booléen; true si les deux médecins ont le même nom                  	       *
	***************************************************************************************************/
	bool operator==(const Medecin&) const;

	/*****************************************************************
	* Fonction : Surcharge de l'opérateur de comparaison ==	         *
	* Description : Vérifie l'égalité entre un médecin et un nom     *
	* Paramètres : Le nom auquel un médecin sera comparé             *
	* Valeur de retour : Booléen; true si le médecin possède ce nom  *
	*****************************************************************/
	bool operator==(const std::string&) const;

	/********************************************************************
	* Fonction : Surcharge de l'opérateur de comparaison ==			    *
	* Description : Vérifie l'égalité entre un nom et un médecin        *
	* Paramètres : Le nom et le médecin auquel il sera comparé          *
	* Valeur de retour : Booléen; true si le nom est celui du médecin   *
	********************************************************************/
	friend bool operator==(const std::string&, const Medecin&);

private:
	string nom_;
	int horaires_;
	Specialite* specialite_;
};

#endif