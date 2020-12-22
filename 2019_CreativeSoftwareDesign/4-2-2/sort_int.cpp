#include<iostream>
using namespace std;
int* sortsort(int* list, int N) {
	int temp=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++) {
			if (list[j] > list[j + 1]) {
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
	return list;
}

int main() {
	int N;
	cin >> N;
	if (N <= 0) {
		return 0;
	}
	int* list = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	for (int i = 0; i < N; i++) {
		cout << sortsort(list, N)[i]<<" ";
	}
	cout << endl;
	delete[] list;
	return 0;
}