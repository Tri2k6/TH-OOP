#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Rectangle.h"
#include "Array.h"

using namespace std;

int Point::InstanceCount = 0;
int Line::InstanceCount = 0;
int Rectangle::InstanceCount = 0;

int main() {
    cout << "---------------------------Point-------------------------------\n";
    Point P_root(5,6);
    Point P_copy(P_root);
    cout << "Nut copy: " << P_copy.X() << ' ' << P_copy.Y() << ' ' << endl;
    
    Point* start = new Point(4,3);
    Point* end = new Point(10,9);
    
    Point* temp = start;

    Point* meet = new Point(*start);
    cout << "Dia diem gap: " << meet->X() << ' ' << meet->Y() << ' ' << endl;

    delete meet;
    delete start;
    delete end;
    cout << "---------------------------------------------------------------\n";

    cout << "-------------------------Line----------------------------------\n";
    Point* ST = new Point(3,10);
    Point* EN = new Point(5,7);
    Line * LRoot = new Line(ST,EN);
    Line * LCopy = new Line(*LRoot);
    cout << "Line Copy: " << *LCopy->GetStart() << ' ' << *LCopy->GetEnd() << endl;
    cout << "Length of Line: " << LRoot->getLength() << endl;
    cout << "Number of lines: " << Line::InstanceCount << endl;
    delete LRoot;
    delete LCopy;
    delete ST;
    delete EN;
    cout << "Number of lines after deletion: " << Line::InstanceCount << endl;
    cout << "----------------------------------------------------------------\n";


    cout << "---------------------------Rectangle------------------------------\n";
    Point* TLeft = new Point(0,100);
    Point* BRight = new Point(100, 14);
    Rectangle* RectRoot = new Rectangle(*TLeft, *BRight);
    Rectangle* RectCopy = new Rectangle(*RectRoot);
    cout << "Rectangle Copy: " << RectCopy->GetTLeft() << ' ' << RectCopy->GetBRight() << endl;
    cout << "Number of rectangle: " << Rectangle::InstanceCount << endl;
    delete TLeft; delete BRight; delete RectRoot; delete RectCopy;
    cout << "Number of rectangle after deletion: " << Rectangle::InstanceCount << endl;
    cout << "------------------------------------------------------------------\n\n";


    cout << "------------------------------Array-------------------------------\n";
    cout << "Moi thay nhap lan luot cac phan tu trong mang (neu gap -1 thi dung): ";
    Array* PtrArr = new Array;
    int x;
    while (cin >> x && x != -1) {
        PtrArr->PushBack(x);
    }
    cout << "Mang ban vua nhap la: \n";
    PtrArr->output();

    Array* CopyArr = new Array(*PtrArr);
    cout << "Array Copy: \n";
    CopyArr->output();
    
    delete PtrArr; delete CopyArr;
    cout << "-------------------------------------------------------------------\n";
    return 0;
}