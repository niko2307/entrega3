#ifndef CARTA_H
#define CARTA_H

#include <string>

class Carta {
public:
    Carta(std::string tipoCarta, std::string territorio);
    std::string obtenerTipoCarta();
    void establecerTipoCarta(std::string nuevoTipo);

    std::string obtenerTerritorio();
    void establecerTerritorio(std::string nuevoTerritorio);

    std::string obtenerFicha();
    void establecerFicha(std::string nuevaFicha);

    std::string obtenerMision();
    void establecerMision(std::string nuevaMision);

private:
    std::string tipoCarta;
    std::string territorio;
    std::string ficha;
    std::string mision;


};

#endif 