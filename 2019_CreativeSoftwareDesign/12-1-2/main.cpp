#include<iostream>
#include<string>
#include"my_container.h"
using namespace std;

int main() {
	int n_int;
	double n_dou;
	string str;

	int size;
	cin >> size;
	MyContainer<int> mc_i(size);
	cin >> mc_i;
	cout << mc_i;

	int size2;
	cin >> size2;
	MyContainer<double> mc_d(size2);
	cin >> mc_d;
	cout << mc_d;

	int size3;
	cin >> size3;
	MyContainer<string> mc_s(size3);
	cin >> mc_s;
	cout << mc_s;
	
	return 0;
}