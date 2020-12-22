#include<iostream>
#include<algorithm>
#include<vector>
#include"intset.h"
using namespace std;

IntegerSet::IntegerSet() {	//초기화(constructor)
	numbers_.clear();
}
IntegerSet::~IntegerSet() {	//destructor

}

void IntegerSet::AddNumber(int num) {	//add, print out
	
	for (int i = 0; i < numbers_.size(); i++) {
		if (num == numbers_[i]) {	//중복되면 지우고  push
			numbers_.erase(numbers_.begin()+i);
		}
	}
	numbers_.push_back(num);
}
void IntegerSet::DeleteNumber(int num) {	//delete, print out
	for (int i = 0; i < numbers_.size(); i++) {
		if (num == numbers_[i]) {	//벡터 안에 있으면 지우기
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
