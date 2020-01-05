#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include "Moteur.h"
#include "Pompe.h"
#include "Vanne.h"
#include "Reservoir.h"
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   MainWindow w;
        w.show();

        QWidget fenetre;
        QPushButton * bouton = new QPushButton ("ouvrir", &fenetre );
        QDialog secondeFenetre (&fenetre);



        QWidget::connect(bouton, SIGNAL(clicked()), &secondeFenetre, SLOT(exec()));
        fenetre.show();


    return a.exec();
}
