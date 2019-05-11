/**************************************************
 * Main.cpp
 * Date: 31 janvier 2017
**************************************************/

#include <string>
#include <iostream>
#include <clocale>
#include "Hopital.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	// C'est a vous de voir si vous devez allouer dynamiquement ou non les elements

	//1-  Creez 11 objets du type Infirmier � l'aide du constructeur par param�tre avec des valeurs de votre choix
	// A COMPLETER...

	Infirmier* gilles = new Infirmier("Tremblay", "Gilles", 2);
	Infirmier* sylvie = new Infirmier("Labe", "Sylvie", 3);
	Infirmier* amelie = new Infirmier("Labelle", "Amelie", 4);
	Infirmier* maxime = new Infirmier("Lamontagne", "Maxime", 5);
	Infirmier* john = new Infirmier("Laflamme", "John", 6);
	Infirmier* julie = new Infirmier("Lamoureux", "Julie", 7);
	Infirmier* eric = new Infirmier("Langlais", "Eric", 8);
	Infirmier* roger = new Infirmier("Lamarre", "Roger", 9);
	Infirmier* linda = new Infirmier("Laplante", "Linda", 10);
	Infirmier* hug = new Infirmier("Latour", "Hug", 11);
	Infirmier* emilie = new Infirmier("Lessard", "Emilie", 12);

	//2-  Creez deux objets du type Personnel � l'aide du constructeur par d�faut
	// A COMPLETER...
	Personnel personnelSC;
	Personnel personnelJT;

	//3 - Creez deux objects de type Hopital qui vont prendre chacun en parametre le nom de l'hopital et le personnel assigné
	// Hopital Sacré-Coeur de Montréal
	// Hôpital Jean-Talon
	// A COMPLETER...
	Hopital hopitalSC("Hôpital Sacré-Coeur de Montréal", &personnelSC);
	Hopital hopitalJT("Hôpital Jean-Talon", &personnelJT);

	//4-  Ajoutez les 6 objets du type Infimier � au personnel de l'Hôpital Sacré-Coeur de Montréal
	// A COMPLETER...
	
	personnelSC += gilles;
	personnelSC += sylvie;
	personnelSC += amelie;
	personnelSC += maxime;
	personnelSC += john;
	personnelSC += julie;

	//5-  Ajoutez les 5 objets qui restent du type Infimier � au personnel de l'Hôpital Jean-Talon
	// A COMPLETER...
	
	personnelJT += eric;
	personnelJT += roger;
	personnelJT += linda;
	personnelJT += hug;
	personnelJT += emilie;

	//6-  Creez 7 objets du type Specialite � l'aide du constructeur par param�tre avec des valeurs de votre choix
	// Specialites : Chirurgie, Demartologie, Gastrologie, Sport, Podologie, Pediatrie, Psychiatrie
	// A COMPLETER...
	 Specialite* pediatrie = new Specialite("Pediatrie", 9);
	 Specialite* dermatologie = new Specialite("Dermatologie", 10);
	 Specialite* gastrologie = new Specialite("Gastrologie", 11);
	 Specialite* podologie = new Specialite("Podologie", 8);
	 Specialite* sport = new Specialite("Sport", 7);
	 Specialite* chirurgie = new Specialite("Chirurgie", 15);
	 Specialite* psychiatrie = new Specialite("Psychiatrie", 45);

	//7- Creez 7 autres objets du type Medecin � l'aide du constructeur par param�tre avec des valeurs de votre choix
	// Dr. Franc : en Chirurgie
	// Dr. Sherlock : en Demartologie
	// Dr. Holmes : en Gastrologie
	// Dr. Jean : en Podologie
	// Dr. Jules : en Pediatrie
	// Dr. Kyle : en Sport
	// Dr. House : en Psychiatrie
	// A COMPLETER...
	Medecin* franc = new Medecin("Franc", 9, chirurgie);
	Medecin* sherlock = new Medecin("Sherlock", 5, dermatologie);
	Medecin* holmes = new Medecin("Holmes", 6, gastrologie);
	Medecin* jean = new Medecin("Jean", 8, podologie);
	Medecin* jules = new Medecin("Jules", 9, pediatrie);
	Medecin* kyle = new Medecin("Kyle", 7, sport);
	Medecin* house = new Medecin("House", 10, psychiatrie);

	//8- Creer un autre medecin Sherlock en utilisant l'opérateur = et en utilisant le medecin existante Sherlock.
	// Le horaire du deuxieme Sherlock devrai ensuite etre modifie pour une valeur differnte du premier Sherlock
	// A COMPLETER...
	Medecin* autreSherlock = new Medecin(*sherlock);
	autreSherlock->modifierHoraires(6);

	//9- Creer un autre medecin Holmes en utilisant le constructeur de copie et en utilisant le medecin existante Holmes.
	// Le horaire du deuxieme Holmes devrai ensuite etre modifie pour une valeur differnte du premier Holmes
	// A COMPLETER...
	Medecin* autreHolmes = new Medecin(*holmes);
	autreHolmes->modifierHoraires(3);

	//10- Ajoutez les medecins : parmis le personnel de l'hopital Sacré-Coeur : 
	// Dr. Franc, Dr. Sherlock, Dr. Holmes, Dr. Jean, Dr. Jules
	// A COMPLETER...
	personnelSC += franc;
	personnelSC += sherlock;
	personnelSC += holmes;
	personnelSC += jean;
	personnelSC += jules;

	// Dr. Sherlock(2), Dr. Holmes(2), Dr. Kyle, Dr. House
	// A COMPLETER...
	personnelJT += autreSherlock;
	personnelJT += autreHolmes;
	personnelJT += kyle;
	personnelJT += house;

	//11- Retirer le medecin Jean et deux infirmiers de l'hopital Sacré-Coeur et ajouter les
	// a l'hopital Jean-talon
	personnelSC -= jean;
	personnelJT += jean;
	personnelSC -= gilles;	  // on retire par exemple le 1er infirmier (Gilles Tremblay) ainsi que le 
	personnelSC -= julie;	  // dernier (Julie Lamoureux) de la liste d'infirmiers de l'hôpital Sacré-Coeur
	personnelJT += gilles;
	personnelJT += julie;

	// Si on essaye d'ajouter deux fois le même infirmier ou le même médecin
	personnelJT += gilles; // On essaye d'ajouter Gilles Tremblay au personnel infirmier de l'hôpital Jean-Talon
							// alors qu'il y existe déjà
	personnelSC += franc; // On essaye d'ajouter Franc aux médecins de l'hôpital Sacré-Coeur
						  // alors qu'il y existe déjà

	// Si on essaye de retirer un infirmier ou un médecin d'un hôpital auquel il n'est pas affecté
	personnelJT -= franc;
	personnelSC -= gilles;

	//12- Faites afficher l'hopital Sacré-Coeur puis Jean-Talon
	// A COMPLETER...
	cout << hopitalSC << endl;
	cout << hopitalJT << endl;

	// Libération des espaces mémoires alloués dynamiquement(afin d'éviter les fuites de mémoire)

	delete chirurgie; chirurgie = nullptr;
	delete dermatologie; dermatologie = nullptr;
	delete podologie; podologie = nullptr;
	delete pediatrie; pediatrie = nullptr;
	delete sport; sport = nullptr;
	delete gastrologie; gastrologie = nullptr;
	
	return 0;
}
