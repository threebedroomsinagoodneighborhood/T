﻿#pragma once

#include <iostream>
#include "Point2D.h"

class Character {

    std::string name;   // имя персонажа
    Point2D location;   // текущее положение персонажа
    bool npc;           // признак NPC

public:

    Character(const std::string& name, const Point2D& location, bool npcFlag = 0); // конструктор

    void moveTo(Point2D point);             // изменить положение на указанную координату
    void moveTo(int direction, int steps);  // изменить положение по направлению и количеству шагов 

    Point2D getLocation();                  // узнать положение
    bool isNPC();                           // флаг NPC

    virtual void autoMove() = 0;            // движение

    std::string getName() { return name; }  // узнать имя

};

class Prey : public Character {

    const int maxRange = 1;     // максимальный шаг

public:

    Prey(const std::string& name, const Point2D& location, bool npcFlag = 0); // конструктор

    int askDirection();         // узнать направление

    void autoMove() override;   // движение

};

class Predator : public Character{

    const int maxRange = 5;     // максимальный шаг
 
public:

    Predator(const std::string & name,const Point2D & location,bool npcFlag = 0); // конструктор

    int askDirection();         // узнать направление
    int askRange();             // узнать шаг

    void autoMove() override;   // движение

};