#include "Ctrl.h"
#include "Ui.h"
#include "repository.h"
#include <cstring>

#include "Teste.h"
using namespace std;

int main()
{

	ApartamentRepository repo = ApartamentRepository();
	Ctrl ctrl = Ctrl(repo);
	UI ui = UI(ctrl);
	ui.run();
	Tests::tests();
	Tests::testRepo();
	Tests::testCtrl();

	system("pause");
	return 0;
}