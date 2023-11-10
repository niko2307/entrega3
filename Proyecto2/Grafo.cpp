#include "grafo.h"


//Constructor
 Grafo::Grafo(){
    aristas = new int * [42];
    for(int i=0;i<42;i++){
        aristas[i]= new int [42];
    }
 }

void Grafo::actualizarMatrizAdyacencia() {
    for (int i = 0; i < vertices.size(); i++) {
        std::vector<Territorio*> colindantes = vertices[i]->getTerritoriosColindantes();
        for (int j = 0; j < colindantes.size(); j++) {
            int indiceTerritorio = -1;
            int indiceColindante = -1;
            for (int k = 0; k < vertices.size(); k++) {
                if (vertices[k] == vertices[i]) {
                    indiceTerritorio = k;
                }
                if (vertices[k] == colindantes[j]) {
                    indiceColindante = k;
                }
                if (indiceTerritorio != -1 && indiceColindante != -1) {
                    break;
                }
            }
            if (indiceTerritorio != -1 && indiceColindante != -1) {
                aristas[indiceTerritorio][indiceColindante] = vertices[i]->GetQFichas();
                aristas[indiceColindante][indiceTerritorio] = colindantes[j]->GetQFichas();
            }
        }
    }
}

void Grafo::inicializarGrafo(Risk* risk) {
    // Obtén la lista de territorios
    for (int i = 0; i < risk->getContinentes().size(); i++) {
        std::vector<Continente*> continentes = risk->getContinentes();
        for (int j = 0; j < continentes[i]->GetTerritorios().size(); j++) {
            std::vector<Territorio*> territorios = continentes[i]->GetPTerritorios();
            vertices.push_back(territorios[j]);
        }
    }
    
    // Inicializar la matriz de adyacencia con false
    aristas = new int*[vertices.size()];
    for (int i = 0; i < vertices.size(); ++i) {
        aristas[i] = new int[vertices.size()];
        for (int j = 0; j < vertices.size(); ++j) {
            aristas[i][j] = 0;
        }
    }
    
    // Actualizar la matriz de adyacencia según la colindancia
    actualizarMatrizAdyacencia();
}

 void Grafo::imprimirInformacionGrafo() {
    // Imprimir información de los vértices
    std::cout << "Informacion de los vertices:" << std::endl;
    for (int i = 0; i < vertices.size(); i++) {
        std::cout << "Vertice " << i << ": " << vertices[i]->getNombre() << std::endl;
    }
     // Imprimir matriz de adyacencia
    std::cout << "Matriz de adyacencia:" << std::endl;
    for (int i = 0; i < vertices.size(); i++) {
        for (int j = 0; j < vertices.size(); j++) {
            std::cout << aristas[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/*
void Grafo::imprimirInformacionGrafo() {
    // Imprimir información de los vértices
    std::cout << "Información de los vértices:" << std::endl;
    for (int i = 0; i < vertices.size(); i++) {
        std::cout << "Vértice " << i << ": " << vertices[i]->getNombre() << std::endl;
    }
    
    // Imprimir matriz de adyacencia
    std::cout << "Matriz de adyacencia:" << std::endl;
    
    // Imprimir nombres de los territorios en las columnas
    std::cout << "   ";
    for (int i = 0; i < vertices.size(); i++) {
        std::cout << vertices[i]->getNombre() << " ";
    }
    std::cout << std::endl;
    
    for (int i = 0; i < vertices.size(); i++) {
        // Imprimir nombre del territorio en la fila
        std::cout << vertices[i]->getNombre() << " ";
        
        // Imprimir valores de la matriz de adyacencia
        for (int j = 0; j < vertices.size(); j++) {
            std::cout << aristas[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
*/