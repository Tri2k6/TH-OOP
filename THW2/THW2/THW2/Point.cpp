#include "Point.h"
#include <iostream>
using std::ostream;

Point::Point() {
	this->_x = 0;
	this->_y = 0;
}

Point::Point(float x, float y) {
	this->_x = x;
	this->_y = y;
}

void Point::operator = (const Point& other) {
	_x = other._x;
	_y = other._y;
}

bool Point::operator == (const Point& other) {
	return (_x == other._x) && (_y == other._y);
}

void Point::output() {
	std::cout << "(" << X() << ", " << Y() << ") ";
}

Point::~Point() {

}

float Point::CalcDistanceTo(const Point* other) {
	float dx = this->_x - other->_x;
	float dy = this->_y - other->_y;
	return sqrt(dx * dx + dy * dy);
}