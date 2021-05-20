#ifndef RESULTAT_H_INCLUDED
#define RESULTAT_H_INCLUDED
#include<iostream>

class Resultat
{
private :
    std::string fichier_resultat;

public :
    Resultat(std::string);
    std::string getfichier_resulat();
    void setfichier_resultat(std::string);
};


#endif // RESULTAT_H_INCLUDED
