#include "Characters.h"

Character::Character(const std::string& name, const Point2D& location, bool npcFlag) : name(name), location(location), npc(npcFlag) {   }

void Character::moveTo(Point2D point) {    location = point; }

//0 - ����� 1 - ������ 2 - ���� 3 - ����� 4 - �����-����� 
//5 - �����-������ 6 - ����-������ 7 - ����-�����
void Character::moveTo(int direction, int steps) {

    int deltaX(0), deltaY(0);

    switch (direction)
    {
    case 0:
        deltaY = 1;
        break;
    case 1:
        deltaX = 1;
        break;
    case 2:
        deltaY = -1;
        break;
    case 3:
        deltaX = -1;
        break;
    case 4:
        deltaX = -1;
        deltaY = 1;
        break;
    case 5:
        deltaX = 1;
        deltaY = 1;
        break;
    case 6:
        deltaX = 1;
        deltaY = -1;
        break;
    case 7:
        deltaX = -1;
        deltaY = -1;
        break;
    default:
        break;
    }

    location.setPoint(location.getX() + deltaX * steps, location.getY() + deltaY * steps);
}

Point2D Character::getLocation() {    return location; }

bool Character::isNPC() {   return npc; }



Prey::Prey(const std::string& name, const Point2D& location, bool npcFlag) : Character(name, location, npcFlag) {   }

Predator::Predator(const std::string & name,const Point2D & location,bool npcFlag = 0) : Character(name, location, npcFlag) {   }



int Prey::askDirection() {

    do {

        int direction(0);
        std::cout << "���� ����? \n";
        std::cout << "0 - �����, 1 - ������, 2 - ����, 3 - �����, \n";
        std::cout << "4 - ����� - �����, 5 - �����-������, 6 - ����-������, 7 - ����-����� \n";
        std::cin >> direction;

        if (direction <= 7 && direction >= 0) {
            return direction;
        }
        else std::cout << "������������ ����, �������� ��� ��� \n\n";

    } while (true);

}

int Predator::askRange() {

    do {
        int range;
        std::cout << "�� �������? (1-5) \n";
        std::cin >> range;

        if (range >= 1 && range <= maxRange) {
            return range;
        }
        else std::cout << "������������ ����, �������� ��� ��� \n";

    } while (true);
}

int Predator::askDirection() {

    do {

        int direction(0);
        std::cout << "���� ����?\n";
        std::cout << "0 - �����, 1 - ������, 2 - ����, 3 - �����,\n";
        std::cin >> direction;

        if (direction <= 3 && direction >= 0) {
            return direction;
        }
        else std::cout << "������������ ����, �������� ��� ��� \n";

    } while (true);

}



void Prey::autoMove() {

    int direction = 0;

    if (isNPC()) {
        direction = rand() % 8;
    }
    else {
        direction = askDirection();
    }

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