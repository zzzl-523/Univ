#pragma once
#include<iostream>
#include<vector>
#include"intset.h"
using namespace std;

class IntegerSet {
public:
	IntegerSet();
	~IntegerSet();
	void AddNumber(int num);
	void DeleteNumber(int num);
	int GetItem(int pos);
	vector<int> GetAll();
private:
	vector<int> numbers_;
};
