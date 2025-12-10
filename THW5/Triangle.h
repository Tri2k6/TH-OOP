#pragma once

#include "Point.h"
#include <math.h>
#include "Tokenizer.h"

class Triangle {
private:
	Point* _A, * _B, * _C;
public:
	Triangle();
	Triangle(const Point* A, const Point* B, const Point* C);
	Triangle(const Triangle& other);
	Triangle(const Triangle* other);
	~Triangle();
public:
	Point getA() const;
	Point getB() const;
	Point getC() const;
	void setA(Point *A);
	void setB(Point *B);
	void setC(Point *C);
public:
	float Area();
	float Perimeter();
	static bool isValid(const Point* A, const Point* B, const Point* C);

	static Triangle* Parse(string stringLine);
public:
	friend ostream& operator << (ostream& output, Triangle* Tri);
};
