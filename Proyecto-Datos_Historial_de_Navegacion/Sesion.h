#pragma once
#include "GestorPestania.h"
#include "GestorMarcador.h"
#include <fstream>
#include <iostream>

class Sesion {
public:
    Sesion() {}
    ~Sesion() {}

    // M�todo para guardar la sesi�n en un archivo binario
    void guardarSesion(GestorPestania* gestorPestania, GestorMarcador* gestorMarcador) {
        std::ofstream archivoMarcadores("marcadores.bin", std::ios::binary);
        std::ofstream archivoNavegador("navegador.bin", std::ios::binary);

        if (!archivoMarcadores.is_open()) {
            std::cerr << "No se pudo abrir el archivo para guardar la sesi�n." << std::endl;
            return;
        }
        // Serializar GestorPestania y GestorMarcador
        gestorMarcador->serializar(archivoMarcadores);


        if (!archivoNavegador.is_open()) {
            std::cerr << "No se pudo abrir el archivo para guardar la sesi�n." << std::endl;
            return;
        }
        // Serializar GestorPestania y GestorMarcador
        gestorPestania->serializar(archivoNavegador);

        archivoMarcadores.close();
        archivoNavegador.close();
        std::cout << "Sesi�n guardada exitosamente." << std::endl;
    }

    // M�todo para cargar la sesi�n desde un archivo binario
    void cargarSesion(GestorPestania* gestorPestania, GestorMarcador* gestorMarcador) {
        std::ifstream archivoMarcadores("marcadores.bin", std::ios::binary);
        std::ifstream archivoNavegador("navegador.bin", std::ios::binary);

        if (!archivoMarcadores.is_open() || !archivoNavegador.is_open()) {
            std::cerr << "No se pudo abrir el archivo para cargar la sesi�n." << std::endl;
            return;
        }

        // Deserializar GestorPestania y GestorMarcador
        gestorPestania->deserializar(archivoNavegador);
        gestorMarcador->deserializar(archivoMarcadores);

        archivoNavegador.close();
        archivoMarcadores.close();
        std::cout << "Sesi�n cargada exitosamente." << std::endl;
    }
};