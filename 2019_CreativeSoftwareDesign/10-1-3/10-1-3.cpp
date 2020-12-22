#include<iostream>
#include<vector>
#include<string>
using namespace std;

class B
{
public:
	virtual ~B() {}
};
class C : public B
{
public:
	void test_C() { std::cout << "C::test_C()" << std::endl; }
};
class D : public B
{
public:
	void test_D() { std::cout << "D::test_D()" << std::endl; }
};

vector<B*>arr;
vector<string>v;

int main() {
	char menu;
	while (1) {
		cin >> menu;
		if (menu == 'C') {
			arr.push_back(new C);
			v.push_back("C");
		}
		else if (menu == 'D') {
			arr.push_back(new D);
			v.push_back("D");
		}
		else if (menu == '0') {
			
			for (int i = 0; i < arr.size(); i++) {
				if (v[i] == "C") {
					C* ptr=dynamic_cast<C*>(arr[i]);
					ptr->test_C();
				}
				if (v[i] == "D") {
					D* ptr=dynamic_cast<D*>(arr[i]);
					ptr->test_D();
				}
			}
			break;
		}
	}
	return 0;
}