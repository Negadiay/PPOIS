#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle() {
    point.x = 0;
    point.y = 0;
    height = 1;
    length = 1;
}

Rectangle::Rectangle(int x, int y, int height, int length) {
    this->point.x = x;
    this->point.y = y;
    this->height = height;
    this->length = length;
}

Rectangle::Rectangle(const Rectangle& rectangle) {
    *this = rectangle;
}


// методы

Point Rectangle::getBottomLeft() {
    return point;
}

Point Rectangle::getBottomRight() {
    Point temp = point;
    temp.x += length;

    return temp;
}

Point Rectangle::getTopLeft() {
    Point temp = point;
    temp.y += height;

    return temp;
}

Point Rectangle::getTopRight() {
    Point temp = point;
    temp.x += length;
    temp.y += height;

    return temp;
}

void Rectangle::setNewLocation(int x, int y) {
    point.x = x;
    point.y = y;
}

void Rectangle::changeHeight(int height) {
    this->height = height;
}

void Rectangle::changeLength(int length) {
    this->length = length;
}

Rectangle& Rectangle::operator++(int) {
    height++;
    length++;
    return *this;
}

Rectangle& Rectangle::operator--(int) {
    height--;
    length--;
    return *this;
}

Rectangle& Rectangle::operator--() {
    height--;
    length--;
    return *this;
}

Rectangle& Rectangle::operator++() {
    height++;
    length++;
    return *this;
}

bool Rectangle::operator == (const Rectangle& rectangle) const {
    bool flag = (this->height == rectangle.height) && (this->length == rectangle.length);
    return flag;
}

bool Rectangle::operator != (const Rectangle& rectangle) const {
    bool flag = (this->height == rectangle.height) && (this->length == rectangle.length);
    return !flag;
}

std::ostream& operator<<(std::ostream& stream, const Rectangle& rec) {

    stream << "Координата x: "<< rec.point.x << std::endl;
    stream << "Координата y: " << rec.point.y << std::endl;
    stream << "Высота: " << rec.height << std::endl;
    stream << "Длина: " << rec.length << std::endl;
    
    return stream;
}

std::istream& operator>>(std::istream& stream, Rectangle& rec) {
    stream >> rec.point.x;
    stream >> rec.point.y;
    stream >> rec.height;
    stream >> rec.length;
    return stream;
}


//вернуть объект
Rectangle Rectangle::operator+(const Rectangle& other) {
    Rectangle testHeight;
    Rectangle testlength;
    int maxHeight;
    int maxLength;

    if (this->height >= other.height)
        maxHeight = this->height;
    else
        maxHeight = other.height;

    if (this->length >= other.length)
        maxLength = this->length;
    else
        maxLength = other.length;

    testHeight.height = this->height + other.height;
    testHeight.length = maxLength;
    testHeight.point = this->point;

    testlength.length = this->length + other.length;
    testlength.height = maxHeight;
    testlength.point = this->point;

    if (testHeight.height * testHeight.length <= testlength.height * testlength.length)
        return testHeight;
    else
        return testlength;
}
//вернуть ссылку на объект
Rectangle& Rectangle::operator+=(const Rectangle& other) {
    Rectangle testHeight;
    Rectangle testLength;
    int maxHeight;
    int maxLength;

    if (this->height >= other.height)
        maxHeight = this->height;
    else
        maxHeight = other.height;

    if (this->length >= other.length)
        maxLength = this->length;
    else
        maxLength = other.length;

    testHeight.height = this->height + other.height;
    testHeight.length = maxLength;
    testHeight.point = this->point;

    testLength.length = this->length + other.length;
    testLength.height = maxHeight;
    testLength.point = this->point;

    if (testHeight.height * testHeight.length <= testLength.height * testLength.length)
        *this = testHeight;
    else
        *this = testLength;

    return *this;
}

Rectangle Rectangle::operator-(const Rectangle& other) {
    int minHeight;
    int minLength;

    if (this->height <= other.height)
        minHeight = this->height;
    else
        minHeight = other.height;

    if (this->length <= other.length)
        minLength = this->length;
    else
        minLength = other.length;

    Rectangle temp(this->point.x, this->point.y, minHeight, minLength);
    return temp;
}

Rectangle& Rectangle::operator-=(const Rectangle& other) {
    int minHeight;
    int minLength;

    if (this->height <= other.height)
        minHeight = this->height;
    else
        minHeight = other.height;

    if (this->length <= other.length)
        minLength = this->length;
    else
        minLength = other.length;

    Rectangle temp(this->point.x, this->point.y, minHeight, minLength);
    *this = temp;
    return *this;
}