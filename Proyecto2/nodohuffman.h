#ifndef NODO_HUFFMAN_H
#define NODO_HUFFMAN_H
template<class T>
class NodoHuffman {

private:
    T caracter;
    int frecuencia;
    NodoHuffman<T>* izquierdo;
    NodoHuffman<T>* derecho;
public:
     
    NodoHuffman();
    NodoHuffman(T car, int fre);
    T getCaracter() ;
    int getFrecuencia() ;
    bool esHoja() ;
    NodoHuffman<T>* getIzquierdo() ;
    NodoHuffman<T>* getDerecho() ;
    void setCaracter(T car);
    void setFrecuencia(int fre);
    void setIzquierdo(NodoHuffman<T> *izq);
    void setDerecho(NodoHuffman<T> *der);
};
#include "nodohuffman.hxx"

#endif//NODO_HUFFMAN_H
