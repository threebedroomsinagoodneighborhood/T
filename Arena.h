#pragma once

#include <iostream>
#include "Characters.h"


class Arena {
    
    int length, width;              // размер поля

    Prey* prey;                     // игрок-жертва

    Predator* predator;             // игрок-хищник

    int view_length, view_width;    // отображение

    char** field;                   // поле

public:

    Arena(int l, int w, Prey* prey, Predator* predator);

    void clearStep();

    bool checkOverRun();
    
    ~Arena();

    friend std::ostream& operator<<(std::ostream&, const Arena&);

    friend bool gameover(const Prey & prey,const Predator & predator);

    friend bool inView(const Prey & prey,const Predator & predator);

};



