#include "Characters.h"

Character::Character(const std::string& name, const Point2D& location, bool npcFlag) : name(name), location(location), npc(npcFlag) {   }

void    Character::moveTo(int direction, int steps) {

    int deltaX(0), deltaY(0);

    switch (direction)
    {
    case 0://0 - вверх
        deltaY = 1;
        break;
    case 1://1 - вправо
        deltaX = 1;
        break;
    case 2://2 - вниз
        deltaY = -1;
        break;
    case 3://3 - влево
        deltaX = -1;
        break;
    case 4://4 - вверх-влево
        deltaX = -1;
        deltaY = 1;
        break;
    case 5://5 - вверх-вправо
        deltaX = 1;
        deltaY = 1;
        break;
    case 6://6 - вниз-вправо
        deltaX = 1;
        deltaY = -1;
        break;
    case 7://7 - вниз-влево
        deltaX = -1;
        deltaY = -1;
        break;
    default:
        break;
    }

    location.setPoint(location.getX() + deltaX * steps, location.getY() + deltaY * steps);
}

void    Character::moveTo(Point2D point) { location = point; }
Point2D Character::getLocation()         {  return location; }
bool    Character::isNPC()               {  return npc; }



Prey::Prey          (const std::string& name, const Point2D& location, bool npcFlag) : Character(name, location, npcFlag) {   }
Predator::Predator  (const std::string& name, const Point2D& location, bool npcFlag) : Character(name, location, npcFlag) {   }

int Prey::askDirection() {
    while (true){

        int direction(0);
        //std::cout << "\nКуда идти? \n"
        //<< "0 - вверх, 1 - вправо, 2 - вниз, 3 - влево, \n"
        //<< "4 - вверх - влево, 5 - вверх-вправо, 6 - вниз-вправо, 7 - вниз-влево \n";
        std::cout<<"prey: 0 - up, 1 - right, 2 - down, 3 - left,\n4 (0+3), 5 (0+1), 6 (2+1), 7 (2+3)";
        std::cin >> direction;

        if (direction <= 7 && direction >= 0)   return direction;
        else std::cout << "Некорректный ввод, попробуй ещё раз \n";

    }

}

int Predator::askDirection() {
    while (true){

        int direction(0);
        std::cout //<< "\nКуда идти?\n"<<"0 - вверх, 1 - вправо, 2 - вниз, 3 - влево\n";
            <<"predator: 0 - up, 1 - right, 2 - down, 3 - left";
        std::cin >> direction;

        if (direction <= 3 && direction >= 0)   return direction;
        else std::cout << "Некорректный ввод, попробуй ещё раз \n";

    } 

}

int Predator::askRange() {
    while (true){

        int range;
        std::cout //<< "\nНа сколько? (1-5)\n";
            <<"\n step (1-5)\n";
        std::cin >> range;

        if (range >= 1 && range <= maxRange)    return range;
        else std::cout << "Некорректный ввод, попробуй ещё раз \n";

    } 

}



void Prey::autoMove() {

    int direction = 0;

    if (isNPC())    direction = rand() % 8;
    else            direction = askDirection();

    moveTo(direction, maxRange);

}

void Predator::autoMove() {

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

    moveTo(direction,range);

}