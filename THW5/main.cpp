#include <iostream>
#include <string>

#include "Point.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Fraction.h"
#include "Array.h"
#include "Line.h"
#include "Date.h"

using std::cin;
using std::endl;
using std::cout;

int Point::InstanceCount = 0;
int Line::InstanceCount = 0;
int Rectangle::InstanceCount = 0;
int Circle::InstanceCount = 0;
int Fraction::InstanceCount = 0;
int Array::InstanceCount = 0;

int main() {
    string stringLine;
    cout << "--------------------Point-------------------\n";
    cout << "Enter your point: ";
    getline(cin,stringLine);
    Point * p = Point::Parse(stringLine);
    cout << "Entered Point: " << p << endl;
    delete p;

    cout << "------------------Line-----------------------\n";
    cout << "Enter your Line: ";
    getline(cin, stringLine);
    Line* L = Line::Parse(stringLine);
    cout << "Entered Line: \n" << L << endl;
    delete L;

    cout << "----------------------Rectangle------------------\n";
    cout << "Enter your Rectangle: ";
    getline(cin, stringLine);
    Rectangle* Rect = Rectangle::Parse(stringLine);
    cout << "Entered Rectangle: \n" << Rect << endl;
    delete Rect;

    cout << "-----------------------Triangle---------------------\n";
    cout << "Enter your Triangle: ";
    getline(cin, stringLine);
    Triangle* Tri = Triangle::Parse(stringLine);
    cout << "Entered Triangle: \n" << Tri << endl;
    delete Tri; 

    cout << "----------------------Circle---------------------------\n";
    cout << "Enter your Circle: ";
    getline(cin,stringLine);
    Circle* Cir = Circle::Parse(stringLine);
    cout << "Entered Circle: \n" << Cir << endl;
    delete Cir;

    cout << "---------------------------Fraction---------------------\n";
    cout << "Enter your Fraction: ";
    getline(cin,stringLine);
    Fraction* Frac = Fraction::Parse(stringLine);
    cout << "Entered Fraction: " << Frac << endl;
    delete Frac; 

    cout << "------------------------------Array--------------------------\n";
    cout << "Enter your Array: ";
    getline(cin, stringLine);
    Array* Arr = Array::Parse(stringLine);
    cout << "Entered Array: \n" << Arr << endl;
    delete Arr;

    cout << "-------------------------Date------------------------------------\n";
    cout << "Enter your Date: ";
    getline(cin, stringLine);
    Date* D = Date::Parse(stringLine);
    cout << "Entered Date: " << D << endl;
}
