#include "Date.h"

Date::Date() {
    _d = 1;
    _m = 1;
    _y = 0;
}

Date::Date(int d, int m, int y) {
    if (!Date::isValid(d, m , y)) {
        _d = 1;
        _m = 1;
        _y = 0;
    }
    _d = d;
    _m = m;
    _y = y;
}

Date::Date(const Date& other) {
    _d = other._d;
    _m = other._m;
    _y = other._y;
}

Date::Date(const Date* other) {
    if (!other) {
        _d = 1;
        _m = 1;
        _y = 0;        
    }
    _d = other->_d;
    _m = other->_m;
    _y = other->_y;
}

Date::~Date() {
    _d = _m = _y = 0;
}

ostream& operator << (ostream& output, const Date* D) {
    if (!D) return output;
    output << D->_d << "/" << D->_m << "/" << D->_y;
    return output;
}

bool Date::isValid(int d, int m,int y) {
    // Kiem tra nam nhuan
    if (y < 0) return false;

    bool isNamNhuan = ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0);

    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        return 1 <= d && d <= 31;
    }

    if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 1 <= d && d <= 30;
    }

    if (isNamNhuan) return 1 <= d && d <= 29;
    return 1 <= d && d <= 28;
}

Date* Date::Parse(string stringLine) {
    string delimeter = "/";
    Tokenizer tokenize(stringLine, delimeter);

    int d = tokenize.nextInt();
    int m = tokenize.nextInt();
    int y = tokenize.nextInt();

    if (!Date::isValid(d,m,y)) return new Date();
    Date* D = new Date(d, m ,y);
    return D;
}