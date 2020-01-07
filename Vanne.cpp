   #include "Vanne.h"
#include <iostream>
#include <QMessageBox>
#include <QDebug>
#include <QString>
using namespace std;

        // constructeur de la classe Vanne
    Vanne::Vanne(QString nom){
        etat = 0;
        this->nom = nom;
    }

    void Vanne::power(){
        etat = 1-etat;
        QString tmpNom;
        if (etat) tmpNom = "Ouverte";
        else tmpNom = "Fermée";
       qDebug()<<"La Vanne " << nom << " est en "<< tmpNom<< endl;



    }
    int Vanne::get_etat()
    {
    return etat;
    }

        // destructeur de la classe Vanne

    Vanne::~Vanne(){}

