#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using std::string;
using std::istream;
using std::ostream;
using std::stringstream;

class Array {
public:
    static int InstanceCount;
private:
    int *_arr;
    int _size;
public:
    Array();
    Array(int size, int * arr);
    Array(const Array& other);
    Array(const Array* other);
    ~Array();
public:
    int getSize() const;
    void SetAt(int idx , int val);
    void PushBack(int val);
    int GetAt(int idx) const;
    Array& operator = (const Array& other);
    string ToString() const;
    friend istream& operator >>(istream& input, Array* Arr);
    friend ostream& operator << (ostream& output, const Array* Arr);
};