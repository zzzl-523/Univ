#include<iostream>
using namespace std;

typedef struct Person {
	char name[10];
	int age;
}person;

int main() {
	int N;
	cin >> N;
	person* p=new person[N];

	for (int i = 0; i < N; i++) {
		cin >> p[i].name >> p[i].age;
	}

	for (int i = 0; i < N; i++) {
		cout << "Name:" << p[i].name << ", Age:" << p[i].age<<endl;
	}
	delete[] p;
	return 0;
}