#include <fstream>
#include <iostream>
#include <string>
#include "GridWithPeriodicBorder.h"

#include "Cell.h"

GridWithPeriodicBorder::GridWithPeriodicBorder(int filas, int columnas) {
    rejilla_ = new Cell*[filas];
    filas_ = filas;
    columnas_ = columnas;
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


/*const Cell& GridWithPeriodicBorder::getCell(int i, int j) const {
    
    int posicionI = 0, posicionJ = 0;

    //Condiciones de las filas
    if (i < 0) {
        posicionI = filas_-1;
    } else if (i >= filas_) {
        posicionI = 0;
    } else {
        posicionI = i;
    }

    //Condiciones de las columnas
    if (j < 0) {
        posicionJ = columnas_-1;
    } else if (j >= columnas_) {
        posicionJ = 0;
    } else {
        posicionJ = j;
    }

    return rejilla_[posicionI][posicionJ];
    
}*/

Cell& GridWithPeriodicBorder::getCell(int i, int j) {
    std::cout << "GETCELL INCORRECTO" << std::endl;
    if (i < 0 || i >= filas_ || j < 0 || j >= columnas_) {
        std::cerr << "ERROR en el getCell(int, int)" << std::endl;
    }
    return rejilla_[i][j];
}


/*std::ostream& operator<<(std::ostream& os, const GridWithPeriodicBorder &grid1) {

    std::cout << "TURNO " << grid1.nTurnos_ << ": " << std::endl << "  ";
    for (int i = 0; i < grid1.columnas_; i++){ // Leyenda números parte superior
        os << i << " ";
    }
    os << std::endl;
    for (int i = 0; i < grid1.filas_; i++) { // Se imprimen por pantalla las células
        os << i << " ";
        for (int j = 0; j < grid1.columnas_; j++) {
            os << grid1.rejilla_[i][j] << " ";
        } 
        os << std::endl;
    }
    for (int i = 0; i < grid1.columnas_; i++){
        os << "__";
    }
    os << std::endl;
    return os;
}*/


void GridWithPeriodicBorder::Print() {

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
}