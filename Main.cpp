#include "Menu.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	Input inp = Input("Data.txt");
	Menu m = Menu(inp);
	_getch();
	return 0;

}