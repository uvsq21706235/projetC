#include "simulateur.h"


Simulateur::Simulateur(string nom)
    {
        this->nom = nom;

        p11 = new Pompe( "p11",1);
        p12 = new Pompe("p12");
        p21 = new Pompe("p21",1);
        p22 = new Pompe("p22");
        p31 = new Pompe("p31",1);
        p32 = new Pompe("p32");

        r1 = new Reservoir(1000, "Tank1", p11, p12);
        r2 = new Reservoir(5000, "Tank2", p21, p22);
        r3 = new Reservoir(1000, "Tank3", p32, p32);

        m1 = new Moteur(*r1 );
        m2 = new Moteur(*r2);
        m3 = new Moteur(*r3);


         VT12 = new Vanne("VT12");
         VT23 = new Vanne("VT23");
         V12 = new Vanne("V12");
         V13 = new Vanne("V13");
         V23 = new Vanne("V23");
}

        void Simulateur::infoVanneVT12() { VT12->power(); if (VT12->get_etat() ) equilibre_res();}
        void Simulateur::infoVanneVT23() { VT23->power(); if (VT23->get_etat() ) equilibre_res();}
        void Simulateur::infoVanneV12()  { V12->power();}
        void Simulateur::infoVanneV13()  { V13->power();}
        void Simulateur::infoVanneV23()  { V23->power();}


        void Simulateur::infoPompe12() { p12->power();}
        void Simulateur::infoPompe22() { p22->power();}
        void Simulateur::infoPompe32() { p32->power();}

        void Simulateur::ex_vidangeR1(){r1->vidange(); }
        void Simulateur::ex_vidangeR2(){r2->vidange();}
        void Simulateur::ex_vidangeR3(){r3->vidange();}

        void Simulateur::ex_pannepompe11(){ p11->panne();}
        void Simulateur::ex_pannepompe12(){ p12->panne();}
        void Simulateur::ex_pannepompe21(){ p21->panne();}
        void Simulateur::ex_pannepompe22(){ p22->panne();}
        void Simulateur::ex_pannepompe31(){ p31->panne();}
        void Simulateur::ex_pannepompe32(){ p32->panne();}


        // getter VANNE
        int Simulateur::getEtatVanneVT12(){ return VT12->get_etat();}
        int Simulateur::getEtatVanneVT23(){ return VT23->get_etat();}
        int Simulateur::getEtatVanneV12(){ return V12->get_etat(); }
        int Simulateur::getEtatVanneV13(){ return V13->get_etat(); }
        int Simulateur::getEtatVanneV23(){ return V23->get_etat(); }

        //getter POMPE
        int Simulateur::getEtatPompep11(){ return p11->get_etat(); }
        int Simulateur::getEtatPompep12(){ return p12->get_etat(); }
        int Simulateur::getEtatPompep21(){ return p21->get_etat(); }
        int Simulateur::getEtatPompep22(){ return p22->get_etat(); }
        int Simulateur::getEtatPompep31(){ return p31->get_etat(); }
        int Simulateur::getEtatPompep32(){ return p32->get_etat(); }

        //getter RESERVOIR
        int  Simulateur::getEtatReservoirR1(){ return r1->get_etatReservoir(); }
        int  Simulateur::getEtatReservoirR2(){ return r2->get_etatReservoir(); }
        int  Simulateur::getEtatReservoirR3(){ return r3->get_etatReservoir(); }

        //getter MOTEUR
        int Simulateur::getPompeM1(){return m1->getPompe();}
        int Simulateur::getPompeM2(){return m2->getPompe();}
        int Simulateur::getPompeM3(){return m3->getPompe();}
        QString Simulateur::getResM1(){return m1->getReservoir()->get_nom();}
        QString Simulateur::getResM2(){return m2->getReservoir()->get_nom();}
        QString Simulateur::getResM3(){return m3->getReservoir()->get_nom();}

        QString Simulateur::getEtat(){
            QString tmp = "<html> <body>";

            //initialisqation avec l'etat des reservoirs
            if (getEtatReservoirR1()) tmp += "tank1 est plein <br>";
            else tmp +=  "tank1 est vide ! <br>";
            if (getEtatReservoirR2()) tmp += "tank2 est plein <br>";
            else tmp +=  "tank2 est vide ! <br>";
            if (getEtatReservoirR3()) tmp += "tank3 est plein <br><br>";
            else tmp +=  "tank3 est vide ! <br><br>";

            //initialisation avec l'etat des pompes
            if (getEtatPompep11() == 0) tmp += "pompe11 est a l'arrêt <br>";
            else if(getEtatPompep11() == 1) tmp += "pompe11 est en marche <br>";
            else tmp += "pompe11 est en panne... <br>";
            if (getEtatPompep12()==0) tmp += "pompe12 est a l'arrêt <br>";
            else if(getEtatPompep12()==1) tmp += "pompe12 est en marche <br>";
            else tmp += "pompe12 est en panne... <br>";

            if (getEtatPompep21()==0) tmp += "pompe21 est a l'arrêt <br>";
            else if(getEtatPompep21()==1) tmp += "pompe21 est en marche <br>";
            else tmp += "pompe21 est en panne... <br>";
            if (getEtatPompep22()==0) tmp += "pompe22 est a l'arrêt <br>";
            else if(getEtatPompep22()==1) tmp += "pompe22 est en marche <br>";
            else tmp += "pompe22 est en panne... <br>";

            if (getEtatPompep31()==0) tmp += "pompe31 est a l'arrêt <br>";
            else if(getEtatPompep31()==1) tmp += "pompe31 est en marche <br>";
            else tmp += "pompe31 est en panne... <br>";
            if (getEtatPompep32()==0) tmp += "pompe32 est a l'arrêt <br><br>";
            else if(getEtatPompep32()==1) tmp += "pompe32 est en marche <br><br>";
            else tmp += "pompe32 est en panne... <br><br>";

            //initialistion avec l'etat des vannes
            if(getEtatVanneV12()) tmp += "vanneV12 est ouverte <br>";
            else tmp += "vanneV12 est fermée <br>";
            if(getEtatVanneV13()) tmp += "vanneV13 est ouverte <br>";
            else tmp += "vanneV13 est fermée <br>";
            if(getEtatVanneV23()) tmp += "vanneV23 est ouverte <br>";
            else tmp += "vanneV23 est fermée <br>";
            if(getEtatVanneVT12()) tmp += "vanneVT12 est ouverte <br>";
            else tmp += "vanneVT12 est fermée <br>";
            if(getEtatVanneVT23()) tmp += "vanneVT23 est ouverte <br><br>";
            else tmp += "vanneVT23 est fermee <br><br>";

            //initialisation avec l'etat des moteurs
            if(getPompeM1())tmp += "moteur1 approvisionné par la pompe primaire de " + getResM1() +"<br>";
            else tmp += "moteur1 approvisionné par la pompe secondaire de " + getResM1() + "<br>";
            if(getPompeM2())tmp += "moteur2 approvisionné par la pompe primaire de " + getResM2() +"<br>";
            else tmp += "moteur2 approvisionné par la pompe secondaire de " + getResM2() + "<br>";
            if(getPompeM3())tmp += "moteur3 approvisionné par la pompe primaire de " + getResM3() +"<br><br>";
            else tmp += "moteur3 approvisionné par la pompe secondaire de " + getResM3() + "<br><br>";


            tmp += "</body> </html>";
            return tmp;
        }

        //FLUX DE CHAQUE MOTEUR
        //(implementation)
        //permet d'equilibrer les reservoirs
    void Simulateur::equilibre_res(){
        int glob;
        if (VT12->get_etat()) {
            if (VT23->get_etat()){
                glob = r1->get_etatReservoir() + r2->get_etatReservoir() + r3->get_etatReservoir();
                if (glob/3 < MAX2){
                    r1->set_capacite(glob);
                    r2->set_capacite(glob);
                    r3->set_capacite(glob);
                    qDebug() << glob<<endl;

                }
                else{
                    r2->set_capacite(MAX2);
                    glob = (glob-MAX2)/2;
                    r1->set_capacite(glob);
                    r3->set_capacite(glob);

                }
            }
            else {
                glob = r1->get_etatReservoir() + r2->get_etatReservoir();
                if (glob/2 < MAX2){
                    r2->set_capacite(glob/2);
                    r1->set_capacite(glob/2);
                }
                else{
                    r2->set_capacite(MAX2);
                    r1->set_capacite(glob-MAX2);
                }
            }
        }
        else{
            if (VT23->get_etat()){
                glob = r3->get_etatReservoir() + r2->get_etatReservoir();
                if (glob/2 < MAX2){
                    r2->set_capacite(glob/2);
                    r3->set_capacite(glob/2);
                }
                else{
                    r2->set_capacite(MAX2);
                    r3->set_capacite(glob-MAX2);
                }
            }
        }


    }

Simulateur::~Simulateur(){}

