#pragma once
#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <iostream>
#include <vector>
#include "Apartament.h"


using namespace std;

class ApartamentRepository
{
private:
	vector<Apartament>apartamente;
	vector<vector<Apartament>> list;
public:
	ApartamentRepository();
	void loadData();
	void saveData();
	void addElem(Apartament a);
	vector<Apartament>getAll();
	vector<Apartament>apartamenteSelectate(int limita);
	void eliminareNrApartament(int nrApartament);
	void eliminareIntervalApartamente(int left, int right);
	void eliminareTip(char *tip);
	void updateTip(int ap, char* tip, int suma);
	vector<Apartament>inlocuireSuma(char *tip, int nrAp, int sumaNoua);
	vector<Apartament> filtrareTip(char *tip);
	vector<Apartament> filtrareSuma(int suma);
	void inserareLista();
	void undoLista();
};
#endif // !REPOSITORY_H
