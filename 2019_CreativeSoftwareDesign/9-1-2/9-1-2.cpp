#include<iostream>
#include<string>
#include<vector>
using namespace std;

class A {
public:	
	A(){}
	virtual ~A(){}
	virtual string getTypeInfo() {
		return "This is an instance of class A";
	}
};
class B :public A {
public:
	B() {}
	virtual ~B() {}
	virtual string getTypeInfo() {
		return "This is an instance of class B";
	}
};
class C : public B {
public:
	C() {}
	virtual ~C() {}
	virtual string getTypeInfo() {
		return "This is an instance of class C";
	}
};
void printObjectTypeInfo1(A* object) {
	cout << object->getTypeInfo()<<"\n";
}
void printObjectTypeInfo2(A& object) {
	cout << object.getTypeInfo() << "\n";
}
vector<A*> v;

int main() {
	A* alloc_a = new A;
	A* alloc_b = new B;
	A* alloc_c = new C;

	v.push_back(alloc_a);
	v.push_back(alloc_b);
	v.push_back(alloc_c);

	for (int i = 0; i < v.size(); i++) {
		printObjectTypeInfo1(v[i]);
		printObjectTypeInfo2(*(v[i]));
	}

	delete alloc_a;
	delete alloc_b;
	delete alloc_c;

	return 0;
}