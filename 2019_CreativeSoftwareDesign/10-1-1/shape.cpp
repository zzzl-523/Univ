#include<iostream>
#include"shape.h"
using namespace std;

Shape::Shape(double width, double height){
	width_ = width;
	height_ = height;
}
Rectangle::Rectangle(double width, double height) {	//¿©±â¿¡ 
	width_ = width;
	height_ = height;
}
double Rectangle::getArea() {
	return width_ * height_;
}
Triangle::Triangle(double width, double height) {
	width_ = width;
	height_ = height;
}
double Triangle::getArea() {
	return width_ * height_ / 2;
}
