#include<iostream>
#include<algorithm>
#include<vector>
#include"intset.h"
using namespace std;

IntegerSet::IntegerSet() {	//�ʱ�ȭ(constructor)
	numbers_.clear();
}
IntegerSet::~IntegerSet() {	//destructor

}

void IntegerSet::AddNumber(int num) {	//add, print out
	
	for (int i = 0; i < numbers_.size(); i++) {
		if (num == numbers_[i]) {	//�ߺ��Ǹ� �����  push
			numbers_.erase(numbers_.begin()+i);
		}
	}
	numbers_.push_back(num);
}
void IntegerSet::DeleteNumber(int num) {	//delete, print out
	for (int i = 0; i < numbers_.size(); i++) {
		if (num == numbers_[i]) {	//���� �ȿ� ������ �����
			numbers_.erase(numbers_.begin()+i);
		}
	}
}
int IntegerSet::GetItem(int pos) {
	if (numbers_.empty() || (pos<0 || pos>numbers_.size()) ){
		return -1;
	}
	else {
		return numbers_[pos];
	}
}
vector<int>IntegerSet::GetAll() {
	sort(numbers_.begin(), numbers_.end());
	return numbers_;
}
