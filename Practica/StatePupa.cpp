#include <fstream>
#include <iostream>
#include <string>
#include "StatePupa.h"

#include "Grid.h"

#include "StateDead.h"
#include "StateAdult.h"

StatePupa::StatePupa() {
    State_ = 'P'; 
}

char StatePupa::getState() const {
    return State_;
}

State* StatePupa:: nextState() {
    if (neighbors_ == 1) {
        return new StateDead;
    } else {
        return new StateAdult; // CUIDADO. Pulpa
    }
}

void  StatePupa::neighbors (const Grid& rejilla1, int i, int j) {
    int contador_larvas = 0;
    int contador_huevos = 0;
    int contador_pupas = 0;
    int contador_muertas = 0;
    int contador_adultas = 0;

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
                case ' ':
                    contador_muertas++;
                    break;
                case 'A':
                    contador_adultas++;
                    break;
                default:
                    break;
                }
            }
        }
    }
    if (contador_pupas > contador_adultas && contador_pupas > contador_huevos && contador_pupas > contador_muertas && contador_pupas > contador_larvas) { // Si se cumplen las condiciones
        neighbors_ = 1; // Establece neighbors como 1 porque se cumple la condición
    } else {
        neighbors_ = 0; // Establece 0 porque NO se cumple la condición
    }
}