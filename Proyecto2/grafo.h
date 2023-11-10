#ifndef GRAFO_H
#define GRAFO_H

#include<vector>
#include<stdlib.h>
#include <iostream>
#include"Continente.h"
#include"Risk.h"
#include "Territorio.h"


class Grafo{
    private:
        std::vector<Territorio*> vertices;

        //Es un puntero a una matriz de enteros 
        int **aristas ;

    public:
        Grafo();
        void inicializarGrafo(Risk* risk);

};


#endif // Grafo.h