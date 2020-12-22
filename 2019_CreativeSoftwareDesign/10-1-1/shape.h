#pragma once

class Shape {
public:
	Shape() {};
	Shape(double width, double height);
	virtual ~Shape() {};
	virtual double getArea()=0;	//pure virtual

protected:
	double width_;
	double height_;
};
class Triangle:public Shape {
public:
	Triangle() {};
	Triangle(double width, double height);
	virtual ~Triangle() {};
	virtual double getArea();
};
class Rectangle:public Shape {
public:
	Rectangle() {};
	Rectangle(double width, double height);
	virtual ~Rectangle() {};
	virtual double getArea();
};



