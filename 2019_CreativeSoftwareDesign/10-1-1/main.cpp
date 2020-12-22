#include<iostream>
#include<vector>
#include"shape.h"
using namespace std;
vector<Shape*>arr;

int main() {
	char menu;
	double height, width;
	
	while (1) {
		cin >> menu;
		if (menu == '0') {
			for (int i = 0; i < arr.size(); i++) {
				cout<<arr[i] ->getArea()<<endl;
			}
			break;
		}

		cin >> width >> height;
		if (menu == 'r') {
			arr.push_back(new Rectangle(width, height));
		}
		else if (menu == 't') {
			arr.push_back(new Triangle(width, height));
		}
		
	}
	return 0;
}