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

std::string Marcador::toString(){

   std::stringstream s;
   s << "Etiqueta: " << etiqueta << "Pagina: "<< pagina << std::endl;
   return s.str();
}

Marcador::~Marcador(){
    delete this->pagina;
}
