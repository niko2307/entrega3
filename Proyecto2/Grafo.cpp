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

int Grafo::indiceTerritoriosMatrizAristas(Territorio* territorio) {
    int indiceTerritorio = -1;
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i] == territorio) {
            indiceTerritorio = i;
            break;
        }
    }
    return indiceTerritorio;
}

int Grafo::indiceColindantesMatrizAristas(Territorio* territorio) {
    int indiceColindante = -1;
    std::vector<Territorio*> colindantes = territorio->getTerritoriosColindantes();
    for (int i = 0; i < colindantes.size(); i++) {
        for (int j = 0; j < vertices.size(); j++) {
            if (vertices[j] == colindantes[i]) {
                indiceColindante = j;
                break;
            }
        }
        if (indiceColindante != -1) {
            break;
        }
    }
    return indiceColindante;
}
// Método para buscar el camino más corto utilizando el algoritmo de Dijkstra




// Método para buscar el camino más corto utilizando el algoritmo de Dijkstra
std::vector<Territorio*> Grafo::buscarCaminoDijkstra(Territorio* territorioOrigen, Territorio* territorioDestino) {
   // Valor para representar infinito
const int INFINITY_COST = 1000000;
    // Obtener el índice de los territorios en la matriz de adyacencia
    int origen = indiceTerritoriosMatrizAristas(territorioOrigen);
    int destino = indiceTerritoriosMatrizAristas(territorioDestino);

    // Verificar si los territorios son válidos
    if (origen == -1 || destino == -1) {
        std::cout << "Territorios no válidos." << std::endl;
        return std::vector<Territorio*>();
    }

    // Número de territorios en el grafo
    int numVertices = vertices.size();

    // Crear un arreglo para almacenar la distancia más corta desde el origen hasta cada territorio
    int distancias[numVertices];

    // Crear un arreglo para almacenar el predecesor de cada territorio en el camino más corto
    int predecesor[numVertices];

    // Inicializar distancias y predecesor
    for (int i = 0; i < numVertices; ++i) {
        distancias[i] = INFINITY_COST;
        predecesor[i] = -1;
    }

    distancias[origen] = 0;

    // Crear una cola de prioridades utilizando un montículo (heap)
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> colaPrioridad;
    colaPrioridad.push(std::make_pair(0, origen));

    // Iterar hasta que se visiten todos los territorios
    while (!colaPrioridad.empty()) {
        // Obtener el territorio con menor costo actual
        int territorioActual = colaPrioridad.top().second;
        int costoActual = colaPrioridad.top().first;
        colaPrioridad.pop();

        // Actualizar distancias y predecesor
        for (int colindante = 0; colindante < numVertices; ++colindante) {
            int costo = aristas[territorioActual][colindante];

            if (costo > 0 && distancias[territorioActual] != INFINITY_COST && distancias[territorioActual] + costo < distancias[colindante]) {
                distancias[colindante] = distancias[territorioActual] + costo;
                predecesor[colindante] = territorioActual;
                colaPrioridad.push(std::make_pair(distancias[colindante], colindante));
            }
        }
    }

    // Reconstruir el camino más corto
    std::vector<Territorio*> caminoMasCorto;
    for (int territorio = destino; territorio != -1; territorio = predecesor[territorio]) {
        caminoMasCorto.push_back(vertices[territorio]);
    }

    // Invertir el vector para que esté en el orden correcto
    std::reverse(caminoMasCorto.begin(), caminoMasCorto.end());

    return caminoMasCorto;
}



