#include "Medecin.h"
#include "Infirmier.h"
#include "Personnel.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

Personnel::Personnel() {}

Personnel::~Personnel() {
// rien � faire si l'on avait consid�r� une relation d'agr�gation Personnel-Medecin/Infirmier

	// Dans le cas pr�sent o� l'on consid�re une relation de composition Personnel-Medecin/Infirmier
	// On d�truit les objets m�decins

	for (unsigned int i = 0; i < medecins_.size(); ++i)
		delete medecins_[i];
	medecins_.clear();
	
	// Et les objets infirmiers
	for (unsigned int i = 0; i < infirmiers_.size(); ++i)
		delete infirmiers_[i];
	infirmiers_.clear();
}
	
bool Personnel::ajouterMedecin(Medecin* medecin)  
{
	for (unsigned int i = 0; i < medecins_.size(); ++i) {
		if (*medecins_[i] == *medecin) // si le m�decin pass� en param�tre existe dans le vecteur de m�decins
			return false; // il ne sera pas �t� ajout�
	}
	medecins_.push_back(medecin); // sinon, on l'y ajoute
	return true;
}

bool Personnel::retirerMedecin(const std::string& nom)  
{
	for (unsigned int i = 0; i < medecins_.size(); ++i) {
		if (*medecins_[i] == nom) { // on v�rifie que le m�decin � retirer existe dans le vecteur de m�decins
			medecins_[i] = medecins_.back(); // on suppose que l'ordre n'est pas important

// Dans le cas contraire, i.e. l'ordre est important, il faut d�placer les �l�ments du vecteurs d'une position vers la gauche
// � partir de la position suivante de celle de l'�l�ment supprim� :
// for(int j=i; j<medecins_.size() -1; ++j) {
// medecins_[j] = medecins_[j + 1]; }

			medecins_.pop_back();
			return true; // le m�decin dont le nom est pass� en param�tre a bien �t� supprim�
		}
	}
	return false; // le m�decin dont le nom est pass� en param�tre n'est pas dans le vecteur de m�decins
}

bool Personnel::ajouterInfirmier(Infirmier* infirmier) 
{
	for (unsigned int i = 0; i < infirmiers_.size(); ++i) {
		if (*infirmiers_[i] == *infirmier) // si l'infirmier pass� en param�tre existe dans le vecteur d'infirmiers
			return false; // il ne sera pas �t� ajout�
	}
	infirmiers_.push_back(infirmier); // sinon, on l'y ajoute
	return true;
}

bool Personnel::retirerInfirmier(const std::string& nomComplet) 
{
	for (unsigned int i = 0; i < infirmiers_.size(); ++i) {
		if (*infirmiers_[i] == nomComplet) { // on v�rifie que l'infirmier � retirer existe dans le																  vecteur d'infirmiers
			infirmiers_[i] = infirmiers_.back(); // On suppose que l'ordre n'est pas important

// Dans le cas contraire, il faut d�placer les �l�ments du vecteurs d'une position vers la gauche
// � partir de la position suivante de celle de l'�l�ment supprim� :
// for(int j=i; j<infirmiers_.size() -1; ++j) {
// infirmiers_[j] = infirmiers_[j + 1]; }

			infirmiers_.pop_back();
			return true; // l'infirmier dont le nom complet est pass� en param�tre a bien �t� supprim�
		}
	}
	return false; // l'infirmier dont le nom complet est pass� en param�tre n'est pas dans le vecteur d'infirmiers
}

Personnel& Personnel::operator+=(Medecin* medecin) {
	ajouterMedecin(medecin) ?
		cout << medecin->obtenirNom() << " a bien �t� ajout� au personnel de l'h�pital concern�" << endl :
		cout << medecin->obtenirNom() << " n'a pas �t� ajout� au personnel de l'h�pital concern�" << endl;
	return *this;
}

Personnel& Personnel::operator-=(Medecin* medecin) {
	retirerMedecin(medecin->obtenirNom()) ?
		cout << medecin->obtenirNom() << " a bien �t� retir� du personnel de l'h�pital concern�" << endl :
		cout << medecin->obtenirNom() << " n'est pas dans la liste de m�decins de l'h�pital concern�" << endl;
	return *this;
}

Personnel& Personnel::operator+=(Infirmier* infirmier) {
	ajouterInfirmier(infirmier) ?
		cout << infirmier->obtenirNomComplet() << " a bien �t� ajout� au personnel de l'h�pital concern�" << endl :
		cout << infirmier->obtenirNomComplet() << " n'a pas �t� ajout� au personnel de l'h�pital concern�" << endl;
	return *this;
}

Personnel& Personnel::operator-=(Infirmier* infirmier) {
	retirerInfirmier(infirmier->obtenirNomComplet()) ?
		cout << infirmier->obtenirNomComplet() << " a bien �t� retir� du personnel de l'h�pital concern�" << endl :
		cout << infirmier->obtenirNomComplet() << " n'est pas dans la liste d'infirmiers de l'h�pital concern�" << endl;
	return *this;
}
	
ostream& operator<<(ostream& os, const Personnel& personnel) {
	string tabMed = "Tableau Medecins";
	string nom = "Nom";
	string horaires = "Horaires";
	string domaine = "Domaine Specialite";
	string niveau = "Niveau Specialite";

	os << AFFICHER_ESPACE(espacement_medecin / 2) << tabMed 
		<< AFFICHER_ESPACE(espacement_medecin / 2) << endl;

	os << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;

	os << "| " << nom << AFFICHER_ESPACE(espace_nom - nom.size()) 
		<< " | " << horaires << AFFICHER_ESPACE(2*espace_horaires - horaires.size())
		<< " | " << domaine << AFFICHER_ESPACE(espace_domaine - domaine.size()) 
		<< " | " << AFFICHER_ESPACE(espace_niveau - niveau.size() / 2) << niveau
		<< AFFICHER_ESPACE(espace_niveau - niveau.size() / 2)
		<< "| " << endl;
		
	os << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;
	for (size_t i = 0; i < personnel.medecins_.size(); i++)
	{	
		//medecins_[i]->information();
		os << *(personnel.medecins_[i]);
		os << endl;
	}
	os << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;
	os << AFFICHER_ESPACE(espacement_medecin + tabMed.size()) << endl;

	string tabInf = "Tableau Infimiers";
	string nomComplet = "Nom Complet";
	string nbChambre = "Nombre de Chambre";
	 os << AFFICHER_ESPACE(espacement_infirmier/2) << tabInf 
		<< AFFICHER_ESPACE(espacement_infirmier/2) << endl;
	os << AFFICHER_LINE(espacement_infirmier + tabInf.size()) << endl;
	
	os << "| " << nomComplet << AFFICHER_ESPACE(espace_nom - nomComplet.size())
		 << " | " << nbChambre << AFFICHER_ESPACE(2 * espace_chambre - nbChambre.size())
		 << " | " << endl;
	os << AFFICHER_LINE(espacement_infirmier + tabInf.size()) << endl;

	for (size_t i = 0; i < personnel.infirmiers_.size(); i++)
	{
		os << *(personnel.infirmiers_[i]);
		os << endl;
	}

	os << AFFICHER_LINE(espacement_infirmier + tabInf.size());

	return os;
}