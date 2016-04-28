#pragma once
#include <iostream>

using namespace std;

class Set{
	public:
		int *parent;
		int *rank;

	Set(int n);
	void Make(int x);
	int Find(int x);
	void Union(int x, int y);
	~Set();
	void FindComponents(int** arr, int n);
};