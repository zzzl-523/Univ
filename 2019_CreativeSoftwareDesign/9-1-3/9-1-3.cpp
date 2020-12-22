#include<iostream>
#include<string>
#include<vector>
using namespace std;

class A {
	int* memberA;
public:
	A() {}
	A(int number){
		memberA = new int;
		*memberA = number;
		cout << "new memberA\n";
	}
	virtual ~A() {
		delete memberA;
		cout << "delete memberA\n";
	}
	virtual void print() {
		cout << "*memberA "<<*memberA<<endl;
	}
};
class B :public A {
	double* memberB;
public:
	B() {}
	B(double number):A(1) {
		memberB = new double;
		*memberB = number;
		cout << "new memberB\n";
	}
	virtual ~B() {
		delete memberB;
		cout << "delete memberB\n";
	}
	virtual void print() {
		A::print();
		cout << "*memberB " << *memberB<<endl;
	}
};
class C : public B {
	string* memberC;
public:
	C() {}
	C(const string& str):B(1.1) {
		memberC = new string;
		*memberC = str;
		cout << "new memberC\n";
	}
	virtual ~C() {
		delete memberC;
		cout << "delete memberC\n";
	}
	virtual void print() {
		B::print();
		cout << "*memberC " << *memberC<<endl;
	}
};

vector<A*> v;

int main() {
	int n_int;
	double n_double;
	string s_string;

	cin >> n_int >> n_double >> s_string;

	A* alloc_a = new A(n_int);
	A* alloc_b = new B(n_double);
	A* alloc_c = new C(s_string);

	v.push_back(alloc_a);
	v.push_back(alloc_b);
	v.push_back(alloc_c);

	for (int i = 0; i < v.size(); i++) {
		v[i]->print();
	}

	delete alloc_a;
	delete alloc_b;
	delete alloc_c;

	return 0;
}