#ifndef TERRITORIO_H
#define TERRITORIO_H

#include <string>
#include <vector>
#include "Ficha.h" 

class Territorio {
public:
    Territorio( std::string nuevoNombre);

    void addFicha(Ficha ficha);
    void deleteFicha( std::string jugador);
    void restarFichas(int cantidadEliminar);

    bool esColindante(Territorio* otroTerritorio);
    bool EsFichadeJugador( std::string jugador);
    
    void setReclamar( std::string jugador);
    void setTerritoriosColindantes(Territorio* Territorio);
   
    Ficha GetFicha(std::string jugador);
    int GetQFichas();
    std::string getNombre();
    std::string getReclamado();
    std::vector<Territorio*> getTerritoriosColindantes();
    
    
private:
    std::string nombre;
    std::vector<Ficha> fichas;
    std::string reclamado;
    int unidades;
    int id;
    std::string nombreContinente;
    std::vector<Territorio*> TerritoriosColindantes;
};

#endif // TERRITORIO_H

