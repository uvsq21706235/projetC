#include "window3.h"
#include <QWidget>

Window3::Window3(QWidget *parent)
{
 //   MainWindow *mw= new MainWindow(s);
 //   Window3 *w = new Window3(s);
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
    ifstream fichier("/home/user/Bureau/projet/user.txt");
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
             QMessageBox::information(this, "s'identifier", "Bonjour " + username);
         }
         else QMessageBox::critical(this, "s'identifier", "identifiant ou mot de passe incorects");
       }
    }
    }

}

void Window3::entrainement(){
    if (this->nom != ""){
        Simulateur *s = new Simulateur(this->nom);
    Window2 *w = new Window2(s);
    MainWindow *m = new MainWindow(s);

    w->show();
    m->show();
    }
    else QMessageBox::critical(this, "entraînement", "veuillez vous connecter");
}

void Window3::historique(){
    if (this->nom != ""){
        string path = "/home/user/Bureau/projet/exercice/" + nom + ".txt";
        ifstream fichier(path);
        if(fichier)
        {

                cout << "fichier ouvert!";
         }
         else
                {
                    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
                }
    }
    else QMessageBox::critical(this, "historique", "veuillez vous connecter");
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
