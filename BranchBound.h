#include <vector>
#pragma once
class BranchBound
{
public:
	BranchBound();
	~BranchBound();
	void run(int size_, int ** matrix_);
private:
	struct node {
		int value, imp;
	};
	int cost;
	int mincost;
	int max;
	int size;
	bool *visited;
	std::vector<int> path;
	std::vector<int> minpath;
	std::vector<node> queue;
};

