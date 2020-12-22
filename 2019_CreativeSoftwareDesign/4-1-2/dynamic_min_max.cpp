#include<iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	int* list = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	int min = 0, max = 0;
	for (int i = 0; i < N; i++) {
		if (list[i] < min) {
			min=list[i];
		}
	}
	for (int i = 0; i < N; i++) {
		if (list[i] > max) {
			max=list[i];
		}
	}
	cout << "min: " << min << endl;
	cout << "max: " << max << endl;
	delete[] list;
	return 0;
}
