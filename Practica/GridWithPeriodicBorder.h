#ifndef GRIDWITHPERIODICBORDER_H
#define GRIDWITHPERIODICBORDER_H

#include "Grid.h"

class GridWithPeriodicBorder : public Grid { 
    public:
        //GridWithPeriodicBorder() {}
        GridWithPeriodicBorder(int filas, int columnas); // Constructor propio
        //const Cell& getCell(int i, int j) const;
        Cell& getCell(int i, int j);
        ~GridWithPeriodicBorder() = default;

        //friend std::ostream& operator<<(std::ostream& os, const GridWithOpenBorder &grid1);

        friend std::ostream& operator<<(std::ostream& os, const Grid &grid1); // Inserta sin fronteras incluidas
        void Print(); // Imprime por pantalla la rejilla con las fronteras incluidas
};

#endif