#ifndef _VANNE_H
#define _VANNE_H

#include <iostream>
#include <QWidget>
#include  <QDebug>
#include <QMessageBox>

#include <iostream>



using namespace std;

class Vanne : public QWidget {

Q_OBJECT
 friend class Reservoir;
private:
        // etat égal à 1 si la vanne est fermée, à 0 si la vanne est ouverte,
    int etat;

public slots:
 void power();
     //getters
   int get_etat();

public:
   // constructeur de la classe Vanne
Vanne();
        // destructeur de la classe Vanne

    ~Vanne();
};

#endif
