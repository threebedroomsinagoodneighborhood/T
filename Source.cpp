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
    try{
        //system("chcp 65001");

        srand(time(NULL));

        Prey prey("prey",Point2D(1,1),0);//1 = npc, 0 = контроль
        Predator predator("predator",Point2D(9,9),1);

        Arena arena(10,10,&prey,&predator);

        std::cout << arena;

        for (int i = 0; i <= 40; i++) {
            arena.clearStep();

            Point2D prevPreyLocation(prey.getLocation());
            Point2D prevPredLocation(predator.getLocation());

            prey.autoMove();
            if (arena.PreyInView()) arena.PredatorPounce();
            else predator.autoMove();
            //if (arena.checkOverRun()){
            //    prey.moveTo(prevPreyLocation);
            //    predator.moveTo(prevPredLocation);
            //}

            std::cout << arena;
            if (arena.gameover()) break;
            std::cout<<arena.PreyLocation()<<", "<<arena.PredatorLocation()<<'\n';
            system("timeout /t 1");
            //system("cls");
        }
    }
    catch (exception * e)
    {
        cout<<"An error occurred.";
        cout<<e<<'\n'<<e->what();
    }
    
    return 0;
}