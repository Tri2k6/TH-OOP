#pragma once
#include "Point.h"

class Circle {
public:
	const float PI = 3.14f;
private:
	Point* _center;
	float _radius;
public:
	Circle();
	Circle(Point* Center, float R);
	Point* Center();
	float Radius();
	void SetCenter(Point* value);
	void SetRadius(float value);
	~Circle();
public:
	float Diameter();
	float Perimeter();
	float Area();
};
