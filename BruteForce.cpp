#include "BruteForce.h"
#include <iostream>
#include <algorithm>

using namespace std;

BruteForce::BruteForce()
{
	cost = 0;
	mincost = 2147483647;
}


BruteForce::~BruteForce()
{
}

void BruteForce::run(int size_, int ** matrix_)
{
	size = size_;
	path = new int*[size];
	minpath = new int*[size];

	//wypelnianie tablicy indeksami miast
	for (int i = 0; i < size; i++) {
		path[i] = new int(i);
	}

	//obliczanie kosztu trasy dla kazdej mozliwiej drogi
	do {
		cost = 0;
		for (int j = 0; j < size; j++) {
			if (j != size - 1) {
				cost += matrix_[*path[j]][*path[j + 1]];
			}
		}
		cost += matrix_[*path[size - 1]][*path[0]];

		//nadpisywanie dla drogi z minimalnym kosztem
		if (cost < mincost) {
			mincost = cost;
			minpath = path;
		}

	} while (next_permutation(path, path+size_));

	
	//wyswietlanie wyniku
	cout << "Najmniejszy koszt: " << mincost << " dla drogi: ";
	for (int k = 0; k < size; k++) {
		cout << *minpath[k] << " ";
	}

}

