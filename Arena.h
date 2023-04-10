#pragma once

#include <iostream>
#include "Characters.h"


class Arena {
    
    int length, width;
    Prey* prey;
    Predator* predator;

    int view_length, view_width;   
    char** field;

public:

    Arena(int l, int w, Prey* prey, Predator* predator);

    void clearStep();
    bool checkOverRun();
    
    ~Arena();

    friend std::ostream& operator<<(std::ostream&, const Arena&);

};



//bool check(const Prey& prey, const Predator& predator) {
//
//    if (prey.location.x == predator.location.x && abs(prey.location.y - predator.location.y) <= 5) {
//        return 1;
//    }
//    else if (prey.location.y == predator.location.y && abs(prey.location.x - predator.location.x) <= 5) {
//        return 1;
//    }
//    else return 0;
//}
//
//
//bool check1(const Prey& prey, const Predator& predator) {
//    if ((prey.location.x == predator.location.x) && (prey.location.y == predator.location.y)) return 1;
//    else return 0;
//}