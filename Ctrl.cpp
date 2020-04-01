#include "Ctrl.h"
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;
vector<Apartament> apartamente;
vector<vector<Apartament>> list;

Ctrl::Ctrl()
{

}
Ctrl::~Ctrl()
{

}
Ctrl::Ctrl(ApartamentRepository repo)
{
	this->repo = repo;
}
void Ctrl::addElem(Apartament a)
{
	repo.addElem(a);
}

vector<Apartament>Ctrl::getAll()
{
	return repo.getAll();
}
vector <Apartament>Ctrl::apartamenteSelectate(int limita)
{
	return repo.apartamenteSelectate(limita);
}

void Ctrl::eliminareNrApartament(int nrApartament)
{
	repo.eliminareNrApartament(nrApartament);
}

void Ctrl::eliminareIntervalApartamente(int left, int right)
{
	repo.eliminareIntervalApartamente(left, right);
}

void Ctrl::eliminareTip(char *tip)
{
	repo.eliminareTip(tip);
}



vector<Apartament> Ctrl::inlocuireSuma(char *tip, int nrAp, int sumaNoua)
{

	return repo.inlocuireSuma(tip, nrAp, sumaNoua);
}

vector<Apartament> Ctrl::filtrareTip(char *tip)
{
	return repo.filtrareTip(tip);
}


vector<Apartament> Ctrl::filtrareSuma(int suma)
{
	return repo.filtrareSuma(suma);
}

void Ctrl::inserareLista()
{
	vector<Apartament> ap = apartamente;
	list.push_back(ap);

	cout << endl;
	for (vector<Apartament> a : list)
	{
		for (int i = 0; i < a.size(); i++)
			cout << a.at(i).getSuma() << " ";

		cout << endl;
	}
	cout << endl;

}

void Ctrl::undoLista()
{
	if (list.empty())
		cout << "Nu avem ce undo sa facem\n";

	if (list.size() == 1)
	{
		vector<Apartament> vectorAp;
		apartamente = vectorAp;
		return;
	}

	vector<Apartament> vectorAp = list[list.size() - 2];

	apartamente = vectorAp;

	cout << endl;
	for (int i = 0; i < apartamente.size(); i++)
		cout << apartamente.at(i).getSuma() << " ";
	cout << endl;


	list.pop_back();
}

void Ctrl::listeaza()
{
	vector<Apartament>lista = repo.getAll();
	for (int i = 0; i < lista.size(); i++)
	{
		Apartament a = lista.at(i);
		cout << "Ap nr:";
		cout << a.getNumar_ap();
		cout << " - ";
		cout << a.getSuma();
		cout << " lei -  ";
		cout << a.getTip() << endl;
	}
}

void Ctrl::listeaza(vector<Apartament> lista)
{
	for (int i = 0; i < lista.size(); i++)
	{
		Apartament a = lista.at(i);
		cout << "Ap nr:";
		cout << a.getNumar_ap();
		cout << " - ";
		cout << a.getSuma();
		cout << " lei -  ";
		cout << a.getTip() << endl;
	}
}

void Ctrl::listeazaAp(int nr)
{
	vector<Apartament>lista = repo.getAll();
	for (int i = 0; i < lista.size(); i++)
	{
		Apartament a = lista.at(i);
		if (a.getNumar_ap() == nr)
		{
			cout << "Ap nr:";
			cout << a.getNumar_ap();
			cout << " - ";
			cout << a.getSuma();
			cout << " lei -  ";
			cout << a.getTip() << endl;
		}
	}
}

void Ctrl::listeazaSumaMaiMareDecat(int suma)
{
	vector<Apartament>lista = repo.getAll();
	for (int i = 0; i < lista.size(); i++)
	{
		Apartament a = lista.at(i);
		if (a.getSuma() > suma)
		{
			cout << "Ap nr:";
			cout << a.getNumar_ap();
			cout << " - ";
			cout << a.getSuma();
			cout << " lei -  ";
			cout << a.getTip() << endl;
		}
	}
}

void Ctrl::listeazaSuma(int suma)
{
	vector<Apartament>lista = repo.getAll();
	for (int i = 0; i < lista.size(); i++)
	{
		Apartament a = lista.at(i);
		if (a.getSuma() == suma)
		{
			cout << "Ap nr:";
			cout << a.getNumar_ap();
			cout << " - ";
			cout << a.getSuma();
			cout << " lei -  ";
			cout << a.getTip() << endl;
		}
	}
}
void Ctrl::updateTip(int ap, char * tip, int suma)
{
	repo.updateTip(ap, tip, suma);
}