#include "Risk.h"
#include "Territorio.h"
#include <iostream>
#include <random>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <windows.h>

Risk::Risk() {
  Partida=false;
  Ganador=false;
  turnoActual=0;
  Totalturnos=0;
}

int Risk::lanzarDado() {
    // Generar una semilla aleatoria única para cada ejecución
    Sleep(10);
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);

    // Generar un número aleatorio entre 1 y 6 (correspondiente a las caras del dado)
    int resultado = (rand() % 6) + 1;

    return resultado;
}
//pone la bandera de partida en verdadero
void Risk::iniciarPartida() {
  Partida=true; 
}

bool Risk::estadoPartida(){
  return Partida;
}

bool Risk::evaluarexistenciaGanador() {
    // Iterar sobre los jugadores
    for (Jugador& jugador : jugadores) {
        // Verificar si el jugador tiene todos los territorios
        if (jugador.GetTerritorios().size() == 42) {
            Ganador = true; // Actualizar variable Ganador
            return true;
        }
    }
    return false;
}

bool Risk::estadoGanador(){
  return Ganador;
}

//pone el contador de turnos en cero para volver a empezar desde el jugador 0
void Risk::turnosEnCero(){
  Totalturnos = 0;
}

void Risk::crearContinente() {
  
  //vamos a crear los contienentes aca 
    //contienete de America del norte 
    Continente continente1 ("america del norte");
    
    continente1.InicializarTerritorio("alaska");

    continente1.InicializarTerritorio("alberta");
    /*
    continente1.InicializarTerritorio("america central");
    continente1.InicializarTerritorio("estados unidos orientales");
    continente1.InicializarTerritorio("groenlandia");
    continente1.InicializarTerritorio("territorio noroccidental");
    continente1.InicializarTerritorio("ontario");
    continente1.InicializarTerritorio("quebec");
    continente1.InicializarTerritorio("estados unidos occidentales");
    */

  //Continente de europa 
   Continente continente2 ("europa");

    continente2.InicializarTerritorio("gran bretana");
    /*
    continente2.InicializarTerritorio("islandia");
    continente2.InicializarTerritorio("europa del norte");
    continente2.InicializarTerritorio("escandinavia");
    continente2.InicializarTerritorio("europa del sur");
    continente2.InicializarTerritorio("ucrania");
    continente2.InicializarTerritorio("europa occidental");
    */

  //Continente de America del sur 
    Continente continente3 ("america del sur");
    continente3.InicializarTerritorio("argentina");
    /*
    continente3.InicializarTerritorio("brasil");
    continente3.InicializarTerritorio("colombia");
    continente3.InicializarTerritorio("peru");
    */

  //continente de Africa 
    Continente continente4 ("africa");
    continente4.InicializarTerritorio("congo");
    /*
    continente4.InicializarTerritorio("africa oriental");
    continente4.InicializarTerritorio("egipto");
    continente4.InicializarTerritorio("madagascar");
    continente4.InicializarTerritorio("africa del norte");
    s
    continente4.InicializarTerritorio("africa del sur");
    */
  //continete de Oceania
   Continente continente5 ("australia");
    continente5.InicializarTerritorio("australia oriental");
    /*
    continente5.InicializarTerritorio("indonesia");
    continente5.InicializarTerritorio("nueva guinea");
    continente5.InicializarTerritorio("australia occidental");
    */

    //continente de Asia 
    Continente continente6 ("asia");
    continente6.InicializarTerritorio("afghanistan");
    /*
    continente6.InicializarTerritorio("china");
    continente6.InicializarTerritorio("india");
    continente6.InicializarTerritorio("irkutsk");
    continente6.InicializarTerritorio("japon");
    continente6.InicializarTerritorio("kamchatka");
    continente6.InicializarTerritorio("medio oriente");
    continente6.InicializarTerritorio("mongolia");
    continente6.InicializarTerritorio("siam");
    continente6.InicializarTerritorio("siberia");
    continente6.InicializarTerritorio("ural");
    continente6.InicializarTerritorio("yakutsk");
    */
   // Agregar los continentes al tablero del juego
    continentes.push_back(continente1);
    continentes.push_back(continente2);
    continentes.push_back(continente3);
    continentes.push_back(continente4);
    continentes.push_back(continente5);
    continentes.push_back(continente6);
  

}
void Risk::InicializarTerritoriosColindantes(Risk* risk){
 
// Continente de América del Norte
Territorio* americaCentral = risk->getTerritorio("america del norte", "america central");
Territorio* estadosUnidosOrientales = risk->getTerritorio("america del norte", "estados unidos orientales");
Territorio* groenlandia = risk->getTerritorio("america del norte", "groenlandia");
Territorio* territorioNoroccidental = risk->getTerritorio("america del norte", "territorio noroccidental");
Territorio* ontario = risk->getTerritorio("america del norte", "ontario");
Territorio* quebec = risk->getTerritorio("america del norte", "quebec");
Territorio* estadosUnidosOccidentales = risk->getTerritorio("america del norte", "estados unidos occidentales");
Territorio* alaska = risk->getTerritorio("america del norte", "alaska");
Territorio* alberta = risk->getTerritorio("america del norte", "alberta");


// Continente de Europa
Territorio* islandia = risk->getTerritorio("europa", "islandia");
Territorio* europaDelNorte = risk->getTerritorio("europa", "europa del norte");
Territorio* escandinavia = risk->getTerritorio("europa", "escandinavia");
Territorio* europaDelSur = risk->getTerritorio("europa", "europa del sur");
Territorio* ucrania = risk->getTerritorio("europa", "ucrania");
Territorio* europaOccidental = risk->getTerritorio("europa", "europa occidental");
Territorio* granBretana = risk->getTerritorio("europa", "gran bretana");



// Continente de América del Sur
Territorio* brasil = risk->getTerritorio("america del sur", "brasil");
Territorio* colombia = risk->getTerritorio("america del sur", "colombia");
Territorio* peru = risk->getTerritorio("america del sur", "peru");
Territorio* argentina = risk->getTerritorio("america del sur", "argentina");


// Continente de África
Territorio* africaOriental = risk->getTerritorio("africa", "africa oriental");
Territorio* egipto = risk->getTerritorio("africa", "egipto");
Territorio* madagascar = risk->getTerritorio("africa", "madagascar");
Territorio* africaDelNorte = risk->getTerritorio("africa", "africa del norte");
Territorio* africaDelSur = risk->getTerritorio("africa", "africa del sur");
Territorio* congo = risk->getTerritorio("africa", "congo");


// Continente de Oceanía
Territorio* indonesia = risk->getTerritorio("australia", "indonesia");
Territorio* nuevaGuinea = risk->getTerritorio("australia", "nueva guinea");
Territorio* australiaOccidental = risk->getTerritorio("australia", "australia occidental");
Territorio* australiaOriental = risk->getTerritorio("australia", "australia oriental");

// Continente de Asia
Territorio* china = risk->getTerritorio("asia", "china");
Territorio* india = risk->getTerritorio("asia", "india");
Territorio* irkutsk = risk->getTerritorio("asia", "irkutsk");
Territorio* japon = risk->getTerritorio("asia", "japon");
Territorio* kamchatka = risk->getTerritorio("asia", "kamchatka");
Territorio* medioOriente = risk->getTerritorio("asia", "medio oriente");
Territorio* mongolia = risk->getTerritorio("asia", "mongolia");
Territorio* siam = risk->getTerritorio("asia", "siam");
Territorio* siberia = risk->getTerritorio("asia", "siberia");
Territorio* ural = risk->getTerritorio("asia", "ural");
Territorio* yakutsk = risk->getTerritorio("asia", "yakutsk");
Territorio* afghanistan = risk->getTerritorio("asia", "afghanistan");
//cout<<"entre inicalizar"<<std::endl;

// América del Norte
alaska->setTerritoriosColindantes(alberta);
alberta->setTerritoriosColindantes(alaska);
/*
alaska->setTerritoriosColindantes(territorioNoroccidental);
alaska->setTerritoriosColindantes(kamchatka);

alberta->setTerritoriosColindantes(territorioNoroccidental);
alberta->setTerritoriosColindantes(estadosUnidosOccidentales);

alberta->setTerritoriosColindantes(ontario);

americaCentral->setTerritoriosColindantes(estadosUnidosOrientales);
americaCentral->setTerritoriosColindantes(estadosUnidosOccidentales);
americaCentral->setTerritoriosColindantes(ontario);

estadosUnidosOrientales->setTerritoriosColindantes(ontario);
estadosUnidosOrientales->setTerritoriosColindantes(quebec);
estadosUnidosOrientales->setTerritoriosColindantes(americaCentral);

groenlandia->setTerritoriosColindantes(quebec);
groenlandia->setTerritoriosColindantes(territorioNoroccidental);
groenlandia->setTerritoriosColindantes(ontario);
groenlandia->setTerritoriosColindantes(islandia);

territorioNoroccidental->setTerritoriosColindantes(alaska);
territorioNoroccidental->setTerritoriosColindantes(alberta);
territorioNoroccidental->setTerritoriosColindantes(ontario);
territorioNoroccidental->setTerritoriosColindantes(groenlandia);

ontario->setTerritoriosColindantes(alberta);
ontario->setTerritoriosColindantes(quebec);
ontario->setTerritoriosColindantes(groenlandia);
ontario->setTerritoriosColindantes(estadosUnidosOccidentales);
ontario->setTerritoriosColindantes(estadosUnidosOrientales);
ontario->setTerritoriosColindantes(territorioNoroccidental);

quebec->setTerritoriosColindantes(ontario);
quebec->setTerritoriosColindantes(estadosUnidosOrientales);
quebec->setTerritoriosColindantes(groenlandia);

estadosUnidosOccidentales->setTerritoriosColindantes(alberta);
estadosUnidosOccidentales->setTerritoriosColindantes(ontario);
estadosUnidosOccidentales->setTerritoriosColindantes(estadosUnidosOrientales);

// Europa
granBretana->setTerritoriosColindantes(islandia);
granBretana->setTerritoriosColindantes(escandinavia);
granBretana->setTerritoriosColindantes(europaDelNorte);
granBretana->setTerritoriosColindantes(europaOccidental);

islandia->setTerritoriosColindantes(groenlandia);
islandia->setTerritoriosColindantes(escandinavia);
islandia->setTerritoriosColindantes(granBretana);

europaDelNorte->setTerritoriosColindantes(europaDelSur);
europaDelNorte->setTerritoriosColindantes(ucrania);
europaDelNorte->setTerritoriosColindantes(escandinavia);
europaDelNorte->setTerritoriosColindantes(europaOccidental);
europaDelNorte->setTerritoriosColindantes(granBretana);

escandinavia->setTerritoriosColindantes(ucrania);
escandinavia->setTerritoriosColindantes(europaDelNorte);
escandinavia->setTerritoriosColindantes(granBretana);
escandinavia->setTerritoriosColindantes(islandia);

europaDelSur->setTerritoriosColindantes(europaDelNorte);
europaDelSur->setTerritoriosColindantes(ucrania);
europaDelSur->setTerritoriosColindantes(europaOccidental);
europaDelSur->setTerritoriosColindantes(medioOriente);
europaDelSur->setTerritoriosColindantes(egipto);
europaDelSur->setTerritoriosColindantes(africaDelNorte);

ucrania->setTerritoriosColindantes(ural);
ucrania->setTerritoriosColindantes(afghanistan);
ucrania->setTerritoriosColindantes(medioOriente);
ucrania->setTerritoriosColindantes(escandinavia);
ucrania->setTerritoriosColindantes(europaDelNorte);
ucrania->setTerritoriosColindantes(europaDelSur);

europaOccidental->setTerritoriosColindantes(europaDelSur);
europaOccidental->setTerritoriosColindantes(europaDelNorte);
europaOccidental->setTerritoriosColindantes(granBretana);
europaOccidental->setTerritoriosColindantes(africaDelNorte);

// América del Sur
brasil->setTerritoriosColindantes(africaDelNorte);
brasil->setTerritoriosColindantes(argentina);
brasil->setTerritoriosColindantes(colombia);
brasil->setTerritoriosColindantes(congo);

colombia->setTerritoriosColindantes(americaCentral);
colombia->setTerritoriosColindantes(brasil);
colombia->setTerritoriosColindantes(peru);

peru->setTerritoriosColindantes(colombia);
peru->setTerritoriosColindantes(brasil);
peru->setTerritoriosColindantes(argentina);

argentina->setTerritoriosColindantes(brasil);
argentina->setTerritoriosColindantes(peru);

// África
africaOriental->setTerritoriosColindantes(egipto);
africaOriental->setTerritoriosColindantes(africaDelNorte);
africaOriental->setTerritoriosColindantes(congo);
africaOriental->setTerritoriosColindantes(africaDelSur);
africaOriental->setTerritoriosColindantes(madagascar);
africaOriental->setTerritoriosColindantes(medioOriente);

egipto->setTerritoriosColindantes(europaDelSur);
egipto->setTerritoriosColindantes(medioOriente);
egipto->setTerritoriosColindantes(africaOriental);
egipto->setTerritoriosColindantes(africaDelNorte);

madagascar->setTerritoriosColindantes(africaOriental);
madagascar->setTerritoriosColindantes(africaDelSur);

africaDelNorte->setTerritoriosColindantes(egipto);
africaDelNorte->setTerritoriosColindantes(africaOriental);
africaDelNorte->setTerritoriosColindantes(europaOccidental);
africaDelNorte->setTerritoriosColindantes(brasil);
africaDelNorte->setTerritoriosColindantes(congo);

africaDelSur->setTerritoriosColindantes(congo);
africaDelSur->setTerritoriosColindantes(madagascar);
africaDelSur->setTerritoriosColindantes(africaOriental);

congo->setTerritoriosColindantes(africaOriental);
congo->setTerritoriosColindantes(africaDelNorte);
congo->setTerritoriosColindantes(africaDelSur);

// Oceanía
indonesia->setTerritoriosColindantes(siam);
indonesia->setTerritoriosColindantes(nuevaGuinea);
indonesia->setTerritoriosColindantes(australiaOccidental);

nuevaGuinea->setTerritoriosColindantes(indonesia);
nuevaGuinea->setTerritoriosColindantes(australiaOccidental);
nuevaGuinea->setTerritoriosColindantes(australiaOriental);

australiaOccidental->setTerritoriosColindantes(nuevaGuinea);
australiaOccidental->setTerritoriosColindantes(australiaOriental);
australiaOccidental->setTerritoriosColindantes(indonesia);

australiaOriental->setTerritoriosColindantes(australiaOccidental);
australiaOriental->setTerritoriosColindantes(nuevaGuinea);

// Continente de Asia
china->setTerritoriosColindantes(ural);
china->setTerritoriosColindantes(siberia);
china->setTerritoriosColindantes(mongolia);
china->setTerritoriosColindantes(india);
china->setTerritoriosColindantes(siam);
china->setTerritoriosColindantes(afghanistan);

india->setTerritoriosColindantes(china);
india->setTerritoriosColindantes(siam);
india->setTerritoriosColindantes(afghanistan);
india->setTerritoriosColindantes(medioOriente);

irkutsk->setTerritoriosColindantes(siberia);
irkutsk->setTerritoriosColindantes(mongolia);
irkutsk->setTerritoriosColindantes(yakutsk);
irkutsk->setTerritoriosColindantes(kamchatka);

japon->setTerritoriosColindantes(mongolia);
japon->setTerritoriosColindantes(irkutsk);
japon->setTerritoriosColindantes(kamchatka);

kamchatka->setTerritoriosColindantes(yakutsk);
kamchatka->setTerritoriosColindantes(irkutsk);
kamchatka->setTerritoriosColindantes(mongolia);
kamchatka->setTerritoriosColindantes(japon);
kamchatka->setTerritoriosColindantes(alaska);

medioOriente->setTerritoriosColindantes(ucrania);
medioOriente->setTerritoriosColindantes(afghanistan);
medioOriente->setTerritoriosColindantes(egipto);
medioOriente->setTerritoriosColindantes(africaOriental);
medioOriente->setTerritoriosColindantes(europaDelSur);
medioOriente->setTerritoriosColindantes(india);

mongolia->setTerritoriosColindantes(japon);
mongolia->setTerritoriosColindantes(kamchatka);
mongolia->setTerritoriosColindantes(irkutsk);
mongolia->setTerritoriosColindantes(siberia);
mongolia->setTerritoriosColindantes(china);

siam->setTerritoriosColindantes(china);
siam->setTerritoriosColindantes(india);
siam->setTerritoriosColindantes(indonesia);

siberia->setTerritoriosColindantes(irkutsk);
siberia->setTerritoriosColindantes(mongolia);
siberia->setTerritoriosColindantes(china);
siberia->setTerritoriosColindantes(ural);
siberia->setTerritoriosColindantes(yakutsk);

ural->setTerritoriosColindantes(siberia);
ural->setTerritoriosColindantes(china);
ural->setTerritoriosColindantes(afghanistan);
ural->setTerritoriosColindantes(ucrania);

yakutsk->setTerritoriosColindantes(kamchatka);
yakutsk->setTerritoriosColindantes(irkutsk);
yakutsk->setTerritoriosColindantes(siberia);

// Continente de África
congo->setTerritoriosColindantes(africaOriental);
congo->setTerritoriosColindantes(africaDelNorte);
congo->setTerritoriosColindantes(africaDelSur);

africaOriental->setTerritoriosColindantes(egipto);
africaOriental->setTerritoriosColindantes(africaDelNorte);
africaOriental->setTerritoriosColindantes(congo);
africaOriental->setTerritoriosColindantes(africaDelSur);
africaOriental->setTerritoriosColindantes(madagascar);
africaOriental->setTerritoriosColindantes(medioOriente);

egipto->setTerritoriosColindantes(europaDelSur);
egipto->setTerritoriosColindantes(medioOriente);
egipto->setTerritoriosColindantes(africaOriental);
egipto->setTerritoriosColindantes(africaDelNorte);

madagascar->setTerritoriosColindantes(africaOriental);
madagascar->setTerritoriosColindantes(africaDelSur);

africaDelNorte->setTerritoriosColindantes(egipto);
africaDelNorte->setTerritoriosColindantes(africaOriental);
africaDelNorte->setTerritoriosColindantes(europaOccidental);
africaDelNorte->setTerritoriosColindantes(brasil);
africaDelNorte->setTerritoriosColindantes(congo);

africaDelSur->setTerritoriosColindantes(congo);
africaDelSur->setTerritoriosColindantes(madagascar);
africaDelSur->setTerritoriosColindantes(africaOriental);

// Continente de Oceanía
australiaOriental->setTerritoriosColindantes(nuevaGuinea);
australiaOriental->setTerritoriosColindantes(australiaOccidental);

nuevaGuinea->setTerritoriosColindantes(indonesia);
nuevaGuinea->setTerritoriosColindantes(australiaOccidental);
nuevaGuinea->setTerritoriosColindantes(australiaOriental);

australiaOccidental->setTerritoriosColindantes(nuevaGuinea);
australiaOccidental->setTerritoriosColindantes(australiaOriental);
australiaOccidental->setTerritoriosColindantes(indonesia);
*/
}



void Risk::CrearCartasJuego() {
    std::vector<Carta> VecCartasTemp; //vector temporal que guardara todas las cartas para luego ingresarlas
    // a la cola

    // Creacion de todas las cartas del juego
    // Cartas para América del Norte
    Carta carta1("infanteria", "americaCentral");
    Carta carta2("caballeria", "estadosUnidosOrientales");
    Carta carta3("artilleria", "groenlandia");
    Carta carta4("infanteria", "territorioNoroccidental");
    Carta carta5("caballeria", "ontario");
    Carta carta6("artilleria", "quebec");
    Carta carta7("infanteria", "estadosUnidosOccidentales");
    Carta carta8("caballeria", "alaska");
    Carta carta9("artilleria", "alberta");

    // Cartas para Europa
    Carta carta10("infanteria", "islandia");
    Carta carta11("caballeria", "europaDelNorte");
    Carta carta12("artilleria", "escandinavia");
    Carta carta13("infanteria", "europaDelSur");
    Carta carta14("caballeria", "ucrania");
    Carta carta15("artilleria", "europaOccidental");
    Carta carta16("infanteria", "granBretana");

    // Cartas para América del Sur
    Carta carta17("infanteria", "brasil");
    Carta carta18("caballeria", "colombia");
    Carta carta19("artilleria", "peru");
    Carta carta20("infanteria", "argentina");

    // Cartas para África
    Carta carta21("infanteria", "africaOriental");
    Carta carta22("caballeria", "egipto");
    Carta carta23("artilleria", "madagascar");
    Carta carta24("infanteria", "africaDelNorte");
    Carta carta25("caballeria", "africaDelSur");
    Carta carta26("artilleria", "congo");

    // Cartas para Oceanía
    Carta carta27("infanteria", "indonesia");
    Carta carta28("caballeria", "nuevaGuinea");
    Carta carta29("artilleria", "australiaOccidental");
    Carta carta30("infanteria", "australiaOriental");

    // Cartas para Asia
    Carta carta31("infanteria", "china");
    Carta carta32("caballeria", "india");
    Carta carta33("artilleria", "irkutsk");
    Carta carta34("infanteria", "japon");
    Carta carta35("caballeria", "kamchatka");
    Carta carta36("artilleria", "medioOriente");
    Carta carta37("infanteria", "mongolia");
    Carta carta38("caballeria", "siam");
    Carta carta39("artilleria", "siberia");
    Carta carta40("infanteria", "ural");
    Carta carta41("caballeria", "yakutsk");
    Carta carta42("artilleria", "afghanistan");

// Agregar todas las cartas al vector
    VecCartasTemp.push_back(carta1);

    VecCartasTemp.push_back(carta2);
    VecCartasTemp.push_back(carta3);
    VecCartasTemp.push_back(carta4);
    VecCartasTemp.push_back(carta5);
    VecCartasTemp.push_back(carta6);
    VecCartasTemp.push_back(carta7);
    VecCartasTemp.push_back(carta8);
    VecCartasTemp.push_back(carta9);
    VecCartasTemp.push_back(carta10);
    VecCartasTemp.push_back(carta11);
    VecCartasTemp.push_back(carta12);
    VecCartasTemp.push_back(carta13);
    VecCartasTemp.push_back(carta14);
    VecCartasTemp.push_back(carta15);
    VecCartasTemp.push_back(carta16);
    VecCartasTemp.push_back(carta17);
    VecCartasTemp.push_back(carta18);
    VecCartasTemp.push_back(carta19);
    VecCartasTemp.push_back(carta20);
    VecCartasTemp.push_back(carta21);
    VecCartasTemp.push_back(carta22);
    VecCartasTemp.push_back(carta23);
    VecCartasTemp.push_back(carta24);
    VecCartasTemp.push_back(carta25);
    VecCartasTemp.push_back(carta26);
    VecCartasTemp.push_back(carta27);
    VecCartasTemp.push_back(carta28);
    VecCartasTemp.push_back(carta29);
    VecCartasTemp.push_back(carta30);
    VecCartasTemp.push_back(carta31);
    VecCartasTemp.push_back(carta32);
    VecCartasTemp.push_back(carta33);
    VecCartasTemp.push_back(carta34);
    VecCartasTemp.push_back(carta35);
    VecCartasTemp.push_back(carta36);
    VecCartasTemp.push_back(carta37);
    VecCartasTemp.push_back(carta38);
    VecCartasTemp.push_back(carta39);
    VecCartasTemp.push_back(carta40);
    VecCartasTemp.push_back(carta41);
    VecCartasTemp.push_back(carta42);

//  el vector tiene todas las cartas , sin embargo la idea es que el jugador agarre una carta
// aleatoria entonces se barajara la lista con la funcion shuffle.
    std::shuffle(VecCartasTemp.begin(), VecCartasTemp.end(), std::default_random_engine());
    // se pasa la lista revuelta a una cola para que los jugadores puedan sacar de a 1 carta facilmente
    // Pasar las cartas desde el vector a la cola
        for (Carta carta : VecCartasTemp) {
          this->Cartas.push(carta);
}
}
//
void Risk::AgregarFichasTropas(Jugador* jugador, int total) {
    
    while(total!=0){
      Ficha batallon(InicializarcolorJugador(), "infanteria");
    
    jugador->agregarFicha(batallon);
    total--;
  }


}
void Risk::setTerritorioaJugador(std::string nombreJugador,Territorio* nuevoTerritorio ){
for(int i =0; i<jugadores.size(); i++){
    if(jugadores[i].GetNombreJugador()==nombreJugador){
      jugadores[i].setTerritorio(nuevoTerritorio);
     
    }
  }
}

//aumenta la cantiad de turnos realizados, para poder avanzar al siguiente turno
//esta funcion reliza el avanzar en los jugadores mostradondo el nombre del jugador 




//retorna el nombre de un continente disponible 
std::string Risk::infoContinentes(){
  std::string retorno ="";
  int contador=0;
  for(int i=0; i<6; i++){
    if(continentes[i].getTerritoriosOcupados()!=continentes[i].GetcantidadTerritorios()){
      retorno+="\t"+std::to_string(contador+1)+". "+ continentes[i].GetNombreContinente()+"\n";
      contador++;
    }
  
  }
  return retorno;
}

//guarda en una variable los territorios de un continente
//si el nombre del continente no existe, retorna ""
std::string Risk::infoTerritorios(std::string nameContinente){
  std::string retorno ="";
  int qTerritorios =0, cont=0;
  
  for(int i=0; i<6; i++){
    if(continentes[i].GetNombreContinente()==nameContinente){
      
      qTerritorios = continentes[i].GetcantidadTerritorios();
      
      for(int terri=0; terri<qTerritorios; terri++){
        if(continentes[i].reclamado(terri)==""){
            retorno+="\t"+std::to_string(cont+1)+". "+continentes[i].getNombreTerritorio(terri)+"\n";
            cont++;
           }
        }
      i=6;
    }else retorno ="";
    
  }
  return retorno;
}
//retorna una cadena de caracteres con salida en pantalla donde se indican los continentes
//disponibles para consultar los territorios disponibles para conquistar.
bool Risk::estadoTerritorioLibre(std::string nameContinente, std::string nameTerritorio){
   for(int i=0; i<6; i++){
    if(continentes[i].GetNombreContinente()==nameContinente){
      return continentes[i].territorioValido(nameTerritorio);
    }
  }
  return false;
}

//recibo el nombre de un jugador y lo guardo en el vector de jugadores
void Risk::CrearJugador(std::string nombre, int qJugadores){

  int total = QTropasIniciales(qJugadores);
  Jugador aux(nombre, InicializarcolorJugador());
  Ficha batallon(InicializarcolorJugador(), "infanteria");
  //agrega qUnidades de infanteria al jugador
  while(total!=0){
    aux.agregarFicha(batallon);
    total--;
  }
  //guardo el jugador
  jugadores.push_back(aux);
  
}

//retorna el color que se le debe asignar a un jugador
std::string Risk::InicializarcolorJugador(){
  switch(jugadores.size()+1){
    case 1:return "verde";
    case 2:return "azul";
    case 3:return "rojo";
    case 4:return "amarillo"; 
    case 5:return "negro";
    case 6:return "gris";
  }
  return NULL;
}

//identifica las unidad ed de batallón inicial
int Risk::QTropasIniciales(int qJugadores){
  switch(qJugadores){
    case 3: return 35;
    case 4: return 30;
    case 5: return 25;
    case 6: return 20;
  }
    return -1;
}

//función de depuración 
std::string Risk::infoJug(){
  std::string retorno = "";

  retorno = jugadores[turnoActual].GetNombreJugador() + " : "+ std::to_string(jugadores[turnoActual].GetTotalFichas());
  return retorno;
}

//retorna el nombre del jugador en turno
std::string Risk::getNameJugadorEnTurno(){
  return jugadores[turnoActual].GetNombreJugador();
}

//retorna el color del juagdor en turno
std::string Risk::getColorJugadorEnTurno(){
  return jugadores[turnoActual].GetColor();
}
//retorna la cantidad de fichas que tiene el jugador en turno
int Risk::getFichasJugadorEnTurno(){
  return jugadores[turnoActual].GetTotalFichas();
}

void Risk::turnoJugado(){
  
  Jugador* aux=getJugador(this->getNameJugadorEnTurno());
  
  Carta card = this->Cartas.front();
  
  aux->agregarCarta(card);
  
  this->Cartas.pop();
  Totalturnos+=1;
  turnoActual=Totalturnos%jugadores.size();
  
}




//mueve una cantidad de fichas de un jugador a un territorio de un continente en especifico
//y permite ocupar ese territorio por el jugador
bool Risk::moverFichasDisponiblesNuevoTerritorio(int qFichas, std::string continente, std::string territorio){
  int iContinente = indiceContinente( continente);
  int iTerritorio = indiceTerritorio(iContinente, territorio);

  if(jugadores[turnoActual].GetTotalFichas()>=qFichas){
    for(int i=0; i<qFichas; i++){
      continentes[iContinente].ocuparTerritorio(jugadores[turnoActual].moverFicha(), iTerritorio, jugadores[turnoActual].GetNombreJugador() );
   }
    return true;
  }else
    return false;
 
}

//busca en el vector de continentes el indice de un continente 
int Risk::indiceContinente(std::string continente){
  for(int i=0; i<continentes.size(); i++){
    if(continentes[i].GetNombreContinente()==continente)
      return i;
  }
  return -1;
}

//busca en el vector de territorio todos los indices
int Risk::indiceTerritorio(int iContinente, std::string territorio){
  for(int i=0; i<continentes[iContinente].GetcantidadTerritorios(); i++){
    if(continentes[iContinente].getNombreTerritorio(i)==territorio){
        return i;
    }    
  }
  return -1;
}

//indica si todos los territorios de todos los continentes han sido ocupados
bool Risk::ExistenterritoriosLibres(){
  int qContiOcupados=0;
  for(int i=0; i<continentes.size(); i++){
    if(continentes[i].getTerritoriosOcupados()==continentes[i].GetcantidadTerritorios())
      qContiOcupados++;
  }

  if(qContiOcupados==continentes.size())
    return false;
  return true;
 }

//retorna una cadena de caracteres con la salida a la pantalla de los territorios que le pertenecen al usuairo en turno
//usada para mostrar en fortificar y decirle al usuario cuales son los territorios con la cantidad de fichas que tiene en cada uno

std::string Risk::buscarterritoriosJugador(){
  std::string retorno="";
  int contador =0;

  for(int i=0; i<continentes.size(); i++){
    for(int terri=0; terri<continentes[i].GetcantidadTerritorios(); terri++){
      if(continentes[i].reclamado(terri)==jugadores[turnoActual].GetNombreJugador()){
        retorno+=std::to_string(contador+1)+". "+continentes[i].getNombreTerritorio(terri)+ " - F: "+std::to_string(continentes[i].getFichasEnTerritorio(terri))+"\n";
        contador++;
     }
    }
  }
  return retorno;
}

Jugador* Risk::territorioPerteneceAJugador(Territorio* territorio) {
    for (Jugador& jugador : jugadores) {
        for (Territorio* t : jugador.GetTerritorios()) {
            if (t == territorio) {
                return &jugador;
            }
        }
    }
    return nullptr;
}


//busca y regresa el nombre del contiente del territorio que ingresó el usuario
//usada en reforzar para poder validar el continente al cual pertecene el territorio y usar
//la función declarada en Risk::moverFichasJugadory validar despúes que el territorio de ese continente
//le pertenece al jugador en turno.
std::string Risk::buscarContinenteTerritorio(std::string territorio){
  for(int conti=0; conti<continentes.size(); conti++){

    for(int terri=0; terri<continentes[conti].GetcantidadTerritorios(); terri++){

      if(continentes[conti].getNombreTerritorio(terri)==territorio)
        return continentes[conti].GetNombreContinente();
    }

  }
  return "";
}

//revisa que el territorio ingresado corresponda al jugador que se encuentra en turno
//usada en reforzar para que solo pueda ingresar el nombre de un territorio que le pertenece al jugador que está reforzando 
bool Risk::EsterritorioJugador(std::string continente, std::string territorio){
  int conti = indiceContinente(continente);
  int iTerritorio = indiceTerritorio(conti, territorio);

  if(continentes[conti].reclamado(iTerritorio)==jugadores[turnoActual].GetNombreJugador())
    return true;
  return false;
}


//compara con los jugadores de la partida el nombre ingresado 
//retorna true, cuando el nombre ingresado es el mismo del jugador actual
bool Risk::esTurnoJugador(std::string nombreIngresado){
  for(int i =0; i<jugadores.size(); i++){
    if(jugadores[i].GetNombreJugador()==nombreIngresado){
      if(jugadores[turnoActual].GetNombreJugador()==nombreIngresado)
      return true;
    }
  }
  return false;
}

//busca los nombres de los jugadores y retorna true cuando el nombre del jugador existe
//en la partida actual
bool Risk::jugadorExiste(std::string nombreIngresado){
  for(int i=0; i<jugadores.size(); i++){
    if(jugadores[i].GetNombreJugador()== nombreIngresado)
      return true;
  }
  return false;
}


Territorio* Risk::getTerritorio(std::string nombreContinente, std::string nombreTerritorio) {
    for (Continente& continente : continentes) {
        if (continente.GetNombreContinente() == nombreContinente) {
           return continente.buscarTerritorio(nombreTerritorio);
       
        }

    }
    return nullptr;
}
Jugador* Risk::getJugador(std::string nombreJugador) {
    for (Jugador& jugador : jugadores) {
        if (jugador.GetNombreJugador() == nombreJugador) {
            return &jugador;
        }
    }
    return NULL;
}


// Getter
int Risk::getGrupo_de_Cartas() {
    return Grupo_de_Cartas;
}

// Setter
void Risk::setGrupo_de_Cartas(int valor) {
    Grupo_de_Cartas = valor;
}


int Risk::CantidadNuevasFICHASTropasxTurno(Jugador* jugador) {
    int nuevasUnidades = 10;
    int territoriosOcupados = jugador->contarTerritorios();
    int continentesOcupados = 0;
    int cartasIntercambiadas = 0;
    int cartasTerritoriosOcupados = 0;
    std::vector<Carta> cartasJugador = jugador->GetCartas();
    int cantidadCartas = cartasJugador.size();

    // Obtener unidades por territorios
    nuevasUnidades += territoriosOcupados / 3;

    // Obtener unidades por continentes
    for (int i = 0; i < continentes.size(); i++) {
        bool continenteOcupado = true;
        std::vector<Territorio> territoriosContinente = continentes[i].GetTerritorios();
        for (int j = 0; j < territoriosContinente.size(); j++) {
            if (!territoriosContinente[j].EsFichadeJugador(jugador->GetColor())) {
                continenteOcupado = false;
                break;
            }
        }
        if (continenteOcupado) {
            if (continentes[i].GetNombreContinente() == "America del Sur" || continentes[i].GetNombreContinente() == "Australia") {
                nuevasUnidades += 2;
            } else if (continentes[i].GetNombreContinente() == "Africa") {
                nuevasUnidades += 3;
            } else if (continentes[i].GetNombreContinente() == "America del Norte" || continentes[i].GetNombreContinente() == "Europa") {
                nuevasUnidades += 5;
            } else if (continentes[i].GetNombreContinente() == "Asia") {
                nuevasUnidades += 7;
            }
            continentesOcupados++;
        }
    }


    // Obtener unidades por cartas
    if (cantidadCartas >= 3) {
        int infanteria = 0;
        int caballeria = 0;
        int artilleria = 0;
        int comodin = 0;
         std::vector<Carta> cartasUtilizadas; // Para almacenar las cartas utilizadas en los tríos
   

        for (int i = 0; i < cantidadCartas; i++) {
            std::string tipoCarta = cartasJugador[i].obtenerTipoCarta();
            if (tipoCarta == "Infantería") {
                infanteria++;
            } else if (tipoCarta == "Caballería") {
                caballeria++;
            } else if (tipoCarta == "Artillería") {
                artilleria++;
            } else if (tipoCarta == "Comodín") {
                comodin++;
            }
          cartasUtilizadas.push_back(cartasJugador[i]);
 
        }
        

        //calcula la cantidad de cartas extra dependiendo del grupo de cartas en el que estemos 
          int unidadesAdicionales = 4 + (Grupo_de_Cartas - 1) * 2;
      if (Grupo_de_Cartas > 6) {
          unidadesAdicionales += (Grupo_de_Cartas - 6) * 5;
      }

      // Verificar los tríos y eliminar las cartas utilizadas
    std::queue<Carta> cartasUtilizadasQueue; // Cola para almacenar las cartas utilizadas en los tríos
    if (infanteria >= 3 || caballeria >= 3 || artilleria >= 3) {
        nuevasUnidades += unidadesAdicionales;
        // Agregar las cartas utilizadas a la cola
        for (int i = 0; i < cartasUtilizadas.size(); i++) {
            cartasUtilizadasQueue.push(cartasUtilizadas[i]);
        }
    } else if ((infanteria >= 1 && caballeria >= 1 && artilleria >= 1) || (infanteria >= 2 || caballeria >= 2 || artilleria >= 2)) {
        if (comodin >= 1) {
            nuevasUnidades += unidadesAdicionales;
            // Agregar las cartas utilizadas a la cola
            for (int i = 0; i < cartasUtilizadas.size(); i++) {
                cartasUtilizadasQueue.push(cartasUtilizadas[i]);
            }
        }
    }


    std::queue<Carta> cartasTemporales;

// Guardar toda la información en el nuevo queue
while (!cartasUtilizadasQueue.empty()) {
    Carta cartaActual = cartasUtilizadasQueue.front();
    cartasUtilizadasQueue.pop();
    cartasTemporales.push(cartaActual);
}

    //hace la comprobacion de un territorio jugador con el territorio de la carta
while (!cartasTemporales.empty()) {
    Carta cartaActual = cartasTemporales.front();
    cartasTemporales.pop();
    bool territorioEnJugador = false;
    const std::vector<Territorio*>& territoriosJugador = jugador->GetTerritorios();
    for (int j = 0; j < territoriosJugador.size(); j++) {
        if (territoriosJugador[j]->getNombre() == cartaActual .obtenerTerritorio()) {
            territorioEnJugador = true;
            break;
        }
    }
    if (territorioEnJugador) {
        cartasTerritoriosOcupados++;
    }
}


      //agrega las cartas extra dependiendo de las cartas utilizadas que pertenexcan a un territorio que el jugador posee
        nuevasUnidades += cartasTerritoriosOcupados * 2;

// Eliminar las cartas utilizadas del jugador
    while (!cartasUtilizadasQueue.empty()) {
         Carta cartaUtilizada = cartasUtilizadasQueue.front();
        for (int i = 0; i < cartasJugador.size(); i++) {
            if (cartasJugador[i].obtenerTerritorio() == cartaUtilizada.obtenerTerritorio() &&
        cartasJugador[i].obtenerTerritorio() == cartaUtilizada.obtenerTerritorio()) {
                cartasJugador.erase(cartasJugador.begin() + i);
                cantidadCartas--;
                break;
            }
        }
        cartasUtilizadasQueue.pop();
    }




    }
    

    return nuevasUnidades;
}

std::string Risk::buscarterritoriosColindantes(std::string nombreTerritorio) {
  std::string retorno = "";
 // int i=0;
  Territorio* territorio = nullptr;

  // Buscar el territorio por su nombre
  for (Continente& continente : continentes) {
    territorio = continente.buscarTerritorio(nombreTerritorio);
    if (territorio != nullptr) {
      //i++;
      //std::cout<<i<<". "<<territorio->getNombre()<<std::endl;
      break;
    }
  }


  if (territorio != nullptr) {
      int contador = 0;
    for (int i = 0; i < territorio->getTerritoriosColindantes().size(); i++) {
     Territorio* colindante = territorio->getTerritoriosColindantes()[i];
      if(territorio->getReclamado()!=colindante->getReclamado()){
      
      int Nu_FichasJugador = colindante->GetQFichas();
      //std::cout<<"numero de fichas jugador contrincancte"<<Nu_FichasJugador <<territorioPerteneceAJugador(colindante)->obtenerNombreJugador()<<std::endl;
      retorno += std::to_string(contador + 1) + ". " + colindante->getNombre() + " - FichasContrincante: " + std::to_string(Nu_FichasJugador) + "\n";
      contador++;
      }
    }
  }

  return retorno;
}



std::string Risk::OperacionesDADOSAtaque(std::string Territorioatacante, std::string TerritorioDefensor) {
    std::string resultado;
    bool continuar = true;
    
    // Obtener el jugador atacante y el jugador defensor
    Jugador* atacante = &jugadores[turnoActual];
    Continente* continenteD = getContinentedelPais(TerritorioDefensor);
    Territorio* territorioD = getTerritorio(continenteD->GetNombreContinente(), TerritorioDefensor);
    Jugador* defensor = territorioPerteneceAJugador(territorioD);

    // Para revisar que el jugador no se vaya a atacar a sí mismo
    for (Jugador& jugador : jugadores) {
        if (jugador.GetNombreJugador() == atacante->GetNombreJugador()) {
            continuar = false;
        }
    }

    // Lanzar los dados para el atacante y el defensor
    std::vector<int> dadosAtacante;
    std::vector<int> dadosDefensor;
    resultado += "Dados de " + atacante->GetNombreJugador() + ": ";
    for (int i = 0; i < 3; i++) {
        int dadoA = lanzarDado();
        resultado += std::to_string(dadoA) + ", ";
        dadosAtacante.push_back(dadoA);
    }
    resultado += "\n";
    resultado += "Dados de " + defensor->GetNombreJugador() + ": ";
    for (int i = 0; i < 2; i++) {
        int dadoD = lanzarDado();
        resultado += std::to_string(dadoD) + ", ";
        dadosDefensor.push_back(dadoD);
    }
    resultado += "\n";

    // Ordenar los dados de mayor a menor
    for (int i = 0; i < dadosAtacante.size() - 1; i++) {
        for (int j = 0; j < dadosAtacante.size() - i - 1; j++) {
            if (dadosAtacante[j] < dadosAtacante[j + 1]) {
                std::swap(dadosAtacante[j], dadosAtacante[j + 1]);
            }
        }
    }
    for (int i = 0; i < dadosDefensor.size() - 1; i++) {
        for (int j = 0; j < dadosDefensor.size() - i - 1; j++) {
            if (dadosDefensor[j] < dadosDefensor[j + 1]) {
                std::swap(dadosDefensor[j], dadosDefensor[j + 1]);
            }
        }
    }

    // Comparar los dados y determinar el resultado del ataque
    // numDados: indica el valor mínimo entre la cantidad de dados
    int numDados = dadosAtacante.size() < dadosDefensor.size() ? dadosAtacante.size() : dadosDefensor.size();
    int unidadesPerdidasAtacante = 0;
    int unidadesPerdidasDefensor = 0;
    for (int i = 0; i < numDados; i++) {
        if (dadosAtacante[i] >= dadosDefensor[i]) {
            unidadesPerdidasDefensor++;
        } else {
            unidadesPerdidasAtacante++;
        }
    }

    // Actualizar las unidades de ejército de cada jugador
    atacante->restarUnidades(unidadesPerdidasAtacante, Territorioatacante);
    defensor->restarUnidades(unidadesPerdidasDefensor, TerritorioDefensor);
    
    Continente* continenteA = getContinentedelPais(Territorioatacante);
    Territorio* territorioA = getTerritorio(continenteA->GetNombreContinente(), Territorioatacante);
    
    resultado += "\n" + defensor->GetNombreJugador() + " perdio: " + std::to_string(unidadesPerdidasDefensor) + " fichas\n";
    resultado += territorioD->getNombre() + " - F: " + std::to_string(territorioD->GetQFichas()) + "\n";
    resultado += atacante->GetNombreJugador() + " perdio: " + std::to_string(unidadesPerdidasAtacante) + " fichas\n";
    resultado += territorioA->getNombre() + " - F: " + std::to_string(territorioA->GetQFichas()) + "\n";

    return resultado;
}


void Risk::EvaluarConquistaTerritorio(std::string Territorioatacante, std::string TerritorioDefensor){


//territorio del que esta siendo atacado
Continente* continenteD = getContinentedelPais(TerritorioDefensor);
  Territorio* territorioD =getTerritorio (continenteD->GetNombreContinente(),TerritorioDefensor);
    Jugador* defensor = territorioPerteneceAJugador(territorioD);

//Territorio que esta atacadndo
Continente* continenteA = getContinentedelPais(Territorioatacante);
Territorio* territorioA = getTerritorio (continenteA->GetNombreContinente(),Territorioatacante);
Jugador* atacante = territorioPerteneceAJugador(territorioA);

//comparar si el territorio que esta siendo atacado tiene 0 fichas ->moverlo a otro jugador

if(territorioD->GetQFichas()==0){
  int cantidad=0;
  system("cls");
 do{
  std::cout<<"HAS CONQUISTADO "<<territorioD->getNombre()<<std::endl;
std::cout<<"\ncuantas fichas deseas mover a: "<<territorioD->getNombre()<<std::endl;
std::cin>>cantidad;

 }while(cantidad<=0 || (territorioA->GetQFichas())-1<cantidad);

std::string movimientofichas=ConquistarTerritorio( territorioA,territorioD,atacante,defensor,cantidad);
std::cout<<movimientofichas<<std::endl;
}




}


std::string Risk::ConquistarTerritorio(Territorio* territorioOrigen, Territorio* territorioConquistado, Jugador* jugadorEnTurno,Jugador* jugadorDerrotado, int cantidadFichas) {
    std::string resultado;
    

   
    // Verificar si el territorio esta disponible
    if (territorioPerteneceAJugador(territorioOrigen) != territorioPerteneceAJugador(territorioConquistado)) {

        // Verificar si el territorio de origen tiene suficientes fichas
        
        if (territorioOrigen->GetQFichas() >= cantidadFichas) {
         
           setTerritorioaJugador(jugadorEnTurno->GetNombreJugador(),territorioConquistado);
           territorioConquistado->setReclamar(jugadorEnTurno->GetNombreJugador());
           jugadorDerrotado->eliminarTerritorio(territorioConquistado);
            // Mover las fichas del territorio de origen al territorio de destino
            for (int i = 0; i < cantidadFichas; i++) {
                Ficha ficha = territorioOrigen->GetFicha(jugadorEnTurno->GetNombreJugador());
                territorioConquistado->addFicha(ficha);
            }
           
             territorioOrigen->restarFichas(cantidadFichas);

            // Agregar mensaje de éxito al resultado
            resultado += "Se han movido " + std::to_string(cantidadFichas) + " fichas del territorio " + territorioOrigen->getNombre() + " al territorio " + territorioConquistado->getNombre() + ".\n";
        } else {
            // Agregar mensaje de error al resultado
            resultado += "El territorio de origen no tiene suficientes fichas.\n";
        }
    } else {
        // Agregar mensaje de error al resultado
        resultado += "Los territorios no pertenecen al mismo jugador.\n";
    }
    
    // Agregar lista actualizada de territorios del jugador al resultado
    resultado += buscarterritoriosJugador() + "\n";
    
    return resultado;
}

Continente* Risk::getContinentedelPais(std::string nombreTerritorio) {
    for (int i = 0; i < continentes.size(); ++i) {
        for (int j = 0; j < continentes[i].GetTerritorios().size(); ++j) {
            if (continentes[i].GetTerritorios()[j].getNombre() == nombreTerritorio) {
                return &(continentes[i]);
            }
        }
    }
    return nullptr; // Si no se encuentra el continente
}

std::vector<Continente*> Risk::getContinentes() {
    std::vector<Continente*> listaContinentes;
    for (Continente& continente : continentes) {
        listaContinentes.push_back(&continente);
    }
    return listaContinentes;
}