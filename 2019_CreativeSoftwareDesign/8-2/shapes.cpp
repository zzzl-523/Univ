#include<iostream>
#include<string>
#include<cmath>
#include"shapes.h"
using namespace std;

Shape::Shape() {

}
Shape::Shape(int x,int y,char brush) {
	top_left_x = x;
	top_left_y = y;
	brush_ = brush;
}
double Shape::GetArea() {
	return 0;
}
int Shape::GetPerimeter() {
	return 0;
}
void Shape::Draw(int canvas_width, int canvas_height) {	//클래스마다 다르게 해주기

}

rect::rect(int x, int y, int width, int height,  char brush) :Shape(x, y, brush) {
	width_ = width;
	height_ = height;
}
double rect:: GetArea() {
	return width_ * height_;
}
int rect::GetPerimeter() {
	return 2 * (width_ + height_);
}
void rect::Draw(int canvas_width, int canvas_height) {

	cout << " ";	//첫 줄 출력
	for (int i = 0; i < canvas_width; i++) {
		cout << i;
	}
	cout << "\n";

	for (int i = 0; i < canvas_height; i++) {
		cout << i;

		for (int j = 0; j < canvas_width; j++) {

			if (top_left_x-1 <= (j-1)&& (j - 1) < (top_left_x-1 + width_) && top_left_y-1 <= (i-1)&& (i - 1) < (top_left_y-1 + height_)) {
				cout << brush_;
			}
			else {
				cout << ".";
			}
		}

		cout << "\n";

	}
	cout << "\n";
}
square::square(int x, int y, int length, char brush):Shape(x,y,brush) {
	length_ = length;
}
double square::GetArea(){
	return length_ * length_;
}
int square::GetPerimeter() {
	return 4 * (length_);
}
void square::Draw(int canvas_width, int canvas_height) {
	cout << " ";	//첫 줄 출력
	for (int i = 0; i < canvas_width; i++) {
		cout << i;
	}
	cout << "\n";
	for (int i = 0; i < canvas_height; i++) {
		cout << i;

		for (int j = 0; j < canvas_width; j++) {

			if (top_left_x-1 <= (j-1)&& (j - 1) <= (top_left_x-1 + length_) && top_left_y-1 <= (i-1)&& (i - 1) <= (top_left_y-1 + length_)) {
				cout << brush_;
			}
			else {
				cout << ".";
			}
		}

		cout << "\n";

	}
	cout << "\n";
}


diamond::diamond(int x, int y, int distance, char brush) : Shape(x, y, brush) {
	distance_ = distance;
}
double diamond::GetArea() {
	return (double((2*distance_+1))*(2 * distance_+1))/2;
}
int diamond::GetPerimeter() {
	return sqrt(2)*(double(2*distance_+1)/2)*4;
}
void diamond::Draw(int canvas_width, int canvas_height) {
	cout << " ";	//첫 줄 출력
	for (int i = 0; i < canvas_width; i++) {
		cout << i;
	}
	cout << "\n";

	int mid_y = top_left_y+distance_ ;
	int mid_x = top_left_x;

	for (int i = 0; i < canvas_height; i++) {
		cout << i;

		for (int j = 0; j < canvas_width; j++) {
			
			if (top_left_y-1<=(i-1)&&(i-1)<=(top_left_y -1+distance_*2)  &&  (mid_x-1-distance_+abs(i-mid_y))<=(j-1)&&(j-1)<=(mid_x-1+distance_ - abs(i- mid_y))) {
				cout << brush_;
			}
			
			else {
				cout << ".";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}


