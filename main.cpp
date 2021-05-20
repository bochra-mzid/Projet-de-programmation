#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include "Eleve.cpp"
#include "Maladie.cpp"
#include "Responsable.cpp"
using namespace std;

int main()
{
    // Initialisation du Responsable
    Responsable R("Abyedh","Slimen","psychoterapeute",26200714,"admin","0000");
    string login,mdp;
    bool test=false;
    // authentification
    do
    {
        cout<<"Entrez votre login :"<<endl;
        cin>>login;
        cout<<"Entrez votre mot de passe :"<<endl;
        cin>>mdp;
        if((R.getlogin()!=login)||(R.getmdp()!=mdp))
            cout<<"Login ou mot de passe incorrect"<<endl;
        else
            test=true;
    }while(test == false);


    // les maladies
    std::map<int,Maladie> tab_maladie;
    Maladie M1("Agoraphobie","C:/Users/21623/Desktop/Projet Programmation - Version finale/Projet Programmation/Maladies/Agoraphobie.txt");
    Maladie M2("Bordeline","C:/Users/21623/Desktop/Projet Programmation - Version finale/Projet Programmation/Maladies/bordeline.txt");
    Maladie M3("Stress","C:/Users/21623/Desktop/Projet Programmation - Version finale/Projet Programmation/Maladies/Stress.txt");
    Maladie M4("Bipolaire","C:/Users/21623/Desktop/Projet Programmation - Version finale/Projet Programmation/Maladies/Bipolaire.txt");
    Maladie M5("Depression","C:/Users/21623/Desktop/Projet Programmation - Version finale/Projet Programmation/Maladies/Depression.txt");
    Maladie M6("lanxiete-de-performance","C:/Users/21623/Desktop/Projet Programmation - Version finale/Projet Programmation/Maladies/lanxiete-de-performance.txt");
    tab_maladie[1]=M1;
    tab_maladie[2]=M2;
    tab_maladie[3]=M3;
    tab_maladie[4]=M4;
    tab_maladie[5]=M5;
    tab_maladie[6]=M6;

    // les élèves
    std::map<int,Eleve> tab_eleve;
    Eleve E1(1010, "Med" , "Ahmed" , 14 , "1B9" ,22635987, "Mohamed", "Leila" , "parents divorc\x82\s");
    Eleve E2(2020, "Dridi" , "Mouna" , 15 , "2B4" ,25685788, "Walid", "Habiba" , "parents separ\x82\s");
    Eleve E3(3030, "Sallemi" , "Firas" , 14 , "3B1" ,20515778, "Slim", "Marwa" , "p\x8Are d\x82\ced\x82");


    tab_eleve[1010]=E1;
    tab_eleve[2020]=E2;
    tab_eleve[3030]=E3;

    // choix du responsable
    int choix1,choix2,k,id;

    do {
    k=1;
    cout<<"Liste des fonctionnalit\x82\s"<<endl;
    cout<<"1: Test Standard"<<endl;
    cout<<"2: Test sp\x82\cifique"<<endl;
    cout<<"3: Consulter la liste des \x82\l\x8Aves"<<endl;
    cout<<"4: Consulter la fiche d'un \x82\l\x8Ave"<<endl;
    cout<<"5: Quitter"<<endl;
    cout<<"Entrez votre choix: ";
    cin>>choix1;
    // Test spécifique
    if (choix1==2){
        cout<<"Choisissez une maladie: "<<endl;
        for(map<int,Maladie>::iterator i=tab_maladie.begin(); i!=tab_maladie.end(); ++i)
        {
            cout<<k<<" : "<<(i->second).getnom()<<endl;
            k++;
        };
        cin>>choix2;
        map<int, Maladie>::iterator trouve_maladie = tab_maladie.find(choix2);
        if(trouve_maladie == tab_maladie.end())
        {
            cout << "Numero de maladie introuvable" << endl;
        }
        else
        {
            cout<<"donnez l'identifiant de l'\x82\l\x8Ave"<<endl;
            cin>>id;
            map<int, Eleve>::iterator trouve_eleve = tab_eleve.find(id);
            if(trouve_eleve == tab_eleve.end())
            {
                cout<< "Identifiant introuvable"<<endl;
            }
            else
            {
                R.lancer_test(trouve_eleve->second,trouve_maladie->second);
            }
        }
    }
    // Test standard
    else if (choix1 == 1){
        cout<<"donnez l'identifiant de l'\x82\l\x8Ave"<<endl;
            cin>>id;
            map<int, Eleve>::iterator trouve_eleve = tab_eleve.find(id);
            if(trouve_eleve == tab_eleve.end())
            {
                cout<< "Identifiant introuvable"<<endl;
            }
            else
            {
                R.lancer_test_standard(trouve_eleve->second);
            }

    }
    // consulter la liste des eleves
    else if (choix1==3){
        R.consulter_liste_eleve(tab_eleve);
    }
    // consulter la fiche d'un eleve
    else if (choix1==4){
        cout<<"donnez l'identifiant de l'\x82\l\x8Ave"<<endl;
        cin>>id;
        R.consulter_fiche_eleve(id,tab_eleve);

    }
    // quitter
    else if (choix1==5){
        exit(0);
    }
    else{cout<<"choix incorrect"<<endl;}
    }
    while(true);

    return 0;
}
