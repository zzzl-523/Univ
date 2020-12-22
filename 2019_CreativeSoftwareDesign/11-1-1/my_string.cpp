#include<iostream>
#include"my_string.h"
using namespace std;

MyString& MyString::operator=(const MyString& b) {
	this->str = b.str;
	return *this;
}
MyString MyString::operator+(const MyString& b) {
	MyString temp = *this;
	temp.str = temp.str + b.str;
	return temp;
}
MyString MyString::operator*(const int b) {
	MyString ms;
	for (int i = 0; i < b; i++) {
		ms.str += this->str;
	}
	return ms;
}
ostream& operator<<(std::ostream& out, MyString& my_string){
	out << my_string.str << endl;
	return out;
}
istream& operator>>(std::istream& in, MyString& my_string) {
	in >> my_string.str;
	return in;
}