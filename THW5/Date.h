#pragma once

#include "Tokenizer.h"
#include <string>
#include <iostream>

using std::ostream;
using std::string;

class Date {
private:
    int _d;
    int _m;
    int _y;
public:
    Date();
    Date(int d, int m, int y);
    Date(const Date& other);
    Date(const Date* other);
    ~Date();
public:
    friend ostream& operator << (ostream& output, const Date* D);
    static bool isValid(int d, int m, int y);
    static Date* Parse(string stringLine);
};