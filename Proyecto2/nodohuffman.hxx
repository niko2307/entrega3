#include "nodohuffman.h"
template <class T>
NodoHuffman<T>::NodoHuffman(){

}

template <class T>
NodoHuffman<T>::NodoHuffman(T car, int fre){
izquierdo=NULL;
derecho=NULL;
car=caracter;
fre=frecuencia;
} 

template <class T>
T NodoHuffman<T>::getCaracter() {
    return caracter;
}

template <class T>
int NodoHuffman<T>::getFrecuencia() {
    return frecuencia;
}

template <class T>
bool NodoHuffman<T>::esHoja() {
    return izquierdo == nullptr && derecho == nullptr;
}

template <class T>
NodoHuffman<T>* NodoHuffman<T>::getIzquierdo() {
    return izquierdo;
}

template <class T>
NodoHuffman<T>* NodoHuffman<T>::getDerecho() {
    return derecho;
}
template <class T>
void NodoHuffman<T>::setCaracter(T car) {
    caracter = car;
}

template <class T>
void NodoHuffman<T>::setFrecuencia(int fre) {
    frecuencia = fre;
}

template <class T>
void NodoHuffman<T>::setIzquierdo(NodoHuffman<T>* izq) {
    izquierdo = izq;
}

template <class T>
void NodoHuffman<T>::setDerecho(NodoHuffman<T>* der) {
    derecho = der;
}