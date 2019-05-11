#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <string>
#include <vector>
#include "Medecin.h"
#include "Infirmier.h"

using namespace std;

class Personnel
{
public:
	// Constructeur par defaut
	Personnel();

	// Destructeur
	~Personnel();
	
	// M�thodes publiques
	/***********************************************************************
	* Fonction : ajouterMedecin		                                       *
	* Description : Ajoute un m�decin au vecteur de m�decins               *
	* Param�tres : L'adresse du m�decin � ajouter                          *
	* Valeur de retour : Bool�en; true si le m�decin a �t� ajout� et donc  *
	*					 qu'il n'existait pas d�j� dans le vecteur         *
	***********************************************************************/
	bool ajouterMedecin(Medecin* medecin);

	/***********************************************************************
	* Fonction : retirerMedecin		                                       *
	* Description : Retire un m�decin du vecteur de m�decins               *
	* Param�tres : Le nom du m�decin � retirer                             *
	* Valeur de retour : Bool�en; true si le m�decin a �t� retir� et donc  *
	*					 qu'il se trouvait d�j� dans le vecteur            *
	***********************************************************************/
	bool retirerMedecin(const std::string& nom);

	/************************************************************************
	* Fonction : ajouterInfirmier	                                        *
	* Description : Ajoute un infirmier au vecteur d'infirmiers             *
	* Param�tres : L'adresse de l'infirmier � ajouter                       *
	* Valeur de retour : Bool�en; true si l'infirmier a �t� ajout� et donc  *
	*					 qu'il n'existait pas d�j� dans le vecteur          *
	************************************************************************/
	bool ajouterInfirmier(Infirmier* infirmier);

	/************************************************************************
	* Fonction : retirerInfirmier		                                    *
	* Description : Retire un infirmier du vecteur d'infirmiers             *
	* Param�tres : Le nom de l'infirmier � retirer                          *
	* Valeur de retour : Bool�en; true si l'infirmier a �t� retir� et donc  *
	*					 qu'il se trouvait d�j� dans le vecteur             *
	************************************************************************/
	bool retirerInfirmier(const std::string& nomComplet);

	// Surcharge d'op�rateurs 
	/**********************************************************
	* Fonction : Surcharge de l'op�rateur +=		          *
	* Description : Ajoute un m�decin au vecteur de m�decins  *
	* Param�tres : L'adresse du m�decin � ajouter             *
	* Valeur de retour : R�f�rence au Personnel d'un h�pital  *
	**********************************************************/
	Personnel& operator+=(Medecin* medecin);
	
	/**********************************************************
	* Fonction : Surcharge de l'op�rateur -=		          *
	* Description : Retire un m�decin au vecteur de m�decins  *
	* Param�tres : L'adresse du m�decin � retirer             *
	* Valeur de retour : R�f�rence au Personnel d'un h�pital  *
	**********************************************************/
	Personnel& operator-=(Medecin* medecin);
	
	/*************************************************************
	* Fonction : Surcharge de l'op�rateur +=		             *
	* Description : Ajoute un infirmier au vecteur d'infirmiers  *
	* Param�tres : L'adresse de l'infirmier � ajouter            *
	* Valeur de retour : R�f�rence au Personnel d'un h�pital     *
	*************************************************************/
	Personnel& operator+=(Infirmier* infirmier);
	
	/*************************************************************
	* Fonction : Surcharge de l'op�rateur -=		             *
	* Description : Retire un infirmier au vecteur d'infirmiers  *
	* Param�tres : L'adresse du m�decin � retirer                *
	* Valeur de retour : R�f�rence au Personnel d'un h�pital     *
	*************************************************************/
	Personnel& operator-=(Infirmier* infirmier);

	/***********************************************************************************************
	* Fonction : surcharge de l'op�rateur de flux de sortie <<									   *
	* Description : Permet d'afficher les informations du personnel selon un format donn�          *
	* Param�tres : Flux de sortie (stream) et le personnel dont les informations seront affich�es  *
	* Valeur de retour : R�f�rence au flux de sortie (appel en cascade)							   *
	***********************************************************************************************/
	friend ostream& operator<<(ostream& os, const Personnel& personnel);

private:
	vector<Medecin*> medecins_;
	vector<Infirmier*> infirmiers_;
};

#endif