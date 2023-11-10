  #include "Continente.h"
#include "Territorio.h"
//constructor
Continente::Continente( std::string nNombre){
  nombre = nNombre;
  territoriosOcupados=0;
}

std::string Continente::GetNombreContinente(){
  return nombre;
}

/*
//get color 
std::string Continente::obtenerColor() {
    return color;
}
//set color 
void Continente::establecerColor( std::string nuevoColor) {
    color = nuevoColor;

}
*/
//la parte ocupar el territorio 
void Continente::ocuparTerritorio(Ficha ficha, int nTerritorio, std::string nombreJugador) {
    territorios[nTerritorio].addFicha(ficha);
    territorios[nTerritorio].setReclamar(nombreJugador);
    territoriosOcupados++;
}

int Continente::GetcantidadTerritorios(){
  return territorios.size();
}

int Continente::getTerritoriosOcupados(){
  return territoriosOcupados;
}


std::string Continente::getNombreTerritorio(int indice){
  return territorios[indice].getNombre();
}


//buscar el nombre de un territorio en un continente y si existe, retorna true
bool Continente::territorioValido(std::string territorio){
  for(int i=0; i<territorios.size(); i++){
    if(territorios[i].getNombre()==territorio && territorios[i].getReclamado()=="")
      return true;
  }
  return false;
}


//adicionar al continente el territorio escogido por el usuario //// por eso se pasa por referencia 
void Continente::InicializarTerritorio( std::string nombre) {
  
   Territorio territorio (nombre);
    territorios.push_back(territorio);
}

std::string Continente::reclamado(int indice){
  return territorios[indice].getReclamado();
}

int Continente::getFichasEnTerritorio(int indice){
  return territorios[indice].GetQFichas();
}

Territorio* Continente::buscarTerritorio(std::string nombreTerritorio) {
    for (Territorio& territorio : territorios) {
        if (territorio.getNombre() == nombreTerritorio) {
            return &territorio;
        }
    }
    return nullptr;
}
std::vector<Territorio> Continente::GetTerritorios() {
    return territorios;
}

std::vector<Territorio*> Continente::GetPTerritorios() {
    std::vector<Territorio*> pTerritorios;
    for (Territorio& territorio : territorios) {
        pTerritorios.push_back(&territorio);
    }
    return pTerritorios;
}