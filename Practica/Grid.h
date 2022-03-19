#ifndef GRID_H
#define GRID_H
#include <fstream>
#include <iostream>
#include "Cell.h"

class Cell;
class Grid {
    public:
        Grid(int filas, int columnas); // Constructor

        virtual const Cell& getCell(int i, int j) const = 0;
        virtual Cell& getCell(int i, int j) = 0;
        void nextGeneration(Grid& rejilla1); // Clase propia
        virtual ~Grid() = default;
        virtual void update() = 0; // Actualiza las células del borde de la frontera

        friend std::ostream& operator<<(std::ostream& os, const Grid &grid1); // Inserta sin fronteras incluidas
        void Print(); // Imprime por pantalla la rejilla con las fronteras incluidas
        bool verificacion(int i, int j); // verifica que las posiciones existen

    protected:
        Cell** rejilla_;
        int nTurnos_; // va contando los turnos
        int filas_; // Dimensiones NxM de la rejilla (FilasXColumnas)
        int columnas_;

};

#endif