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

    //getters
    std::string GetNombreContinente();
    int GetcantidadTerritorios();
    std::string getNombreTerritorio(int indice);
    int getFichasEnTerritorio(int indice);
    int getTerritoriosOcupados();
    std::vector<Territorio> GetTerritorios();
    std::vector<Territorio*> GetPTerritorios();

    void ocuparTerritorio(Ficha ficha, int nTerritorio, std::string nombreJugador); 
    void InicializarTerritorio( std::string nombre);
    Territorio* buscarTerritorio(std::string nombreTerritorio) ;
    
    
    bool territorioValido(std::string territorio);
    std::string reclamado(int indice);
    
    

    

private:
    std::string nombre;
    std::vector<Territorio> territorios;
    int territoriosOcupados;
};

#endif // CONTINENTE_H
