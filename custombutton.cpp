#include "custombutton.h"
#include  <QDebug>
#include <QMessageBox>
#include "Reservoir.h"
#include <iostream>
#include <QString>
#include <sstream>
#include "Vanne.h"
#include <QDebug>


CustomButton::CustomButton(QWidget * parent, QString nom)
    :QPushButton(parent)

{
 this->nom =nom;

 setText(nom);
 setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum); }

CustomButton::~CustomButton()
{
qDebug() << "destruction" << endl;

}
void CustomButton::VanneEtat()
{
//t.power();
    qDebug() << " hello";
}


void CustomButton::PompeEtat()
{
    Reservoir * Res = new  Reservoir(4);

   int tmp =  Res->get_etat_pompe_secondaire();
    string s;
    if (tmp ==1 ) s =  "marche";

        else if ( tmp  == 0) s = "arrêt";

            else s="panne";

/*     ostringstream entier;
    entier << Res->get_etat_pompe_secondaire();
    string e =  entier.str();
*/
    const QString &e = QString::fromStdString(s);



QMessageBox::information(this, this->nom,  e) ;
}

/*
void CustomButton::VanneEtat()
{
    Reservoir * Res = new  Reservoir(5);

     ostringstream entier;
    entier << Res->get_capacite();
    string e =  entier.str();

    const QString &s = QString::fromStdString(e);

//QMessageBox::information(this, this->nom,"capacite " );

QMessageBox::information(this, this->nom,  s );
}


void CustomButton::MoteurFlux()
{
    Reservoir * Res = new  Reservoir(4);

     ostringstream entier;
    entier << Res->get_capacite();
    string e =  entier.str();

    const QString &s = QString::fromStdString(e);

//QMessageBox::information(this, this->nom,"capacite " );

QMessageBox::information(this, this->nom,  s );
}

*/
