#ifndef GRIDWITHOPENBORDER_H
#define GRIDWITHOPENBORDER_H

#include "Grid.h"

class GridWithOpenBorder : public Grid { 
    public:
        GridWithOpenBorder() {} // Constructor propio
        const Cell& getCell(int i, int j) const;
        Cell& getCell(int i, int j);
        ~GridWithOpenBorder() = default;

        //friend std::ostream& operator<<(std::ostream& os, const GridWithOpenBorder &grid1);
};

#endif