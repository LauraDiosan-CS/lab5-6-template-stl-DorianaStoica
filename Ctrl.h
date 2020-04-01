
#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Apartament.h"
#include "repository.h"
#include <vector>
#include <iostream>
using namespace std;

class Ctrl {
private:
	ApartamentRepository repo;
public:
	Ctrl();
	~Ctrl();
	Ctrl(ApartamentRepository repo);
	void addElem(Apartament a);
	vector<Apartament> getAll();
	vector<Apartament> apartamenteSelectate(int limita);
	void eliminareNrApartament(int nrApartament);
	void eliminareIntervalApartamente(int left, int right);
	void eliminareTip(char *tip);
	vector<Apartament> inlocuireSuma(char *tip, int nrAp, int sumaNoua);
	vector<Apartament> filtrareTip(char *tip);
	vector<Apartament>filtrareSuma(int suma);
	void inserareLista();
	void undoLista();
	void listeaza();
	void listeaza(vector<Apartament> lista);
	void listeazaAp(int nr);
	void listeazaSumaMaiMareDecat(int suma);
	void listeazaSuma(int suma);
	void updateTip(int ap, char* tip, int suma);
};

#endif // !CONTROLLER_H


