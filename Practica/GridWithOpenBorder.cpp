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
    nTurnos_ = -1;
    for (int i = 0; i < columnas; i++) {
        rejilla_[i] = new Cell[columnas];
    }

    for (int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            rejilla_[i][j].setposicion(i, j);
        }
    }

    rejillaMuerta_ = new Cell*[1];
    rejillaMuerta_[0] = new Cell[1];
    rejillaMuerta_[0][0].setState(new StateDead);
}

/*const Cell& GridWithOpenBorder::getCell(int i, int j) const {
    std::cout << "Here" << std::endl;
    if (i < 0 || i >= filas_ || j < 0 || j >= columnas_) {
        return rejillaMuerta_[0][0];
    } else {
        std::cout << "live is live " << i << ", " << j << ": " << rejilla_[i][j].getState() <<std::endl;
        return rejilla_[i][j];
    }

    std::cout << "GetCellOK" << std::endl;
    
}*/

Cell& GridWithOpenBorder::getCell(int i, int j) {

    if (i < 0 || i >= filas_ || j < 0 || j >= columnas_) {
        //std::cout << "Celula: " << i << "," << j << std::endl;
        return rejillaMuerta_[0][0];
    } else {
        //std::cout << "live is live " << i << ", " << j << ": " << rejilla_[i][j].getState() <<std::endl;
        return rejilla_[i][j];
    }


    /*if (i < 0 || i >= filas_ || j < 0 || j >= columnas_) {
        getCell(i, j);
        std::cerr << "ERROR en el getCell(int, int)" << std::endl;
    }
    return rejilla_[i][j];*/
}


/*std::ostream& operator<<(std::ostream& os, const GridWithOpenBorder &grid1) {

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


void GridWithOpenBorder::Print() {
    //std::cout << "PRINT" << std::endl;

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
            std::cout << getCell(i, j).getState() << " ";
            //std::cout << estado1 << " ";
        } 
        std::cout << std::endl;
    }
    for (int i = 0; i < columnas_; i++){
        std::cout << "__";
    }
    std::cout << std::endl;
}
