#include<iostream>
#include"my_vector.h"
using namespace std;

MyVector::MyVector() {}
MyVector::MyVector(int length) {
	this->length = length;
	this->a = new double[length];
}
MyVector::~MyVector() {
	//delete[] this->a; 
}

MyVector& MyVector:: operator=(const MyVector& b) {
	//this->a = new double[this->length];
	this->a = b.a;
	return *this;
}
MyVector MyVector:: operator+(const MyVector& b) {
	MyVector mv(this->length);
	for (int i = 0; i < this->length; i++) {
		mv.a[i] = this->a[i] + b.a[i];
	}
	return mv;
}
MyVector MyVector::operator-(const MyVector& b) {
	MyVector mv(this->length);
	for (int i = 0; i < this->length; i++) {
		mv.a[i] = this->a[i] - b.a[i];
	}
	return mv;
}
MyVector MyVector::operator+(const int b) {
	MyVector mv(this->length);
	for (int i = 0; i < this->length; i++) {
		mv.a[i] = this->a[i] + b;
	}
	return mv;
}
MyVector MyVector:: operator-(const int b) {
	MyVector mv(this->length);
	for (int i = 0; i < this->length; i++) {
		mv.a[i] = this->a[i] - b;
	}
	return mv;
}
std::ostream& operator<< (std::ostream& out, MyVector& b) {
	for (int i = 0; i < b.length; i++) {
		out << b.a[i] << " ";
	}
	out << "\n";
	return out;
}
std::istream& operator>> (std::istream& in, MyVector& b) {
	for (int i = 0; i < b.length; i++) {
		in >> b.a[i];
	}
	return in;
}
