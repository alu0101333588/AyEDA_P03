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



Grid::Grid(int filas, int columnas) {
    rejilla_ = new Cell*[filas];
    n_ = filas;
    m_ = columnas;
    nTurnos_ = -1;
    for (int i = 0; i < columnas; i++) {
        rejilla_[i] = new Cell[columnas];
    }

    for (int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            rejilla_[i][j].setposicion(i, j);
        }
    }

}

void Grid::Menu (Grid& rejilla1) {

    visualizacion();
    int i = 0, j = 0; // i Filas, j Columnas
    char letra = 'M';
    std::cout << "A continuación indica las posiciones de las células vivas (i,j)" << std::endl;
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

bool Grid::verificacion(int i, int j) { // verifica si la posición indicada existe o no
    if (i >= filas_ || j >= columnas_ || i < 0 || j < 0) {
        return true; // Manifestamos un error
    }
    return false;
}

void Grid::nextGeneration(Grid& rejilla1){
    nTurnos_++;

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


friend std::ostream& operator<<(std::ostream& os, const Grid &grid1) {

    std::cout << "TURNO " << nTurnos_ << ": " << std::endl << "  ";
    for (int i = 0; i < grid1.m_-2; i++){ // Leyenda números parte superior
        os << i << " ";
    }
    os << std::endl;
    for (int i = 1; i < grid1.n_-1; i++) { // Se imprimen por pantalla las células
        os << i-1 << " ";
        for (int j = 1; j < grid1.m_-1; j++) {
            os << grid1.rejilla_[i][j] << " ";
        } 
        os << std::endl;
    }
    for (int i = 0; i < grid1.m_-2; i++){
        os << "__";
    }
    os << std::endl;
    return os;
}
