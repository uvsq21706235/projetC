#include "application.h"

Application::Application(QWidget*parent):S(new Simulateur), M(new MainWindow (parent)) {
/*
    connect(M->vt12, SIGNAL(clicked(bool)), this, SLOT(powerVanne(S.getVanneVT12())));
    connect(M->vt23, SIGNAL(clicked(bool)), this, SLOT(powerVanne(S.getVanneVT23())));

    connect(M->v12, SIGNAL(clicked(bool)), this, SLOT(powerVanne(S.getVanneV12())));
    connect(M->v13, SIGNAL(clicked(bool)), this, SLOT(powerVanne(S.getVanneV13())));
    connect(M->v23, SIGNAL(clicked(bool)), this, SLOT(powerVanne(S.getVanneV23())));

    connect(M->p12, SIGNAL(clicked(bool)), this, SLOT(powerPompe(S.getPompe12())));
    connect(M->p22, SIGNAL(clicked(bool)), this, SLOT(powerPompe(S.getPompe22())));
    connect(M->p32, SIGNAL(clicked(bool)), this, SLOT(powerPompe(S.getPompe32())));*/
}

Application::~Application() {

}

void Application::powerVanne(Vanne& v) {
    v.power();
}

void Application::powerPompe(Pompe& p) {
    p.power();
}
void Application::pannePompe(Pompe& p) {
    p.panne();
}
