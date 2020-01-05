#include "mainwindow.h"

#include <QDebug>
#include <QFrame>
#include <simulateur.h>


MainWindow::MainWindow(Simulateur &simi, QWidget *parent ) : QMainWindow(parent)
{
      this->s = simi;

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
    vt12->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    vt23->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    QPushButton *p12 = new QPushButton("P12", m_mainWidget);
    QPushButton *p22 = new QPushButton( "P22", m_mainWidget);
    QPushButton *p32 = new QPushButton( "P32", m_mainWidget);
    p12->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    p22->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    p32->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    QPushButton *v12 = new QPushButton( "V12", m_mainWidget);
    QPushButton *v13 = new QPushButton( "V13",m_mainWidget );
    QPushButton *v23 = new QPushButton("V23", m_mainWidget );

    v12->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    v13->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    v23->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);


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




    m_mainWidget->setLayout(m_hLayout);

   //Connection boutons et classe -> Ouvert et Fermer d'une Vanne
    QWidget::connect(p12, SIGNAL(clicked()), this, SLOT(OnOffPompeP12()) );
    QWidget::connect(p22, SIGNAL(clicked()), this, SLOT(OnOffPompeP22()) );
    QWidget::connect(p32, SIGNAL(clicked()), this, SLOT(OnOffPompeP32())   );




    //Connection boutons et classe -> Arrêt , Panne  et Marche d'une Pompe
    QWidget::connect(vt12, SIGNAL(clicked()), this, SLOT(OnOffVanneVT12()) );
    QWidget::connect(vt23, SIGNAL(clicked()), this, SLOT(OnOffVanneVT23()) );
    QWidget::connect(v12, SIGNAL(clicked()), this, SLOT(OnOffVanneV12())   );
    QWidget::connect(v13, SIGNAL(clicked()), this, SLOT(OnOffVanneV13())   );
    QWidget::connect(v23, SIGNAL(clicked()), this, SLOT(OnOffVanneV23())   );
    setCentralWidget(m_mainWidget);

}
void  MainWindow::OnOffVanneVT12(){  s.infoVanneVT12(); }
void  MainWindow::OnOffVanneVT23(){ s.infoVanneVT23();  }
void  MainWindow::OnOffVanneV12() { s.infoVanneV12();   }
void  MainWindow::OnOffVanneV13() { s.infoVanneV13();   }
void  MainWindow::OnOffVanneV23() { s.infoVanneV23();   }


void  MainWindow::OnOffPompeP12() { s.infoPompe12();   }
void  MainWindow::OnOffPompeP22() { s.infoPompe22();   }
void  MainWindow::OnOffPompeP32() { s.infoPompe32();   }
MainWindow::~MainWindow()
{
}


