#include"Eleve.h"
#include<iostream>
#include <dirent.h>
#include <sys/types.h>

using namespace std;


Eleve::Eleve(int num_inscri, std::string nom,std::string prenom,int age,std::string classe,int num_tel,std::string prenom_pere,std::string prenom_mere,std::string situation_familiale)
{
    this->num_inscri=num_inscri;
    this->nom=nom;
    this->prenom=prenom;
    this->age=age;
    this->classe=classe;
    this->num_tel=num_tel;
    this->prenom_pere=prenom_pere;
    this->prenom_mere=prenom_mere;
    this->situation_familiale=situation_familiale;
    dossier_resultat="C:/Users/21623/Desktop/Projet Programmation - Version finale/Projet Programmation/Résultats/"+ std::to_string(num_inscri);
    mkdir(dossier_resultat.c_str());
}
Eleve::Eleve()
{

}

std::string Eleve :: getdossier_resultat()
{
    return(dossier_resultat);
}

void Eleve :: setdossier_resultat(std::string path)
{
    dossier_resultat=path;
}

std::string Eleve :: getnom()
{
    return nom;
}

std::string Eleve :: getprenom()
{
    return prenom ;
}

std::string Eleve :: getclasse ()
{
    return classe ;
}

std::string Eleve :: getprenom_pere()
{
    return prenom_pere;
}

std::string Eleve :: getprenom_mere ()
{
    return prenom_mere;
}

std::string Eleve :: getsituation_familiale ()
{
    return situation_familiale ;
}

int Eleve :: getnum_tel ()
{
    return num_tel;
}

int Eleve :: getage ()
{
    return age ;
}

void Eleve :: setnom (std::string nom)
{
    this->nom = nom;
}

void Eleve :: setprenom (std::string prenom)
{
    this->prenom = prenom;
}

void Eleve :: setclasse (std::string classe)
{
    this->classe = classe;
}

void Eleve :: setprenom_pere(std::string prenom_pere)
{
    this->prenom_pere = prenom_pere;
}

void Eleve :: setprenom_mere(std::string prenom_mere)
{
    this->prenom_mere = prenom_mere;
}

void Eleve :: setsituation_familiale(std::string situation_familiale)
{
    this->situation_familiale = situation_familiale;
}

void Eleve :: setnum_tel (int num_tel)
{
    this->num_tel = num_tel;
}

std::string Eleve :: getconclusion ()
{
    return conclusion ;
}


void Eleve :: setconclusion (std::string conclusion )
{
    this->conclusion = conclusion ;
}

int Eleve :: getnum_inscri()
{
    return num_inscri;

}

void Eleve :: setnum_inscri(int num_inscri)
{
    this->num_inscri = num_inscri;
}
