#include <fstream>
#include <iostream>
#include <string>
#include "GridWithOpenBorder.h"

#include "Cell.h"
#include "StateDead.h"

GridWithOpenBorder::GridWithOpenBorder(int filas, int columnas) {
    rejilla_ = new Cell*[filas];
    filas_ = filas;
    columnas_ = columnas;
    nTurnos_ = 0;
    std::cout << "Dimensiones " << filas_ << "x" << columnas_ << std::endl;
    for (int i = 0; i < filas; i++) {
        rejilla_[i] = new Cell[columnas];
    }

    std::cout << "okey 1" << std::endl;

    for (int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            std::cout << "prueba: " << i << "," << j << std::endl;
            rejilla_[i][j].setposicion(i, j);
        }
    }

    std::cout << "okey 2" << std::endl;

    rejillaMuerta_ = new Cell*[1];
    rejillaMuerta_[0] = new Cell[1];
    rejillaMuerta_[0][0].setState(new StateDead);

    std::cout << "okey 3" << std::endl;
}

const Cell& GridWithOpenBorder::getCell(int i, int j) const {
    if (i < 0 || i >= filas_ || j < 0 || j >= columnas_) {
        return rejillaMuerta_[0][0];
    } else {
        return rejilla_[i][j];
    }
    
}

Cell& GridWithOpenBorder::getCell(int i, int j) {

    if (i < 0 || i >= filas_ || j < 0 || j >= columnas_) {
        return rejillaMuerta_[0][0];
    } else {
        return rejilla_[i][j];
    }
}

void GridWithOpenBorder::Print() {

    std::cout << "(Open) TURNO " << nTurnos_ << ": " << std::endl << "  ";
    for (int i = 0; i < columnas_; i++){ // Leyenda números parte superior
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < filas_; i++) { // Se imprimen por pantalla las células
        std::cout << i << " ";
        for (int j = 0; j < columnas_; j++) {
            //char estado1 = getCell(i,j).getState();
            //Cell prueba = getCell(i, j);
            char estado1 = getCell(i, j).getState();
            std::cout << estado1 << " ";
            //std::cout << estado1 << " ";
        } 
        std::cout << std::endl;
    }
    for (int i = 0; i < columnas_; i++){
        std::cout << "__";
    }
    std::cout << std::endl;
}
