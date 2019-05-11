#ifndef MEDECIN_H
#define MEDECIN_H

#include <string>
#include "Specialite.h"

using namespace std;

class Medecin 
{
public:
	// Constructeurs par param�tres
	Medecin(const string& nom);
	Medecin(const string& nom, int horaires, Specialite* specialite);

	// Contructeur par copie
	Medecin(const Medecin&);

	// Destructeur
	~Medecin();
	
	// M�thodes d'acc�s aux attributs
	string obtenirNom() const;
	int obtenirHoraires() const;
	Specialite obtenirSpecialite() const;
	
	// M�thodes de modification des attributs
	void modifierNom(const string& nom);
	void modifierHoraires(int horaires);
	void modifierSpecialite(Specialite* specialite);

	// Srucharge d'op�rateurs
	/*********************************************************************************************
	* Fonction : surcharge de l'op�rateur de flux de sortie <<									 *
	* Description : Permet d'afficher les informations d'un m�decin selon un format donn�        *
	* Param�tres : Flux de sortie (stream) et le m�decin dont les informations seront affich�es  *
	* Valeur de retour : R�f�rence au flux de sortie (appel en cascade)							 *
	*********************************************************************************************/
	friend ostream& operator<<(ostream&, const Medecin&);

	/***********************************************************************************************************
	* Fonction : surcharge de l'op�rateur d'affectation =    									               *
	* Description : Affecte un m�decin � un autre                                                              *
	* Param�tres : Le m�decin qui sera affect� (� celui se trouvant � gauche de l'�galit�)                     *
	* Valeur de retour : R�f�rence au flux de sortie (appel en cascade)	                                       *
	* Note : Lors d'une affectation, l'objet � gauche de l'�galit� sera �cras� par celui � droite de celle-ci  *
	***********************************************************************************************************/
	Medecin& operator=(const Medecin&);

	/***************************************************************************************************
	* Fonction : Surcharge de l'op�rateur de comparaison ==										       *
	* Description : V�rifie l'�galit� entre deux m�decins en comparant leurs noms respectifs           *
	* Param�tres : Le m�decin � comparer (avec celui qui sera appliqu� � la fonction; objet de gauche) *
	* Valeur de retour : Bool�en; true si les deux m�decins ont le m�me nom                  	       *
	***************************************************************************************************/
	bool operator==(const Medecin&) const;

	/*****************************************************************
	* Fonction : Surcharge de l'op�rateur de comparaison ==	         *
	* Description : V�rifie l'�galit� entre un m�decin et un nom     *
	* Param�tres : Le nom auquel un m�decin sera compar�             *
	* Valeur de retour : Bool�en; true si le m�decin poss�de ce nom  *
	*****************************************************************/
	bool operator==(const std::string&) const;

	/********************************************************************
	* Fonction : Surcharge de l'op�rateur de comparaison ==			    *
	* Description : V�rifie l'�galit� entre un nom et un m�decin        *
	* Param�tres : Le nom et le m�decin auquel il sera compar�          *
	* Valeur de retour : Bool�en; true si le nom est celui du m�decin   *
	********************************************************************/
	friend bool operator==(const std::string&, const Medecin&);

private:
	string nom_;
	int horaires_;
	Specialite* specialite_;
};

#endif