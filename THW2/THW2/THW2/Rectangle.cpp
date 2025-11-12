#include "Rectangle.h"

bool isValid(Point* TLeft, Point* BRight) {
	if (!TLeft || !BRight) return false;
	return TLeft->X() < BRight->X() && TLeft->Y() > BRight->Y();
}

Rectangle::Rectangle() {
	_topLeft = new Point(1,1);
	_bottomRight = new Point(10, 10);
}

Rectangle::Rectangle(Point* tLeft, Point* bRight) {
	if (!isValid(tLeft, bRight)) *this = Rectangle();
	_topLeft = new Point(tLeft->X(), tLeft->Y());
	_bottomRight = new Point(bRight->X(), bRight->Y());
}


Rectangle::~Rectangle() {
	delete _topLeft;
	_topLeft = nullptr;

	delete _bottomRight;
	_bottomRight = nullptr;
}

Point* Rectangle::getTLeft() {
	return _topLeft;
}

Point* Rectangle::getBRight() {
	return _bottomRight;
}

void Rectangle::setTLeft(Point* TLeft) {
	if (!isValid(TLeft, _bottomRight)) return;
	_topLeft->SetX(TLeft->X());
	_topLeft->SetY(TLeft->Y());
}

void Rectangle::setBRight(Point* BRight) {
	if (!isValid(_topLeft, BRight)) return;
	_bottomRight->SetX(BRight->X());
	_bottomRight->SetY(BRight->Y());
}

float Rectangle::Area() {
	float dy = (_topLeft->Y() - _bottomRight->Y());
	float dx = (_bottomRight->X() - _topLeft->X());
	return dy * dx;
}

float Rectangle::Perimeter() {
	float dy = (_topLeft->Y() - _bottomRight->Y());
	float dx = (_bottomRight->X() - _topLeft->X());
	return 2 * (dy + dx);
}