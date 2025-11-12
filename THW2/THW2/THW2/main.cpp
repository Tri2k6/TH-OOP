#include <iostream>
#include "Point.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Array.h"
#include "Circle.h"
using namespace std;

#define endl '\n'

int main() {
	cout << "---------Circle----------------------\n";
	Point* Center = new Point(14, 15);
	Circle* Cir = new Circle(Center, 1.5f);
	cout << "Diameter: " << Cir->Diameter() << endl;
	cout << "Perimeter: " << Cir->Perimeter() << endl;
	cout << "Area: " << Cir->Area() << endl;
	cout << "--------------------------------------" << endl;
	delete Center; Center = nullptr;
	delete Cir; Cir = nullptr;

	cout << "-------------Rectangle----------------\n";
	Point* TopLeft = new Point(1.0f, 10.0f);
	Point* BottomRight = new Point(10.0f, 5.0f);
	Rectangle* Rect = new Rectangle(TopLeft, BottomRight);
	cout << "Perimeter: " << Rect->Perimeter() << endl;
	cout << "Area: " << Rect->Area() << endl;
	cout << "----------------------------------------" << endl;
	delete TopLeft; TopLeft = nullptr;
	delete BottomRight; BottomRight = nullptr;
	delete Rect; Rect = nullptr;

	cout << "------------Triangle-------------------\n";
	Point* A = new Point(14.5f, 11.5125f);
	Point* B = new Point(41.51f, 15);
	Point* C = new Point(31.151f, 12);
	Triangle* Tri = new Triangle(A, B, C);
	cout << "Perimeter: " << Tri->Perimeter() << endl;
	cout << "Area: " << Tri->Area() << endl;
	cout << "-----------------------------------------" << endl;
	delete A; A = nullptr;
	delete B; B = nullptr;	
	delete C; C = nullptr;
	delete Tri; Tri = nullptr;

	cout << "-----------------Array-------------------\n";
	cout << "Moi thay nhap cac phan tu cua mang (neu nhap so -1 thi dung): \n";
	int x;
	Array* arr = new Array;
	while (cin >> x && x != -1) {
		arr->PushBack(x);
	}

	arr->output();
	delete arr; arr = nullptr;

	return 0;
}