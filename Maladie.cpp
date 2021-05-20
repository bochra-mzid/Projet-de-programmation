#include"Maladie.h"
#include<iostream>
using namespace std;

Maladie::Maladie(std::string nom,std::string fichier_maladie)
{
    this->nom = nom;
    this->fichier_maladie = fichier_maladie;

}
Maladie::Maladie()
{

}
std::string Maladie :: getnom ()
{
    return nom ;
}

std::string Maladie :: getfichier_maladie ()
{
    return fichier_maladie ;
}

void Maladie :: setnom(std::string nom)
{
    this->nom = nom ;
}

void Maladie :: setfichier_maladie(std::string fichier_maladie)
{
    this->fichier_maladie  = fichier_maladie;
}
