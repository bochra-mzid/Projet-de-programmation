#include"Resultat.h"
#include<iostream>
using namespace std;

Resultat::Resultat(string path)
{
    this->fichier_resultat=path;
}
std::string getfichier_resulat()
{
    return fichier_resultat;
}

void setfichier_resultat(std::string fichier_resultat)
{
    this->fichier_resultat=fichier_resultat;
}
