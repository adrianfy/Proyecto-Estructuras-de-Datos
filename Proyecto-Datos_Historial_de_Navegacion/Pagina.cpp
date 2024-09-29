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

void Pagina::setUrl(std::string url)
{
    this->url = url;
}

void Pagina::setMarcaDeTiempo(Hora* hora)
{
    this->marcaDeTiempo = hora;
}

void Pagina::serializar(std::ofstream& archivo)
{
    size_t urlLength = url.length();
    archivo.write(reinterpret_cast<char*>(&urlLength), sizeof(urlLength));  // Escribir la longitud de la URL
    archivo.write(url.c_str(), urlLength);  // Escribir la URL

    // Serializar la marca de tiempo
    marcaDeTiempo->serializar(archivo);
}

Pagina* Pagina::deserializar(std::ifstream& archivo)
{
    size_t urlLength;
    archivo.read(reinterpret_cast<char*>(&urlLength), sizeof(urlLength));  // Leer la longitud de la URL

    char* buffer = new char[urlLength + 1];
    archivo.read(buffer, urlLength);  // Leer la URL
    buffer[urlLength] = '\0';
    url = std::string(buffer);
    delete[] buffer;

    // Deserializar la marca de tiempo
    marcaDeTiempo = marcaDeTiempo->deserializar(archivo);

    Pagina* p = new Pagina(url);
    p->setMarcaDeTiempo(marcaDeTiempo);

    return p;
}

std::string Pagina::toString()
{
    std::stringstream ss;
    ss << url;
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