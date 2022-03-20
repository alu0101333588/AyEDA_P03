#include <fstream>
#include <iostream>
#include <string>
#include "StateLarva.h"

#include "StateDead.h"

#include "Grid.h"

#include "StatePupa.h"

StateLarva::StateLarva() {
    State_ = 'L'; 
}

char StateLarva::getState() const {
    return State_;
}

State* StateLarva:: nextState() {
    if (neighbors_ == 1) {
        return new StateDead;
    } else {
        return new StatePupa; 
    }
}

void StateLarva::neighbors (const Grid& rejilla1, int i, int j) {
    int contador_larvas = 0;
    int contador_huevos = 0;
    int contador_pupas = 0;
    for (int a = i-1; a < i+2; a++){
        for (int b = j-1; b < j+2; b++){
            if (b != j || a != i) {
                char estado1 = rejilla1.getCell(a,b).getState();

                switch (estado1){
                case 'L':
                    contador_larvas++;
                    break;
                case 'H':
                    contador_huevos++;
                    break;
                case 'P':
                    contador_pupas++;
                    break;
                default:
                    break;
                }
            }
        }
    }
    if (contador_larvas > (contador_huevos+contador_pupas)) { // Si se cumplen las condiciones
        neighbors_ = 1; // Establece neighbors como 1 porque se cumple la condición
    } else {
        neighbors_ = 0; // Establece 0 porque NO se cumple la condición
    }
}