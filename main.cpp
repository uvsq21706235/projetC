

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

        Window3 *f = new Window3();
               f->show();

    return a.exec();
}

