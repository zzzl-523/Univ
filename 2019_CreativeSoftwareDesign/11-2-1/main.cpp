#include<iostream>
#include"my_vector.h"
using namespace std;

int main() {
	string menu,from,ope,to;
	int length_;
	
	cin >> menu>>length_;
	MyVector a(length_);
	MyVector b(length_);
	MyVector temp(length_);

	if (menu == "new") {
		MyVector a2(length_);
		MyVector b2(length_);
		cout << "enter a"<<endl;
		cin >> a2;
		a = a2;
		cout << "enter b"<<endl;
		cin >> b2;
		b = b2;

		while (1) {
			cin >> from;
			if (from == "quit") {
				break;
			}
			
			cin>> ope >> to;

			if (from == "a") {
				if (ope == "+") {
					if (to == "a") {
						temp = a.operator+(a);
						cout << temp;
					}
					else if (to == "b") {
						temp = a.operator+(b);
						cout << temp;
					}
					else {
						temp = a.operator+(stoi(to));
						cout << temp;
					}
				}
				else if (ope == "-") {
					if (to == "a") {
						temp = a.operator-(a);
						cout << temp;
					}
					else if (to == "b") {
						temp = a.operator-(b);
						cout << temp;
					}
					else {
						temp = a.operator-(stoi(to));
						cout << temp;
					}
				}
			}
			else if (from == "b") {
				if (ope == "+") {
					if (to == "a") {
						temp = b.operator+(a);
						cout << temp;
					}
					else if (to == "b") {
						temp = b.operator+(b);
						cout << temp;
					}
					else {
						temp = b.operator+(stoi(to));
						cout << temp;
					}
				}
				else if (ope == "-") {
					if (to == "a") {
						temp = b.operator-(a);
						cout << temp;
					}
					else if (to == "b") {
						temp = b.operator-(b);
						cout << temp;
					}
					else {
						temp = b.operator-(stoi(to));
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