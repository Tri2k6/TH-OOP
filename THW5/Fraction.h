#pragma once

#include "Tokenizer.h"
#include <string>
#include <sstream>
#include <iostream>
using std::istream;
using std::ostream;
using std::string;
using std::stringstream;

class Fraction {
public:
    static int InstanceCount;
private:
    int num;
    int den;
public:
    Fraction();
    Fraction(const int tu, const int mau);
    Fraction(const Fraction& other);
    Fraction(const Fraction*other);
    ~Fraction();
public:
    const int getNum() const;
    const int getDen() const;
    void setNum(const int val);
    void setDen(const int val);
public:
    Fraction& operator = (const Fraction& other);
    std::string ToString() const;
public:
    friend istream& operator >> (istream& input, Fraction* p);
    friend ostream& operator << (ostream& output, const Fraction* p);
public:
    static Fraction* Parse(string stringLine);
};