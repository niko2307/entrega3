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
    //Ficha GetFicha( std::string jugador);
    bool ChekFicha( std::string jugador);
    void setReclamar( std::string jugador);
   
    int GetQFichas();
    std::string getNombre();
    std::string getReclamado();
    bool esColindante(Territorio* otroTerritorio);
    Ficha obtenerFicha(std::string jugador);

    std::vector<Territorio*> getTerritoriosColindantes();
    void setTerritoriosColindantes(Territorio* Territorio);
    void restarFichas(int cantidadEliminar);
    
    
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

