#include<iostream>
#include<string>
#include"rect.h"
using namespace std;

int main() {
	string what;
	int garo, sero;

	while (1) {
		cin >> what;
		if (what == "quit") {
			break;
		}

		if (what == "nonsquare") {
			cin >> garo>> sero;
			NonSquare nonsqr(garo, sero);
			nonsqr.print();
		}
		else if (what == "square") {
			cin >> garo;
			Square sqr(garo);
			sqr.print();
		}
	}
	return 0;
}