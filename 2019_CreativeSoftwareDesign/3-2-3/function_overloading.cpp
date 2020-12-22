#include<iostream>
#include<string>
using namespace std;
int add(int a, int b) {
	return a + b;
}
string add(string a, string b) {
	return a+'-'+b;
}
int main() {
	int n1, n2;
	string str1, str2;
	cin >> n1 >> n2 >>str1>>str2;

	cout << add(n1, n2) << endl;
	cout<< add(str1, str2) << endl;
}
