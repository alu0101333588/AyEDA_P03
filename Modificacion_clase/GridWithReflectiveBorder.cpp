#include <fstream>
#include <iostream>
#include <string>
#include "GridWithReflectiveBorder.h"

#include "Cell.h"

GridWithReflectiveBorder::GridWithReflectiveBorder(int filas, int columnas) {
    rejilla_ = new Cell*[filas];
    filas_ = filas;
    columnas_ = columnas;
    nTurnos_ = 0;
    for (int i = 0; i < filas; i++) {
        rejilla_[i] = new Cell[columnas];
    }

    for (int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            rejilla_[i][j].setposicion(i, j);
        }
    }
}

const Cell& GridWithReflectiveBorder::getCell(int i, int j) const {
    
    int posicionI = i, posicionJ = j;

    //Condiciones de las filas
    if (i < 0) {
        posicionI = 0;
    } else if (i >= filas_) {
        posicionI = filas_-1;
    } else {
        posicionI = i;
    }

    //Condiciones de las columnas
    if (j < 0) {
        posicionJ = 0;
    } else if (j >= columnas_) {
        posicionJ = columnas_-1;
    } else {
        posicionJ = j;
    }

    return rejilla_[posicionI][posicionJ];
    
}

Cell& GridWithReflectiveBorder::getCell(int i, int j) {
    int posicionI = i, posicionJ = j;

    //Condiciones de las filas
    if (i < 0) {
        posicionI = 0;
    } else if (i >= filas_) {
        posicionI = filas_-1;
    } else {
        posicionI = i;
    }

    //Condiciones de las columnas
    if (j < 0) {
        posicionJ = 0;
    } else if (j >= columnas_) {
        posicionJ = columnas_-1;
    } else {
        posicionJ = j;
    }

    return rejilla_[posicionI][posicionJ];
}


void GridWithReflectiveBorder::Print() {

    std::cout << "(Reflective) TURNO " << nTurnos_ << ": " << std::endl << "  ";
    for (int i = 0; i < columnas_; i++){ // Leyenda números parte superior
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < filas_; i++) { // Se imprimen por pantalla las células
        std::cout << i << " ";
        for (int j = 0; j < columnas_; j++) {
            char estado1 = getCell(i, j).getState();
            std::cout << estado1 << " ";
        } 
        std::cout << std::endl;
    }
    for (int i = 0; i < columnas_; i++){
        std::cout << "__";
    }
    std::cout << std::endl;
}