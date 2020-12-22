#include<iostream>
using namespace std;
void magicSquare(int** arr, int N) {

	int r = 0, c = (N / 2);

	for (int i = 1; i <= N * N; i++) {
		arr[r][c] = i;
		if (i%N == 0) {			//��ĭ�� �ƴ� ��(�Ʒ��� �̵�)
			r++;
		}
		else {
			r--, c++;			//��ĭ(�׳� �̵�)(��-1, ��+1)
			if (r < 0) {		//�� ����(��=�Ǹ�����, ��+1)
				r = N - 1;
			}
			if (c > (N - 1)) {	//�� ������ ��(��-1, ��=0)
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