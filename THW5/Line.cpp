#include "Line.h"

Line::Line() {
    _begin = new Point(0, 0);
    _end = new Point(1, 1);
    Line::InstanceCount++;
}

Line::Line(const Point* Begin, const Point* End){
    if (!Begin || !End || !Line::isValid(Begin, End)) {
        _begin = new Point(0,0);
        _end = new Point(1, 1);
    } else {
        _begin = new Point(Begin->X(), Begin->Y());
        _end = new Point(End->X(), End->Y());
    }
    Line::InstanceCount++;
}

Line::Line(const Line* other) {
    if (!other) {
        _begin = new Point(0,0);
        _end = new Point(1, 1);        
    } else {
        _begin = new Point(other->getBegin());
        _end = new Point(other->getEnd());
    }

    Line::InstanceCount++;
}

Line::Line(const Line& other) {
    _begin = new Point(other.getBegin());
    _end = new Point(other.getEnd());
    Line::InstanceCount++;
}

Line::~Line() {
    if (_begin) {
        delete _begin;
        _begin = NULL;
    }
    if (_end) {
        delete _end;
        _end = NULL;
    }
    Line::InstanceCount--;
}

const Point Line::getBegin() const {
    if (!_begin) return Point();
    return *_begin;
}

const Point Line::getEnd() const {
    if (!_end) return Point();
    return *_end;
}

void Line::setBegin(const Point* Begin) {
    if (!Begin || !Line::isValid(Begin, _end)) return;
    delete _begin;
    _begin = new Point(Begin);
}

void Line::setEnd(const Point * End) {
    if (!End || !Line::isValid(_begin, End)) return;
    delete _end;
    _end = new Point(End);
}

float Line::getLength() const {
    return Point::CalcDistance(_begin, _end);
}

bool Line::isValid(const Point* a, const Point* b) {
    if (!a || !b) return false;
    return a->X() != b->X() || a->Y() != b->Y();
}

string Line::ToString() const {
    if (!_begin || !_end) return "";
    stringstream writer;
    writer << "Begin: " << _begin->ToString() << "\n";
    writer << "End: " << _end->ToString() << "\n";
    return writer.str();
}

istream& operator >> (istream& input, Line* L) {
    if (!L) return input;
    Point * buf_ben = new Point(), *buf_en = new Point();


    std::cout << "Moi ban nhap diem bat dau: \n";
    input >> buf_ben;
    std::cout << "Moi ban nhap diem ket thuc: \n";
    input >> buf_en;

    if (Line::isValid(buf_ben, buf_en)) {
        delete L->_begin;
        delete L->_end;

        L->_begin = buf_ben;
        L->_end = buf_en;
    } else {
        delete buf_ben;
        delete buf_en;
    }
    return input;
}

ostream& operator << (ostream& output, const Line* L) {
    if (!L) return output;
    output << L->ToString();
    return output;
}

Line& Line::operator= (const Line& other) {
    if (this == &other) return *this;
    if (!other._begin || !other._end) return *this;

    Point* TmpBegin = new Point(other.getBegin());
    Point* TmpEnd = new Point(other.getEnd());

    delete _begin;
    delete _end;

    _begin = TmpBegin;
    _end = TmpEnd;
    
    return *this;
}

Line* Line::Parse(string stringLine) {
    Line* res = new Line();
    if (!res) return NULL;

    string delimeter = "(), ";
    Tokenizer tokenizer(stringLine, delimeter);

    float x1 = tokenizer.nextDouble();
    float y1 = tokenizer.nextDouble();

    float x2 = tokenizer.nextDouble();
    float y2 = tokenizer.nextDouble();

    Point * start = new Point(x1,y1);
    Point * end = new Point(x2, y2);
    if (!Line::isValid(start, end)) return new Line();
    res->setBegin(start);
    res->setEnd(end);
    return res;
}