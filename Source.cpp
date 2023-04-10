#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <cstdlib>

#include "Characters.h"
#include "Arena.h"

using namespace std;


int main() {
    system("chcp 65001");

    srand(time(NULL));

    Prey prey("prey", Point2D(5, 20), true);
    Predator predator("predator", Point2D(3, 10), true);

    Arena arena(30, 30, &prey, &predator);

    cout << arena;

    for (int i = 0; i <= 40; i++) {
        arena.clearStep();

        Point2D prevPreyLocation(prey.getLocation());
        Point2D prevPredLocation(predator.getLocation());

        prey.autoMove();
        predator.autoMove();

        if (arena.checkOverRun())
        {
            prey.moveTo(prevPreyLocation);
            predator.moveTo(prevPredLocation);
        }

        
        cout << arena;
         
        system("timeout /t 1");
        
        system("cls");
    }
    
    return 0;
}