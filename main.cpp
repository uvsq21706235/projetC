#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <simulateur.h>
#include <QDialog>
#include "window2.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        Simulateur s;

         Window2 *f = new Window2(s);
         MainWindow *w = new MainWindow(s);

        f->show();
        w->show();

    return a.exec();
}
