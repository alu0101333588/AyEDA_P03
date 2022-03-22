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



/*Grid::Grid(int filas, int columnas) {
    rejilla_ = new Cell*[filas];
    filas_ = filas;
    columnas_ = columnas;
    nTurnos_ = -1;
    for (int i = 0; i < filas; i++) {
        rejilla_[i] = new Cell[columnas];
    }

    for (int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            rejilla_[i][j].setposicion(i, j);
        }
    }

}*/

bool Grid::verificacion(int i, int j) { // verifica si la posición indicada existe o no
    if (i >= filas_ || j >= columnas_ || i < 0 || j < 0) {
        return true; // Manifestamos un error
    }
    return false;
}

void Grid::nextGeneration(){
    nTurnos_++;

    for (int i = 0; i < filas_; i++) { // Se aplican las condiciones
        for (int j = 0; j < columnas_; j++) {
            char estado3 = rejilla_[i][j].getState();
            switch (estado3) {
            case ' ':
                rejilla_[i][j].neighbors(*this);
                break;

            case 'X':
                rejilla_[i][j].neighbors(*this);
                break;
            default:
                std::cout << "ERROR en el nextGeneration()" << std::endl;
                break;
            }
        } 
    }

    for (int i = 0; i < filas_; i++) { // Se actualiza el estado de las células
        for (int j = 0; j < columnas_; j++) {
            rejilla_[i][j].updateState(); 
        } 
    }
}

void Grid::visualizacion() {

    // n_ Filas
    // m_ Columnas

    for (int i = 0; i < columnas_; i++){
        std::cout << "_ ";
    }
    std::cout << std::endl;
    for (int i = 0; i < columnas_; i++){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (int j = 1; j < filas_; j++) {
        std::cout << j << std::endl;
    }
    for (int i = 0; i < columnas_; i++){
        std::cout << "_ ";
    }
    std::cout << std::endl;
        
}


/*void Grid::Print() {

    std::cout << "TURNO " << nTurnos_ << ": " << std::endl << "  ";
    for (int i = -1; i < columnas_+1; i++){ // Leyenda números parte superior
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (int i = -1; i < filas_+1; i++) { // Se imprimen por pantalla las células
        std::cout << i << " ";
        for (int j = -1; j < columnas_+1; j++) {
            std::cout << getCell(i,j) << " ";
        } 
        std::cout << std::endl;
    }
    for (int i = -1; i < columnas_+1; i++){
        std::cout << "__";
    }
    std::cout << std::endl;
}*/

/*std::ostream& operator<<(std::ostream& os, const Grid* grid1) {
    os << "--" << std::endl;
    return os;
}*/