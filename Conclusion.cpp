#include"Conclusion.h"
#include<iostream>
using namespace std;

Eleve Conclusion :: gete ()
{
    return e;
}

string Conclusion :: getconclusion ()
{
    return conclusion ;
}

void Conclusion :: sete (Eleve e )
{
    this->e = e;
}

void Conclusion :: setconclusion (string conclusion )
{
    this->conclusion = conclusion ;
}
