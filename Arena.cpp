#include "Arena.h"

Arena::Arena(int l,int w,Prey * prey,Predator * predator): prey(prey),predator(predator) {
    //TODO: Проверка диапазона l w от (1 до 99)       
    length = l;
    width = w;

    // увеличение размера поля для постоянных символов (границы, координаты)
    int shift_l = 3;
    int shift_w = 4;
    int stretch_w = 2;  // удвоим ширину поля (для симметрии клеток при отображении)

    view_length = length + shift_l;
    view_width = width * stretch_w + shift_w;

    // Выделение памяти под массив field размером view_length x view_width
    field = new char * [view_length]();

    for (int i = 0; i < view_length; i++) {

        field[i] = new char[view_width]();

        for (int j = 0; j < view_width; j++)
        {
            field[i][j] = ' ';
        }
    }

    // Заполнение массива декоративными символами //

    // Верхняя и нижняя грань поля
    for (int j = 2; j < view_width; j++) {
        field[0][j] = '~';
        field[view_length - 2][j] = '~';

        // Нумерация снизу
        int cell_num = (j / 2);

        if (j >= view_width - 2) continue;

        if (cell_num > 9) {

            if ((j + 1) % 2 == 0) {
                field[view_length - 1][j + 1] = (cell_num % 10) + '0';
            }
            else field[view_length - 1][j + 1] = (cell_num / 10) + '0';

        }
        else {
            if ((j + 1) % 2 == 0) {
                field[view_length - 1][j + 1] = cell_num + '0';
            }
            else field[view_length - 1][j + 1] = ' ';
        }
    }

    // Левая и правая грань поля
    for (int i = 1; i < view_length - 2; i++) {

        field[i][2] = '|';
        field[i][view_width - 1] = '|';

        // Нумерации слева            
        int y_coords = view_length - shift_l + 1;

        if (y_coords - i > 9) {
            int tmp = ((y_coords - i) / 10);
            field[i][0] = ((y_coords - i) / 10) + '0';
            field[i][1] = ((y_coords - i) % 10) + '0';
        }
        else field[i][1] = y_coords - i + '0';
    }
}

void Arena::clearStep() {
    // Удаление жертвы
    int preyX = (prey->getLocation().getX() * 2) + 2;
    int preyY = prey->getLocation().getY() + 2;

    field[view_length - preyY][preyX] = ' ';
    field[view_length - preyY][preyX - 1] = ' ';

    // Удаление хищника
    int predX = (predator->getLocation().getX() * 2) + 2;
    int predY = predator->getLocation().getY() + 2;

    field[view_length - predY][predX] = ' ';
    field[view_length - predY][predX - 1] = ' ';
}

bool Arena::checkOverRun() {
    int preyX = (prey->getLocation().getX() * 2) + 2;
    int preyY = prey->getLocation().getY() + 2;

    if (preyX > width || preyX < 1 || preyY > length || preyY < 1) return true;

    int predX = (predator->getLocation().getX() * 2) + 2;
    int predY = predator->getLocation().getY() + 2;

    if (predX > width || predX < 1 || predY > length || predY < 1) return true;

    return false;
    //мне кажется прямо здесь можно сделать fixOverrun без цикла
    //одной попытки хватит тк невозможно за один шаг в два раза превысить предел границ
}

Arena::~Arena() {

    //TODO: Проверить правильность освобождения памяти
    for (int i = 0; i < length; i++) {

        delete[] field[i];
    }

    delete[] field;
}

std::ostream & operator<<(std::ostream & out,const Arena & a) {
    int truePreyX=a.prey->getLocation().getX(),
        truePreyY=a.prey->getLocation().getY(),
        truePredX=a.predator->getLocation().getX(),
        truePredY=a.predator->getLocation().getY();


    // Размещение жертвы
    int preyX = (truePreyX * 2) + 2;
    int preyY = truePreyY + 2;

    a.field[a.view_length - preyY][preyX] = 'Y';
    a.field[a.view_length - preyY][preyX - 1] = 'E';

    // Размещение хищника
    int predX = (truePredX * 2) + 2;
    int predY = truePredY + 2;

    a.field[a.view_length - predY][predX] = 'R';
    a.field[a.view_length - predY][predX - 1] = 'O';


    for (int i = 0; i < a.view_length; i++) {
        for (int j = 0; j < a.view_width; j++) {
            std::cout << a.field[i][j];
        }
        std::cout << "\n";
    }
    return out;
}

bool Arena::gameover(){     // условие окончания игры

    if ((prey->getLocation() == predator->getLocation())) {
        std::cout<<"\nyou died\n"; return 1;
    }
    
    return 0;

}

bool Arena::PreyInView(){   // жертва в поле зрения хищника-NPC

    if (prey->getLocation().getX() == predator->getLocation().getX() && abs(prey->getLocation().getY() - predator->getLocation().getY()) <= 5)
        return 1;

    else if (prey->getLocation().getY() == predator->getLocation().getY() && abs(prey->getLocation().getX() - predator->getLocation().getX()) <= 5)
        return 1;

    else
        return 0;

}

void Arena::PredatorPounce(){       // атака при PreyInView

    int  distance;
    if (prey->getLocation().getX() - predator->getLocation().getX()!=0){
        distance = (prey->getLocation().getX() - predator->getLocation().getX());
        if (abs(distance)<=5) 
            predator->moveTo(prey->getLocation().getX()+distance,prey->getLocation().getY());
        else 
            predator->moveTo(prey->getLocation().getX()+5,prey->getLocation().getY());
    }
    else { 
        distance = (prey->getLocation().getY() - predator->getLocation().getY()); 
        if (abs(distance)<=5)
            predator->moveTo(prey->getLocation().getX(),prey->getLocation().getY()+distance);
        else
            predator->moveTo(prey->getLocation().getX(),prey->getLocation().getY()+5);
    }


}
