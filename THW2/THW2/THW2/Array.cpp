#include"Array.h"
#include <iostream>

Array::Array() {
	_len = 0;
	a = nullptr;
}

Array::~Array() {
	delete[] a;
	a = nullptr;
	_len = 0;
}

int Array::GetAt(int idx) {
	return a[idx];
}

void Array::SetAt(int idx, int val) {
	a[idx] = val;
}

void Array::PushBack(int value) {
	int* b = new int[_len];
	for (int i = 0; i < _len; i++) {
		b[i] = a[i];
	}
	delete[] a;
	a = new int[_len + 1];
	for (int i = 0; i < _len; i++) {
		a[i] = b[i];
	}
	a[_len] = value;
	_len++;
	delete[] b;
}

void Array::output() {
	std::cout << _len << '\n';
	for (int i = 0; i < _len; i++) {
		std::cout << a[i] << ' ';
	}
	std::cout << '\n';
}