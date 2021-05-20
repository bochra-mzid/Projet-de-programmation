#ifndef ELEVE_H_INCLUDED
#define ELEVE_H_INCLUDED
#include<iostream>
#include<vector>

#include"Resultat.h"

class Eleve
{
private :
    int num_inscri;
    std::string nom;
    std::string prenom;
    int age;
    std::string classe;
    int num_tel;
    std::string prenom_pere;
    std::string prenom_mere;
    std::string situation_familiale;
    std::vector<Resultat> tab_res;
    std::string conclusion;
    std::string dossier_resultat;
public :
    // constructeurs
    Eleve(int,std::string,std::string,int,std::string,int,std::string,std::string,std::string);
    Eleve();
    // getters et setters
    std::string getdossier_resultat();
    void setdossier_resultat(std::string);
    int getnum_inscri();
    void setnum_inscri(int);
    std::string getnom();
    std::string getprenom();
    int getage();
    std::string getclasse();
    int getnum_tel();
    std::string getprenom_pere();
    std::string getprenom_mere();
    std::string getsituation_familiale();
    Resultat getres();
    std::string getconclusion();
    void setnom(std::string);
    void setprenom(std::string);
    void setage(int);
    void setclasse(std::string);
    void setnum_tel(int);
    void setprenom_pere(std::string);
    void setprenom_mere(std::string);
    void setsituation_familiale(std::string);
    void setres(Resultat);
    void setconclusion (std::string);
};


#endif // ELEVE_H_INCLUDED
