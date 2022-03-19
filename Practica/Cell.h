#ifndef CELL_H
#define CELL_H
#include <fstream>
#include <iostream>
#include "State.h"
#include "Grid.h"


class Grid;
class Cell {
    public:
        Cell(); // Constructor
        void setposicion(int i, int j) {i_ = i; j_ = j;}
        char getState() const;
        void setState(State* estado1) {estado_ = estado1;}
        void updateState();
        void neighbors(const Grid& rejilla1);
        friend std::ostream& operator<<(std::ostream& os, const Cell &celula1);

    private:
        State* estado_;
        int i_; // Posición i que ocupa la célula
        int j_; // Posición j que ocupa la célula

};

#endif
