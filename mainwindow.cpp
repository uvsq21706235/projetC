#include "mainwindow.h"

#include <QDebug>
#include <QFrame>
#include <QDialog>
#include "Vanne.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Simulateur d'avion de chasse ");
  //  m_customBtn = new CustomButton(this);

    //setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    m_mainWidget =new QWidget(this);
    m_vLayout1 = new QVBoxLayout(this);
    m_vLayout2 = new QVBoxLayout(this);
    m_vLayout3 = new QVBoxLayout(this);
    m_vLayoutbis = new QVBoxLayout(this);

    m_hLayout = new QHBoxLayout(this);
    m_hLayout1 = new QHBoxLayout(this);

    QPushButton *vt12 = new QPushButton( "VT12", m_mainWidget );
    QPushButton *vt23 = new QPushButton("VT23",  m_mainWidget);


    QPushButton *p12 = new QPushButton("P12", m_mainWidget);
    QPushButton *p22 = new QPushButton( "P22", m_mainWidget);
    QPushButton *p32 = new QPushButton( "P32", m_mainWidget);


    QPushButton *v12 = new QPushButton( "V12", m_mainWidget);
    QPushButton *v13 = new QPushButton( "V13",m_mainWidget );
    QPushButton *v23 = new QPushButton("V23", m_mainWidget );



   m_vLayout1->addWidget(vt12);
   m_vLayout1->addSpacing(50);

   m_vLayout2->addSpacing(150);
   m_vLayout3->addWidget(vt23);
   m_vLayout3->addSpacing(50);



    m_hLayout->addLayout(m_vLayout1);
    m_vLayout1->addWidget(p12);
    m_vLayout1->addWidget(v12);



   m_hLayout->addLayout(m_vLayout2);
    m_vLayout2->addWidget(p22);
    m_vLayout2->addWidget(v13);


    m_hLayout->addLayout(m_vLayout3);
    m_vLayout3->addWidget(p32);
    m_vLayout3->addWidget(v23);


   // m_mainWidget->setLayout(m_hLayout1);
    m_mainWidget->setLayout(m_hLayout);


      // CustomButton* btn =  new CustomButton(this, "boutton 1");
     //   m_listBtn.append(btn ); // mettre dans une liste pour faire des actions dessus


        //btn->move(i*30,0);
       /* if (i == 1)

            m_vLayout->addSpacing(30); // espace entre 2 bouttons


        */



  setCentralWidget(m_mainWidget);

}



MainWindow::~MainWindow()
{
}


