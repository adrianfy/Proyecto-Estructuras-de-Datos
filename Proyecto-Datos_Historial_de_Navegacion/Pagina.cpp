#include "Pagina.h"

Pagina::Pagina()
{
    this->url = "";
    this->marcaDeTiempo = new Hora();
}

Pagina::Pagina(std::string url)
{
    this->url = url;
    this->marcaDeTiempo = new Hora();
}


std::string Pagina::getUrl()
{
    return url;
}

std::string Pagina::toString()
{
    std::stringstream ss;
    ss << "URL: " << url;
    return ss.str();
}

std::string Pagina::mostrarEnHistorial()
{
    std::stringstream ss;

    // Extraer la parte principal de la URL eliminando "www." y ".com"
    std::string urlTitulo = url;

    // Eliminar "www." si está presente al principio
    std::string prefijo = "www.";
    if (urlTitulo.find(prefijo) == 0) {
        urlTitulo = urlTitulo.substr(prefijo.length());
    }

    // Eliminar ".com" si está presente al final
    std::string sufijo = ".com";
    if (urlTitulo.size() >= sufijo.size() &&
        urlTitulo.compare(urlTitulo.size() - sufijo.size(), sufijo.size(), sufijo) == 0) {
        urlTitulo = urlTitulo.substr(0, urlTitulo.size() - sufijo.size());
    }

    // Formatear la salida
    ss << "Hora: " << marcaDeTiempo->toString() << " | " << urlTitulo << " | " << url;

    return ss.str();
}

Pagina::~Pagina()
{
    delete marcaDeTiempo;
}