#pragma once

#include "Point.h"

class Rectangle {
public:
    static int InstanceCount;
private:
    Point* _topLeft;
    Point* _bottomRight;
public:
    const Point getTLeft() const;
    const Point getBRight() const;
    void setTLeft(const Point* TLeft);
    void setBRight(const Point* BRight);
public:
    Rectangle();
    Rectangle(const Point* TLeft, const Point* BRight);
    Rectangle(const Rectangle& other);
    Rectangle(const Rectangle* other);
    ~Rectangle();
public:
    float Area() const;
    float Perimeter() const;
    float Diagonal() const;
public:
    static bool isValid(const Point* a, const Point* b);
public:
    string ToString() const;
    Rectangle& operator = (const Rectangle& other);
    friend istream& operator >> (istream& input, Rectangle* Rect);
    friend ostream& operator << (ostream& output, const Rectangle* Rect);
};