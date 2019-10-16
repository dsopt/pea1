#include "Menu.h"
#include "Input.h"
#include <iostream>

using namespace std;

Menu::Menu(Input inp_)
{
	input = inp_;
	options();
}


Menu::~Menu()
{
}

void Menu::options()
{
	cout << endl;
	cout << "Co chcesz zrobic?\n[0] - wczytaj dane z pliku\n[1] - wyswietl dane\n[2] - przeglad zupelny (brute force)\n[3] - branch and bound\n[9] - wyjdz" << endl;
	cin >> in;
	cout << endl;

	switch (in) {
	case '0':
		matrix = input.fromFile();
		options();
		break;
	case '1':
		print();
		options();
		break;
	case '2':
		//brute force
		break;
	case '3':
		//branch and boud
		break;
	case '9':
		break;
	default:
		cout << "Nie ma takiej operacji" << endl << endl;
		options();
		break;
	}

}

void Menu::print() {
	for (int i = 0; i < input.getSize(); i++) {
		for (int j = 0; j < input.getSize(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
