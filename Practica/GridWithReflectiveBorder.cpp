#include <fstream>
#include <iostream>
#include <string>
#include "GridWithReflectiveBorder.h"

#include "Cell.h"


const Cell& GridWithReflectiveBorder::getCell(int i, int j) const {
    return rejilla_[i][j];
}

Cell& GridWithReflectiveBorder::getCell(int i, int j) {
    return rejilla_[i][j];
}

void GridWithReflectiveBorder::update() {

    // Esquinas
    rejilla_[0][0] = rejilla_[1][1];
    rejilla_[n_-1][0] = rejilla_[n_-2][1];
    rejilla_[0][m_-1] = rejilla_[1][m_-2];
    rejilla_[n_-1][m_-1] = rejilla_[n_-2][n_-2];

    for (int i = 1; i < m_; i++) { // Parte inferior y superior
        rejilla_[0][i] = rejilla_[1][i];
        rejilla_[n_-1][i] = rejilla_[n_-2][i];
    }

    for (int i = 1; i < n_; i++) { // Laterales
        rejilla_[i][0] = rejilla_[i][1];
        rejilla_[i][m_-1] = rejilla_[i][m_-2];
    }
    
}