#pragma once

#include<iostream>
#include<string>
using namespace std;

class Animal {
protected:
	string name_;
	int age_;
public:
	Animal() {};
	Animal(string name, int age);
	virtual void printInfo() {};
};

class Zebra :public Animal {
protected:
	int numStripes_;
public:
	Zebra() {};
	Zebra(int numStripes, string name, int age);//initializer list 로 부모 class 생성자
	virtual void printInfo();
};

class Cat :public Animal {
protected:
	string favoriteToy_;
public:
	Cat() {};
	Cat(string favoriteToy, string name, int age);
	virtual void printInfo();
};