#include "Point.h"

Point::Point() {
    _x = _y = 0;
    Point::InstanceCount++;
}

Point::Point(const float x, const float y) {
    _x = x;
    _y = y;
    Point::InstanceCount++;
}

Point::Point(const Point& other) {
    _x = other._x;
    _y = other._y;
    Point::InstanceCount++;
}

Point::~Point() {
    Point::InstanceCount--;
}

Point& Point::operator= (const Point& other) {
    _x = other._x;
    _y = other._y;
    return *this;
}

float Point::CalcDistanceTo(const Point* other) const {
    float dx = _x - other->_x;
    float dy = _y - other->_y;
    return sqrt(dx * dx + dy * dy);
}

bool Point::operator==(const Point& other) const {  
    return other._x == _x && other._y == _y;
}

float Point::CalcDistance(const Point* a, const Point* b) {
    return a->CalcDistanceTo(b);
}

std::ostream& operator << (std::ostream& output, const Point& a) {
    output << "(" << a.X() << " , " << a.Y() << ")";
    return output;
}