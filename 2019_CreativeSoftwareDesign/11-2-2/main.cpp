#include<iostream>
#include"my_vector2.h"
using namespace std;

int main() {
	string menu, from, ope, to;
	int length_;

	cin >> menu >> length_;
	MyVector2 a(length_);
	MyVector2 b(length_);

	if (menu == "new") {
		MyVector2 a2(length_);
		MyVector2 b2(length_);
		cout << "enter a" << endl;
		cin >> a;
		cout << "enter b" << endl;
		cin >> b;


		while (1) {
			cin >> from;
			if (from == "quit") {
				break;
			}

			cin >> ope >> to;

			if (from == "a") {
				if (ope == "+") {
					if (to == "a") {
						MyVector2 temp(a.operator+(a));
						cout << temp;
					}
					else if (to == "b") {
						MyVector2 temp(a.operator+(b));
						cout << temp;
					}
					else {
						MyVector2 temp(a.operator+(stoi(to)));
						cout << temp;
					}
				}
				else if (ope == "-") {
					if (to == "a") {
						MyVector2 temp(a.operator-(a));
						cout << temp;
					}
					else if (to == "b") {
						MyVector2 temp(a.operator-(b));
						cout << temp;
					}
					else {
						MyVector2 temp(a.operator-(stoi(to)));
						cout << temp;
					}
				}
			}
			else if (from == "b") {
				if (ope == "+") {
					if (to == "a") {
						MyVector2 temp(b.operator+(a));
						cout << temp;
					}
					else if (to == "b") {
						MyVector2 temp(b.operator+(b));
						cout << temp;
					}
					else {
						MyVector2 temp(b.operator+(stoi(to)));
						cout << temp;
					}
				}
				else if (ope == "-") {
					if (to == "a") {
						MyVector2 temp(b.operator-(a));
						cout << temp;
					}
					else if (to == "b") {
						MyVector2 temp(b.operator-(b));
						cout << temp;
					}
					else {
						MyVector2 temp(b.operator-(stoi(to)));
						cout << temp;
					}
				}
			}

		}
	}
	else if (menu == "quit") {
		return 0;
	}

	return 0;
}