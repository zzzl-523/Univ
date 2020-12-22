#include<iostream>
#include"my_vector2.h"
using namespace std;

MyVector2::MyVector2() {}
MyVector2::MyVector2(int length) {
	this->length = length;
	this->a = new double[length];
}
MyVector2::MyVector2(const MyVector2& mv) {
	//delete[] this->a;
	//this->a = new double[length];

	this->a = mv.a;
	this->length = mv.length;
}
MyVector2::~MyVector2(){
	//delete[] this->a;
}
MyVector2 MyVector2:: operator+(const MyVector2& b) {
	MyVector2 mv(this->length);
	for (int i = 0; i < this->length; i++) {
		mv.a[i] = this->a[i] + b.a[i];
		//this->a[i] = this->a[i] + b.a[i];
	}
	return mv;
}
MyVector2 MyVector2:: operator-(const MyVector2& b) {
	MyVector2 mv(this->length);
	for (int i = 0; i < this->length; i++) {
		mv.a[i] = this->a[i] - b.a[i];
	}
	return mv;
}
MyVector2 MyVector2:: operator+(const int b) {
	MyVector2 mv(this->length);
	for (int i = 0; i < this->length; i++) {
		mv.a[i] = this->a[i] + b;
	}
	return mv;
}
MyVector2 MyVector2:: operator-(const int b) {
	MyVector2 mv(this->length);
	for (int i = 0; i < this->length; i++) {
		mv.a[i] = this->a[i] - b;
	}
	return mv;
}
std::ostream& operator<< (std::ostream& out, MyVector2& b) {
	for (int i = 0; i < b.length; i++) {
		out << b.a[i] << " ";
	}
	out << "\n";
	return out;
}
std::istream& operator>> (std::istream& in, MyVector2& b) {
	for (int i = 0; i < b.length; i++) {
		in >> b.a[i];
	}
	return in;
}