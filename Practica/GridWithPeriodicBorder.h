#ifndef GRIDWITHPERIODICBORDER_H
#define GRIDWITHPERIODICBORDER_H

#include "Grid.h"

class GridWithPeriodicBorder : public Grid { 
    public:
        GridWithPeriodicBorder() {} // Constructor propio
        const Cell& getCell(int i, int j) const;
        Cell& getCell(int i, int j);
        ~GridWithPeriodicBorder() = default;
        void update(); // Aplica las condiciones pertinentes de la frontera

        //friend std::ostream& operator<<(std::ostream& os, const GridWithOpenBorder &grid1);
};

#endif