#ifndef CONTINENTE_H
#define CONTINENTE_H

#include <string>
#include <vector>
#include "Territorio.h" 
#include "Jugador.h"
#include "Ficha.h"

class Continente {
public:
    Continente(std::string nNombre);
    std::string obtenerNombre();
    //void establecerNombre( std::string nuevoNombre);
    void ocuparTerritorio(Ficha ficha, int nTerritorio, std::string nombreJugador); 
    void InicializarTerritorio( std::string nombre);
    Territorio* buscarTerritorio(std::string nombreTerritorio) ;
    //void MoverFicha(int territorio1, int territorio2); 
    int cantidadTerritorios();
    std::string getNombreTerritorio(int indice);
    bool territorioValido(std::string territorio);
    std::string reclamado(int indice);
    int getTerritoriosOcupados();
    std::vector<Territorio> obtenerTerritorios();

    int getFichasEnTerritorio(int indice);

private:
    std::string nombre;
    std::vector<Territorio> territorios;
    int territoriosOcupados;
};

#endif // CONTINENTE_H
