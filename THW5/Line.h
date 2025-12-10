#pragma once
#include "Point.h"
#include "Tokenizer.h"

class Line {
public:
    static int InstanceCount;
private:
    Point * _begin;
    Point * _end;
public:
    const Point getBegin() const;
    const Point getEnd() const;
    void setBegin(const Point * Begin);
    void setEnd(const Point* End);
public:
    Line();
    Line(const Point* Begin, const Point* End);
    Line(const Line* other);
    Line(const Line& other);
    ~Line();
public:
    static bool isValid(const Point* a, const Point* b);
    float getLength() const;
public:
    string ToString() const;
    Line& operator = (const Line& other);
    
    friend istream& operator >> (istream& input, Line* L);
    friend ostream& operator << (ostream& output, const Line* L);
public:
    static Line* Parse(string stringLine);
};