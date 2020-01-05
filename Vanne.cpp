#include "Vanne.h"
#include <iostream>
#include <QMessageBox>
#include <QDebug>
using namespace std;

        // constructeur de la classe Vanne
    Vanne::Vanne(){
        etat = 0;
    }

    void Vanne::power(){
        etat = 1-etat;
        qDebug() << "hello";


    }
    int Vanne::get_etat()
    {
    return etat;
    }

        // destructeur de la classe Vanne

    Vanne::~Vanne(){}

