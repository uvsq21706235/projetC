#include "application.h"

Application::Application(QWidget*parent):S(new Simulateur), M(parent) {

	connect(M->vt12, SIGNAL(clicked(bool)), this, SLOT(powerVanne(S.getVanneVT12())));
	connect(M->vt23, SIGNAL(clicked(bool)), this, SLOT(powerVanne(S.getVanneVT23())));

	connect(M->p12, SIGNAL(clicked(bool)), this, SLOT(powerPompe(S.getPompe12())));
	connect(M->p22, SIGNAL(clicked(bool)), this, SLOT(powerPompe(S.getPompe22())));
	connect(M->p32, SIGNAL(clicked(bool)), this, SLOT(powerPompe(S.getPompe32())));
}

~Application() {

}

void Application::powerVanne(Vanne& v) {
	v->power();
}

void Application::powerPompe(Pompe& p) {
	p->power();
}
void Application::pannePompe(Pompe& p) {
	p->panne();
}