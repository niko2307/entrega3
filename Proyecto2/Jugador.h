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
    std::string GetColor() ;
    std::vector<Carta> GetCartas() ;
    int GetTotalFichas();
    std::list<Ficha> GetFichas() ;
    std::vector<Territorio*>& GetTerritorios();  
    std::string GetNombreJugador() ;
    


    void agregarCarta(Carta carta); 
    void agregarFicha(Ficha ficha); 
    void setTerritorio(Territorio* nuevoTerritorio);
    Ficha moverFicha();
    void restarUnidades(int cantidadEliminar,std::string territorio);
    void eliminarTerritorio(Territorio* territorio);
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
