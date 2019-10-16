#include <iostream>
#include <string>
#include <fstream>
#include "Input.h"
#pragma once
using namespace std;


Input::Input(string path_) {
	size = 0;
	path = path_;
}
Input::Input()
{
}
Input::~Input() {

}

int ** Input::fromFile() {
	//czytanie danych z pliku

	ifstream file(path.c_str());

	if (file) {
		file >> size;
		matrix_ = new int*[size];

		for (int i = 0; i < size; i++) {
			matrix_[i] = new int[size];

			for (int j = 0; j < size; j++) {
				file >> matrix_[i][j];
			}
		}
		
	}
	file.close(); 
	cout << "Dane zostaly wczytane" << endl;
	return matrix_;

}

int Input::getSize()
{
	return size;
}
