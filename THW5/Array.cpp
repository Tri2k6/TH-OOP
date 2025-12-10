#include "Array.h"

Array::Array() {
    _size = 0;
    _arr = nullptr;
    Array::InstanceCount++; 
}

Array::Array(int size, int * arr) {
    if (size <= 0 || arr == nullptr) {
        _size = 0;
        _arr = nullptr;
    } else {
        _size = size;
        _arr = new int[size];
        for (int i = 0;i < size;i++) {
            _arr[i] = arr[i];
        }
    }
    Array::InstanceCount++;
}

Array::Array(const Array& other) {
    if (other._size <= 0 || !other._arr) {
        _size = 0;
        _arr = nullptr;
    } else {
        _size = other._size;
        _arr = new int[_size];
        for (int i = 0;i < _size;i++) {
            _arr[i] = other._arr[i];
        }
    }
    Array::InstanceCount++;
}

Array::Array(const Array* other) {
    if (!other || other->_size <= 0 || !other->_arr) {
        _size = 0;
        _arr = nullptr;
    } else {
        _size = other->_size;
        _arr = new int[_size];
        for (int i = 0;i < _size;i++) {
            _arr[i] = other->_arr[i];
        }
    }
    Array::InstanceCount++;    
}

Array::~Array() {
    if (_arr) {
        delete[] _arr;
        _arr = nullptr;
    }
    _size = 0;
    Array::InstanceCount--;
}

int Array::getSize() const {
    return _size;
}

void Array::SetAt(int idx, int val) {
    if (idx < 0 || idx >= _size) return;
    _arr[idx] = val;
}

void Array::PushBack(int val) {
    int newLen = _size + 1;
    int* newArr = new int[newLen];
    for (int i = 0;i < _size;i++) {
        newArr[i] = _arr[i];
    }
    newArr[_size] = val; 
    if (_arr) delete[] _arr;
    _arr = newArr;
    _size = newLen;
}

int Array::GetAt(int idx) const {
    if (idx < 0 || idx >= _size) return -1;
    return _arr[idx];
}

Array& Array::operator= (const Array& other) {  
    if ((this == &other)) {
        return *this;
    } 

    Array tmpArr(other);
    std::swap(_arr, tmpArr._arr);
    std::swap(_size, tmpArr._size);
    return *this;
}

string Array::ToString() const {
    stringstream writer;
    writer << _size << "\n";
    for (int i = 0;i < _size;i++) {
        writer << _arr[i] << ' ';
    }
    writer << '\n';
    return writer.str();
}

istream& operator >> (istream& input, Array* Arr) {
    if (!Arr) return input;  
    std::cout << "Moi thay nhap lien tiep cac phan tu trong cung 1 mang (gap -1 thi dung lai): \n";
    int buffer;
    while (input >> buffer && buffer != -1) {
        Arr->PushBack(buffer);
    }
    return input;
}

ostream& operator << (ostream& output, const Array* Arr) {
    if (!Arr) return output;
    output << Arr->ToString();
    return output;
}

Array* Array::Parse(string stringLine) {
    string delimeter = ", ";
    Tokenizer tokenizer(stringLine, delimeter);

    Array* Arr = new Array;
    if (!Arr) return nullptr;

    while (tokenizer.hasMoreTokens()) {
        int x = tokenizer.nextInt();
        Arr->PushBack(x);
    }

    return Arr;
}