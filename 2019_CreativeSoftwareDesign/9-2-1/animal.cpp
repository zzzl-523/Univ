#include<iostream>
#include<string>
#include"animal.h"
using namespace std;

Animal::Animal(string name, int age) {
	name_ = name;
	age_ = age;
}
Zebra::Zebra(int numStripes, string name, int age):Animal(name,age) {
	numStripes_ = numStripes;
}
void Zebra::printInfo() {
	cout << "Zebra, Name: " << name_ << ", Age: " << age_ << ", Number of stripes: " << numStripes_<<endl;
}
Cat::Cat(string favoriteToy, string name, int age) :Animal(name, age) {
	favoriteToy_ = favoriteToy;
}
void Cat::printInfo() {
	cout << "Cat, Name: " << name_ << ", Age: " << age_ << ", Favorite toy: " << favoriteToy_<<endl;
}