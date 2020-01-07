#include "window2.h"
#include <QDebug>
#include <QFrame>
#include <QLabel>
#include <QLayout>
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
    m_vLayout4 = new QVBoxLayout(this);
    m_vLayout5 = new QVBoxLayout(this);
    m_vLayoutbis = new QVBoxLayout(this);


    text = new QHBoxLayout(this);
    m_hLayout = new QHBoxLayout(this);
    m_hLayout1 = new QHBoxLayout(this);

    txt = new QTextEdit();
    txt->setText(s.getEtat());
    text->addWidget(txt);

    txt->setReadOnly(true);
    QPushButton *exercice1 = new QPushButton( "Exercice 1", m_mainWidget );
    QPushButton *exercice2 = new QPushButton( "Exercice 2", m_mainWidget );
    QPushButton *exercice3 = new QPushButton( "Exercice 3", m_mainWidget );
    QPushButton *exercice4 = new QPushButton( "Exercice 4", m_mainWidget );
    QPushButton *exercice5 = new QPushButton( "Exercice 5", m_mainWidget );
    QPushButton *exercice6 = new QPushButton( "Exercice 6", m_mainWidget );
    QPushButton *exercice7 = new QPushButton( "Exercice 7", m_mainWidget );
    QPushButton *exercice8 = new QPushButton( "Exercice 8", m_mainWidget );
    QPushButton *exercice9 = new QPushButton( "Exercice 9", m_mainWidget );
    QPushButton *exercice10 = new QPushButton( "Exercice 10", m_mainWidget );

   // QPushButton *equilibrer = new QPushButton( "EQUILIBRER RESERVOIR", m_mainWidget );
    QPushButton *vidangeR1 = new QPushButton( "Vidange Reservoir Tank 1", m_mainWidget );
    QPushButton *vidangeR2 = new QPushButton("Vidange Reservoir Tank 2",  m_mainWidget);
    QPushButton *vidangeR3 = new QPushButton("Vidange Reservoir Tank 3", m_mainWidget);

    exercice1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    exercice2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    exercice3->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    exercice4->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    exercice5->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    exercice6->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    exercice7->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    exercice8->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    exercice9->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    exercice10->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);



    //equilibrer->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    vidangeR1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    vidangeR2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    vidangeR3->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);




    QPushButton *pannep11 = new QPushButton("panne Pompe 11", m_mainWidget);
    QPushButton *pannep12 = new QPushButton("panne Pompe 12", m_mainWidget);
    QPushButton *panne21 = new QPushButton( "panne Pompe 21", m_mainWidget);
    QPushButton *panne22 = new QPushButton( "panne Pompe 22",m_mainWidget );
    QPushButton *panne31 = new QPushButton( "panne Pompe 31", m_mainWidget );
    QPushButton *panne32 = new QPushButton( "panne Pompe 32", m_mainWidget );

    QPushButton *Actualiser = new QPushButton( "Actualiser", m_mainWidget );
    pannep11->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    pannep12->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    panne21->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    panne22->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    panne31->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    panne32->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    Actualiser->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

  // m_vLayout1->addWidget(equilibrer);
   m_vLayout1->addWidget(vidangeR1);
   m_vLayout1->addWidget(vidangeR2);
   m_vLayout1->addWidget(vidangeR3);

   m_vLayout2->addWidget(pannep11);
   m_vLayout2->addWidget(panne21);
   m_vLayout2->addWidget(panne31);

   m_vLayout3->addWidget(pannep12);
   m_vLayout3->addWidget(panne22);
   m_vLayout3->addWidget(panne32);

   m_vLayout5->addWidget(exercice1);
   m_vLayout5->addWidget(exercice2);
   m_vLayout5->addWidget(exercice3);
   m_vLayout5->addWidget(exercice4);
   m_vLayout5->addWidget(exercice5);
   m_vLayout5->addWidget(exercice6);
   m_vLayout5->addWidget(exercice7);
   m_vLayout5->addWidget(exercice8);
   m_vLayout5->addWidget(exercice9);
   m_vLayout5->addWidget(exercice10);

   m_vLayout4->addWidget(Actualiser);

   m_vLayout1->addSpacing(50);
   m_vLayout2->addSpacing(50);
   m_vLayout3->addSpacing(50);
   m_vLayout5->addSpacing(50);
   m_vLayout4->addSpacing(50);

   m_hLayout->addLayout(m_vLayout1);
   m_hLayout->addLayout(m_vLayout2);
   m_hLayout->addLayout(m_vLayout3);
   m_hLayout->addLayout(m_vLayout4);
   m_hLayout->addLayout(m_vLayout5);
   m_hLayout->addLayout(text);

   m_mainWidget->setLayout(m_hLayout);
   setCentralWidget(m_mainWidget);

        //connect boutons exos
        QWidget::connect(exercice1,SIGNAL(clicked()), this, SLOT(simu_exercice1()));
        QWidget::connect(exercice2,SIGNAL(clicked()), this, SLOT(simu_exercice2()));
        QWidget::connect(exercice3,SIGNAL(clicked()), this, SLOT(simu_exercice3()));
        QWidget::connect(exercice4,SIGNAL(clicked()), this, SLOT(simu_exercice4()));
        QWidget::connect(exercice5,SIGNAL(clicked()), this, SLOT(simu_exercice5()));
        QWidget::connect(exercice6,SIGNAL(clicked()), this, SLOT(simu_exercice6()));
        QWidget::connect(exercice7,SIGNAL(clicked()), this, SLOT(simu_exercice7()));
        QWidget::connect(exercice8,SIGNAL(clicked()), this, SLOT(simu_exercice8()));
        QWidget::connect(exercice9,SIGNAL(clicked()), this, SLOT(simu_exercice9()));
        QWidget::connect(exercice10,SIGNAL(clicked()), this, SLOT(simu_exercice10()));

    //connect  bouton pour equilibrer les vannes
   // QWidget::connect(equilibrer,SIGNAL(clicked()), this, SLOT(equilibrage()));

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

    QWidget::connect(Actualiser, SIGNAL(clicked()), this, SLOT(update())   );


    setCentralWidget(m_mainWidget);


}
void Window2::simu_exercice1(){
          s.ex_pannepompe11();
          s.ex_pannepompe31();
          update();

          QMessageBox::critical(this, "  Exercice 1 ", "DEFAILLANCE !/nPompe primaire Tank 1 en panne.\nPompe primaire Tank 3 en panne.");

}


void Window2::simu_exercice2(){
            s.ex_vidangeR1();
            update();
           QMessageBox::critical(this, "  Exercice 2 ", "VIDANGE !\nReservoir Tank 1 s'est vidé.");

}
void Window2::simu_exercice3(){
        s.ex_pannepompe21();
        update();
      QMessageBox::critical(this, "  Exercice 3 ", "DEFAILLANCE \nPompe primaire Tank 2.");

}
void Window2::simu_exercice4(){
            s.ex_vidangeR2();
            s.ex_vidangeR3();
            update();
           QMessageBox::critical(this, "  Exercice 4 ", "VIDANGE !\nReservoirs Tank 3 et Tank 2 se sont vidés.");

}
void Window2::simu_exercice5(){
    s.ex_pannepompe11();
    s.ex_pannepompe12();
    update();
      QMessageBox::critical(this, "  Exercice 5 ", "DEFAILLANCE !\nPompe primaire et secondaire du reservoir Tank 1 en panne.");

}
void Window2::simu_exercice6(){
        s.ex_pannepompe21();
        s.ex_pannepompe31();
        s.ex_pannepompe32();
        update();
           QMessageBox::critical(this, "  Exercice 6 ", "DEFAILLANCE !\nPompe primaire Tank 2 en panne.\n Pompe primaire et secondaire Tank 3 en panne.");

}
void Window2::simu_exercice7(){
    s.ex_vidangeR3();
    s.ex_vidangeR2();
    s.ex_pannepompe11();
    update();
      QMessageBox::critical(this, "  Exercice 7 ", "VIDANGE et DEFAILLANCE !\nReservoirs Tank 2 et Tank 3 se sont vidés.\n  Pompe primaire Tank 1 en panne.");

}
void Window2::simu_exercice8(){
    s.ex_vidangeR1();
    s.ex_vidangeR3();
    s.ex_pannepompe11();
    update();
           QMessageBox::critical(this, "  Exercice 8 ", "VIDANGE et DEFAILLANCE !\nReservoirs Tank 1 et Tank 3 se sont vidés.\n  Pompe primaire Tank 1 en panne.");

}
void Window2::simu_exercice9(){
      s.ex_vidangeR3();
        update();
      QMessageBox::critical(this, "  Exercice 9 ", "VIDANGE !\nReservoir Tank 3  s'est vidé." );

}
void Window2::simu_exercice10(){
    s.ex_vidangeR1();
    s.ex_pannepompe31();
    s.ex_pannepompe32();
      update();
      QMessageBox::critical(this, "  Exercice 10 ", "VIDANGE et DEFAILLANCE !\nReservoirs Tank 1 s'est vidé.\nPompe primaire et secondaire Tank 3 en panne.");

}


void Window2::equilibrage(){
                           s.equilibre_res();
                              qDebug() << "glob"<<endl;
                        }
void Window2::update(){txt->setText(s.getEtat());
                       text->addWidget(txt);}
//vidange reservoir
void Window2::VidangeReservoir1(){ s.ex_vidangeR1();
                                   update();
                                   QMessageBox::critical(this, "  Exercice pilote ", "Vidange du reservoir Tank 1 ");}
void  Window2::VidangeReservoir2(){s.ex_vidangeR2();
                                   update();
                                   QMessageBox::critical(this, "  Exercice pilote ", "Vidange du reservoir Tank 2 ");}
void  Window2::VidangeReservoir3(){s.ex_vidangeR3();
                                   update();
                                   QMessageBox::critical(this, "  Exercice pilote ", "Vidange du reservoir Tank 3 ");}

 //panne Pompe
void  Window2::PannePompe11(){s.ex_pannepompe11();
                              update();
                              QMessageBox::critical(this, "  Exercice pilote ", "Injection Panne dans la pompe P11 ");}
void  Window2::PannePompe12(){s.ex_pannepompe12();
                              update();
                              QMessageBox::critical(this, "  Exercice pilote ", "Injection Panne dans la pompe P12 ");}
void  Window2::PannePompe21(){s.ex_pannepompe21();
                              update();
                              QMessageBox::critical(this, "  Exercice pilote ", "Injection Panne dans la pompe P21 ");}
 void  Window2::PannePompe22(){s.ex_pannepompe22();
                               update();
                               QMessageBox::critical(this, "  Exercice pilote ", "Injection Panne dans la pompe P22 ");}
 void  Window2::PannePompe31(){s.ex_pannepompe31();
                               update();
                               QMessageBox::critical(this, "  Exercice pilote ", "Injection Panne dans la pompe P31 ");}
 void  Window2::PannePompe32(){s.ex_pannepompe32();
                               update();
                               QMessageBox::critical(this, "  Exercice pilote ", "Injection Panne dans la pompe P32 ");}

 Window2::~Window2(){};
