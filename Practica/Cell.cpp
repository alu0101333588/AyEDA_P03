#include <fstream>
#include <iostream>
#include <string>
#include "Cell.h"
#include "State.h"
#include "StateDead.h"

void Cell::updateState(){
    estado_ = estado_->nextState();
}

void Cell::neighbors(const Grid& rejilla1) { // Indica el número de células vecinas vivas
    estado_->neighbors(rejilla1, i_, j_);
}

std::ostream& operator<<(std::ostream& os, const Cell &celula1){

    os << celula1.getState();
    return os;
}

Cell::Cell (){
    estado_ = new StateDead();
}

char Cell::getState() const {
    return estado_->getState();
}
