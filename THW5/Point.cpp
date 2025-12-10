#include "Point.h"

Point::Point() {
    _x = _y = 0;
    Point::InstanceCount++;
}

Point::Point(const float& X, const float& Y) {
    _x = X;
    _y = Y;
    Point::InstanceCount++;
}

Point::Point(const Point* other) {
    if (!other) {
        _x = _y = 0;
        Point::InstanceCount++;
        return;
    }
    _x = other->_x;
    _y = other->_y;
    Point::InstanceCount++;
}

Point::Point(const Point& other) {  
    _x = other._x;
    _y = other._y;
    Point::InstanceCount++;
}

Point::~Point() {
    _x = _y = 0;
    Point::InstanceCount--;
}

float Point::X() const {
    return _x;
}

float Point::Y() const {
    return _y;
}

void Point::setX(const float& X) {
    _x = X;
}

void Point::setY(const float& Y) {
    _y = Y;
}

float Point::CalcDistanceTo(const Point* other) const {
    if (!other) return 0;
    float dx = other->_x - _x;
    float dy = other->_y - _y;
    return sqrt(dx * dx + dy * dy);
}

float Point::CalcDistance(const Point* a, const Point* b) {
    if (!a || !b) return 0;
    return a->CalcDistanceTo(b);
}

string Point::ToString() const {
    stringstream writer;
    writer << "(" << _x << ", " << _y << ")";
    return writer.str();
}

istream& operator >> (istream& input, Point * other) {
    if (!other) return input;
    std::cout << "Nhap x: ";
    input >> other->_x;
    std::cout << "Nhap y: ";
    input >> other->_y;
    return input;
}

ostream& operator << (ostream& output, const Point* other) {
    if (!other) return output;
    output << other->ToString();
    return output;
}

Point* Point::Parse(string stringLine) {
    Point * res = new Point();
    if (!res) return NULL;

    string delimeter = ", ()";
    Tokenizer tokenize(stringLine, delimeter);

    float x = tokenize.nextDouble();
    float y = tokenize.nextDouble();

    res->_x = x;
    res->_y = y;
    return res;
}