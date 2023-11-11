#ifndef GRAFO_H
#define GRAFO_H

#include <queue>
#include <vector>
#include <limits>
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
         void imprimirInformacionGrafo();
         void actualizarMatrizAdyacencia();
        int indiceTerritoriosMatrizAristas(Territorio* territorio);
        int indiceColindantesMatrizAristas(Territorio* territorio);
        std::vector<Territorio*> buscarCaminoDijkstra(Territorio* territorioOrigen, Territorio* territorioDestino); 
 
};


#endif // Grafo.h