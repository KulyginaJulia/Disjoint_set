#include "Set.h"

void Set :: Make(int x){
	this->rank[x] = 0;
	this->parent[x] = x;
}
Set::Set(int n){
		parent = new int[n];
		rank = new int[n];
}
int Set ::Find(int x_){
	int x = x_;
	int p = parent[x_];

	while (p != x) {
		x = p;
		p = parent[p];
	}
	while (x_!=p)
	{
		x = parent[x_];
		parent[x_] = p;
		x_ = x;
	}
	return p;
}
void Set::Union(int x, int y ){
	int s2 = this->Find(y);
	int s1 = this->Find(x);

	int r1 = this->rank[s1];
	int r2 = this->rank[s2];
	
	if (r1 < r2) this->parent[s1] = s2;
	else {
		this->parent[s2] = s1;
		if(r1 == r2 )
			this->rank[x] = this->rank[x] + 1;
	}
}
Set :: ~Set(){
	delete [] rank;
	delete [] parent;
}
void Set :: FindComponents(int** arr, int n){
	
	for (int i = 0; i < n; i++){
		int x = arr[i][0];
		int y = arr[i][1];
		Union(x, y);
	}

	int count = 0; int a;
	for (int i = 0; i < n; i++){
		a = Find(i);
		cout << a << " ";
		if (a == i) count++;
	}
	cout << "\n";

	int j = 0;
	cout << "Component [" << j << "] = {";
	for (int i = 0; i < n; i++)
	{		
		int whisComp = 0;
		for (int k = 0; k < n; k++)
		{
			int a = Find(k);
			if (a == i)
			{
				cout << k << " ";
				whisComp++;
			}
		}
		if (whisComp > 0)
		{
			j++;
			cout << " } " << endl;
			if (j < count)
				cout << "Component [" << j << "] = {";
		}
	}

	//for (int j = 0; j < count; j++){
	//	cout << "Component [" << j << "] = {";
	//	int cur_component = -1;
	//	int i = 0;
	//	for (int k = 0; k < n; k++){
	//		a = Find(k);
	//		if (a != -1){
	//			cur_component = a;
	//			i = k;
	//			break;
	//		}
	//	}
	//	for (; i < n; i++){
	//		a = Find(i);
	//		if (a == cur_component){
	//		a = -1;
	//		cout << " " << i;
	//		} 
	//	}
	//	cout << " } " << endl;
	//}
}
