#include <fstream>
#include <iostream>
#include <string>
#include "Grid.h"
#include "State.h"

#include "GridWithOpenBorder.h"
#include "GridWithPeriodicBorder.h"
#include "GridWithReflectiveBorder.h"
#include "StateAlive.h"

int main() {

    int nfilas = 0, ncolumnas = 0, tipoRejilla = 1;
    std::cout << "Indica el tamaño de la rejilla (FilasxColumnas)(NxM): ";
    std::cin >> nfilas >> ncolumnas; // Filas x Columnas 

    Grid* rejilla1;
    //std::cout << "prueba: " << rejilla1 << std::endl;

    //GridWithReflectiveBorder* rejilla2();
    //rejilla2.GridWithReflectiveBorder(nfilas, ncolumnas);

    std::cout << "______________________ " << std::endl;
    std::cout << "Rejillas disponibles: " << std::endl;
    std::cout << "1 - GridWithOpenBorder " << std::endl;
    std::cout << "2 - GridWithPeriodicBorder " << std::endl;
    std::cout << "3 - GridWithReflectiveBorder " << std::endl;
    std::cout << "______________________ " << std::endl;
    std::cout << "Indica el tipo de rejilla: ";
    std::cin >> tipoRejilla;

    while (tipoRejilla <= 0 || tipoRejilla > 3) {
        std::cout << "Has introducido un tipo de rejilla no válido, vuelve a intentarlo: ";
        std::cin >> tipoRejilla;
    }

    switch (tipoRejilla) {
    case 1:
        rejilla1 = new GridWithOpenBorder(nfilas, ncolumnas);
        break;

    case 2:
        rejilla1 = new GridWithPeriodicBorder(nfilas, ncolumnas);
        break;

    case 3:
        rejilla1 = new GridWithReflectiveBorder(nfilas, ncolumnas);
        break;
    default:
        std::cerr << "Ha habido un error a la hora de seleccionar tipo de Frontera" << std::endl;
        break;
    }

    rejilla1->Grid::visualizacion();

    int i = 0, j = 0;
    std::cout << "A continuación indica las posiciones de las células vivas (i,j)" << std::endl;
    std::cout << "****(Cuando desees finalizar escribe -1)****" << std::endl;
    while (i != -1) {
        std::cout << "Introduce (i,j): ";
        std::cin >> i;
        if (i != -1){
            std::cin >> j;  
            if(rejilla1->Grid::verificacion(i, j)) {
                std::cout << "*** Ha habido un error, introduce valores correctos. *** (ERROR al introducir valores NUMÉRICOS). " << std::endl;
            } else {
                rejilla1->getCell(i,j).setState(new StateAlive);
                std::cout << "Subida. Correcta: (" << i << ", " << j << "). Estado: Alive" << std::endl;
            }
        }
    }
    std::cout << std::endl << "Has finalizado el proceso de subida de células vivas..." << std::endl << std::endl;
    
    
    int opcionLoop = 1;
    std::cout << "Si desea interrumpir el proceso pulsa 0, sino culquier otro número..." << std::endl;
    rejilla1->Print();
    while (opcionLoop != 0) {
        
        //std::cout << "PRUEBA: " << rejilla1 << std::endl;
        rejilla1->Grid::nextGeneration();
        rejilla1->Print();
        std::cout << "¿Continuar? (0/1): ";
        std::cin >> opcionLoop;
    }

    if (tipoRejilla == 2) {
        rejilla1->Contar();
    }

    std::cout << "Fin del programa. " << std::endl;

    return 0;
}