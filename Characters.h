#pragma once

#include <iostream>
#include "Point2D.h"

class Character {

    std::string name;
    Point2D location;
    bool npc;

public:

    Character(const std::string& name, const Point2D& location, bool npcFlag = 0);

    void moveTo(Point2D point);

    //0 - вверх 1 - вправо 2 - вниз 3 - влево 4 - вверх-влево 
    //5 - вверх-вправо 6 - вниз-вправо 7 - вниз-влево
    void moveTo(int direction, int steps);

    Point2D getLocation();

    bool isNPC();

    virtual void autoMove() = 0;

    std::string getName() { return name; }
};

class Prey : public Character {

private:

    const int maxRange = 1;

public:

    Prey(const std::string& name, const Point2D& location, bool npcFlag = 0);

    int askDirection();

    void autoMove() override;



};

class Predator : public Character{
private:

    const int maxRange = 5;
 
public:
    Predator(const std::string& name, const Point2D& location, bool npcFlag = 0) 
        : Character(name, location, npcFlag) {   }

    int askRange() {

        do {
            int range;
            std::cout << "На сколько? (1-5) \n";
            std::cin >> range;

            if (range >= 1 && range <= maxRange) {
                return range;     
            }
            else std::cout << "Некорректный ввод, попробуй ещё раз \n";

        } while (true);
    }

    int askDirection() {
        do {

            int direction(0);
            std::cout << "Куда идти?\n";
            std::cout << "0 - вверх, 1 - вправо, 2 - вниз, 3 - влево,\n";
            std::cin >> direction;

            if (direction <= 3 && direction >= 0) {
                return direction;
            }
            else std::cout << "Некорректный ввод, попробуй ещё раз \n";

        } while (true);       

    }

    void autoMove() override {

        int direction = 0;
        int range = 0;

        if (isNPC()) {
            direction = rand() % 4;
            range = rand() % 5 + 1;
        }
        else {
            direction = askDirection();
            range = askRange();
        }

        moveTo(direction, range);
    }

};