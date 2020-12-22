#include<iostream>
#include"my_string2.h"
using namespace std;

MyString2::MyString2(const MyString2& b) {
	this->str = b.str;
}

MyString2 MyString2::operator+(const MyString2& b) {
	MyString2 temp = *this;
	temp.str = temp.str + b.str;
	return temp;
}
MyString2 MyString2::operator*(const int b) {
	MyString2 ms;
	for (int i = 0; i < b; i++) {
		ms.str += this->str;
	}
	return ms;
}
ostream& operator<<(std::ostream& out, MyString2& my_string2) {
	out << my_string2.str << endl;
	return out;
}
istream& operator>>(std::istream& in, MyString2& my_string2) {
	in >> my_string2.str;
	return in;
}