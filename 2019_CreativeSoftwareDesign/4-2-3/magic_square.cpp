#include<iostream>
using namespace std;
void magicSquare(int** arr, int N) {

	int r = 0, c = (N / 2);

	for (int i = 1; i <= N * N; i++) {
		arr[r][c] = i;
		if (i%N == 0) {			//빈칸이 아닐 때(아래로 이동)
			r++;
		}
		else {
			r--, c++;			//빈칸(그냥 이동)(행-1, 열+1)
			if (r < 0) {		//맨 윗줄(행=맨마지막, 열+1)
				r = N - 1;
			}
			if (c > (N - 1)) {	//맨 오른쪽 줄(행-1, 열=0)
				c = 0;
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	if ((N % 2) == 0 || N < 3) {
		return 0;
	}
	int** arr = new int*[N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = 0;
		}
	}

	magicSquare(arr, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < N; i++) {//delete
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}