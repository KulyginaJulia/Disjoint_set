#include "set.h"

void main(){
	int n; 
	int ver = 0;

	cout << "Enter the number of ver: ";
	cin >> ver;

	cout << "Enter the number of relations: ";
	cin >> n;

	int **E;
	E = new int *[n];
	for (int i = 0; i < n; i++) {
		E[i] = new int[2];
	}
	cout << "Enter the relations: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << " 1 element = ";
		cin >> E[i][0];
		cout << " 2 element = ";
		cin >> E[i][1];
		cout << endl;
	}

	Set s(ver);
	for (int i = 0; i < ver; i++)
		s.Make(i);
	s.FindComponents(E,n);
	for (int count = 0; count < n; count++)
        delete [] E[count];
}