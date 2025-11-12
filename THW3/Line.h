#pragma once
#include "Point.h"

class Line {
public:
    static int InstanceCount;
private:
    Point* _start;
    Point* _end;
    float length;
public:
    Line();
    Line(const Point* ST, const Point* EN);
    Line(const Line& other);
    ~Line();
public:
    Line& operator = (const Line& other);
    Point* GetStart();
    Point* GetEnd();
    float getLength();

    void setStart(const Point* ST);
    void setEnd(const Point* EN);
public:
    static bool isValid(const Point* ST, const Point* EN);
};