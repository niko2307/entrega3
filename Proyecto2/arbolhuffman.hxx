#include <vector>
#include <queue>
#include "arbolhuffman.h"
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <unordered_map>

template <class T>
ArbolHuffman<T>::ArbolHuffman() {
    raiz = nullptr;
}

template <class T>
ArbolHuffman<T>::~ArbolHuffman() {
    destruirArbol(raiz);
}

template <class T>
void ArbolHuffman<T>::destruirArbol(NodoHuffman<T>* nodo) {
    if (nodo) {
        destruirArbol(nodo->getIzquierdo());
        destruirArbol(nodo->getDerecho());
        delete nodo;
    }
}

template <class T>
std::vector<std::pair<T, int>> ArbolHuffman<T>::calcularFrecuencias(const std::string& texto) {
    // Declara un mapa para almacenar las frecuencias de los caracteres
    std::map<T, int> frecuencias;

    // Recorre el texto y cuenta las frecuencias de cada carácter
    for (char c : texto) {
        frecuencias[c]++;
    }

    // Convierte el mapa en un vector de pares (carácter, frecuencia)
    std::vector<std::pair<T, int>> vectorFrecuencias;
    for (typename std::map<T, int>::const_iterator it = frecuencias.begin(); it != frecuencias.end(); ++it) {
        const std::pair<T, int>& par = *it;
        vectorFrecuencias.push_back(std::make_pair(par.first, par.second));
    }

    return vectorFrecuencias;
}

template <class T>
NodoHuffman<T>* ArbolHuffman<T>::construirArbol(std::vector<std::pair<T, int>>& vectorFrecuencias) {
     typedef bool(*Comparador)(NodoHuffman<T>*, NodoHuffman<T>*);
    Comparador comparador = [](NodoHuffman<T>* lhs, NodoHuffman<T>* rhs) {
        return lhs->getFrecuencia() > rhs->getFrecuencia();
    };
    std::priority_queue<NodoHuffman<T>*, std::vector<NodoHuffman<T>*>, Comparador> colaPrioridad(comparador);

    for (typename std::vector<std::pair<T, int>>::const_iterator it = vectorFrecuencias.begin(); it != vectorFrecuencias.end(); ++it) {
        const std::pair<T, int>& par = *it;
        NodoHuffman<T>* nodo = new NodoHuffman<T>(par.first, par.second);
        colaPrioridad.push(nodo);
    }

    // Construimos el árbol de Huffman combinando los nodos con menor frecuencia
    while (colaPrioridad.size() > 1) {
        NodoHuffman<T>* izquierdo = colaPrioridad.top();
        colaPrioridad.pop();
        NodoHuffman<T>* derecho = colaPrioridad.top();
        colaPrioridad.pop();

        // Creamos un nuevo nodo con frecuencia combinada y lo agregamos a la cola
        int frecuenciaCombinada = izquierdo->getFrecuencia() + derecho->getFrecuencia();
        NodoHuffman<T>* nodoCombinado = new NodoHuffman<T>(T(), frecuenciaCombinada);
        nodoCombinado->setIzquierdo(izquierdo);
        nodoCombinado->setDerecho(derecho);
        colaPrioridad.push(nodoCombinado);
    }

    // El último nodo en la cola es la raíz del árbol de Huffman
    raiz = colaPrioridad.top();

    return raiz; // Devuelve la raíz del árbol
}


template <class T>
std::string ArbolHuffman<T>::codificar( const std::string& texto) {
    std::string codigo;

    // Asegúrate de que el árbol Huffman esté construido antes de codificar
    if (!raiz) {
        std::cout << "El árbol Huffman no está construido." << std::endl;
        return codigo;
    }

    // Recorre el texto caracter por caracter
    for (char caracter : texto) {
        // Llama a una función que busca el código Huffman del caracter en el árbol
        std::string codigoCaracter = obtenerCodigoCaracter(caracter);

        // Agrega el código del caracter al resultado
        codigo += codigoCaracter;
    }


    return codigo;
}

template <class T>
std::string ArbolHuffman<T>::obtenerCodigoCaracter(char caracter) {
    std::string codigo;
    NodoHuffman<T>* nodoActual = raiz;

    // Realiza un recorrido descendente en el árbol para encontrar el código del caracter
    while (nodoActual) {
        if (nodoActual->esHoja() && nodoActual->getCaracter() == caracter) {
            break; // Hemos encontrado el código del caracter
        }

        // Si el bit actual es 0, nos movemos hacia el hijo izquierdo; si es 1, hacia el hijo derecho
        if (caracter & 1) {
            nodoActual = nodoActual->getDerecho();
            codigo += '1'; // Agrega '1' al código
        } else {
            nodoActual = nodoActual->getIzquierdo();
            codigo += '0'; // Agrega '0' al código
        }

        // Quitamos el bit procesado del caracter
        caracter >>= 1;
    }

    // Invierte el código ya que lo estamos construyendo desde las hojas hacia la raíz
    std::reverse(codigo.begin(), codigo.end());

    return codigo;
}

template <class T>
bool ArbolHuffman<T>::CompararFrecuencia(NodoHuffman<T>* lhs, NodoHuffman<T>* rhs) {
    return lhs->getFrecuencia() > rhs->getFrecuencia();
}

template <class T>
std::string ArbolHuffman<T>::decodificar(std::string& codigo) {
    std::string textoDecodificado;
    NodoHuffman<T>* nodoActual = raiz;

    for (char bit : codigo) {
        if (bit == '0') {
            nodoActual = nodoActual->getIzquierdo();
        } else if (bit == '1') {
            nodoActual = nodoActual->getDerecho();
        }

        if (nodoActual->esHoja()) {
            textoDecodificado += nodoActual->getCaracter();
            nodoActual = raiz;
        }
    }


    return textoDecodificado;
}
