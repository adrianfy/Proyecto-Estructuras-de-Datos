#pragma once
#include <fstream>
#include <vector>
#include "Tab.h"
#include "Marcador.h"

class Sesion {
public:
    Sesion();
    ~Sesion();

    void guardarSesion(const std::vector<Tab*>& tabs, const std::vector<Marcador*>& marcadores, const std::string& archivo);
    void cargarSesion(std::vector<Tab*>& tabs, std::vector<Marcador*>& marcadores, const std::string& archivo);
};
