#include<iostream>
#include "shapes.h"
using namespace std;

int main() {
	Circle a_circle;
	Rectangle a_rec;
	char menu;
	while (1) {
		cout << "shape?" << "\n";
		cin >> menu;
		if (menu == 'C') {
			int x, y, r;
			cin >> x >> y >> r;
			cout << "area: " << a_circle.C_area(x, y, r) << ", perimeter: " << a_circle.C_perimeter(x, y, r) << "\n";
		}
		else if (menu == 'R') {
			int tx, ty, bx, by;
			cin >> tx >> ty >> bx >> by;
			cout << "area: " << a_rec.R_area(tx, ty, bx, by) << ", perimeter: " << a_rec.R_perimeter(tx, ty, bx, by) << "\n";
		}
		else if (menu == 'Q') {
			return 0;
		}
		cout << "\n";
	}
	return 0;
}