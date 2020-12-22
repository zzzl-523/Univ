#include<iostream>
#include<string>
#include<vector>
#include"animal.h"
using namespace std;
vector<Animal*>v;

int main() {
	char menu;
	string name;
	int age;

	while (1) {
		cin >> menu;
		if (menu == '0') {
			for (int i = 0; i < v.size(); i++) {
				v[i]->printInfo();
			}
			break;
		} 
		cin >> name >> age;
		if (menu == 'z') {
			int numStripes;
			cin >> numStripes;
			Animal* zebra=new Zebra(numStripes, name, age);
			v.push_back(zebra);
		}
		else if (menu == 'c') {
			string favoriteToy;
			cin >> favoriteToy;
			Animal* cat = new Cat(favoriteToy, name, age);
			v.push_back(cat);
		}
		
	}
	return 0;
}