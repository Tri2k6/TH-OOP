#include "Triangle.h"

Triangle::Triangle() {
    _A = new Point(0,1);
    _B = new Point(1,1);
    _C = new Point(1,0);
}

Triangle::Triangle(const Point * A, const Point* B, const Point* C) {
    if (!A || !B || !C || !Triangle::isValid(A,B,C)) {
        _A = new Point(0,1);
        _B = new Point(1,1);
        _C = new Point(1,0);
        return;
    }
    _A = new Point(A);
    _B = new Point(B);
    _C = new Point(C);
}

Triangle::Triangle(const Triangle& other) {
    _A = new Point(other._A);
    _B = new Point(other._B);
    _C = new Point(other._C);
}

Triangle::Triangle(const Triangle* other) {
    if (!other) {
        _A = new Point(0,1);
        _B = new Point(1,1);
        _C = new Point(1,0);
        return;       
    }
    _A = new Point(other->_A);
    _B = new Point(other->_B);
    _C = new Point(other->_C);    
}

Triangle::~Triangle() {
    if (!_A) delete _A;
    _A = nullptr;

    if (!_B) delete _B;
    _B = nullptr;

    if (!_C) delete _C;
    _C = nullptr;
}

Point Triangle::getA() const {
    if (!_A) return Point(0,1);
    return *(_A);
}

Point Triangle::getB() const {
    if (!_B) return Point(1,1);
    return *(_B);
}

Point Triangle::getC() const {
    if (!_C) return Point(1,0);
    return *(_C);
}

void Triangle::setA(Point* A) {
    if (!A || !Triangle::isValid(A, _B, _C)) return;
    _A->setX(A->X());
    _A->setY(A->Y());
}

void Triangle::setB(Point* B) {
    if (!B || !Triangle::isValid(_A, B, _C)) return;
    _B->setX(B->X());
    _B->setY(B->Y());
}

void Triangle::setC(Point* C) {
    if (!C || !Triangle::isValid(_A, _B, C)) return;
    _C->setX(C->X());
    _C->setY(C->Y());
}

float Triangle::Area() {
	float AB = _A->CalcDistanceTo(_B);
	float AC = _A->CalcDistanceTo(_C);
	float BC = _B->CalcDistanceTo(_C);
	float p = (AB + AC + BC) / 2;
	return (float) sqrt(p * (p - AB) * (p - AC) * (p - BC));
}

float Triangle::Perimeter() {
	float AB = _A->CalcDistanceTo(_B);
	float AC = _A->CalcDistanceTo(_C);
	float BC = _B->CalcDistanceTo(_C);
	return AB + AC + BC;
}

bool Triangle::isValid(const Point* A, const Point* B, const Point* C) {
    if (!A || !B || !C) return false;
 	float AB = A->CalcDistanceTo(B);
	float AC = A->CalcDistanceTo(C);
	float BC = B->CalcDistanceTo(C);
    return (AB + AC > BC) && (AB + BC > AC) && (AC + BC > AB);
}


Triangle* Triangle::Parse(string stringLine) {
    string delimeter = "(), ";
    Tokenizer tokenizer(stringLine, delimeter);

    float x1 = tokenizer.nextDouble();
    float y1 = tokenizer.nextDouble();

    float x2 = tokenizer.nextDouble();
    float y2 = tokenizer.nextDouble();

    float x3 = tokenizer.nextDouble();
    float y3 = tokenizer.nextDouble();

    Point * A = new Point(x1,y1);
    Point * B = new Point(x2, y2);
    Point * C = new Point(x3, y3);

    if (!Triangle::isValid(A,B,C)) {
        return new Triangle();
    }

    Triangle* res = new Triangle(A,B,C);

    return res;
}

ostream& operator << (ostream& output, Triangle* Tri) {
    if (!Tri) return output;
    output << Tri->_A << ", " << Tri->_B << ", " << Tri->_C;
    return output;
}   