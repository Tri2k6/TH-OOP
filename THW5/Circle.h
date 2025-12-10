#pragma once
#include "Point.h"

#define PI 3.14159265358979323846

class Circle {
public:
    static int InstanceCount;
private:
    Point* _center;
    float _radius;
public:
    const float getRadius() const;
    const Point getCenter() const;
    void setRadius(const float& R);
    void setCenter(const Point* Center);
public:
    Circle();
    Circle(const Point * Center, const float& R);
    Circle(const Circle* other);
    Circle(const Circle& other);
    ~Circle();
public:
    float Area() const;
    float Perimeter() const;
    float Diameter() const;
    static bool isValid(const float& Radius);
public:
    string ToString() const;
    Circle& operator = (const Circle& other);
    friend istream& operator >> (istream& input, Circle* Cir);
    friend ostream& operator << (ostream& output, const Circle* Cir);
public:
    static Circle* Parse(string stringLine);
};