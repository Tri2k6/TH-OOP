#include <iostream>
#include <string>

#include "Point.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Fraction.h"
#include "Array.h"
#include "Line.h"

using std::cin;
using std::cout;

int Point::InstanceCount = 0;
int Line::InstanceCount = 0;
int Rectangle::InstanceCount = 0;
int Circle::InstanceCount = 0;
int Fraction::InstanceCount = 0;
int Array::InstanceCount = 0;

int main() {
    std::cout << "--------------------Point--------------------------\n";
    Point* start = new Point();
    std::cin >> start;
    std::cout << "Point: " << start << '\n';
    std::cout << "To_string: " << start->ToString() << '\n';
    delete start;

    std::cout << "----------------------Line-------------------------\n";
    Line* LinePtr = new Line();
    cin >> LinePtr;
    cout << "Line: \n" << LinePtr << "\n";
    cout << "To_string: \n" << LinePtr->ToString() << '\n';
    delete LinePtr;

    cout << "---------------------------Rectangle---------------------\n";
    Rectangle *Rect = new Rectangle;
    cin >> Rect;
    cout << "Rectangle: \n" << Rect << '\n';
    cout << "To_string: \n " << Rect->ToString() << '\n';
    delete Rect;

    cout << "--------------------------Circle-------------------------\n";
    Circle *Cir = new Circle;
    cin >> Cir;
    cout << "Circle: \n" << Cir << '\n';
    cout << "To_string: \n" << Cir->ToString() << '\n';
    delete Cir;

    cout << "--------------------------Fraction-----------------------\n";
    Fraction* Frac = new Fraction();
    cin >> Frac;
    cout << "Fraction: " << Frac << '\n';
    cout << "To_string: " << Frac->ToString() << '\n';

    delete Frac;

    cout << "----------------------Array------------------------------\n";
    Array* Arr = new Array;
    cin >> Arr;
    cout << "Array: \n" << Arr << '\n';
    cout << "To_string: \n" << Arr->ToString() << '\n'; 
    return 0;
}
