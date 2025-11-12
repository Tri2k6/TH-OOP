#include "Line.h"

Line::Line() {
    _start = new Point(0,0);
    _end = new Point(1,0);
    length = Point::CalcDistance(_start, _end);
    Line::InstanceCount++;
}

Line::Line(const Point* ST, const Point* EN) {
    if (!Line::isValid(ST, EN)) (*this) = Line();
    _start = new Point();
    _end = new Point();

    _start->SetX(ST->X());
    _start->SetY(ST->Y());

    _end->SetX(EN->X());
    _end->SetY(EN->Y());
    length = Point::CalcDistance(_start, _end);
    Line::InstanceCount++;
}

Line::Line(const Line& other) {
    _start = new Point();
    _end = new Point();

    _start->SetX(other._start->X());
    _start->SetY(other._start->Y());

    _end->SetX(other._end->X());
    _end->SetY(other._end->Y());
    length = Point::CalcDistance(_start, _end);
    Line::InstanceCount++;
}

Line::~Line() {
    delete _start; _start = NULL;
    delete _end; _end = NULL;
    length = 0;
    Line::InstanceCount--;
}

Point* Line::GetStart() {
    return _start;
}

Point* Line::GetEnd() {
    return _end;

}

float Line::getLength() {
    return length;
}

bool Line::isValid(const Point* ST, const Point* EN) {
    return !((*ST) == (*EN));
}

Line& Line::operator= (const Line& other) {
    _start = new Point();
    _end = new Point();

    _start->SetX(other._start->X());
    _start->SetY(other._start->Y());

    _end->SetX(other._end->X());
    _end->SetY(other._end->Y());
    length = Point::CalcDistance(_start, _end);
    return *this;
}

void Line::setStart(const Point* ST) {  
    if (!isValid(ST, _end)) {
        _start->SetX(ST->X());
        _start->SetY(ST->Y());
        length = Point::CalcDistance(_start, _end);
    }   
}

void Line::setEnd(const Point* EN) {
    if (!isValid(_start, EN)) {
        _end->SetX(EN->X());
        _end->SetY(EN->Y());
        length = Point::CalcDistance(_start, _end);
    }
}
