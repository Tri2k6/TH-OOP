#include "Circle.h"

Circle::Circle() {
    _center = new Point(0,0);
    _radius = 1.0f;
    Circle::InstanceCount++;
}

Circle::Circle(const Point* Center, const float& R) {
    if (!Center || !Circle::isValid(R)) {
        _center = new Point(0,0);
        _radius = 1.0f;
    } else {
        _center = new Point(Center);
        _radius = R;
    }
    Circle::InstanceCount++;    
}

Circle::Circle(const Circle* other) {
    if (!other || !Circle::isValid(other->_radius)) {
        _center = new Point(0,0);
        _radius = 1.0f;
    } else {
        _center = new Point(other->_center);
        _radius = other->_radius;
    }
    Circle::InstanceCount++;
}

Circle::Circle(const Circle& other) {
    if (!Circle::isValid(other._radius)) {
        _center = new Point(0,0);
        _radius = 1.0f;
    } else {
        _center = new Point(other._center);
        _radius = other._radius;
    }
    Circle::InstanceCount++;
}

Circle::~Circle() {
    if (_center) {
        delete _center;
        _center = nullptr;
    }
    _radius = 0;
    Circle::InstanceCount--;
}

const float Circle::getRadius() const {
    return _radius;
}

const Point Circle::getCenter() const {
    if (_center) return *_center;
    return Point(0,0);
}

void Circle::setRadius(const float& R) {
    if (!Circle::isValid(R)) return;
    _radius = R;
}

void Circle::setCenter(const Point* Center) {
    if (!Center || !_center) return;
    delete _center;
    _center = new Point(Center);
}

float Circle::Area() const {
    return PI * _radius * _radius;
}

float Circle::Perimeter() const {
    return 2.0f * PI * _radius;
}

float Circle::Diameter() const {
    return 2.0f * _radius;
}

bool Circle::isValid(const float& Radius) {
    return Radius > 0;
}

string Circle::ToString() const {
    if (!_center) return "";
    stringstream writer;
    writer << "Center: " << _center->ToString() << '\n';
    writer << "Radius: " << _radius << '\n';
    return writer.str();
}

Circle& Circle::operator= (const Circle& other) {
    if (this == &other) return *this;
    
    delete _center;
    _center = new Point(other._center);
    _radius = other._radius;
    
    return *this;
}

istream& operator >> (istream& input, Circle* Cir) {
    if (!Cir) return input;

    Point * buffer_Center = new Point();
    float buffer_Radius; 

    std::cout << "Nhap tam cua hinh tron: \n";
    input >> buffer_Center;
    std::cout << "Nhap ban kinh hinh tron: ";
    input >> buffer_Radius;

    if (Circle::isValid(buffer_Radius)) {
        delete Cir->_center;

        Cir->_center = buffer_Center;
        Cir->_radius = buffer_Radius;
    } else {
        delete buffer_Center;
    }
    return input;
}

ostream& operator << (ostream& output, const Circle* Cir) { 
    if (!Cir) return output;
    output << Cir->ToString();
    return output;
}