#pragma once
#include "Point.h"
#include <math.h>

class Rectangle {
private:
	Point* _topLeft;
	Point* _bottomRight;
public:
	friend bool isValid(Point* TLeft, Point* BRight);
	Rectangle();
	Rectangle(Point* tLeft, Point* bRight);
	~Rectangle();
	Point* getTLeft();
	Point* getBRight();
	void setTLeft(Point* TLeft);
	void setBRight(Point* BRight);
public:
	float Area();
	float Perimeter();
};