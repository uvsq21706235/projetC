#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QObject>
#include <QPushButton>
#include "Reservoir.h"
#include "Vanne.h"

class CustomButton : public QPushButton
{

    Q_OBJECT // genere des bout de code en plus pour que le mecanisme fonctionne
private :
    QString nom;


public slots:
    void VanneEtat();
    void PompeEtat();

   // void VanneEtat();

    //void MoteurFlux()
;
public:
    CustomButton( QWidget *parent = nullptr, QString nom = nullptr );
    ~CustomButton();

};

#endif // CUSTOMBUTTON_H
