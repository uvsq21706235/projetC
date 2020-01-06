

#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <simulateur.h>
#include <QDialog>
#include "window2.h"
#include "window3.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
       Simulateur s;

       //  Window2 *f = new Window2(s);
        // MainWindow *w = new MainWindow(s);
Window3 *f = new Window3(s);
       f->show();
       // w->show();

      //  test = new QWidget(this);



    return a.exec();
}

