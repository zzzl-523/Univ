#include<iostream>
#include<string>
#include"setfunc.h"
using namespace std;

int main() {
	string set1;
	string set2;
	char oper;
	char start;

	set<int>real_set1, real_set2;
	set<int>union_set, diff_set, inter_set;

	
	

	while (1) {
		cin>>start;
		if(start=='0'){
			break;
		}
	
		getline(cin, set1, '}');

		real_set1 = parseSet(set1);
		cin >> oper;
		getline(cin, set2, '}');
		real_set2 = parseSet(set2);

		if (oper == '+') {
			union_set = getUnion(real_set1, real_set2);
			printSet(union_set);
		}
		else if (oper == '-') {
			diff_set = getDifference(real_set1, real_set2);
			printSet(diff_set);
		}
		else if (oper == '*') {
			inter_set = getIntersection(real_set1, real_set2);
			printSet(inter_set);
		}
		/*else if (oper == '0') {
			return 0;
		}*/
	}
	return 0;

}
