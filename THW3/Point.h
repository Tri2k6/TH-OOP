#pragma once
#include <math.h>
#include <iostream>

class Point {
public:
    static int InstanceCount;
private:
    float _x;
    float _y;
public:
    const float X() const {return _x;}
    const float Y() const {return _y;}
    void SetX(const float value) { _x = value;}
    void SetY(const float value) { _y = value;}
public:
    Point();
    Point(const float, const float);
    Point(const Point& other);
    ~Point();
public:
    Point& operator = (const Point& other);
    bool operator == (const Point& other) const;
    float CalcDistanceTo(const Point* other) const;
    friend std::ostream& operator << (std::ostream& output, const Point& a);
public:
    static float CalcDistance(const Point* a, const Point*b);
};