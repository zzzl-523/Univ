#include<iostream>
#include<string>
#include"number.h"
using namespace std;

int Square::getSquare() {
	return (_num*_num);
}
int Cube::getCube(){
	return (_num*_num*_num);
}