#include "Risk.h"
#include "Territorio.h"
#include <iostream>
#include <random>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

Risk::Risk() {
  Partida=false;
  Ganador=false;
  turnoActual=0;
  Totalturnos=0;
}

int Risk::LanzarDado() {
    // Implementación para lanzar un dado y retornar el número aleatorio de 1 a 6
    // esto retorna unb numero de ese rango de aletorios 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 6);
    return distribution(gen);
}
//pone la bandera de partida en verdadero
void Risk::iniciarPartida() {
  Partida=true; 
}

bool Risk::estadoPartida(){
  return Partida;
}

void Risk::asignarGanador() {
    // Implementación para asignar un ganador y terminar la partida
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
Territorio* americaCentral = risk->buscarTerritorio("america del norte", "america central");
Territorio* estadosUnidosOrientales = risk->buscarTerritorio("america del norte", "estados unidos orientales");
Territorio* groenlandia = risk->buscarTerritorio("america del norte", "groenlandia");
Territorio* territorioNoroccidental = risk->buscarTerritorio("america del norte", "territorio noroccidental");
Territorio* ontario = risk->buscarTerritorio("america del norte", "ontario");
Territorio* quebec = risk->buscarTerritorio("america del norte", "quebec");
Territorio* estadosUnidosOccidentales = risk->buscarTerritorio("america del norte", "estados unidos occidentales");
Territorio* alaska = risk->buscarTerritorio("america del norte", "alaska");
Territorio* alberta = risk->buscarTerritorio("america del norte", "alberta");


// Continente de Europa
Territorio* islandia = risk->buscarTerritorio("europa", "islandia");
Territorio* europaDelNorte = risk->buscarTerritorio("europa", "europa del norte");
Territorio* escandinavia = risk->buscarTerritorio("europa", "escandinavia");
Territorio* europaDelSur = risk->buscarTerritorio("europa", "europa del sur");
Territorio* ucrania = risk->buscarTerritorio("europa", "ucrania");
Territorio* europaOccidental = risk->buscarTerritorio("europa", "europa occidental");
Territorio* granBretana = risk->buscarTerritorio("europa", "gran bretana");



// Continente de América del Sur
Territorio* brasil = risk->buscarTerritorio("america del sur", "brasil");
Territorio* colombia = risk->buscarTerritorio("america del sur", "colombia");
Territorio* peru = risk->buscarTerritorio("america del sur", "peru");
Territorio* argentina = risk->buscarTerritorio("america del sur", "argentina");


// Continente de África
Territorio* africaOriental = risk->buscarTerritorio("africa", "africa oriental");
Territorio* egipto = risk->buscarTerritorio("africa", "egipto");
Territorio* madagascar = risk->buscarTerritorio("africa", "madagascar");
Territorio* africaDelNorte = risk->buscarTerritorio("africa", "africa del norte");
Territorio* africaDelSur = risk->buscarTerritorio("africa", "africa del sur");
Territorio* congo = risk->buscarTerritorio("africa", "congo");


// Continente de Oceanía
Territorio* indonesia = risk->buscarTerritorio("australia", "indonesia");
Territorio* nuevaGuinea = risk->buscarTerritorio("australia", "nueva guinea");
Territorio* australiaOccidental = risk->buscarTerritorio("australia", "australia occidental");
Territorio* australiaOriental = risk->buscarTerritorio("australia", "australia oriental");

// Continente de Asia
Territorio* china = risk->buscarTerritorio("asia", "china");
Territorio* india = risk->buscarTerritorio("asia", "india");
Territorio* irkutsk = risk->buscarTerritorio("asia", "irkutsk");
Territorio* japon = risk->buscarTerritorio("asia", "japon");
Territorio* kamchatka = risk->buscarTerritorio("asia", "kamchatka");
Territorio* medioOriente = risk->buscarTerritorio("asia", "medio oriente");
Territorio* mongolia = risk->buscarTerritorio("asia", "mongolia");
Territorio* siam = risk->buscarTerritorio("asia", "siam");
Territorio* siberia = risk->buscarTerritorio("asia", "siberia");
Territorio* ural = risk->buscarTerritorio("asia", "ural");
Territorio* yakutsk = risk->buscarTerritorio("asia", "yakutsk");
Territorio* afghanistan = risk->buscarTerritorio("asia", "afghanistan");
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
        for (Carta& carta : VecCartasTemp) {
          this->Cartas.push(carta);
}
}
//
void Risk::AgregarTropas(Jugador* jugador, int total) {
    
    while(total!=0){
      Ficha batallon(colorJugador(), "infanteria");
    
    jugador->agregarFicha(batallon);
    total--;
  }


}
void Risk::agregarTerritorioaJugador(std::string nombreIngresado,Territorio* nuevoTerritorio ){
for(int i =0; i<jugadores.size(); i++){
    if(jugadores[i].obtenerNombreJugador()==nombreIngresado){
      jugadores[turnoActual].setTerritorio(nuevoTerritorio);
     
    }
  }
}

//aumenta la cantiad de turnos realizados, para poder avanzar al siguiente turno
//esta funcion reliza el avanzar en los jugadores mostradondo el nombre del jugador 




//retorna el nombre de un continente disponible 
std::string Risk::infoContinente(){
  std::string retorno ="";
  int contador=0;
  for(int i=0; i<6; i++){
    if(continentes[i].getTerritoriosOcupados()!=continentes[i].cantidadTerritorios()){
      retorno+="\t"+std::to_string(contador+1)+". "+ continentes[i].obtenerNombre()+"\n";
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
    if(continentes[i].obtenerNombre()==nameContinente){
      
      qTerritorios = continentes[i].cantidadTerritorios();
      
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
bool Risk::estadoTerritorio(std::string nameContinente, std::string nameTerritorio){
   for(int i=0; i<6; i++){
    if(continentes[i].obtenerNombre()==nameContinente){
      return continentes[i].territorioValido(nameTerritorio);
    }
  }
  return false;
}

//recibo el nombre de un jugador y lo guardo en el vector de jugadores
void Risk::CrearJugador(std::string nombre, int qJugadores){

  int total = qUnidades(qJugadores);
  Jugador aux(nombre, colorJugador());
  Ficha batallon(colorJugador(), "infanteria");
  //agrega qUnidades de infanteria al jugador
  while(total!=0){
    aux.agregarFicha(batallon);
    total--;
  }
  //guardo el jugador
  jugadores.push_back(aux);
  
}

//retorna el color que se le debe asignar a un jugador
std::string Risk::colorJugador(){
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
int Risk::qUnidades(int qJugadores){
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

  retorno = jugadores[turnoActual].obtenerNombreJugador() + " : "+ std::to_string(jugadores[turnoActual].obeterTotalFichas());
  return retorno;
}

//retorna el nombre del jugador en turno
std::string Risk::getNameJugadorEnTurno(){
  return jugadores[turnoActual].obtenerNombreJugador();
}

//retorna el color del juagdor en turno
std::string Risk::getColorJugadorEnTurno(){
  return jugadores[turnoActual].obtenerColor();
}
//retorna la cantidad de fichas que tiene el jugador en turno
int Risk::getFichasJugadorEnTurno(){
  return jugadores[turnoActual].obeterTotalFichas();
}

void Risk::turnoJugado(){
  Totalturnos+=1;
  turnoActual=Totalturnos%jugadores.size();
}
void Risk::turnoJugadoatacar(){
  this->getJugador(this->getNameJugadorEnTurno())->agregarCarta(this->Cartas.front());
  this->Cartas.pop();
  Totalturnos+=1;
  turnoActual=Totalturnos%jugadores.size();
  
}



//mueve una cantidad de fichas de un jugador a un territorio de un continente en especifico
//y permite ocupar ese territorio por el jugador
bool Risk::moverFichasJugador(int qFichas, std::string continente, std::string territorio){
  int iContinente = indiceContinente( continente);
  int iTerritorio = indiceTerritorio(iContinente, territorio);

  if(jugadores[turnoActual].obeterTotalFichas()>=qFichas){
    for(int i=0; i<qFichas; i++){
      continentes[iContinente].ocuparTerritorio(jugadores[turnoActual].moverFicha(), iTerritorio, jugadores[turnoActual].obtenerNombreJugador() );
   }
    return true;
  }else
    return false;
 
}

//busca en el vector de continentes el indice de un continente 
int Risk::indiceContinente(std::string continente){
  for(int i=0; i<continentes.size(); i++){
    if(continentes[i].obtenerNombre()==continente)
      return i;
  }
  return -1;
}

//busca en el vector de territorio todos los indices
int Risk::indiceTerritorio(int iContinente, std::string territorio){
  for(int i=0; i<continentes[iContinente].cantidadTerritorios(); i++){
    if(continentes[iContinente].getNombreTerritorio(i)==territorio){
        return i;
    }    
  }
  return -1;
}

//indica si todos los territorios de todos los continentes han sido ocupados
bool Risk::territoriosLibres(){
  int qContiOcupados=0;
  for(int i=0; i<continentes.size(); i++){
    if(continentes[i].getTerritoriosOcupados()==continentes[i].cantidadTerritorios())
      qContiOcupados++;
  }

  if(qContiOcupados==continentes.size())
    return false;
  return true;
 }

//retorna una cadena de caracteres con la salida a la pantalla de los territorios que le pertenecen al usuairo en turno
//usada para mostrar en fortificar y decirle al usuario cuales son los territorios con la cantidad de fichas que tiene en cada uno

std::string Risk::territoriosJugador(){
  std::string retorno="";
  int contador =0;

  for(int i=0; i<continentes.size(); i++){
    for(int terri=0; terri<continentes[i].cantidadTerritorios(); terri++){
      if(continentes[i].reclamado(terri)==jugadores[turnoActual].obtenerNombreJugador()){
        retorno+=std::to_string(contador+1)+". "+continentes[i].getNombreTerritorio(terri)+ " - F: "+std::to_string(continentes[i].getFichasEnTerritorio(terri))+"\n";
        contador++;
     }
    }
  }
  return retorno;
}

Jugador* Risk::territorioPerteneceAJugador(Territorio* territorio) {
    for (Jugador& jugador : jugadores) {
        for (Territorio* t : jugador.getTerritorios()) {
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

    for(int terri=0; terri<continentes[conti].cantidadTerritorios(); terri++){

      if(continentes[conti].getNombreTerritorio(terri)==territorio)
        return continentes[conti].obtenerNombre();
    }

  }
  return "";
}

//revisa que el territorio ingresado corresponda al jugador que se encuentra en turno
//usada en reforzar para que solo pueda ingresar el nombre de un territorio que le pertenece al jugador que está reforzando 
bool Risk::territorioJugador(std::string continente, std::string territorio){
  int conti = indiceContinente(continente);
  int iTerritorio = indiceTerritorio(conti, territorio);

  if(continentes[conti].reclamado(iTerritorio)==jugadores[turnoActual].obtenerNombreJugador())
    return true;
  return false;
}


//compara con los jugadores de la partida el nombre ingresado 
//retorna true, cuando el nombre ingresado es el mismo del jugador actual
bool Risk::esTurnoJugador(std::string nombreIngresado){
  for(int i =0; i<jugadores.size(); i++){
    if(jugadores[i].obtenerNombreJugador()==nombreIngresado){
      if(jugadores[turnoActual].obtenerNombreJugador()==nombreIngresado)
      return true;
    }
  }
  return false;
}

//busca los nombres de los jugadores y retorna true cuando el nombre del jugador existe
//en la partida actual
bool Risk::jugadorExiste(std::string nombreIngresado){
  for(int i=0; i<jugadores.size(); i++){
    if(jugadores[i].obtenerNombreJugador()== nombreIngresado)
      return true;
  }
  return false;
}


Territorio* Risk::buscarTerritorio(std::string nombreContinente, std::string nombreTerritorio) {
    for (Continente& continente : continentes) {
        if (continente.obtenerNombre() == nombreContinente) {
           return continente.buscarTerritorio(nombreTerritorio);
       
        }

    }
    return nullptr;
}
Jugador* Risk::getJugador(std::string nombreJugador) {
    for (Jugador& jugador : jugadores) {
        if (jugador.obtenerNombreJugador() == nombreJugador) {
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


int Risk::CantidadNuevasTropas(Jugador* jugador) {
    int nuevasUnidades = 10;
    int territoriosOcupados = jugador->contarTerritorios();
    int continentesOcupados = 0;
    int cartasIntercambiadas = 0;
    int cartasTerritoriosOcupados = 0;
    std::vector<Carta> cartasJugador = jugador->obtenerCartas();
    int cantidadCartas = cartasJugador.size();

    // Obtener unidades por territorios
    nuevasUnidades += territoriosOcupados / 3;

    // Obtener unidades por continentes
    for (int i = 0; i < continentes.size(); i++) {
        bool continenteOcupado = true;
        std::vector<Territorio> territoriosContinente = continentes[i].obtenerTerritorios();
        for (int j = 0; j < territoriosContinente.size(); j++) {
            if (!territoriosContinente[j].ChekFicha(jugador->obtenerColor())) {
                continenteOcupado = false;
                break;
            }
        }
        if (continenteOcupado) {
            if (continentes[i].obtenerNombre() == "America del Sur" || continentes[i].obtenerNombre() == "Australia") {
                nuevasUnidades += 2;
            } else if (continentes[i].obtenerNombre() == "Africa") {
                nuevasUnidades += 3;
            } else if (continentes[i].obtenerNombre() == "America del Norte" || continentes[i].obtenerNombre() == "Europa") {
                nuevasUnidades += 5;
            } else if (continentes[i].obtenerNombre() == "Asia") {
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
    const std::vector<Territorio*>& territoriosJugador = jugador->getTerritorios();
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

std::string Risk::territoriosColindantes(std::string nombreTerritorio) {
  std::string retorno = "";
  Territorio* territorio = nullptr;

  // Buscar el territorio por su nombre
  for (Continente& continente : continentes) {
    territorio = continente.buscarTerritorio(nombreTerritorio);
    if (territorio != nullptr) {
      
      std::cout<<"territorio"<<territorio->getNombre()<<std::endl;
      break;
    }
  }

  if (territorio != nullptr) {
      int contador = 0;
    for (int i = 0; i < territorio->getTerritoriosColindantes().size(); i++) {
      Territorio* colindante = territorio->getTerritoriosColindantes()[i];
      int Nu_FichasJugador = colindante->ContarFichas(territorioPerteneceAJugador(colindante)->obtenerColor());
      std::cout<<"numero de fichas jugador contrincancte"<<Nu_FichasJugador <<territorioPerteneceAJugador(colindante)->obtenerNombreJugador()<<std::endl;
      retorno += std::to_string(contador + 1) + ". " + colindante->getNombre() + " - FichasContrincante: " + std::to_string(Nu_FichasJugador) + "\n";
      contador++;
    }
  }

  return retorno;
}



void Risk::resultadoDADOSAtaque(std::string Territorioatacante, std::string TerritorioDefensor) {
    bool continuar = true;

    // Obtener el jugador atacante y el jugador defensor
    Jugador* atacante = &jugadores[turnoActual];
    Territorio* territorioD = buscarTerritorio ("america del norte",TerritorioDefensor);
    Jugador* defensor = territorioPerteneceAJugador(territorioD);
  

//para revisar que el jugador no se vaya a atacar a si mismo  
    for (Jugador& jugador : jugadores) {

        if (jugador.obtenerNombreJugador() == atacante->obtenerNombreJugador()) {
           continuar = false;
           
        }
    }

    // Lanzar los dados para el atacante y el defensor
    std::vector<int> dadosAtacante;
    std::vector<int> dadosDefensor;
    for (int i = 0; i < 3; i++) {
        dadosAtacante.push_back(LanzarDado());
    }
    for (int i = 0; i < 2; i++) {
        dadosDefensor.push_back(LanzarDado());
    }

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
int numDados = dadosAtacante.size() < dadosDefensor.size() ? dadosAtacante.size() : dadosDefensor.size();
int unidadesPerdidasAtacante = 0;
int unidadesPerdidasDefensor = 0;
std::cout<<"numerod dados:"<<numDados<<std::endl;
for (int i = 0; i < numDados; i++) {
    if (dadosAtacante[i] >= dadosDefensor[i]) {
        unidadesPerdidasDefensor++;
    } else {
        unidadesPerdidasAtacante++;
    }
}

    // Actualizar las unidades de ejército de cada jugador
    atacante->restarUnidades(unidadesPerdidasAtacante,Territorioatacante);
    defensor->restarUnidades(unidadesPerdidasDefensor,TerritorioDefensor);


    



}




