#pragma once
#include <iostream>

class Array {
private:
    int size;
    int *arr;
public:
    Array();
    Array(int _len, int *_a);
    Array(const Array& other);
    ~Array();
public:
    Array& operator = (const Array& other);
    void Copy(const Array& other);
    void PushBack(int val);
    int GetAt(int idx);
    void output();
};