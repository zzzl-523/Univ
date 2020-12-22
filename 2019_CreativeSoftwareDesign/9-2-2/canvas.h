#pragma once
#include<iostream>
using namespace std;

class Canvas {
public:
	Canvas(size_t row, size_t col);
	~Canvas();
	// Change this canvas size to w x h. Preserve already existing shapes on the canvas.
	void Resize(size_t w, size_t h);
	// Dot with the brush at (x,y). If (x,y) is outside the canvas, just ignore it.
	bool DrawPixel(int x, int y, char brush);
	//Print out the canvas
	void Print();
	// Erase all (initialize with '.') //.으로 초기화
	void Clear();

protected:
	int garo_, sero_;
	char** canvas_;
};
class Shape {
public:
	virtual ~Shape();
	virtual void Draw(Canvas* canvas) {};
protected:
	int top_x, top_y; //bottom 인 것도 있음
	int height_;
	char brush_;
	// Define common properties of shapes
};
class Rectangle : public Shape { /* Define required members */
public:
	Rectangle(int top_left_x, int top_left_y, int width, int height, char brush);
	virtual ~Rectangle() {};
	virtual void Draw(Canvas* canvas);
protected:
	int width_;
};
class UpTriangle : public Shape { /* Define required members */
public:
	UpTriangle(int top_center_x, int top_center_y, int height, char brush);
	virtual ~UpTriangle() {};
	virtual void Draw(Canvas* canvas);
};
class DownTriangle : public Shape { /* Define required members */
public:
	DownTriangle(int bot_center_x, int bot_center_y, int height, char brush);
	virtual ~DownTriangle() {};
	virtual void Draw(Canvas* canvas);

};
class Diamond : public Shape { /* Define required members */
public:
	Diamond(int top_center_x, int top_center_y, int distance, char brush);
	virtual ~Diamond() {};
	virtual void Draw(Canvas* canvas);

	int distance_;
};