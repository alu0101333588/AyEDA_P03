#ifndef GRIDWITHREFLECTIVEBORDER_H
#define GRIDWITHREFLECTIVEBORDER_H

#include "Grid.h"

class GridWithReflectiveBorder : public Grid { 
    public:
        GridWithReflectiveBorder() {} // Constructor propio
        const Cell& getCell(int i, int j) const;
        Cell& getCell(int i, int j);
        ~GridWithReflectiveBorder() = default;
        void update(); // Aplica las condiciones pertinentes de la frontera

        //friend std::ostream& operator<<(std::ostream& os, const GridWithOpenBorder &grid1);
};

#endif