#include "Rectangle.h"

Rectangle::Rectangle() {
    _topLeft = new Point(0,1);
    _bottomRight = new Point(1,0);
    Rectangle::InstanceCount++;
}

Rectangle::Rectangle(const Point * TLeft, const Point* BRight) {
    if (!TLeft || !BRight || !Rectangle::isValid(TLeft, BRight)) {
        _topLeft = new Point(0,1);
        _bottomRight = new Point(1,0);

    } else {
        _topLeft = new Point(TLeft);
        _bottomRight = new Point(BRight);
    }
    Rectangle::InstanceCount++;
}

Rectangle::Rectangle(const Rectangle* other) {
    if (!other) {
        _topLeft = new Point(0,1);
        _bottomRight = new Point(1,0);
    } else {
        _topLeft = new Point(other->_topLeft);
        _bottomRight = new Point(other->_bottomRight);
    }
    Rectangle::InstanceCount++;
}

Rectangle::Rectangle(const Rectangle& other) {
    _topLeft = new Point(other._topLeft);
    _bottomRight = new Point(other._bottomRight);
    Rectangle::InstanceCount++;
}

Rectangle::~Rectangle() {
    if (_topLeft) {
        delete _topLeft;
        _topLeft = nullptr;
    }
    if (_bottomRight) {
        delete _bottomRight;
        _bottomRight = nullptr;
    }
    Rectangle::InstanceCount--;
}

float Rectangle::Area() const {
    float dx = _topLeft->X() - _bottomRight->X();
    float dy = _topLeft->Y() - _bottomRight->Y();
    return abs(dy * dx);
}

float Rectangle::Perimeter() const {
    float dx = abs(_topLeft->X() - _bottomRight->X());
    float dy = abs(_topLeft->Y() - _bottomRight->Y());
    return 2.0f * (dx + dy);
}

float Rectangle::Diagonal() const {
    return Point::CalcDistance(_topLeft, _bottomRight);
}

bool Rectangle::isValid(const Point* a, const Point* b) {
    if (!a || !b) return false;
    return (a->X() < b->X()) && (a->Y() > b->Y());
}

const Point Rectangle::getTLeft() const {
    if (!_topLeft) return Point();
    return *_topLeft;
}

const Point Rectangle::getBRight() const {
    if (!_bottomRight) return Point();
    return *_bottomRight;
}

void Rectangle::setTLeft(const Point* TLeft) {
    if (!TLeft || !_bottomRight || !Rectangle::isValid(TLeft, _bottomRight)) return;
    delete _topLeft;
    _topLeft = new Point(TLeft);
}

void Rectangle::setBRight(const Point* BRight) {
    if (!BRight || !_topLeft || !Rectangle::isValid(_topLeft, BRight)) return;
    delete _bottomRight;
    _bottomRight = new Point(BRight);
}

string Rectangle::ToString() const {
    if (!_topLeft || !_bottomRight) return "";
    stringstream writer;
    writer << "Top Left: " << _topLeft->ToString() << '\n';
    writer << "Bottom Right: " << _bottomRight->ToString() << '\n';
    return writer.str();
}

Rectangle& Rectangle::operator= (const Rectangle& other) {
    if (this == &other) return *this;
    if (!_topLeft || !_bottomRight) return *this;
    
    Point* TLeft = new Point(other._topLeft);
    Point* BRight = new Point(other._bottomRight);

    delete _topLeft; 
    delete _bottomRight;

    _topLeft = TLeft;
    _bottomRight = BRight;

    return *this;
}

istream& operator >> (istream& input, Rectangle* Rect) {
    if (!Rect) return input;

    Point * bufferTLeft = new Point();
    Point *bufferBRight = new Point();

    std::cout << "Nhap point goc tren ben trai: \n";
    input >> bufferTLeft;
    std::cout << "Nhap point goc duoi ben phai: \n";
    input >> bufferBRight;

    if (Rectangle::isValid(bufferTLeft, bufferBRight)) {
        delete Rect->_topLeft;
        delete Rect->_bottomRight;

        Rect->_topLeft = bufferTLeft;
        Rect->_bottomRight = bufferBRight;
    } else {
        delete bufferBRight;
        delete bufferTLeft;
    }
    return input;
}

ostream& operator << (ostream& output, const Rectangle* Rect) {
    if (!Rect) return output;
    output << Rect->ToString();
    return output;
}