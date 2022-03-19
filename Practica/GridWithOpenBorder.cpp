#include <fstream>
#include <iostream>
#include <string>
#include "GridWithOpenBorder.h"

#include "Cell.h"
#include "StateDead.h"


const Cell& GridWithOpenBorder::getCell(int i, int j) const {
    
    // tengo que preguntar si es frontera o no 
    Grid rejilla2(1,1);
    rejilla2[0][0] = new StateDead;  
    return rejilla2[0][0];
}

Cell& GridWithOpenBorder::getCell(int i, int j) {
    return rejilla_[i][j];
}
