//#include <vector>
//#include <string>
#pragma once
class BruteForce
{
public:
	BruteForce();
	~BruteForce();
	void run(int size_, int **matrix_);
private:
	int cost;
	int mincost;
	int size;
	int **path;
	int **minpath;
};

