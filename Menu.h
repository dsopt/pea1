#include "Input.h"
#include "BruteForce.h"
#pragma once
class Menu
{
public:
	Menu(Input inp);
	~Menu();
private:
	void print();
	void options();
	char in;
	int **matrix;
	Input input;
	BruteForce bf;
};

