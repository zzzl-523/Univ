#include<iostream>
#include<set>
#include<string>
#include<vector>
#include"setfunc.h"
using namespace std;

set<int> parseSet(const string& str) {
	set<int> makeset;
	/*const string& substrr = str.substr(2,str.size()-1);
	
	for (int i = 0; i < str.size(); i++) {
		makeset.insert(atoi(substrr.c_str()+i+1));
	}*/

	for (int i = 0; i < str.size(); i+=2) {
		makeset.insert(atoi(str.substr(i + 1,2).c_str()));
	}

	
	return makeset;
}
void printSet(const set<int>& sett) {
	cout << "{ ";
	for (set<int>::iterator it = sett.begin(); it != sett.end(); it++) {
		cout << *it<<" ";
	}
	cout << "}"<<endl;
	
}
set<int> getIntersection(const set<int>& set0, const set<int>& set1) {
	int size = set0.size() + set1.size();
	int list[10000];
	
	set<int>set_inter0,set_inter1;
	for (set<int>::iterator it = set0.begin(); it != set0.end(); it++) {
		set_inter0.insert(*it);
		set_inter1.insert(*it);
	}
	for (set<int>::iterator it = set1.begin(); it != set1.end(); it++) {
		set_inter0.erase(*it);
	}

	for (set<int>::iterator it = set_inter0.begin(); it != set_inter0.end(); it++) {
		set_inter1.erase(*it);
	}
	set_inter1.erase(0);
	return set_inter1;
}
set<int> getUnion(const set<int>& set0, const set<int>& set1) {
	set<int>set_union;
	for (set<int>::iterator it = set0.begin(); it != set0.end(); it++) {
		set_union.insert(*it);
	}
	for (set<int>::iterator it = set1.begin(); it != set1.end(); it++) {
		set_union.insert(*it);
	}
	set_union.erase(0);
	return set_union;
}
set<int> getDifference(const set<int>& set0, const set<int>& set1) {
	set<int>set_diff;
	for (set<int>::iterator it = set0.begin(); it != set0.end(); it++) {
		set_diff.insert(*it);
	}
	for (set<int>::iterator it = set1.begin(); it != set1.end(); it++) {
		set_diff.erase(*it);
	}
	return set_diff;
}
	