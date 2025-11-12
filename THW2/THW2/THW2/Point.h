#pragma once

class Point {
private:
	float _x;
	float _y;
public:
	float X() { return _x; }
	float Y() { return _y; }
	void SetX(float value) { (_x) = value; }
	void SetY(float value) { (_y) = value; }
public:
	Point();
	Point(float, float);
	~Point();
	void operator = (const Point& other);
	bool operator == (const Point& other);
	void output();
	float CalcDistanceTo(const Point* other);
};