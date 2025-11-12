#include "Fraction.h"

Fraction::Fraction() {
    num = 0;
    den = 1;
    Fraction::InstanceCount++;
}

Fraction::Fraction(const int tu, const int mau) {
    if (mau == 0) {
        num = 0;
        den = 1;
    } else {
        num = tu;
        den = mau;
    }
    Fraction::InstanceCount++;
}

Fraction::Fraction(const Fraction& other) {
    if (other.den == 0) {
        num = 0;
        den = 1;
    } else {
        num = other.num;
        den = other.den;
    }
    Fraction::InstanceCount++;
}

Fraction::Fraction(const Fraction* other) {
    if (!other || other->den == 0) {
        num = 0;
        den = 1;
    } else {
        num = other->num;
        den = other->den;
    }
    Fraction::InstanceCount++;
}

Fraction::~Fraction() {
    num = 0;
    den = 1;
    Fraction::InstanceCount--;
}

const int Fraction::getNum() const {
    return num;
}

const int Fraction::getDen() const {
    return den;
}

void Fraction::setNum(const int val) {  
    num = val;
}

void Fraction::setDen(const int val) {
    if (val == 0) return;
    den = val;
}

Fraction& Fraction::operator= (const Fraction & other) {
    if (this == &other) return *this;
    if (other.den == 0) return *this;
    num = other.num;
    den = other.den;
    return *this;
}

string Fraction::ToString() const {
    stringstream writer;
    writer << num << "/" << den;
    return writer.str();
}

istream& operator >> (istream& input, Fraction* p) {
    if (!p) return input;
    std::cout << "Nhap tu so: ";
    int tu, mau;
    input >> tu;
    std::cout << "Nhap mau so: ";
    input >> mau;
    if (mau == 0) return input;
    p->num = tu;
    p->den = mau;
    return input;
}

ostream& operator << (ostream& output, const Fraction* p) {
    if (!p) return output;
    output << p->ToString();
    return output;
}