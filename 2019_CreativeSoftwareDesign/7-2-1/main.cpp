#include<iostream>
#include<vector>
#include<map>
#include<string>
#include"message.h"
using namespace std;

int main() {
	MessageBook book;
	string menu;
	int number;
	string message;

	while (menu != "quit") {
		cin>> menu;

		if (menu == "add") {
			cin>> number;
			getline(cin, message);
			book.AddMessage(number, message);
		}
		else if (menu == "delete") {
			cin >> number;
			book.DeleteMessage(number);
		}
		else if (menu == "print") {
			int count = 0;
			cin >> number;
			for (int i = 0; i < book.GetNumbers().size(); i++) {
				if (number == book.GetNumbers()[i]) {
					count = i;
				}
			}

			if (count != 0) {
				//cout << endl;
				cout<< book.GetMessage(number) << endl;
				cout << "\n";
			}
			else {
				cout << " " << endl;
				cout<<"\n";
			}
		}
		else if (menu == "list") {
			int num = 0;
			for (int i = 0; i < book.GetNumbers().size(); i++) {
				num = book.GetNumbers()[i];
				cout <<num<<": "<< book.GetMessage(num)<<endl;
			}
		}

	}
	return 0;
}
