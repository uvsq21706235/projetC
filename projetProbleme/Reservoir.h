#ifndef _TEST_H
#define _TEST_H

#include "Pompe.h"
#include "Vanne.h"
#include <QString>
#include <QDebug>
#include <iostream>

using namespace std;



class Reservoir{
    friend class Moteur;
    //friend operator=(Reservoir &);

private:

    QString nom;
    int capacite;
    Pompe *primaire;
    Pompe *secondaire;

public:

        // constructeur de la classe Reservoir qui prend en argument la capacité du reservoir
        // et qui créé les deux pompes associées au moteur en appelant le constructeur
        // la variable etat est à true si le reservoir est plein, false sinon

    Reservoir(int c=0, QString name="Tank0", Pompe *pp=nullptr, Pompe *ps=nullptr);

        //getter de la classe

    bool get_etat();
    int get_etat_pompe_primaire();
    int get_etat_pompe_secondaire();

    int get_etatReservoir();

    QString get_nom();

        //setter de la classe
    void set_capacite(int i);

        //permet de vider le reservoir
    void vidange();



        //destructeur de la classe Reservoir
    ~Reservoir();

};

#endif
