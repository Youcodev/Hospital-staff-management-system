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
	
	// Méthodes publiques
	/***********************************************************************
	* Fonction : ajouterMedecin		                                       *
	* Description : Ajoute un médecin au vecteur de médecins               *
	* Paramètres : L'adresse du médecin à ajouter                          *
	* Valeur de retour : Booléen; true si le médecin a été ajouté et donc  *
	*					 qu'il n'existait pas déjà dans le vecteur         *
	***********************************************************************/
	bool ajouterMedecin(Medecin* medecin);

	/***********************************************************************
	* Fonction : retirerMedecin		                                       *
	* Description : Retire un médecin du vecteur de médecins               *
	* Paramètres : Le nom du médecin à retirer                             *
	* Valeur de retour : Booléen; true si le médecin a été retiré et donc  *
	*					 qu'il se trouvait déjà dans le vecteur            *
	***********************************************************************/
	bool retirerMedecin(const std::string& nom);

	/************************************************************************
	* Fonction : ajouterInfirmier	                                        *
	* Description : Ajoute un infirmier au vecteur d'infirmiers             *
	* Paramètres : L'adresse de l'infirmier à ajouter                       *
	* Valeur de retour : Booléen; true si l'infirmier a été ajouté et donc  *
	*					 qu'il n'existait pas déjà dans le vecteur          *
	************************************************************************/
	bool ajouterInfirmier(Infirmier* infirmier);

	/************************************************************************
	* Fonction : retirerInfirmier		                                    *
	* Description : Retire un infirmier du vecteur d'infirmiers             *
	* Paramètres : Le nom de l'infirmier à retirer                          *
	* Valeur de retour : Booléen; true si l'infirmier a été retiré et donc  *
	*					 qu'il se trouvait déjà dans le vecteur             *
	************************************************************************/
	bool retirerInfirmier(const std::string& nomComplet);

	// Surcharge d'opérateurs 
	/**********************************************************
	* Fonction : Surcharge de l'opérateur +=		          *
	* Description : Ajoute un médecin au vecteur de médecins  *
	* Paramètres : L'adresse du médecin à ajouter             *
	* Valeur de retour : Référence au Personnel d'un hôpital  *
	**********************************************************/
	Personnel& operator+=(Medecin* medecin);
	
	/**********************************************************
	* Fonction : Surcharge de l'opérateur -=		          *
	* Description : Retire un médecin au vecteur de médecins  *
	* Paramètres : L'adresse du médecin à retirer             *
	* Valeur de retour : Référence au Personnel d'un hôpital  *
	**********************************************************/
	Personnel& operator-=(Medecin* medecin);
	
	/*************************************************************
	* Fonction : Surcharge de l'opérateur +=		             *
	* Description : Ajoute un infirmier au vecteur d'infirmiers  *
	* Paramètres : L'adresse de l'infirmier à ajouter            *
	* Valeur de retour : Référence au Personnel d'un hôpital     *
	*************************************************************/
	Personnel& operator+=(Infirmier* infirmier);
	
	/*************************************************************
	* Fonction : Surcharge de l'opérateur -=		             *
	* Description : Retire un infirmier au vecteur d'infirmiers  *
	* Paramètres : L'adresse du médecin à retirer                *
	* Valeur de retour : Référence au Personnel d'un hôpital     *
	*************************************************************/
	Personnel& operator-=(Infirmier* infirmier);

	/***********************************************************************************************
	* Fonction : surcharge de l'opérateur de flux de sortie <<									   *
	* Description : Permet d'afficher les informations du personnel selon un format donné          *
	* Paramètres : Flux de sortie (stream) et le personnel dont les informations seront affichées  *
	* Valeur de retour : Référence au flux de sortie (appel en cascade)							   *
	***********************************************************************************************/
	friend ostream& operator<<(ostream& os, const Personnel& personnel);

private:
	vector<Medecin*> medecins_;
	vector<Infirmier*> infirmiers_;
};

#endif