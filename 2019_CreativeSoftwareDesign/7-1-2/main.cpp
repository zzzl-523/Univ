#include<iostream>
#include<vector>
#include<string>
#include"intset.h"
using namespace std;

int main() {
	IntegerSet set;

	string menu;
	int num;
	int check = 0;
	while (1) {
		cin >> menu;
		if (menu == "quit") {
			break;
		}
		cin >> num;
		if (menu == "add") {
			set.AddNumber(num);
			for (int i = 0; i < set.GetAll().size(); i++) {
				cout << set.GetAll()[i] << " ";
			}
			cout << "\n";
		}
		else if (menu == "del") {
			set.DeleteNumber(num);
			for (int i = 0; i < set.GetAll().size(); i++) {
				cout << set.GetAll()[i] << " ";
			}
			cout << "\n";
		}
		else if (menu == "get") {
			cout << set.GetItem(num) << "\n";
		}
		
	}
	return 0;
}