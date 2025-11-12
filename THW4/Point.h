#pragma once
#include <string>
#include <iostream>
#include <math.h>
#include <sstream>
using std::string;
using std::istream;
using std::ostream;
using std::stringstream;

class Point {
public:
    static int InstanceCount;
private:
    float _x;
    float _y;
public:
    float X() const;
    float Y() const;
    void setX(const float& X);
    void setY(const float& Y);
public:
    Point();
    Point(const float& X, const float& Y);
    Point(const Point* other);
    Point(const Point& other);
    ~Point();
public:
    float CalcDistanceTo(const Point* other) const;
    static float CalcDistance(const Point* a, const Point* b);
public:
    string ToString() const;
    Point& operator = (const Point& other);
    friend istream& operator >> (istream& input, Point* other);
    friend ostream& operator << (ostream& output, const Point* other);
};