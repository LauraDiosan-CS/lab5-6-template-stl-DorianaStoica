#pragma once
#ifndef UI_H
#define UI_H
#include "Apartament.h"
#include "repository.h"
#include "Ctrl.h"
using namespace std;

class UI {
private:
	Ctrl ctrl;
	void printMenu();
	void addElem(Apartament a);
	vector<Apartament> getAll();
	vector<Apartament> apartamenteSelectate(int limita);
	void eliminareNrApartament(int nrApartament);
	void eliminareIntervalApartamente(int left, int right);
	void eliminareTip(char *tip);
	vector<Apartament>inlocuireSuma(char *tip, int nrAp, int sumaNoua);
	vector<Apartament> filtrareTip(char *tip);
	void filtrareSuma(int suma);
	void inserareLista();
	void undoLista();
	bool validTip(char *tip);
	void listeaza();
	void listeaza(vector<Apartament> lista);
	void listeazaAp(int nr);
	void listeazaSumaMaiMareDecat(int suma);
	void listeazaSuma(int suma);
	void updateTip(int ap, char* tip, int suma);
public:
	UI();
	~UI();
	UI(Ctrl ctrl);

	void run();
};
#endif // !UI_H
