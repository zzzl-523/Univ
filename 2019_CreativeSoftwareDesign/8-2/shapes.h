#pragma once
class Shape {
public:
	Shape();
	Shape(int x, int y, char brush);
	double GetArea();
	int GetPerimeter();
	void Draw(int canvas_width, int canvas_height);
protected:
	int top_left_x, top_left_y;
	char brush_;

	// Define common properties for all shape types
};
class rect :public Shape {
public:
	rect(int x, int y, int width, int height, char brush);
	double GetArea();
	int GetPerimeter();
	void Draw(int canvas_width, int canvas_height);

	int width_, height_;
};
class square :public Shape {
public:
	square(int x, int y, int length, char brush);
	double GetArea();
	int GetPerimeter();
	void Draw(int canvas_width, int canvas_height);

	int length_;//한 변의 길이
};
class diamond :public Shape {
public:
	diamond(int x, int y, int distance, char brush);
	double GetArea();
	int GetPerimeter();
	void Draw(int canvas_width, int canvas_height);

	int distance_;
};