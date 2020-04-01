#include "Ui.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>
using namespace std;

bool UI::validTip(char *tip)
{
	if (strcmp(tip, "gaz") == 0 || strcmp(tip, "apa") == 0 || strcmp(tip, "electricitate") == 0
		|| strcmp(tip, "caldura") == 0 || strcmp(tip, "altele") == 0)
		return true;

	return false;
}
void UI::printMenu()
{

	cout << "1) Adaugare in vector\n";
	cout << "2) Afisare vector\n";
	cout << "3) Exit\n";
	cout << "4) Afisare in functie de limita\n";
	cout << "5) Afisare lungime vector\n";
	cout << "6) Afisare informatii apartamente\n";
	cout << "7) Eliminare dupa nr apartament\n";
	cout << "8) Eliminare dupa un interval de apartamente\n";
	cout << "9) Eliminare dupa tip\n";
	cout << "10) Inlocuire suma\n";
	cout << "11) Filtru tip\n";
	cout << "12) Filtru suma\n";
	cout << "13) Undo\n";
	cout << "14) Afiseaza toate cheltuielile unui anumit apartament." << endl;
	cout << "15) Afiseaza cheltuielile mai mari decat o suma pentru toate apartamentele." << endl;
	cout << "16) Afiseaza cheltuielile egale cu o suma pentru toate apartamentele." << endl;


}

void UI::addElem(Apartament a)
{
	ctrl.addElem(a);
}

vector<Apartament>UI::getAll()
{
	return ctrl.getAll();
}
vector <Apartament>UI::apartamenteSelectate(int limita)
{
	return ctrl.apartamenteSelectate(limita);
}

void UI::eliminareNrApartament(int nrApartament)
{
	ctrl.eliminareNrApartament(nrApartament);
}

void UI::eliminareIntervalApartamente(int left, int right)
{
	ctrl.eliminareIntervalApartamente(left, right);
}

void UI::eliminareTip(char *tip)
{
	ctrl.eliminareTip(tip);
}

vector<Apartament> UI::inlocuireSuma(char *tip, int nrAp, int sumaNoua)
{
	return ctrl.inlocuireSuma(tip, nrAp, sumaNoua);
}
vector<Apartament> UI::filtrareTip(char *tip) {
	return ctrl.filtrareTip(tip);

}
void UI::filtrareSuma(int suma)
{
	vector<Apartament> ap = ctrl.filtrareSuma(suma);
	for (Apartament a : ap) {
		cout << a.getNumar_ap() << " " << a.getTip() << " " << a.getSuma() << endl;
	}
}
void UI::updateTip(int ap, char * tip, int suma)
{
	ctrl.updateTip(ap, tip, suma);
}
void  UI::inserareLista()
{
	ctrl.inserareLista();
}
void UI::undoLista()
{
	ctrl.undoLista();
}
void UI::listeaza()
{
	ctrl.listeaza();
}

void UI::listeaza(vector<Apartament> lista)
{
	ctrl.listeaza(lista);
}

void UI::listeazaAp(int nr)
{
	ctrl.listeazaAp(nr);
}

void UI::listeazaSumaMaiMareDecat(int suma)
{
	ctrl.listeazaSumaMaiMareDecat(suma);
}

void UI::listeazaSuma(int suma)
{
	ctrl.listeazaSuma(suma);
}
UI::UI()
{

}
UI::~UI()
{

}
UI::UI(Ctrl ctrl)
{
	this->ctrl = ctrl;
}


void UI::run()
{
	char *tip = new char[100];
	int nrApartament;
	int suma, left, right, sumaNoua;
	vector<Apartament> apartamente;
	vector<Apartament> selectati;

	int limita;

	Apartament a1 = Apartament();
	int optiune;

	do
	{
		printMenu();
		cin >> optiune;

		switch (optiune)
		{
		case 1:
			cout << "Introduceti tipul ";
			cin >> tip;

			if (!validTip(tip))
			{
				printf("Tipul introdus nu este valid\n");
				break;
			}

			cout << "Introduceti numarul apartamentului ";
			cin >> nrApartament;

			cout << "Introduceti suma ";
			cin >> suma;

			a1 = Apartament(nrApartament, tip, suma);
			addElem(a1);

			apartamente = getAll();

			inserareLista();

			break;

		case 2:
			apartamente = getAll();

			for (Apartament a1 : apartamente)
			{
				cout << a1.getNumar_ap() << " " << " " << a1.getTip() << " " << a1.getSuma() << endl;

			}

			cout << '\n';

			break;

		case 4:
			cout << "Introduceti limita ";
			cin >> limita;

			selectati = apartamenteSelectate(1);

			for (Apartament a : selectati)
			{
				cout << "Numarul apartamentului: " << a.getNumar_ap() << ", suma: " << a.getSuma() << '\n';
			}

			cout << '\n';

			apartamente = getAll();
			inserareLista();

			break;

		case 5:
			apartamente = getAll();
			cout << "Lungimea vectorului: " << apartamente.size() << '\n';
			break;

		case 6:
			apartamente = getAll();
			for (Apartament a : apartamente)
			{
				cout << "Numarul apartamentului: " << a.getNumar_ap() << endl;
				cout << "Tipul apartamentului: " << a.getTip() << endl;
				cout << "Suma pentru apartament: " << a.getSuma() << endl;

				cout << endl;
			}

			break;

		case 7:
			apartamente = getAll();
			cout << "Dati numarul apartamentului de sters: ";
			cin >> nrApartament;

			eliminareNrApartament(nrApartament);

			apartamente = getAll();
			inserareLista();

			break;

		case 8:
			apartamente = getAll();

			cout << "Dati capatul stang al intervalului: ";
			cin >> left;

			cout << "Dati capatul drept al intervalului: ";
			cin >> right;

			eliminareIntervalApartamente(left, right);

			apartamente = getAll();
			inserareLista();

			break;

		case 9:
			apartamente = getAll();

			cout << "Dati tipul de eliminat ";
			cin >> tip;

			if (!validTip(tip))
			{
				printf("Tipul introdus nu este valid\n");
				break;
			}

			eliminareTip(tip);

			apartamente = getAll();
			inserareLista();

			break;

		case 10:
		{
			/*cout << "Dati tipul: ";
			cin >> tip;

			if (!validTip(tip))
			{
			printf("Tipul introdus nu este valid\n");
			break;
			}

			cout << "Dati nr. apartament ";
			cin >> nrApartament;

			cout << "Dati suma noua ";
			cin >> sumaNoua;

			inlocuireSuma(tip, nrApartament, sumaNoua);

			apartamente = getAll();
			inserareLista();
			*/
			int ap;
			char* tip = new char[15];
			cout << "nr,tip,suma noua: "; cin >> ap; cin >> tip; cin >> suma;
			updateTip(ap, tip, suma);

			break;
		}
		case 11: {
			char* tip = new char[100];
			cout << "Dati tipul de filtrare ";
			cin >> tip;

			if (!validTip(tip))
			{
				printf("Tipul introdus nu este valid\n");
				break;
			}

			filtrareTip(tip);

			apartamente = getAll();
			inserareLista();

			break;
		}
		case 12: {
			cout << "Dati suma de filtrare (raman cele mai mari decat suma introdusa)";
			cin >> suma;

			filtrareSuma(suma);

			apartamente = getAll();
			inserareLista();

			break;
		}
		case 13:
		{
			undoLista();

			cout << "Undo done";
			break;
		}
		case 14:
		{int nr;
		cout << "nr: "; cin >> nr;
		listeazaAp(nr);
		apartamente = getAll();
		inserareLista();
		break;
		}
		case 15:

			cout << "suma: "; cin >> suma;
			listeazaSumaMaiMareDecat(suma);
			apartamente = getAll();
			inserareLista();
			break;
		case 16:

			cout << "suma: "; cin >> suma;
			listeazaSuma(suma);
			apartamente = getAll();
			inserareLista();
			break;

		case 3:
			cout << "Bye bye...\n";
			break;

		}

		cout << endl;
	} while (optiune != 3);
}