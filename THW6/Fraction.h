#pragma once

#include "Tokenizer.h"
#include "Utils.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Fraction {
private:
    static string SEPERATOR;
private:
    int _num;
    int _den;
public:
    int Numerator();
    int Denominator();
    void SetNumerator(int val);
    void SetDenominator(int val);
public:
    Fraction();
    Fraction(int num, int den);
    Fraction(const Fraction& other);
public:

    Fraction& operator = (const Fraction& other);
    friend istream& operator >> (istream& input, Fraction& Frac);
    friend ostream& operator << (ostream& output, const Fraction& Frac);
public:
    static Fraction* Parse(string line);
    string ToString() const;
public:
    Fraction operator + (const Fraction& other);
    Fraction operator - (const Fraction& other);
    Fraction operator * (const Fraction& other);
    Fraction operator / (const Fraction& other);
    bool operator > (const Fraction& other);
    bool operator < (const Fraction& other);
    Fraction& operator ++ ();
    Fraction operator ++ (int tmp); 
};