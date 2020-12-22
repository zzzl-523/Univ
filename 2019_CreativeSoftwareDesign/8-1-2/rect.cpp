#include<iostream>
#include<string>
#include"rect.h"
using namespace std;

Rectangle::Rectangle(int width, int height) {
	garo = width;
	sero = height;
}
int Rectangle:: getArea() {
	return (garo * sero);
}
int Rectangle::getPerimeter() {
	return (garo + sero) * 2;
}
Square::Square(int width) : Rectangle(width, width) {}
void Square::print() {
	cout << garo << "x" << sero << " Square" << endl;
	cout << "Area: " << getArea() << endl;
	cout << "Perimeter: " << getPerimeter() << endl;
}
NonSquare::NonSquare(int width, int height) : Rectangle(width, height){}
void NonSquare::print() {
	cout << garo << "x" << sero << " NonSquare" << endl;
	cout << "Area: " << getArea() << endl;
	cout << "Perimeter: " << getPerimeter() << endl;
}

