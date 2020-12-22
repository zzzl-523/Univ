#include<iostream>
#include"my_string.h"
using namespace std;

int main() {
	string menu;
	MyString a, b;

	while (1) {
		cin >> menu;

		if (menu == "new") {
			
			operator<<(cout, "enter a\n");
			operator>>(cin, a);//cin>>temp_a와 같음 , 그냥 써봄
			operator<<(cout, "enter b\n");
			operator>>(cin, b);
		}

		else if (menu == "a" || menu== "b"){

			string from,ope,to;
			from = menu;
			cin >> ope >> to;
			

			if (ope == "*") {
				if (from == "a") {
					MyString temp = a.operator*(stoi(to));
					cout << temp;
				}
				else if (from == "b") {
					MyString temp = b.operator*(stoi(to));
					cout << temp;
				}
			}

			else if (ope == "+") {
				if (from == "a") {
					if (to == "a") {
						MyString temp= a.operator+(a);
						cout << temp;
					}
					else if (to == "b") {
						MyString temp = a.operator+(b);
						cout << temp;
					}
				}
				else if (from == "b") {
					if (to == "a") {
						b.operator+(a);
					}
					else if (to == "b") {
						b.operator+(b);
					}
					cout<< b;
				}
				
			}
		}
		else if (menu == "quit") {
			break;
		}
	}
	return 0;
}