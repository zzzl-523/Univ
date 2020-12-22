#include<iostream>
#include<algorithm>
#include<string>
#include"sorted.h"
using namespace std;

int main() {
	SortedArray array;	//class ����

	string menu;	//�޴�, ���� �Է¹ޱ�
	
	while (1){
		cin >> menu;

		if (menu == "ascend") {	//��������
			for (int i = 0; i < array.GetSortedAscending().size(); i++) {
				cout<< array.GetSortedAscending()[i]<<" ";
			}
			cout << "\n";
		}
		else if (menu == "descend") {	//��������
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
		else {	//���ۿ� ���ܼ� ���� �ִ´�
			int number = atoi(menu.c_str());
			array.AddNumber(number);
		}
	}
	return 0;

}