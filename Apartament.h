
#pragma once

#ifndef APARTAMENT_H
#define APARTAMENT_H
#include <iostream>
using namespace std;
class Apartament {
private:
	int numar_ap;
	char* tip;
	int suma;
public:
	Apartament();
	Apartament(int numar_ap, char* tip, int suma);
	Apartament(const Apartament &apartament);
	~Apartament();
	int getNumar_ap()
	{
		return this->numar_ap;
	}
	char* getTip()
	{
		return this->tip;
	}
	int getSuma()
	{
		return this->suma;
	}
	void setNumar_ap(int n);
	void setTip(char* t);
	void setSuma(int s);
	Apartament& operator=(const Apartament& a);
};

#endif // !APARTAMENT_H