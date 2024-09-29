#include "Hora.h"

Hora::Hora()
{
    std::time_t t = std::time(0); // Obtener el tiempo actual
    std::tm now;
    localtime_s(&now, &t); // Usar localtime_s para Windows

    this->hora = now.tm_hour; // Obtener la hora
    this->minuto = now.tm_min; // Obtener los minutos
}

Hora::Hora(int hora, int minuto)
{
    this->hora = hora;
    this->minuto = minuto;
}

int Hora::getHora()
{
    return hora;
}

int Hora::getMinuto()
{
    return minuto;
}

void Hora::serializar(std::ofstream& archivo)
{
    archivo.write(reinterpret_cast<char*>(&hora), sizeof(hora));
    archivo.write(reinterpret_cast<char*>(&minuto), sizeof(minuto));
}

Hora* Hora::deserializar(std::ifstream& archivo)
{
    int hora, minuto;

    archivo.read(reinterpret_cast<char*>(&hora), sizeof(hora));
    archivo.read(reinterpret_cast<char*>(&minuto), sizeof(minuto));

    return new Hora(hora, minuto);
}

std::string Hora::toString()
{
    std::stringstream s;
    s << hora << ":" << minuto << " ";
    return s.str();
}

Hora::~Hora()
{
}