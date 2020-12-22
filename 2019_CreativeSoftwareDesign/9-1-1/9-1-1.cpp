#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class A {
public:	
	A() {}
	virtual ~A(){}
	virtual string test() {	//virtual을 해줘야한다!
		return "A::test()\n";
	}
};
class B :public A {
public:
	B(){}
	virtual ~B() {}
	virtual string test() {
		return "B::test()\n";
	}
};
class C : public B{
public:
	C() {}
	virtual ~C() {}
	virtual string test() {
		return "C::test()\n";
	}
};
vector<A*> v;

int main() {
	A* alloc_a = new A;
	B* alloc_b = new B;
	C* alloc_c = new C;

	v.push_back(alloc_a);
	v.push_back(alloc_b);
	v.push_back(alloc_c);
	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i]->test();
	}

	delete alloc_a;
	delete alloc_b;
	delete alloc_c;

	return 0;
}