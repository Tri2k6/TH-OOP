#include "Fraction.h"

Fraction::Fraction() {
    _num = 0;
    _den = 1;
}

Fraction::Fraction(int num, int den) {
    if (den == 0) {
        _num = 0;
        _den = 1;
        return;
    }
    if (den < 0) {
        num = -num;
        den = -den;
    }
    _num = num;
    _den = den;
    
}

Fraction::Fraction(const Fraction& other) {
    _num = other._num;
    _den = other._den;
}

int Fraction::Numerator() {
    return _num;
}

int Fraction::Denominator() {
    return _den;
}

void Fraction::SetNumerator(int val) {
    _num = val;
} 

void Fraction::SetDenominator(int val) {
    if (val == 0) return;
    _den = val;
}

Fraction& Fraction::operator = (const Fraction& other) {
    if (this == &other) return *this;
    _num = other._num;
    _den = other._den;
    return *this;
}

string Fraction::ToString() const {
    stringstream writer;
    writer << _num << Fraction::SEPERATOR << _den;
    return writer.str();
}

Fraction* Fraction::Parse(string stringLine) {
    Tokenizer tokenizer(stringLine, Fraction::SEPERATOR);

    int num = tokenizer.nextInt();
    int den = tokenizer.nextInt();

    Fraction* res = new Fraction(num, den);
    return res;
}

Fraction Fraction::operator + (const Fraction& other) {
    long long MauChung = Utils::Lcm(abs(_den), abs(other._den));
    long long Tu_A = 1ll * _num * (MauChung / _den);
    long long Tu_B = 1ll * other._num * (MauChung / other._den);
    long long FinalNum = Tu_A + Tu_B;

    int gcd = Utils::Gcd(abs(FinalNum), abs(MauChung));
    return Fraction(FinalNum / gcd, MauChung / gcd);
}

Fraction Fraction::operator - (const Fraction& other) {
    long long MauChung = Utils::Lcm(abs(_den), abs(other._den));
    long long Tu_A = 1ll * _num * (MauChung / _den);
    long long Tu_B = 1ll * other._num * (MauChung / other._den);
    long long FinalNum = Tu_A - Tu_B;
    int gcd = Utils::Gcd(abs(FinalNum), abs(MauChung));
    return Fraction(FinalNum / gcd, MauChung / gcd);
}

Fraction Fraction::operator*(const Fraction& other) {
    long long num = _num * other._num;
    long long den = _den * other._den;
    int gcd = Utils::Gcd(num, den);
    return Fraction(num / gcd, den / gcd);
}

Fraction Fraction::operator/(const Fraction& other) {
    if (other._num == 0) {
        return Fraction(0,1);
    }
    long long num = 1ll * _num * other._den;
    long long den = 1ll * _den * other._num;

    if (den < 0) {
        num = -num;
        den = -den;
    }

    int gcd = Utils::Gcd(num, den);
    return Fraction(num / gcd, den / gcd);
}

istream& operator >> (istream& input, Fraction& Frac) {
    int num, den;
    cout << "Nhap tu: ";
    if (!(input >> num)) return input;
    cout << "Nhap mau: ";
    if (!(input >> den)) return input;

    if (den == 0) {
        Frac._num = 0;
        Frac._den = 1;
        return input;
    }
    if (den < 0) {
        num = -num;
        den = -den;
    }

    Frac._num = num;
    Frac._den = den;
    return input;
}

ostream& operator << (ostream& output, const Fraction& Frac) {
    output << Frac.ToString();
    return output;
}

Fraction& Fraction::operator++() {
    _num += _den;
    int gcd = Utils::Gcd(abs(_num), abs(_den));
    _num /= gcd;
    _den /= gcd;
    return *this;
}

Fraction Fraction::operator++(int tmp) {
    Fraction res(*this);
    
    _num += _den;
    int gcd = Utils::Gcd(abs(_num), abs(_den));
    _num /= gcd;
    _den /= gcd;

    return res;
}

bool Fraction::operator< (const Fraction& other) {
    long long MauChung = Utils::Lcm(_den, other._den);
    long long Tu1 = MauChung / _den * _num;
    long long Tu2 = MauChung / other._den * other._num;
    return Tu1 < Tu2;
}

bool Fraction::operator> (const Fraction& other) {
    long long MauChung = Utils::Lcm(_den, other._den);
    long long Tu1 = MauChung / _den * _num;
    long long Tu2 = MauChung / other._den * other._num;
    return Tu1 > Tu2;
}