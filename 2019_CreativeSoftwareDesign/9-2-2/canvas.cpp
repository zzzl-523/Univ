#include<iostream>
#include"canvas.h"
using namespace std;

Canvas::Canvas(size_t row, size_t col) {
	garo_ = row;
	sero_ = col;

	canvas_ = new char*[sero_];
	for (size_t i = 0; i < sero_; i++) {
		canvas_[i] = new char[garo_];
	}

	for (int i = 0; i < (int)sero_; i++) {
		for (size_t j = 0; j < garo_; j++) {
			canvas_[i][j] = '.';
		}
	}
}
Canvas::~Canvas() {
	for (size_t i = 0; i < sero_; i++) {
		delete[] canvas_[i];
	}
	delete[] canvas_;
}
void Canvas::Resize(size_t w, size_t h) {
	garo_ = w;
	sero_ = h;

	//size_t** canvas_ = new size_t*[sero_];
	/*for (size_t i = 0; i < sero_; i++) {
		canvas_[i] = new size_t[garo_];
	}*/
	canvas_ = new char*[sero_];
	for (size_t i = 0; i < sero_; i++) {
		canvas_[i] = new char[garo_];
	}
}
bool Canvas::DrawPixel(int x, int y, char brush) {
	if (0 <= x && x <= (int)garo_ && 0 <= y && y <= (int)sero_) {
		canvas_[y][x] = brush;
		return 1;
	}
	else {
		return 1;
	}
}
void Canvas::Print() {
	cout << " ";
	for (size_t i = 0; i < garo_; i++) {
		cout << i % 10;
	}
	cout << "\n";

	for (size_t i = 0; i < sero_; i++) {
		cout << i % 10;
		for (size_t j = 0; j < garo_; j++) {
			cout << canvas_[i][j];
		}
		cout << "\n";
	}
}
void Canvas::Clear() {
	for (size_t i = 0; i < sero_; i++) {
		for (size_t j = 0; j < garo_; j++) {
			canvas_[i][j] = '.';
		}
	}
}

Shape::~Shape() {

}
//void Shape::Draw(Canvas* canvas) {}

Rectangle::Rectangle(int top_left_x, int top_left_y, int width, int height, char brush) {
	top_x = top_left_x;
	top_y = top_left_y;
	width_ = width;
	height_ = height;
	brush_ = brush;
}
void Rectangle::Draw(Canvas* canvas) {
	for (int j = 0; j < height_; j++) {
		for (int i = 0; i < width_; i++) {
			canvas->DrawPixel(top_x + i, top_y + j, brush_);
		}
	}
}


UpTriangle::UpTriangle(int top_center_x, int top_center_y, int height, char brush) {
	top_x = top_center_x;
	top_y = top_center_y;
	height_ = height;
	brush_ = brush;
}
void UpTriangle::Draw(Canvas* canvas) {
	for (int i = 0; i <= height_; i++) {
		for (int j = 0; j < i; j++) {
			canvas->DrawPixel(top_x + j, top_y - 1 + i, brush_);//坷弗率
			canvas->DrawPixel(top_x - j, top_y - 1 + i, brush_);//哭率
		}
	}
	/*int x1 = top_x;
	int x2 = top_x;
	for (int i = top_y; i <= top_y + height_; i++) {
		for (int j = x1; j <= x2; j++) {
			canvas->DrawPixel(j, i, brush_);
		}
		x1--;
		x2++;
	}*/
}

DownTriangle::DownTriangle(int bot_center_x, int bot_center_y, int height, char brush) {
	top_x = bot_center_x;
	top_y = bot_center_y;
	height_ = height;
	brush_ = brush;
}
void DownTriangle::Draw(Canvas* canvas) {
	/*int ourY = top_y - height_+1;
	for (int i = 0; i >= height_; i++) {
		for (int j = height_ -i; j >= 0; j--) {
			canvas->DrawPixel(top_x + j , ourY  + 1 + i, brush_);
			canvas->DrawPixel(top_x - j , ourY  + 1 + i, brush_);
		}
		ourY--;
	}*/
	int x1 = top_x;
	int x2 = top_x;
	int y = top_y;
	for (int i = 0; i < height_; i++) {
		for (int j = x1; j <= x2; j++) {
			canvas->DrawPixel(j, y, brush_);
		}
		x1--;
		x2++;
		y--;
	}
}

Diamond::Diamond(int top_center_x, int top_center_y, int distance, char brush) {
	top_x = top_center_x;
	top_y = top_center_y;
	distance_ = distance;
	brush_ = brush;
}
void Diamond::Draw(Canvas* canvas) {
	/*for (int i = 0; i <= distance_ + 1; i++) {
		for (int j = 0; j < i; j++) {
			canvas->DrawPixel(top_x + j, top_y-1 + i, brush_);//坷弗率
			canvas->DrawPixel(top_x - j, top_y-1 + i, brush_);//哭率
		}
	}*/
	/*for (int i = 0; i <= distance_; i++) {
		for (int j = distance_-1-i; j >= 0; j--) {
			canvas->DrawPixel(top_x + j, top_y+distance_+1 + i, brush_);
			canvas->DrawPixel(top_x - j, top_y + distance_+1 + i, brush_);
		}
	}*/
	int x1 = top_x;
	int x2 = top_x;
	for (int i = top_y; i <= top_y + 2 * distance_; i++) {
		for (int j = x1; j <= x2; j++) {
			canvas->DrawPixel(j, i, brush_);
		}
		if (i < top_y + distance_)
		{
			x1--;
			x2++;
		}
		else
		{
			x1++;
			x2--;
		}
	}
}