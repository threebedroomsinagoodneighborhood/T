#pragma once

#include <iostream>
#include "Characters.h"


class Arena {

    Prey * prey;                    // игрок-жертва
    Predator * predator;            // игрок-хищник
    
    int length, width;              // размер поля
    int view_length,view_width;     // отображение

    char** field;                   // поле

public:

    Arena(int, int, Prey *, Predator *);    // конструктор
    ~Arena();                               //деструктор

    void clearStep();                       // оставление следа для проверки захода на границу поля
    bool checkOverRun();                    // проверка захода за правую и верхнюю границы поля

    friend std::ostream& operator<<(std::ostream&, const Arena&); // вывод (отрисовка)

    bool gameover();   // условие окончания игры

    bool PreyInView(); // жертва в поле зрения хищника-NPC

    void PredatorPounce();     // атака при PreyInView

    Point2D PreyLocation() { return prey->getLocation(); }
    Point2D PredatorLocation() { return predator->getLocation(); }

    void overboard(){
        int truePreyX=prey->getLocation().getX(),
            truePreyY=prey->getLocation().getY(),
            truePredX=predator->getLocation().getX(),
            truePredY=predator->getLocation().getY();
        if (truePreyX<0) truePreyX+=length;
        else if (truePreyX>length) truePreyX-=length;
        if (truePreyY<0) truePreyX+=width;
        else if (truePreyY>width) truePreyY-=width;
        if (truePredX<0) truePreyX+=length;
        else if (truePredX>length) truePredX-=length;
        if (truePredY<0) truePreyX+=width;
        else if (truePredY>width) truePredY-=width;

        prey->moveTo(truePreyX,truePreyY);
    }

};