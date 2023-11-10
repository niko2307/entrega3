#ifndef _RISK_H
#define _RISK_H

#include <vector>
#include <queue>
#include<stdlib.h>
#include <string>
#include "Jugador.h"
#include "Carta.h"
#include "Continente.h"
#include "Ficha.h"

class Risk {
public:
    // Partida
    Risk();
    void iniciarPartida();
    bool estadoPartida();
    bool evaluarexistenciaGanador();

    //crear/inicializar
    void crearContinente();
    void InicializarTerritoriosColindantes(Risk* risk);
    
    void CrearCartasJuego();
    void CrearJugador(std::string nombre, int qJugadores);
    int QTropasIniciales(int qJugadores);

    std::string InicializarcolorJugador();

   //estado vvalor
    bool ExistenterritoriosLibres();
    void EvaluarConquistaTerritorio(std::string Territorioatacante, std::string TerritorioDefensor); //pendientemovermain
    bool estadoTerritorioLibre(std::string nameContinente, std::string nameTerritorio);
    bool EsterritorioJugador(std::string continente, std::string territorio);
    bool estadoGanador();
    bool esTurnoJugador(std::string nombreIngresado);
    bool jugadorExiste(std::string nombreIngresado);

    //atatcar
    std::string OperacionesDADOSAtaque(std::string Territorioatacante, std::string TerritorioDefensor);
   

    //MovimientoFichas
    int CantidadNuevasFICHASTropasxTurno(Jugador* jugador);
    bool moverFichasDisponiblesNuevoTerritorio(int qFichas, std::string continente, std::string territorio);
    void AgregarFichasTropas(Jugador *jugador, int total);
    
    //MovimientoTerritorios
    std::string ConquistarTerritorio(Territorio* territorioOrigen, Territorio* territorioDestino, Jugador* jugadorEnTurno,Jugador* jugadorDerrotado, int cantidadFichas);

    // Setters
    void setGrupo_de_Cartas(int valor); //No se usa
    void setTerritorioaJugador(std::string nombreIngresado, Territorio* nuevoTerritorio);
    

    // Funciones buscar de información
    
    std::string infoJug();
    std::string getNameJugadorEnTurno();
    std::string getColorJugadorEnTurno();
    int getFichasJugadorEnTurno();
    std::string buscarterritoriosJugador();
    std::string infoTerritorios(std::string nameContinente);
    std::string buscarterritoriosColindantes(std::string nombreTerritorio);
    std::string infoContinentes();
    std::string buscarContinenteTerritorio(std::string territorio);
    

    int indiceContinente(std::string continente);
    int indiceTerritorio(int iContinente, std::string territorio);

    //funciones de turnos
    void turnoJugado();
    void turnosEnCero();
    
    // Funciones de acceso a objetos (GETTERS)
    Territorio* getTerritorio(std::string nombreContinente, std::string nombreTerritorio);
    Jugador* getJugador(std::string nombreJugador);
    Jugador* territorioPerteneceAJugador(Territorio* territorio);
    Continente* getContinentedelPais(std::string nombreTerritorio);
    int getGrupo_de_Cartas();

    // Funciones extras
    int lanzarDado();

private:
    std::vector<Jugador> jugadores;
    std::queue<Carta> Cartas;
    std::vector<Continente> continentes;
    bool Partida;
    bool Ganador;
    int turnoActual;
    int Totalturnos;
    int Grupo_de_Cartas;
};

#endif // RISK_H
