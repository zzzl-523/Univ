#include<iostream>
#include<string>
#include<cmath>
#include"shapes.h"
using namespace std;

int main() {
	
	int canvas_garo, canvas_sero;
	cin >> canvas_garo >> canvas_sero;

	string menu;
	
	while (1) {
		cin >> menu;
		if (menu == "rect") {
			int top_x, top_y, garo, sero;
			char brush;
			cin >> top_x >> top_y >> garo >> sero>>brush;
			rect nemo(top_x, top_y, garo, sero,brush);
			cout << "\n" << "Area: " << nemo.GetArea() << endl;
			cout << "\n" << "Perimeter: " << nemo.GetPerimeter() << endl;
			nemo.Draw(canvas_garo, canvas_sero);
		}
		else if (menu == "square") {
			int top_x, top_y, length;
			char brush;
			cin >> top_x >> top_y >> length >> brush;
			square squ(top_x, top_y, length, brush);
			cout << "\n" << "Area: " << squ.GetArea() << endl;
			cout << "\n" << "Perimeter: " << squ.GetPerimeter() << endl;
			squ.Draw(canvas_garo, canvas_sero);
		}
		else if (menu == "diamond") {
			int top_x, top_y, distance;
			char brush;
			cin >> top_x >> top_y >> distance >> brush;
			diamond dia(top_x, top_y, distance, brush);
			cout << "\n" << "Area: " << dia.GetArea() << endl;
			cout << "\n" << "Perimeter: " << dia.GetPerimeter() << endl;
			dia.Draw(canvas_garo, canvas_sero);
		}
		else if (menu == "quit") {
			break;
		}
	}
	return 0;

}