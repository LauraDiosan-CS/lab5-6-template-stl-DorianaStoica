#include "Teste.h"
#include"Apartament.h"
#include "repository.h"
#include <assert.h>
#include <iostream>
#include "Ctrl.h"
using namespace std;

void Tests::tests()
{
	char*tip = new char[100];
	char*tip2 = new char[100];
	strcpy_s(tip, 100, "apartament");
	strcpy_s(tip, 100, "garsoniera");
	Apartament a1 = Apartament();
	Apartament a2 = Apartament(215, tip, 161);
	Apartament a3 = Apartament(a2);
	assert(a1.getNumar_ap() == 0);
	assert(a1.getSuma() == 0);
	assert(a1.getTip() == NULL);
	
	assert(a3.getNumar_ap() == 5);
	assert(a3.getSuma() == 10000);
	assert(strcmp(a3.getTip(), tip) == 0);
}

void Tests::testRepo()
{
	ApartamentRepository r;
	char*tip = new char[100];
	char*tip1 = new char[100];
	strcpy_s(tip, 100, "garsoniera");
	strcpy_s(tip1, 100, "apa");
	Apartament c1 = Apartament(25, tip, 100);
	Apartament c2 = Apartament(10, tip1, 50);
	r.addElem(c1);
	r.addElem(c2);
	r.eliminareTip(tip1);
	r.eliminareNrApartament(25);
	assert(r.getAll().size() == 2);
	assert(r.getAll().size() == 1);
	assert(r.getAll().size() == 1);
	

}

void Tests::testCtrl()
{
	Ctrl c;
	char* tip = new char[100];
	char* tip1 = new char[100];
	strcpy_s(tip, 100, "garsoniera");
	strcpy_s(tip1, 100, "apa");
	Apartament c1 = Apartament(25, tip, 100);
	Apartament  c2 = Apartament(213, tip1, 100);
	c.addElem(c1);
	c.addElem(c2);
	c.eliminareTip(tip1);
	c.eliminareIntervalApartamente(2, 6);
	c.eliminareNrApartament(25);
	c.updateTip(25, tip, 100);
	assert(c.getAll().size() == 2);
	assert(c.getAll().size() == 1);
	assert(c.getAll().size() == 1);
	assert(c.getAll().size() == 1);
	assert(c.getAll().size() == 1);
		
}
