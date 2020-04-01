#include "repository.h"
#include <string.h>
#include <fstream>
using namespace std;

ApartamentRepository::ApartamentRepository() {
	loadData();
}

void ApartamentRepository::loadData()
{
	ifstream fin;
	fin.open("date.txt");
	if (!fin) {
		cout << "erroare la deschiderea fisierului" << endl;
	}
	else {
		Apartament t;
		char tip[10];
		int nr;
		int suma;
		//not end of file
		while (fin >> tip >> nr >> suma) {
			t = Apartament(nr, tip, suma);
			apartamente.push_back(t);
		}
		fin.close();
	}
}

void ApartamentRepository::saveData()
{
	ofstream outputFile;
	outputFile.open("date.txt");

	for (Apartament t : apartamente) {
		outputFile << t.getTip() << " " << t.getNumar_ap() << " " << t.getSuma() << endl;
	}
	outputFile.close();
}


void ApartamentRepository::addElem(Apartament a)
{
	apartamente.push_back(a);
	saveData();
}
vector<Apartament>ApartamentRepository::getAll()
{
	return apartamente;
}
vector <Apartament>ApartamentRepository::apartamenteSelectate(int limita)
{
	vector<Apartament>apartamenteSelectate;
	for (Apartament a : apartamente)
	{
		if (a.getNumar_ap() > limita && a.getSuma() > limita)
		{
			apartamenteSelectate.push_back(a);
		}
	}
	return apartamenteSelectate;
}

void ApartamentRepository::eliminareNrApartament(int nrApartament)
{
	// Parcurgem toate apartamentele
	for (int i = 0; i < apartamente.size(); i++)
	{
		// Aflam apartamentul curent (aflat la pozitia i)
		Apartament ap = apartamente.at(i);

		if (ap.getNumar_ap() == nrApartament)
		{
			apartamente.erase(apartamente.begin() + i); // stergem al i-lea apartament
			i--;
		}
	}
}

void ApartamentRepository::eliminareIntervalApartamente(int left, int right)
{
	// Parcurgem toate apartamentele
	for (int i = 0; i < apartamente.size(); i++)
	{
		// Aflam apartamentul curent (aflat la pozitia i)
		Apartament ap = apartamente.at(i);

		// Parcurgem toate numerele de apartamente care trebuie sa fie sterse
		for (int j = left; j <= right; j++)
		{
			// Daca apartamentul curent are numarul de apart. care trebuie sters 
			if (ap.getNumar_ap() == j)
			{
				apartamente.erase(apartamente.begin() + i);
				i--;
				break;
			}
		}
	}
}

void ApartamentRepository::eliminareTip(char *tip)
{

	// Parcurgem toate apartamentele
	for (int i = 0; i < apartamente.size(); i++)
	{
		// Aflam apartamentul curent (aflat la pozitia i)
		Apartament ap = apartamente.at(i);

		if (strcmp(ap.getTip(), tip) == 0)
		{
			apartamente.erase(apartamente.begin() + i);
			i--;
		}
	}
}

void ApartamentRepository::updateTip(int ap, char * tip, int suma)
{
	for (int i = 0; i < this->apartamente.size(); i++)
	{
		if (this->apartamente.at(i).getNumar_ap() == ap && strcmp(this->apartamente.at(i).getTip(), tip) == 0)
			this->apartamente.at(i).setSuma(suma);
	}
	saveData();
}

vector<Apartament> ApartamentRepository::inlocuireSuma(char *tip, int nrAp, int sumaNoua)
{

	int size = apartamente.size();
	for (int i = 0; i < size; i++)
	{
		// Aflam apartamentul curent (aflat la pozitia i)
		Apartament ap = apartamente.at(i);

		if (strcmp(ap.getTip(), tip) == 0 && ap.getNumar_ap() == nrAp && ap.getSuma() != sumaNoua)
		{
			Apartament apNou = Apartament(nrAp, tip, sumaNoua);
			apartamente.erase(apartamente.begin() + i);
			addElem(apNou);
			i--;
		}
		return apartamente;
	}
}

vector<Apartament> ApartamentRepository::filtrareTip(char *tip)
{
	int i = 0;
	while (i<apartamente.size())
	{
		Apartament ap = apartamente.at(i);

		// Daca tipul filtrarii e diferit de tipul curent atunci stergem cheltuiala
		if (strcmp(ap.getTip(), tip) != 0)
		{
			apartamente.erase(apartamente.begin() + i);
		}
		else
		{
			i++;
		}
	}
	return apartamente;
}

vector<Apartament> ApartamentRepository::filtrareSuma(int suma)
{
	int i = 0;
	while (i<apartamente.size())
	{
		Apartament ap = apartamente.at(i);

		if (ap.getSuma() < suma)
		{
			apartamente.erase(apartamente.begin() + i);
		}
		else
			i++;
	}
	saveData();
	return apartamente;
}
void ApartamentRepository::inserareLista()
{
	vector<Apartament> ap = apartamente;
	list.push_back(ap);

}
void ApartamentRepository::undoLista()
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

	list.pop_back();
}