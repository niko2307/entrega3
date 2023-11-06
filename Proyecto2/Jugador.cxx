#include "Jugador.h"
#include <vector>
//constructor 
Jugador::Jugador( std::string nombre, std::string nColor) {
  nombreJugador = nombre;
  color= nColor;
}
// get color 
std::string Jugador::GetColor() {
    return color;
}

//get Nombre del jugador 
std::string Jugador::GetNombreJugador() {
    return nombreJugador;
}

// agregar la targeta 

// get de obtener la tarjeta 
//std::vector<Carta> Jugador::obtenerTarjeta() {
//    return tarjeta;
//}
// agregar ficha 
void Jugador::agregarFicha(Ficha ficha) {
    fichas.push_back(ficha);
    
}

std::list<Ficha> Jugador::GetFichas() {
    return fichas;
}

  int Jugador::GetTotalFichas(){
    
    
    return fichas.size();
  }

Ficha Jugador::moverFicha(){
  Ficha aux = fichas.back();
  fichas.pop_back();
  return aux;
}

std::vector<Territorio*>& Jugador::GetTerritorios() {
        return territorios;
    }

 void Jugador::setTerritorio(Territorio* nuevoTerritorio) {
        territorios.push_back(nuevoTerritorio);

    }
  int Jugador::contarTerritorios() {
    
    return territorios.size();
}
std::vector<Carta> Jugador::GetCartas() {
    return cartasJugador;
}

void Jugador::restarUnidades(int cantidadEliminar,std::string Nterritorio) {
    int fichasEliminadas = 0;
    for (int i = fichas.size() - 1; i >= 0 && fichasEliminadas < cantidadEliminar; i--) {
        fichas.pop_back();
        fichasEliminadas++;
    }

  //elimina las fichas al territorio desde jugador
  for (Territorio* territorio : this->territorios) {
       
if (territorio->getNombre() == Nterritorio) {
          territorio->restarFichas( cantidadEliminar);
        }
}
}

void Jugador::agregarCarta(Carta carta){
  std::cout<<"agreagrecarta"<<std::endl;
    this->cartasJugador.push_back(carta);
    std::cout<<"seagreagrecarta"<<std::endl;
}

void Jugador::eliminarTerritorio(Territorio* territorio) {
    // Buscar el territorio en la lista de territorios del jugador
    for (size_t i = 0; i < territorios.size(); i++) {
        if (territorios[i] == territorio) {
            // Eliminar el territorio de la lista
            territorios.erase(territorios.begin() + i);
            break;
        }
    }
}