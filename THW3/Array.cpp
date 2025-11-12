#include "Array.h"

Array::Array() {
    size = 0;
    arr = nullptr;
}

Array::Array(int _len, int* a) {
    size = _len;  
    arr = new int[size];
    for (int i = 0;i < size;i++) {
        arr[i] = a[i];
    }
}

Array::Array(const Array& other) {
    size = other.size;
    arr = new int[size];
    for (int i = 0;i < size;i++) {
        arr[i] = other.arr[i];
    }
}

Array::~Array() {
    delete[] arr;
    arr = nullptr;
    size = 0;
}

Array& Array:: operator= (const Array& other) {
    int *tmp = new int[other.size];
    for (int i = 0;i < other.size;i++) {
        tmp[i] = other.arr[i];
    }
    std::swap(arr, tmp);
    size = other.size;
    delete[] tmp;
    tmp = nullptr;
    return *this;
}

void Array::Copy(const Array& other) {
    int *tmp = new int[other.size];
    for (int i = 0;i < other.size;i++) {
        tmp[i] = other.arr[i];
    }
    std::swap(arr, tmp);
    size = other.size;
    delete[] tmp;
    tmp = nullptr;
}

void Array::PushBack(int val) {
    int *tmp = new int[size + 1];
    for (int i = 0;i < size;i++) {
        tmp[i] = arr[i];
    }
    tmp[size] = val;
    std::swap(arr, tmp);
    size++;
    delete[] tmp;
    tmp = nullptr;
}

int Array::GetAt(int idx) {
    return arr[idx];
}

void Array::output() {
    std::cout << size  << std::endl;
    for (int i = 0;i < size;i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}