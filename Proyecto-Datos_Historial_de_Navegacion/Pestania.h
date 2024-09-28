#pragma once
#include <list>
#include <sstream>
#include "Historial.h"
#include "GestorMarcador.h"

class Pestania
{
private:
    Historial* historial;
    bool modoIncognito;
    Pagina* pagina;
    GestorMarcador* gestorMarcadores;

public:
    Pestania();
    Pestania(bool modoIncognito);

    Pagina* getPaginaActual();
    Historial* getHistorial();

    void navegar(Pagina* url);
    void retroceder();
    void avanzar();
    //void cambiarModoIncognito(bool incognito);
    bool esIncognito();

    std::string mostrarHistorial();
    std::string mostrarMarcadores();

    ~Pestania();
};