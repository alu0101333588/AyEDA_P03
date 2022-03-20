#include <fstream>
#include <iostream>
#include <string>
#include "StateAdult.h"

#include "Grid.h"

#include "StateEgg.h"
#include "StateDead.h"

StateAdult::StateAdult() {
    State_ = 'A'; 
}

char StateAdult::getState() const {
    return State_;
}

State* StateAdult:: nextState() {
    if (neighbors_ >= 1) {
        return new StateEgg;
    } else {
        return new StateDead; // CUIDADO. Pulpa
    }
}

void  StateAdult::neighbors (const Grid& rejilla1, int i, int j) {
    int contador_adultas = 0;

    for (int a = i-1; a < i+2; a++){
        for (int b = j-1; b < j+2; b++){
            if (b != j || a != i) {
                char estado1 = rejilla1.getCell(a,b).getState();

                if (estado1 == 'A') {
                    contador_adultas++;
                }
            }
        }
    }
    neighbors_ = contador_adultas;
}