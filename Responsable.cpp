#include"Responsable.h"
#include"Resultat.h"
#include<iostream>
#include <fstream>
#include <dirent.h>
#include <sys/types.h>

using namespace std;

Responsable::Responsable(std::string nom,std::string prenom,std::string profession,int num_tel,std::string login,std::string mdp)
{
    this->nom=nom;
    this->prenom=prenom;
    this->profession=profession;
    this->num_tel=num_tel;
    this->login=login;
    this->mdp=mdp;

}

std::string Responsable :: getnom ()
{
    return nom ;
}

std::string Responsable :: getprenom ()
{
    return prenom ;
}

std::string Responsable :: getprofession ()
{
    return profession ;
}

std::string Responsable :: getlogin ()
{
    return login ;
}

std::string Responsable :: getmdp ()
{
    return mdp ;
}

int Responsable :: getnum_tel ()
{
    return num_tel ;
}

void Responsable :: setnom (std::string nom)
{
    this-> nom = nom ;
}

void Responsable :: setprenom (std::string prenom)
{
    this->prenom = prenom ;
}

void Responsable :: setprofession (std::string profession)
{
    this->profession = profession ;
}

void Responsable :: setlogin (std::string login )
{
    this->login  = login ;
}

void Responsable :: setmdp (std::string mdp )
{
    this->mdp  = mdp ;
}

void Responsable :: setnum_tel(int num_tel )
{
    this->num_tel  = num_tel ;
}

void Responsable :: lancer_test_standard(Eleve e)
{
    ifstream test_standard("C:/Users/21623/Desktop/Projet Programmation - Version finale/Projet Programmation/Maladies/Test-standard.txt");
    if(test_standard)
    {
        std::string remarque;
        std::string ligne;
        std::string const nomFichier(e.getdossier_resultat()+"/Test_standard.txt");
        ofstream resultat_test_standard(nomFichier.c_str());
        while(getline(test_standard,ligne))
        {
            cout << ligne << endl;
            std::string reponse ;
            cout<<"ecrire votre reponse:"<< reponse<< endl;
            cin >>reponse ;
            if(resultat_test_standard)
            {
                resultat_test_standard << ligne << endl;
                resultat_test_standard << reponse << endl;
            }
            else
            { cout << "ERREUR: Impossible d'ouvrir le fichier" << endl; }
        }
        if(resultat_test_standard)
        {
            resultat_test_standard<< "Remarques de l'\x82\l\x8Ave :" << endl;
            cout<< "Inserez vos remarques:";
            cin.ignore();
            std::getline (std::cin,remarque);
            resultat_test_standard<<remarque<<endl;
        }
        resultat_test_standard<<"conclusion et remarques du psychologue:" << endl;

        resultat_test_standard.close();
    }
        else
          {cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;}
}

// test spécifique
void Responsable :: lancer_test(Eleve e,Maladie m)
{
    std::string ligne,path,remarque;
    path=e.getdossier_resultat()+"/"+m.getnom()+".txt";
    ifstream test(m.getfichier_maladie());
    ofstream f_rep(path);
    std::string rep;
    while(getline(test, ligne))
      {
         cout << ligne << endl;
         cin>>rep;
         f_rep<<ligne<<endl;
         f_rep<<rep<<endl;
      }

      if(f_rep)
        {
            f_rep<<"Remarques de l'\x82\l\x8Ave :" << endl;
            cout<< "Inserez vos remarques:";
            cin.ignore();
            std::getline (std::cin,remarque);
            f_rep<<remarque<<endl;
        }
        f_rep<<"conclusion et remarques du psychologue:" << endl;

        f_rep.close();
}


void Responsable::consulter_fiche_eleve(int num_inscri,std::map<int,Eleve> tab_eleve)
{
    std::string remarque, fichier;
    Eleve e;
    map<int, Eleve>::iterator trouve_eleve= tab_eleve.find(num_inscri);
            if(trouve_eleve== tab_eleve.end())
            {
                cout<< "Identifiant introuvable"<<endl;
            }
            else {
                e=trouve_eleve->second;
                cout << "\tN Insc\tNom\tPrenom\tAge\tClasse\tN Tel\t\tP\x8Are\tM\x8Are\tS.Familiale\n";
                cout << '\t' << e.getnum_inscri()
                << '\t' << e.getnom()
                << '\t' << e.getprenom()
                << '\t' << e.getage()
                << '\t' << e.getclasse()
                << '\t' << e.getnum_tel()
                << '\t' << e.getprenom_pere()
                << '\t' << e.getprenom_mere()
                << '\t' << e.getsituation_familiale() << '\n';
                cout << "Les tests pass\x82\s par cet \x82\l\x8Ave sont:"<<endl;
                DIR* rep = NULL;
                int k=0, h=0;

                map<int,std::string> resultats;
                struct dirent* fichierLu = NULL;
                rep = opendir((trouve_eleve->second).getdossier_resultat().c_str());
                if (rep == NULL)
                    exit(1);
                while ((fichierLu = readdir (rep)) != NULL )
                {
                    h++;
                    if (h>2){
                    k++;
                    cout<<k<<". "<< fichierLu->d_name<<endl;
                    resultats[k]=fichierLu->d_name;
                    }
                }
                if (closedir(rep) == -1)
                    exit(-1);
                int choix1, choix2, choix3;
                cout<< "Voulez-vous consulter les test pass\x82\s par cet \x82\l\x8Ave?"<< endl;
                cout<< "1. Oui "<< endl;
                cout<< "2. Non "<< endl;
                cin>> choix1;
                if (choix1==1)
                {
                    cout<<"Quel test voulez vous consulter: "<<endl;
                    cin>>choix2;
                    map<int, std::string>::iterator test = resultats.find(choix2);
                    if(test == resultats.end())
                    {
                        cout << "Cet \x82\l\x8Ave n'a pas pass\x82\ ce test" << endl;
                    }
                    else
                    {
                        ifstream fichier_res(e.getdossier_resultat()+"/"+resultats[choix2]);

                        if(fichier_res)
                        {
                            string ligne;
                            while(getline(fichier_res, ligne))
                            {
                                fichier+="\n";
                                fichier+=ligne;
                                cout << ligne << endl;
                            }
                            fichier_res.close();
                            cout<<"voulez vous ajouter une conclusion?"<<endl;
                            cout<<"1. Oui"<<endl;
                            cout<<"2. Non"<<endl;
                            cin>>choix3;
                            if (choix3==1){
                                ofstream f_rep(e.getdossier_resultat()+"/"+resultats[choix2]);
                                if(f_rep)
                                {
                                f_rep<<fichier<<endl;
                                cout<< "Ajoutez votre conclusion ou vos remarques remarques:";
                                cin.ignore();
                                std::getline (std::cin,remarque);
                                f_rep<<remarque<<endl;
                                f_rep.close();
                                }
                            }
                        }
                        else
                        {
                            cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
                        }

                    }
            }
    }
}

void Responsable::consulter_liste_eleve(std::map<int,Eleve> tab)
{
    std::map<int, Eleve>::iterator itr;
    cout << "Liste des \x82\l\x8Aves"<<endl;
    cout << "\tN Insc\tNom\tPrenom\tAge\tClasse\tN Tel\t\tP\x8Are\tM\x8Are\tS.Familiale\n";
    for (itr = tab.begin(); itr != tab.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second.getnom()
             << '\t' << itr->second.getprenom()
             << '\t' << itr->second.getage()
             << '\t' << itr->second.getclasse()
             << '\t' << itr->second.getnum_tel()
             << '\t' <<itr->second.getprenom_pere()
             << '\t' <<itr->second.getprenom_mere()
             << '\t' <<itr->second.getsituation_familiale() << '\n';
    }
}
