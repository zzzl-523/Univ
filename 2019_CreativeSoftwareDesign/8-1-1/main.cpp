#include<iostream>
#include<string>
#include"number.h"
using namespace std;

int main() {
	string dowhat;
	int number;

	while (1) {
		cin >> dowhat;
		if (dowhat == "quit") {
			break;
		}

		cin>> number;
		if (dowhat == "number") {
			Number num;
			num.setNumber(number);
			cout<<"getNumber(): "<<num.getNumber()<<endl;
		}
		else if (dowhat == "square") {
			Square squ;
			squ.setNumber(number);
			cout<<"getNumber(): "<<squ.getNumber()<<endl;
			cout << "getSquare(): " << squ.getSquare() << endl;
		}
		else if (dowhat == "cube") {
			Cube cub;
			cub.setNumber(number);
			cout << "getNumber(): " << cub.getNumber() << endl;
			cout << "getSquare(): " << cub.getSquare() << endl;
			cout << "getCube(): " << cub.getCube() << endl;
		}
		
		
	}
	return 0;
}