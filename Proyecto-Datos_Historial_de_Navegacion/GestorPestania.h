#pragma once
#include "Pestania.h"
#include <list>
#include <iostream>
#include <fstream>

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
    std::list<Pestania*> getPestanias();

    std::string mostrarTabs();

    void serializar(std::ofstream& archivo);
    void deserializar(std::ifstream& archivo);


    ~GestorPestania();
};
