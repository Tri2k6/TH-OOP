#include "Rectangle.h"

Rectangle::Rectangle() {
    _topLeft = new Point(0,1);
    _bottomRight = new Point(1,0);
    Rectangle::InstanceCount++;
}

Rectangle::Rectangle(const Point& TLeft, const Point& BRight) {
    if (!Rectangle::isValid(TLeft, BRight)) *this = Rectangle();
    _topLeft = new Point();
    _bottomRight = new Point();

    *_topLeft = TLeft;
    *_bottomRight = BRight;
    Rectangle::InstanceCount++;
}

Rectangle::Rectangle(const Rectangle& other) {
    _topLeft = new Point();
    _bottomRight = new Point();
    
    *_topLeft = *other._topLeft;
    *_bottomRight = *other._bottomRight;

    Rectangle::InstanceCount++;
}

Rectangle::~Rectangle() {
    delete _topLeft;
    _topLeft = NULL;

    delete _bottomRight;
    _bottomRight = NULL;

    Rectangle::InstanceCount--;
}

Rectangle& Rectangle::operator= (const Rectangle& other) {
    *_topLeft = *other._topLeft;
    *_bottomRight = *other._bottomRight;
    return *this;
}

const Point& Rectangle::GetTLeft() const {
    return *_topLeft;
}

const Point& Rectangle::GetBRight() const {
    return *_bottomRight;
}

void Rectangle::setTLeft(const Point& TLeft) {
    if (!Rectangle::isValid(TLeft, *_bottomRight)) return;
    *_topLeft = TLeft;
}

void Rectangle::setBRight(const Point& BRight) {
    if (!Rectangle::isValid(*_topLeft, BRight)) return;
    *_bottomRight = BRight;
}

bool Rectangle::isValid(const Point& TLeft, const Point& BRight) {
    return TLeft.X() < BRight.X() && TLeft.Y() > BRight.Y(); 
}