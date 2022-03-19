#include <fstream>
#include <iostream>
#include <string>
#include "Grid.h"

#include "State.h" 

#include "StateEgg.h" 
#include "StateDead.h"
#include "StatePupa.h"
#include "StateAdult.h"
#include "StateLarva.h"



char Grid::getGrid(int i, int j) { 
    return rejilla_[i][j].getState(); 
}

Grid::Grid(int n, int m, int turnos) {
    nTurnos_ = turnos;
    rejilla_ = new Cell*[n+2];
    n_ = n+2;
    m_ = m+2;
    for (int i = 0; i < n+2; i++) {
        rejilla_[i] = new Cell[m+2];
    }

    for (int i = 0; i < n+2; i++) {
        for(int j = 0; j < m+2; j++) {
            rejilla_[i][j].setposicion(i, j);
        }
    }

}

void Grid::Menu (Grid& rejilla1) {

    visualizacion();
    int i = 0, j = 0; // i Filas, j Columnas
    char letra = 'M';
    std::cout << "A continuación indica las posiciones de las células vivas (i,j) y el estado" << std::endl;
    std::cout << "||| ESTADOS DISPONIBLES: Huevo (H), Larva (L), Pupa (P), Adulta (A), Muerta (M) |||" << std::endl;
    std::cout << "****(Cuando desees finalizar escribe -1)****" << std::endl;
    while (i != -1) {
        std::cout << "Introduce (i,j): ";
        std::cin >> i;
        if (i != -1){
            std::cin >> j;  
            std::cin >> letra;
            if(verificacion(i+1, j+1)) {
                std::cout << "*** Ha habido un error, introduce valores correctos. *** (ERROR al introducir valores NUMÉRICOS). " << std::endl;
            } else if (Letras(letra, i+1, j+1)) {
                std::cout << "Ha habido un error, introduce valores correctos. (ERROR al introducir la LETRA)." << std::endl;
            } else {
                std::cout << "Subida. Correcta: (" << i << ", " << j << "). Estado: " << letra << std::endl;
            }
        }
    }
    std::cout << std::endl << "Has finalizado el proceso de subida de células vivas..." << std::endl << std::endl;
    nextGeneration(rejilla1);
}

bool Grid::Letras(char letra1, int i, int j) {
    switch (letra1){
    case 'M':
        rejilla_[i][j].setState(new StateDead);
        break;
    case 'H':
        rejilla_[i][j].setState(new StateEgg);
        break;
    case 'L':
        rejilla_[i][j].setState(new StateLarva);
        break;
    case 'P':
        rejilla_[i][j].setState(new StatePupa);
        break;
    case 'A':
        rejilla_[i][j].setState(new StateAdult);
        break;
    
    default:
        return true;
        break;
    }

    return false;

}

bool Grid::verificacion(int i, int j) { // verifica si la posición indicada existe o no
    if (i >= n_-1 || j >= m_-1 || i < 0 || j < 0) {
        return true; // Manifestamos un error
    }
    /*State estado1;
    estado1.setViva();
    rejilla_[i+1][j+1].setState(estado1);*/
    return false;
}

void Grid::nextGeneration(Grid& rejilla1){

    std::cout << "TURNO 0: " << std::endl << "  ";
    for (int i = 0; i < m_-2; i++){ // Leyenda números parte superior
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (int i = 1; i < n_-1; i++) { // Se imprimen por pantalla las células
        std::cout << i-1 << " ";
        for (int j = 1; j < m_-1; j++) {
            std::cout << rejilla_[i][j] << " ";
        } 
        std::cout << std::endl;
    }

    for (int i = 0; i < m_-2; i++){
        std::cout << "__";
    }
    std::cout << std::endl;

    int turn = 0;
    while (turn != nTurnos_) {
        turn++;
        for (int i = 1; i < n_-1; i++) { // Se aplican las condiciones
            for (int j = 1; j < m_-1; j++) {
                char estado3 = rejilla_[i][j].getState();

                switch (estado3) {
                case ' ':
                    rejilla_[i][j].neighbors(rejilla1);
                    break;

                case 'H':
                    rejilla_[i][j].neighbors(rejilla1);
                    break;
                case 'L':
                    rejilla_[i][j].neighbors(rejilla1);
                    break;
                case 'P':
                    rejilla_[i][j].neighbors(rejilla1);
                    break;
                case 'A':
                    rejilla_[i][j].neighbors(rejilla1);
                    break;
                default:
                    std::cout << "ERROR en el nextGeneration()" << std::endl;
                    break;
                }
            } 
        }

        for (int i = 1; i < n_-1; i++) { // Se actualiza el estado de las células
            for (int j = 1; j < m_-1; j++) {
                rejilla_[i][j].updateState(); 
            } 
        }

        std::cout << "TURNO " << turn << ":" << std::endl << "  ";

        for (int i = 0; i < m_-2; i++){ // Leyenda números parte superior
            std::cout << i << " ";
        }
        std::cout << std::endl;
        for (int i = 1; i < n_-1; i++) { // Se imprimen por pantalla las células
            std::cout << i-1 << " ";
            for (int j = 1; j < m_-1; j++) {
                std::cout << rejilla_[i][j] << " ";
            } 
            std::cout << std::endl;
        }
        for (int i = 0; i < m_-2; i++){
            std::cout << "__";
        }
        std::cout << std::endl;
    }
}

void Grid::visualizacion() {

    // n_ Filas
    // m_ Columnas

    for (int i = 0; i < m_-2; i++){
        std::cout << "_ ";
    }
    std::cout << std::endl;
    for (int i = 0; i < m_-2; i++){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (int j = 1; j < n_-2; j++) {
        std::cout << j << std::endl;
    }
    for (int i = 0; i < m_-2; i++){
        std::cout << "_ ";
    }
    std::cout << std::endl;
        
}


const Cell& Grid::getCell(int i, int j) const {
    return rejilla_[i][j];
}