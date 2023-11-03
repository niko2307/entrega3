#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>
#include<algorithm>
#include <iostream>
#include "Ficha.h" 
#include "Carta.h"
#include "Territorio.h"
#include <list>

class Jugador {
public:
    Jugador(std::string nombre, std::string nColor);
    //getters
    std::string obtenerColor() ;
    std::vector<Carta> obtenerCartas() ;
    int obeterTotalFichas();
    std::list<Ficha> obtenerFichas() ;
    std::vector<Territorio*>& getTerritorios();  
    std::string obtenerNombreJugador() ;
    


    void agregarCarta(Carta carta); 
    void agregarFicha(Ficha ficha); 
    void setTerritorio(Territorio* nuevoTerritorio);
    Ficha moverFicha();
    void restarUnidades(int cantidadEliminar,std::string territorio);
    
//  
  // Jugador& obtenerJugador(int indice);
   int contarTerritorios();


   private:
    std::string color;
    std::vector<Carta> cartasJugador;
    std::list <Ficha> fichas;
    std::vector<Territorio *>territorios;
    std::string nombreJugador;
    //Territorio* territorioActual;

   //std::vector<Jugador> jugadores;
};

#endif // JUGADOR_H
