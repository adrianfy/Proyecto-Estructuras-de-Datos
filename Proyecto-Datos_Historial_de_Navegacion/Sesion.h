#pragma once
#include <fstream>

class Sesion {
public:
    Sesion();
    ~Sesion();

    void guardarSesion();
    void cargarSesion();
};
