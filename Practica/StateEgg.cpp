#include <fstream>
#include <iostream>
#include <string>
#include "StateEgg.h"

#include "StateDead.h"
#include "StateLarva.h"
#include "State.h"

#include "Grid.h"


StateEgg::StateEgg() {
    State_ = 'H'; 
}

char StateEgg::getState() const {
    return State_;
}

State* StateEgg::nextState() {
    if (neighbors_ == 1) {
        return new StateDead;
    } else {
        return new StateLarva; // CUIDADO. Larva
    }
}

void StateEgg::neighbors(const Grid& rejilla1, int i, int j) {
    int contador_larvas = 0;
    int contador_huevos = 0;

    for (int a = i-1; a < i+2; a++){
        for (int b = j-1; b < j+2; b++){
            if (b != j || a != i) {
                char estado1 = rejilla1.getCell(a,b).getState();

                if (estado1 == 'L') {
                    contador_larvas++;
                } 

                if (estado1 == 'H') {
                    contador_huevos++;
                }   
            }
        }
    }

    if (contador_larvas > contador_huevos) { // Si se cumplen las condiciones
        neighbors_ = 1; // Establece neighbors como 1 porque se cumple la condición
    } else {
        neighbors_ = 0; // Establece 0 porque NO se cumple la condición
    }
    
}