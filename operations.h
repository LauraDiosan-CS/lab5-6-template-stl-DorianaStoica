#pragma once
#pragma once
#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <iostream>
#include <vector>
#include"Apartament.h"
using namespace std;

void addElem(Apartament a);
vector<Apartament>getAll();
vector<Apartament>apartamenteSelectate(int limita);
void eliminareNrApartament(int nrApartament);
void eliminareIntervalApartamente(int left, int right);
void eliminareTip(char *tip);

#endif // !OPERATIONS_H


