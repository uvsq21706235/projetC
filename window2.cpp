#include "window2.h"
#include <QDebug>
#include <QFrame>
#include <simulateur.h>

Window2::Window2(Simulateur &simi, QWidget *parent) : QMainWindow(parent)
{
     this->s = simi;
    setWindowTitle("Simulateur d'avion de chasse ");
  //  m_customBtn = new CustomButton(this);

    //setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    m_mainWidget = new QWidget(this);
    m_vLayout1 = new QVBoxLayout(this);
    m_vLayout2 = new QVBoxLayout(this);
    m_vLayout3 = new QVBoxLayout(this);
    m_vLayoutbis = new QVBoxLayout(this);

    m_hLayout = new QHBoxLayout(this);
    m_hLayout1 = new QHBoxLayout(this);

    QPushButton *vidangeR1 = new QPushButton( "Vidange Reservoir Tank 1", m_mainWidget );
    QPushButton *vidangeR2 = new QPushButton("Vidange Reservoir Tank 2",  m_mainWidget);
    QPushButton *vidangeR3 = new QPushButton("Vidange Reservoir Tank 3", m_mainWidget);

    vidangeR1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    vidangeR2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    vidangeR3->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);




    QPushButton *pannep11 = new QPushButton("panne Pompe 11", m_mainWidget);
    QPushButton *pannep12 = new QPushButton("panne Pompe 12", m_mainWidget);
    QPushButton *panne21 = new QPushButton( "panne Pompe 21", m_mainWidget);
    QPushButton *panne22 = new QPushButton( "panne Pompe 22",m_mainWidget );
    QPushButton *panne31 = new QPushButton( "panne Pompe 31", m_mainWidget );
    QPushButton *panne32 = new QPushButton( "panne Pompe 32", m_mainWidget );

    pannep11->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    pannep12->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    panne21->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    panne22->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    panne31->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    panne32->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

   m_vLayout1->addWidget(vidangeR1);
   m_vLayout1->addWidget(vidangeR2);
   m_vLayout1->addWidget(vidangeR3);

   m_vLayout2->addWidget(pannep11);
   m_vLayout2->addWidget(panne21);
   m_vLayout2->addWidget(panne31);

   m_vLayout3->addWidget(pannep12);
   m_vLayout3->addWidget(panne22);
   m_vLayout3->addWidget(panne32);


   m_vLayout1->addSpacing(50);
   m_vLayout2->addSpacing(50);
   m_vLayout3->addSpacing(50);

   m_hLayout->addLayout(m_vLayout1);
   m_hLayout->addLayout(m_vLayout2);
   m_hLayout->addLayout(m_vLayout3);

   m_mainWidget->setLayout(m_hLayout);
  setCentralWidget(m_mainWidget);

   //Connection boutons et classe -> Vidange
    QWidget::connect(vidangeR1, SIGNAL(clicked()), this, SLOT(VidangeReservoir1()) );
    QWidget::connect(vidangeR2, SIGNAL(clicked()), this, SLOT(VidangeReservoir2()) );
    QWidget::connect(vidangeR3, SIGNAL(clicked()), this, SLOT(VidangeReservoir3())   );




    //Connection boutons et classe -> Panne
    QWidget::connect(pannep11, SIGNAL(clicked()), this, SLOT(PannePompe11()) );
    QWidget::connect(pannep12, SIGNAL(clicked()), this, SLOT(PannePompe12()) );
    QWidget::connect(panne21, SIGNAL(clicked()), this, SLOT(PannePompe21())   );
    QWidget::connect(panne22, SIGNAL(clicked()), this, SLOT(PannePompe22())   );
    QWidget::connect(panne31, SIGNAL(clicked()), this, SLOT(PannePompe31())   );
    QWidget::connect(panne32, SIGNAL(clicked()), this, SLOT(PannePompe32())   );


    setCentralWidget(m_mainWidget);


}
//vidange reservoir
void Window2::VidangeReservoir1(){ }
void  Window2::VidangeReservoir2(){}
void  Window2::VidangeReservoir3(){}

 //panne Pompe
void  Window2::PannePompe11(){}
void  Window2::PannePompe12(){}
void  Window2::PannePompe21(){}
 void  Window2::PannePompe22(){}
 void  Window2::PannePompe31(){}
 void  Window2::PannePompe32(){}

 Window2::~Window2(){};