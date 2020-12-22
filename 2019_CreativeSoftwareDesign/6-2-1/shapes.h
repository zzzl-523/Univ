#pragma once
class Circle {
	int x, y;	//center point, radius
	int r;
public:
	double C_area(int x, int y, int r);
	double C_perimeter(int x, int y, int r);
};
class Rectangle {
	int tx, ty;	//top left 
	int bx, by;	//bottom right
public:
	double R_area(int tx, int ty, int bx, int by);
	double R_perimeter(int tx, int ty, int bx, int by);
};