#pragma once
#include "Point.h"

class Rectangle {
public:
    static int InstanceCount;
private:
    Point* _topLeft;
    Point* _bottomRight;
public:
    Rectangle();
    Rectangle(const Point& TLeft, const Point& BRight);
    Rectangle(const Rectangle& other);
    ~Rectangle();
public:
    Rectangle& operator = (const Rectangle& other);
    const Point& GetTLeft() const;
    const Point& GetBRight() const;
    void setTLeft(const Point& TLeft);
    void setBRight(const Point& BRight);
public:
    static bool isValid(const Point& Tleft, const Point& BRight);
};