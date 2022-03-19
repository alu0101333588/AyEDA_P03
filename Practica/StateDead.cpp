#include <fstream>
#include <iostream>
#include <string>
#include "StateDead.h"

#include "StateEgg.h"
#include "Grid.h"


StateDead::StateDead() {
    State_ = ' ';
}

/*StateDead::~StateDead() {
    //delete[] *State_;
}*/


char StateDead::getState() const {
    return State_;
}

State* StateDead::nextState() {
    if (neighbors_ >= 2) {
        return new StateEgg;
    } else {
        return new StateDead;
    }
    
}

void  StateDead::neighbors (const Grid& rejilla1, int i, int j) {
    int contador = 0;

    for (int a = i-1; a < i+2; a++){
        for (int b = j-1; b < j+2; b++){
            //std::cout << "Contador: " << i << ", " << j << " :: " << i_ << ", " << j_ << std::endl;
            if (b != j || a != i) {
                char estado1 = rejilla1.getCell(a,b).getState();
                if (estado1 == 'A') {
                    contador++;
                }  
            }
        }
    }
    neighbors_ = contador;
}