#ifndef MALADIE_H_INCLUDED
#define MALADIE_H_INCLUDED
#include<iostream>

class Maladie
{
private :
    std::string nom;
    std::string fichier_maladie; //path
public :
    // constructeurs
    Maladie();
    Maladie(std::string,std::string);
    // getters et setters
    std::string getnom();
    void setnom(std::string);
    std::string getfichier_maladie();
    void setfichier_maladie(std::string);
};


#endif // MALADIE_H_INCLUDED
