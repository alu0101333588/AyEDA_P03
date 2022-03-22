#include <fstream>
#include <iostream>
#include <string>
#include "GridWithPeriodicBorder.h"

#include "Cell.h"

GridWithPeriodicBorder::GridWithPeriodicBorder(int filas, int columnas) {
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


const Cell& GridWithPeriodicBorder::getCell(int i, int j) const {
    
    int posicionI = i, posicionJ = j;

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
    
}

Cell& GridWithPeriodicBorder::getCell(int i, int j) {
    int posicionI = i, posicionJ = j;

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
}


void GridWithPeriodicBorder::Print() {

    std::cout << "(Periodic) TURNO " << nTurnos_ << ": " << std::endl << "  ";
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

void GridWithPeriodicBorder::Contar () {

    int i = 0, j = 0;
    std::cout << "Hola, indica por favor la posición en coordenadas (i,j): ";
    std::cin >> i >> j;
    //Grid::verificacion

    while (verificacion(i, j)) {
        std::cout << "Se ha introducido unos valores incorrectos, vuelve a intentarlo: ";
        std::cin >> i >> j; 
    } 

    int vivas_vertical = 0, vivas_horizontal = 0;

    // Laterales (-i,-j; +i,+j; -i,+j; +i,-j)
    char estado1 = getCell(i-1,j-1).getState();
    if (estado1 == 'X') {
        vivas_horizontal++;
    }

    estado1 = getCell(i+1,j+1).getState();
    if (estado1 == 'X') {
        vivas_horizontal++;
    }

    estado1 = getCell(i-1,j+1).getState();
    if (estado1 == 'X') {
        vivas_horizontal++;
    }

    estado1 = getCell(i+1,j-1).getState();
    if (estado1 == 'X') {
        vivas_horizontal++;
    }

    // Cruz (i,-j; i,+j; -i,j; +i,j)

    estado1 = getCell(i,j-1).getState();
    if (estado1 == 'X') {
        vivas_vertical++;
    }

    estado1 = getCell(i,j+1).getState();
    if (estado1 == 'X') {
        vivas_vertical++;
    }
    
    estado1 = getCell(i-1,j).getState();
    if (estado1 == 'X') {
        vivas_vertical++;
    }

    estado1 = getCell(i+1,j).getState();
    if (estado1 == 'X') {
        vivas_vertical++;
    }
    
    std::cout << "El número de adultas en la cruz es " << vivas_vertical << std::endl;
    std::cout << "El número de adultas en la diagonal es " << vivas_horizontal << std::endl;
}