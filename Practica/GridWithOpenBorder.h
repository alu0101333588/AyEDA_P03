#ifndef GRIDWITHOPENBORDER_H
#define GRIDWITHOPENBORDER_H

#include "Grid.h"

class GridWithOpenBorder : public Grid { 
    public:
        GridWithOpenBorder(int filas, int columnas); // Constructor propio
        //const Cell& getCell(int i, int j) const;
        Cell& getCell(int i, int j);
        ~GridWithOpenBorder() = default;

        friend std::ostream& operator<<(std::ostream& os, const Grid &grid1); // Inserta sin fronteras incluidas
        void Print(); // Imprime por pantalla la rejilla con las fronteras incluidas

        //friend std::ostream& operator<<(std::ostream& os, const GridWithOpenBorder &grid1);
    private:
        Cell** rejillaMuerta_;
};

#endif