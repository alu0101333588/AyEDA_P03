#include <fstream>
#include <iostream>
#include <string>
#include "Cell.h"
#include "State.h"
#include "StateDead.h"

void Cell::updateState(){
    estado_ = estado_->nextState();
    //estado_ = estadoFuturo_;
    /*delete[] estado_;
    //State* nuevoestado;
    estado_ = estado_->nextState();
    estado_ = estadoFuturo_;*/
}

void Cell::neighbors(const Grid& rejilla1) { // Indica el número de células vecinas vivas
    estado_->neighbors(rejilla1, i_, j_);
    //return estado_->neighbors(rejilla1, i_, j_);
    //return 1;
    /*int contador = 0;
    for (int i = i_-1; i < i_+2; i++){
        for (int j = j_-1; j < j_+2; j++){
            //std::cout << "Contador: " << i << ", " << j << " :: " << i_ << ", " << j_ << std::endl;
            if (j == j_ && i == i_) {
                // Evitar que se cuenta a sí misma
            } else {
                State estado2 = rejilla1.getCell(i,j).getState();
                if (estado2.getState1() == 1) {
                    //std::cout << "ENCONTRÉ: " << i-1 << ", " << j-1 << std::endl;
                    contador++;
                }  
            }
            
            
        }
    }
    //std::cout << "update (" << i_-1 << ", " << j_-1 << ") : " << contador << " :: " << std::endl;
    return contador;*/
    
}

std::ostream& operator<<(std::ostream& os, const Cell &celula1){
    /*if (celula1.getState().getState1() == 1) {
        os << "X"; // en caso de estar viva
    } else {
        os << " "; // TEMPORAL
    }*/
    os << celula1.getState();
    return os;
}

Cell::Cell (){

    estado_ = new StateDead();
}

char Cell::getState() const {
    return estado_->getState();
}
