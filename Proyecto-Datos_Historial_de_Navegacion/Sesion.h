#pragma once
#include "GestorPestania.h"
#include "GestorMarcador.h"
#include <fstream>
#include <iostream>

class Sesion {
public:
    Sesion(){}
    ~Sesion(){}

    // Método para guardar la sesión en un archivo binario
    void guardarSesion(GestorPestania* gestorPestania, GestorMarcador* gestorMarcador) {
        std::ofstream archivo("sesion.bin", std::ios::binary);

        if (!archivo.is_open()) {
            std::cerr << "No se pudo abrir el archivo para guardar la sesión." << std::endl;
            return;
        }

        // Serializar GestorPestania y GestorMarcador
        gestorPestania->serializar(archivo);
        gestorMarcador->serializar(archivo);

        archivo.close();
        std::cout << "Sesión guardada exitosamente." << std::endl;
    }

    // Método para cargar la sesión desde un archivo binario
    void cargarSesion(GestorPestania* gestorPestania, GestorMarcador* gestorMarcador) {
        std::ifstream archivo("sesion.bin", std::ios::binary);

        if (!archivo.is_open()) {
            std::cerr << "No se pudo abrir el archivo para cargar la sesión." << std::endl;
            return;
        }

        // Deserializar GestorPestania y GestorMarcador
        gestorPestania->deserializar(archivo);
        gestorMarcador->deserializar(archivo);

        archivo.close();
        std::cout << "Sesión cargada exitosamente." << std::endl;
    }
};
