#include<iostream>
#include<stdio.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int* list =  new int[n];
	for (int i = 0; i < n; i++) {
		list[i] = i;
	}
	for (int i = 0; i < n; i++) {
		cout << list[i]<<" ";
	}
	delete[] list;
	return 0;
}