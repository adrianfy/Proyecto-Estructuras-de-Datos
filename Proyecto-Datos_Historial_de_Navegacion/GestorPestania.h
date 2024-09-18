#pragma once
#include "Pestania.h"
#include <list>
#include <iostream>

class GestorPestania
{
private:
    std::list<Pestania*> listaPestanias;
    std::list<Pestania*>::iterator pestaniaActual;

public:
    GestorPestania();

    void agregarPestania(Pestania* pestania);
    void cerrarPestania();
    void proximaPestania();
    void pestaniaAnterior();
    Pestania* getPestaniaActual();
    std::string mostrarTabs();

    ~GestorPestania();
};
