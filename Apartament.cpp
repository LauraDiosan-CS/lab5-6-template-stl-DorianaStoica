#include "Apartament.h"
#include <string.h>
#include <iostream>
using namespace std;

Apartament::Apartament()
{
	//cout << "Constructor implicit" << endl;
	this->numar_ap = 0;
	this->tip = NULL;
	this->suma = 0;
}
Apartament::Apartament(int numar_ap, char* tip, int suma)
{
	//cout << "Constructor cu parametrii" << endl;
	this->numar_ap = numar_ap;
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
	this->suma = suma;
}
Apartament::Apartament(const Apartament&a)
{
	//cout << "Constructor de copiere" << endl;
	this->numar_ap = a.numar_ap;
	this->tip = new char[strlen(a.tip) + 1];
	strcpy_s(this->tip, strlen(a.tip) + 1, a.tip);
	this->suma = a.suma;
}
Apartament::~Apartament() {
	if (this->tip != NULL)
	{
		//cout << "destructor" << endl;
		delete[]this->tip;
		this->tip = NULL;
	}
}
void Apartament::setNumar_ap(int n)
{
	this->numar_ap = n;
}
void Apartament::setTip(char* t)
{
	if (this->tip)
	{
		delete[]this->tip;
	}
	this->tip = new char[strlen(t) + 1];
	strcpy_s(this->tip, strlen(t) + 1, t);
}
void Apartament::setSuma(int s)
{
	this->suma = s;
}
Apartament& Apartament::operator=(const Apartament&a)
{
	//cout << "supraincarcarea lui =" << endl;
	if (this != &a)
	{
		this->setNumar_ap(a.numar_ap);
		this->setTip(a.tip);
		this->setSuma(a.suma);
	}
	return *this;
}
