#pragma once

class Array {
private:
	int* a;
	int _len;
public:
	Array();
	~Array();
	int GetAt(int idx);
	void SetAt(int idx, int val);
	void PushBack(int value);
	void output();
};