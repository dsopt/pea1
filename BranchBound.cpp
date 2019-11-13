#include "BranchBound.h"
#include <iostream> 
using namespace std;

BranchBound::BranchBound()
{
	cost = 0;
	max = 2147483647;
	mincost = max;
}


BranchBound::~BranchBound()
{
}

void BranchBound::run(int size_, int ** matrix_)
{
	size = size_;
	visited = new bool[size];

	//dodaje wszystkie wierzcholki do kolejki
	for (int i = 0; i < size; i++) {
		queue.push_back({ i, 1 });
	}

	//dodaje wierzcholek poczatkowy do trasy
	path.push_back(queue.back().value);
	queue.pop_back();
	visited[path.back()] = true;

	do {
		if (visited[queue.back().value] != true) {
			if (!queue.empty() && queue.back().imp == path.size()) {
				//spr czy jestesmy w dobrym poddrzewie
				path.push_back(queue.back().value);
				queue.pop_back();
				visited[path.back()] = true;

				cost += matrix_[path.at(path.size() - 2)][path.at(path.size() - 1)];

				if (cost >= mincost) {
					//jesli koszt trasy przewyzsza minimalny cofamy sie do poprzedniego 
					cost -= matrix_[path.at(path.size() - 2)][path.at(path.size() - 1)];
					visited[path.back()] = false;
					path.pop_back();
				}
				else {
					for (int j = 0; j < size; j++) {
						if (visited[j] != true) {
							queue.push_back({ j, int(path.size()) }); 
						}
					}
				}

				if (path.size() == size) {
					//jesli cykl jest zamkniety dodajemy wage przejscia z konca do poczatku i sprawdzamy czy waga jest najmniejsza
					cost += matrix_[path.back()][path.at(0)];
					if (cost < mincost) {
						mincost = cost;
						minpath = path;
					}
					cost -= matrix_[path.back()][path.at(0)];
				}
			} 
			else if (!queue.empty() && queue.back().imp < path.size() && path.size() > 1) {
				//jesli nie ma wiecej wierzcholkow do odwiedzenia musimy sie cofnac
				
				cost -= matrix_[path.at(path.size() - 2)][path.at(path.size() - 1)];
				visited[path.back()] = false;
				path.pop_back();
			}
			else if (!queue.empty() && queue.back().imp > path.size()) {
				queue.pop_back();
			}
		}
		else if(!path.empty()) {
			//jesli z jakiegos powodu wierzcholek jest zawarty w danym cyklu - cofamy sie
			visited[path.back()] = false;
			cost -= matrix_[path.at(path.size() - 2)][path.back()];
			path.pop_back();
		}
	} while (!queue.empty());

	//wyswietlanie wyniku
	cout << "Najmniejszy koszt: " << mincost << " dla drogi: ";
	for (int k = 0; k < size; k++) {
		cout << minpath.at(k) << " ";
	}
	cout << endl;
}
