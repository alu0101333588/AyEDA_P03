#ifndef GRID_H
#define GRID_H
#include <fstream>
#include <iostream>
#include "Cell.h"

class Cell;
class Grid {
    public:
        Grid() {} // Constructor
        virtual const Cell& getCell(int i, int j) const = 0;
        virtual Cell& getCell(int i, int j) = 0;

        void nextGeneration(/*Grid& rejilla1*/); // Clase propia
        virtual ~Grid() = default;

        virtual void Print() = 0; // Imprime por pantalla la rejilla con las fronteras incluidas
        bool verificacion(int i, int j); // verifica que las posiciones existen
        void visualizacion();

        //friend std::ostream& operator<<(std::ostream& os, const Grid &grid1);

    protected:
        Cell** rejilla_;
        int nTurnos_; // va contando los turnos
        int filas_; // Dimensiones NxM de la rejilla (FilasXColumnas)
        int columnas_;

};

#endif