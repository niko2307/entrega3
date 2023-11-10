#include "grafo.h"


//Constructor
 Grafo::Grafo(){
    aristas = new int * [42];
    for(int i=0;i<42;i++){
        aristas[i]= new int [42];
    }
 }


 void Grafo::inicializarGrafo(Risk* risk){
     // Obtén la lista de territorios
     for (int i = 0; i < risk->continentes.size(); i++)
     {
        /* code */
     }
     
    //std::vector<Territorio*> territorios = risk->getTerritorios();


 }