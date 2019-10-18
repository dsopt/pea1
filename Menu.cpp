#include "Menu.h"
#include "Input.h"
#include <iostream>

using namespace std;

Menu::Menu(Input inp_)
{
	input = inp_;
	bf = BruteForce();
	//tutaj tylko do sprawdzenia
	matrix = input.fromFile();
	print();
	//koniec 
	options();
}


Menu::~Menu()
{
}

void Menu::options()
{
	cout << endl;
	cout << "Co chcesz zrobic?\n[1] - wczytaj dane z pliku\n[2] - wyswietl dane\n[3] - brute force\n[4] - branch and bound\n[9] - wyjdz" << endl;
	cin >> in;
	cout << endl;

	switch (in) {
	case '1':
		matrix = input.fromFile();
		options();
		break;
	case '2':
		print();
		options();
		break;
	case '3':
		bf.run(input.getSize(), matrix);
		options();
		break;
	case '4':
		//branch and boud
		options();
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
