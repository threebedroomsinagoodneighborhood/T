#pragma once

#include <iostream>

class Point2D {

    int x, y; // координаты

public:

    Point2D(int x = 0, int y = 0) : x(x), y(y) {  } // конструктор

    void setPoint(int x, int y) {   this->x = x;    this->y = y;    } // изменение координат

    int getX() { return x; } // узнать x

    int getY() { return y; } // узнать y

    bool operator==(const Point2D& point) { // сравнение

        if (x == point.x && y == point.y) return 1;

        else return 0;
    }

    friend std::ostream& operator<<(std::ostream& out, const Point2D& point) { // вывод на экран

        out << "(" << point.x << ", " << point.y << ")";

        return out;

    }

};
