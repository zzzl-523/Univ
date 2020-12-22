#include<iostream>
#include<algorithm>
#include"sorted.h"
using namespace std;

SortedArray::SortedArray() {//√ ±‚»≠
	numbers_.clear();
}
SortedArray::~SortedArray() {//destructor

}

void SortedArray::AddNumber(int num) {
	numbers_.push_back(num);
}
vector<int> SortedArray::GetSortedAscending() {
	sort(numbers_.begin(), numbers_.begin() + numbers_.size());
	return numbers_;
}
vector<int> SortedArray::GetSortedDescending() {
	vector<int> ret;
	sort(numbers_.begin(), numbers_.begin() + numbers_.size());
	vector<int>retDes;
	for (int i = numbers_.size()-1; i >=0 ; i--) {
		retDes.push_back(numbers_[i]);
	}
	return retDes;
}
int SortedArray::GetMax() {
	int maxn = 0;
	maxn=*max_element(numbers_.begin(), numbers_.end());
	
	return maxn;
}
int SortedArray::GetMin() {
	int minn = 0;
	minn = *min_element(numbers_.begin(), numbers_.end());
	
	return minn;
}
