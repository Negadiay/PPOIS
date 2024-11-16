#pragma once

#include <iostream>

struct Point {
    int x, y;
};

class Rectangle {
private:
    Point point;
    int height;
    int length;

public:
    // ������������
    Rectangle();

    Rectangle(int x, int y, int height, int length);

    Rectangle(const Rectangle& rectangle);

    // ������
    void getX();

    Point getBottomLeft();

    Point getBottomRight();

    Point getTopLeft();

    Point getTopRight();

    void setNewLocation(int x, int y);

    void changeHeight(int width);

    void changeLength(int length);

    Rectangle& operator++(int);

    Rectangle& operator--(int);

    Rectangle& operator--();

    Rectangle& operator++();

    bool operator == (const Rectangle& rectangle) const;

    bool operator != (const Rectangle& rectangle) const;

    friend std::ostream& operator<<(std::ostream& stream, const Rectangle& rec);

    friend std::istream& operator>>(std::istream& stream, Rectangle& rec);

    //������� ������
    Rectangle operator+(const Rectangle& other);
    //������� ������ �� ������
    Rectangle& operator+=(const Rectangle& other);

    Rectangle operator-(const Rectangle& other);

    Rectangle& operator-=(const Rectangle& other);

};

