#include<iostream>
#include<algorithm>
#include<string>
#include"sorted.h"
using namespace std;

int main() {
	SortedArray array;	//class 선언

	string menu;	//메뉴, 숫자 입력받기
	
	while (1){
		cin >> menu;

		if (menu == "ascend") {	//오름차순
			for (int i = 0; i < array.GetSortedAscending().size(); i++) {
				cout<< array.GetSortedAscending()[i]<<" ";
			}
			cout << "\n";
		}
		else if (menu == "descend") {	//내림차순
			for (int i = 0; i < array.GetSortedDescending().size(); i++) {
				cout << array.GetSortedDescending()[i] << " ";
			}
			cout << "\n";
		}
		else if (menu == "max") {
			cout << array.GetMax() << "\n";
		}
		else if (menu == "min") {
			cout << array.GetMin() << "\n";
		}
		else if (menu == "quit") {
			break;
		}
		else {	//버퍼에 남겨서 전부 넣는다
			int number = atoi(menu.c_str());
			array.AddNumber(number);
		}
	}
	return 0;

}