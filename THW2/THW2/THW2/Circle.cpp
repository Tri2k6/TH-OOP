#include "Circle.h"

Circle::Circle() {
	_center = new Point();
	_radius = 0;
}

Circle::Circle(Point* Center, float R) {
	if (!Center) return;
	
	_center = new Point(Center->X(), Center->Y());

	_radius = R;
}

Point* Circle::Center() {
	return _center;
}

float Circle::Radius() {
	return _radius;
}

void Circle::SetCenter(Point* value) {
	if (!value) return;
	_center->SetX(value->X());
	_center->SetY(value->Y());
}

void Circle::SetRadius(float value) {
	if (value < 0) return;
	_radius = value;
}

float Circle::Diameter() {
	return 2.0f * _radius;
}

float Circle::Perimeter() {
	return 2.0f * _radius * PI;
}

float Circle::Area() {
	return _radius * _radius * PI;
}

Circle::~Circle() {
	delete _center;
	_center = nullptr;
	_radius = 0;
}