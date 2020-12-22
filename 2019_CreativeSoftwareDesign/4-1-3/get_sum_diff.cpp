#include<iostream>
using namespace std;

void getSumDiff(int a, int b, int& sum, int& diff) {
	sum = a + b;
	diff = a - b;
}

int main() {
	int a = 0, b = 0;
	cin >> a >> b;
	int sum=0,diff=0;
	getSumDiff(a, b, sum, diff);

	cout << "sum:"<< sum<<endl;
	cout << "diff:" << diff << endl;
	
	return 0;
}