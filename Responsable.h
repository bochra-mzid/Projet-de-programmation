#ifndef RESPONSABLE_H_INCLUDED
#define RESPONSABLE_H_INCLUDED
#include<iostream>
#include<fstream>
#include"Eleve.h"
#include"Maladie.h"

class Responsable
{
private :
    std::string nom;
    std::string prenom;
    std::string profession;
    int num_tel;
    std::string login;
    std::string mdp;

public :
    //constructeur
    Responsable(std::string,std::string,std::string,int,std::string,std::string);
    // getters et setters
    std::string getnom();
    std::string getprenom();
    std::string getprofession();
    int getnum_tel();
    std::string getlogin();
    std::string getmdp();
    void setnum_inscri(int);
    void setnom(std::string);
    void setprenom(std::string);
    void setprofession(std::string);
    void setnum_tel(int);
    void setlogin(std::string);
    void setmdp(std::string);
    // methodes
    // lancer un test standard
    void lancer_test_standard(Eleve);
    // lancer un test spécifique
    void lancer_test(Eleve,Maladie);
    // consulter la fiche d'un eleve bien précis
    void consulter_fiche_eleve(int num_inscri,std::map<int,Eleve> tab);
    // consulter la liste compléte des eleves
    void consulter_liste_eleve(std::map<int,Eleve>);
};

#endif // RESPONSABLE_H_INCLUDED
