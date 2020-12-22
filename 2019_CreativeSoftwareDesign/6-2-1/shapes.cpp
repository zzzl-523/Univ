#include<iostream>
#include "shapes.h"
using namespace std;

double Circle::C_area(int x, int y, int r) {
	double area = 0;
	double pi = 3.14;
	area = pi * (r*r);
	return area;
}
double Circle::C_perimeter(int x, int y, int r) {
	double perimeter = 0;
	double pi = 3.14;
	perimeter = 2 * pi*r;
	return perimeter;
}
double Rectangle::R_area(int tx, int ty, int bx, int by) {
	double area = 0;
	area = (bx - tx)*(ty - by);
	return area;
}
double Rectangle::R_perimeter(int tx, int ty, int bx, int by) {
	double perimeter = 0;
	perimeter = (2 * (bx - tx)) + (2 * (ty - by));
	return perimeter;
}