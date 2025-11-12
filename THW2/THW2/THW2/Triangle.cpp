#include "Triangle.h"

bool isValid(Point* A, Point* B, Point* C) {
	if (!A || !B || !C) return false;
	float AB = A->CalcDistanceTo(B);
	float BC = B->CalcDistanceTo(C);
	float AC = A->CalcDistanceTo(C);
	return (AB + BC > AC) && (AB + AC > BC) && (BC + AC > AB);
}

Triangle::Triangle() {
	_A = new Point(1, 1);
	_B = new Point(1, 2);
	_C = new Point(4, 2);
}

Triangle::Triangle(Point*A, Point*B,Point*C) {
	if (!isValid(A, B, C)) *this = Triangle();
	_A = new Point(A->X(), A->Y());
	_B = new Point(B->X(), B->Y());
	_C = new Point(C->X(), C->Y());
}

Triangle::~Triangle() {
	delete _A;
	_A = nullptr;
	delete _B;
	_B = nullptr;
	delete _C;
	_C = nullptr;
}

Point* Triangle::GetA() {
	return _A;
}

Point* Triangle::GetB() {
	return _B;
}

Point* Triangle::GetC() {
	return _C;
}

void Triangle::setA(Point* A) {
	if (!A) return;
	if (!isValid(A, _B, _C)) return;
	_A->SetX(A->X());
	_A->SetY(A->Y());
}

void Triangle::setB(Point* B) {
	if (!B) return;
	if (!isValid(_A, B, _C)) return;
	_B->SetX(B->X());
	_B->SetY(B->Y());
}

void Triangle::setC(Point* C) {
	if (!C) return;
	if (!isValid(_A, _B, C)) return;
	_C->SetX(C->X());
	_C->SetY(C->Y());
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
