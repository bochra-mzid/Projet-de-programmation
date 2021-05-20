#ifndef CONCLUSION_H_INCLUDED
#define CONCLUSION_H_INCLUDED
#include<iostream>
#include<vector>
#include"Resultat.h"
#include"Eleve.h"

class Conclusion
{
private :

    vector<Resultat> tab_res;
    Eleve e;
    string conclusion;

public :
    //getters et setters
    Eleve gete ();
    string getconclusion ();
    void sete (Eleve);
    void setconclusion (string);
};

#endif // CONCLUSION_H_INCLUDED
