#pragma once

#include "Point.h"
#include <math.h>

class Triangle {
private:
	Point* _A, * _B, * _C;
public:
	friend bool isValid(Point* A, Point* B, Point* C);
	Triangle();
	Triangle(Point* A, Point* B, Point* C);
	~Triangle();
	Point* GetA();
	Point* GetB();
	Point* GetC();
	void setA(Point *A);
	void setB(Point *B);
	void setC(Point *C);
public:
	float Area();
	float Perimeter();
};