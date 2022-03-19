#include <fstream>
#include <iostream>
#include <string>
#include "GridWithPeriodicBorder.h"

#include "Cell.h"


const Cell& GridWithPeriodicBorder::getCell(int i, int j) const {

    int posicionI = 0, posicionJ = 0;
    //Condiciones de las filas
    if (i < 0) {
        posicionI = 
    } else if (i > filas_) {
        
    } else {

    }

    return rejilla_[i][j];
}

Cell& GridWithPeriodicBorder::getCell(int i, int j) {
    return rejilla_[i][j];
}

void GridWithPeriodicBorder::update() {

    // Esquinas
    rejilla_[0][0] = rejilla_[n_-2][m_-2];
    rejilla_[n_-1][0] = rejilla_[1][m_-2];
    rejilla_[0][m_-1] = rejilla_[n_-2][1];
    rejilla_[n_-1][m_-1] = rejilla_[1][1];

    for (int i = 1; i < m_; i++) { // Parte inferior y superior
        rejilla_[0][i] = rejilla_[n_-2][i];
        rejilla_[n_-1][i] = rejilla_[1][i];
    }

    for (int i = 1; i < n_; i++) { // Laterales
        rejilla_[i][0] = rejilla_[i][m_-2];
        rejilla_[i][m_-1] = rejilla_[i][1];
    }
    
}