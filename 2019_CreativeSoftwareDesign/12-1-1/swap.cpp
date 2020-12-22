#include<iostream>
#include<string>
using namespace std;

template<typename T>
void myswap(T &a, T &b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}
int main() {
	int num_int1, num_int2;
	double num_dou1, num_dou2;
	string str1, str2;

	cin >> num_int1 >> num_int2;
	myswap(num_int1, num_int2);
	cout << "After calling myswap(): " << num_int1<<" " << num_int2 << endl;

	cin >> num_dou1 >> num_dou2;
	myswap(num_dou1, num_dou2);
	cout << "After calling myswap(): " << num_dou1<<" " << num_dou2 << endl;

	cin >> str1 >> str2;
	myswap(str1, str2);
	cout << "After calling myswap(): " << str1<<" " << str2 << endl;

	return 0;
}