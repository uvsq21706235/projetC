#include "window3.h"
#include <QWidget>
#include <string>

Window3::Window3(Simulateur &simi, QWidget *parent)
{
    s = simi;

    fenetre1 = new MainWindow(s, parent);
    fenetre2 = new Window2(s, parent);

    setWindowTitle("Simulateur d'avion de chasse ");
    test = new QWidget(this);
    layout = new QGridLayout(this);

    QPushButton *boutonid = new QPushButton("s'identifier", test);
    QPushButton *boutondec = new QPushButton("deconnexion", test);
    QPushButton *boutonhist = new QPushButton("historique", test);
    QPushButton *boutonex = new QPushButton("s'entraîner", test);

    layout->addWidget(boutonid, 1 ,1);
    layout->addWidget(boutondec, 1, 2);
    layout->addWidget(boutonhist, 2, 1, 1, 2);
    layout->addWidget(boutonex, 3, 1, 1, 2);

    test->setLayout(layout);
    setCentralWidget(test);

   QWidget::connect(boutonid, SIGNAL(clicked()), this, SLOT(identifier()));
   QWidget::connect(boutondec, SIGNAL(clicked()), this, SLOT(deconnexion()));
   QWidget::connect(boutonex, SIGNAL(clicked()), this, SLOT(entrainement()));
   QWidget::connect(boutonhist, SIGNAL(clicked()), this, SLOT(historique()));
}

bool Window3::verificationID(QString user, QString password){
    QString tmps = user + " " + password;
    string tmp = tmps.toStdString();
    ifstream fichier("/Users/salsabildf/Desktop/projetfinaleC++/projetC/projetC/connexion.txt");
    if(fichier)
    {
        string ligne; //Une variable pour stocker les lignes lues

                while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
                {
                    if (ligne == tmp){
                    return true;
                    }
                }
            }
            else
            {
                cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
            }
            return false;
}


void Window3::identifier(){
    bool ok = false;
    if (this->nom != ""){QMessageBox::information(this, "s'identifier ", "vous vous êtes déjà identifié");}
    else{
   QString username = QInputDialog::getText(this, " s'identifier ", "quel est votre identifiant ? ",QLineEdit::Normal, QString(), &ok);
   if (ok && !username.isEmpty()){
       QString password = QInputDialog::getText(this, " s'identifier ", "quel est votre mot de passe ? ",QLineEdit::Normal, QString(), &ok);
       if(ok && !password.isEmpty()){
         if (verificationID(username, password)) {
             this->nom = username.toStdString();
             QMessageBox::information(this, "s'identifier", "Bonjour " + username ) ;

             //creer le fichier de sauvegarde pour chaque utilisteur s'il n'est pas creer uniquement !
              string const cheminSave( "/Users/salsabildf/Desktop/projetfinaleC++/projetC/projetC/"+this->nom+".txt");
                 ifstream fichier(cheminSave.c_str());

                  if (fichier.is_open())
                  {
                     qDebug() << "fichier sauvegarde pour le pilote existant" << endl;

                  }
                  else
                  {
                       ofstream fichier(cheminSave.c_str());
                        if(fichier)
                           {
                               fichier << "Bonjour, Pilote " << this->nom << endl;

                           }
                           else
                           {
                               cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
                           }

                      qDebug()<< "creation fichier sauvegarde pour le pilote "<< endl;

                  }

    }
         else QMessageBox::critical(this, "s'identifier", "identifiant ou mot de passe incorects");
       }
    }
    }

}

void Window3::entrainement(){


    fenetre1->show();
    fenetre2->show();
}

void Window3::historique(){}



void Window3::sauvegarde(){
string  boutonMainWindow = fenetre1->boutonActive1();
string boutonWindow2 = fenetre2->boutonActive2();

   string const cheminSave( "/Users/salsabildf/Desktop/projetfinaleC++/projetC/projetC/"+this->nom+".txt");
   ofstream fichier(cheminSave.c_str());
    fichier.open (cheminSave, ofstream::out | ofstream::app);

    if (fichier)
      {
        //test
       fichier << boutonMainWindow;
       fichier << boutonWindow2;

       fichier.close();
      }
   else cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;


}




void Window3::deconnexion(){
    if (this->nom != ""){
        this->nom = "";
        QMessageBox::information(this, "deconnexion", "vous avez bien été déconnecté");
    }
    else QMessageBox::information(this, "deconnexion", "vous n'étiez pas connecté");
}

Window3::~Window3(){

}
