#include <fstream>
#include <iostream>
#include <string>
#include "StateDead.h"

#include "StateAlive.h"
#include "Grid.h"


StateDead::StateDead() {
    State_ = ' ';
}

char StateDead::getState() const {
    return State_;
}

State* StateDead::nextState() {
    if (neighbors_ == 3) {
        return new StateAlive;
    } else {
        return new StateDead;
    }
    
}

void StateDead::neighbors (const Grid& rejilla1, int i, int j) {
    int contador = 0;

    for (int a = i-1; a < i+2; a++){
        for (int b = j-1; b < j+2; b++){
            if (b != j || a != i) {
                char estado1 = rejilla1.getCell(a,b).getState();
                if (estado1 == 'X') {
                    contador++;
                }  
            }
        }
    }
    neighbors_ = contador;
}