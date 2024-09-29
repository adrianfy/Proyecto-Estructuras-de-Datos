#include "Marcador.h"

Marcador::Marcador(){
    pagina = nullptr;
    etiqueta = "";
}

Marcador::Marcador(Pagina* pagina,std::string etiqueta)
{
	this->pagina = pagina;
	this->etiqueta = etiqueta;
}

Pagina* Marcador::getPagina() 
{
    return pagina;
}

std::string Marcador::getEtiqueta() 
{
    return etiqueta;
}

void Marcador::serializar(std::ofstream& archivo)
{
    size_t urlLength = pagina->getUrl().size();
    archivo.write(reinterpret_cast<char*>(&urlLength), sizeof(urlLength)); // Escribir tamaño de la URL
    archivo.write(pagina->getUrl().c_str(), urlLength); // Escribir contenido de la URL

    size_t etiquetaLength = etiqueta.size();
    archivo.write(reinterpret_cast<char*>(&etiquetaLength), sizeof(etiquetaLength)); // Escribir tamaño de la etiqueta
    archivo.write(etiqueta.c_str(), etiquetaLength); // Escribir contenido de la etiqueta
}

void Marcador::deserializar(std::ifstream& archivo)
{
    size_t urlLength;
    archivo.read(reinterpret_cast<char*>(&urlLength), sizeof(urlLength)); // Leer tamaño de la URL

    char* bufferURL = new char[urlLength + 1]; // Crear buffer para la URL
    archivo.read(bufferURL, urlLength); // Leer contenido de la URL
    bufferURL[urlLength] = '\0'; // Añadir terminador nulo
    pagina = new Pagina(bufferURL); // Asignar la URL
    delete[] bufferURL;

    size_t etiquetaLength;
    archivo.read(reinterpret_cast<char*>(&etiquetaLength), sizeof(etiquetaLength)); // Leer tamaño de la etiqueta

    char* bufferEtiqueta = new char[etiquetaLength + 1]; // Crear buffer para la etiqueta
    archivo.read(bufferEtiqueta, etiquetaLength); // Leer contenido de la etiqueta
    bufferEtiqueta[etiquetaLength] = '\0'; // Añadir terminador nulo
    etiqueta = std::string(bufferEtiqueta); // Asignar la etiqueta
    delete[] bufferEtiqueta;
}

std::string Marcador::toString(){

   std::stringstream s;
   s << " Marcador: " << std::endl;
   s << "Pagina: " << pagina->toString() << std::endl;
   s << "Etiqueta: " << etiqueta << std::endl;
   return s.str();
}

Marcador::~Marcador(){
}
