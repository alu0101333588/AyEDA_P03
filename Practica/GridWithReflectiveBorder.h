#ifndef GRIDWITHREFLECTIVEBORDER_H
#define GRIDWITHREFLECTIVEBORDER_H

#include "Grid.h"

class GridWithReflectiveBorder : public Grid { 
    public:
        //GridWithReflectiveBorder() {}
        GridWithReflectiveBorder(int filas, int columnas); // Constructor propio
        //const Cell& getCell(int i, int j) const;
        Cell& getCell(int i, int j);
        ~GridWithReflectiveBorder() = default;

        //friend std::ostream& operator<<(std::ostream& os, const GridWithOpenBorder &grid1);

        friend std::ostream& operator<<(std::ostream& os, const Grid &grid1); // Inserta sin fronteras incluidas
        void Print(); // Imprime por pantalla la rejilla con las fronteras incluidas
};

#endif