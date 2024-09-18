#include "Marcador.h"

Marcador::Marcador(){
    pagina = nullptr;
    etiquetas = "";
}

Marcador::Marcador(Pagina* pagina,std::string etiquetas)
{
	this->pagina = pagina;
	this->etiquetas = etiquetas;
}

Pagina* Marcador::getPagina() 
{
    return pagina;
}

std::string Marcador::getEtiquetas() 
{
    return etiquetas;
}

std::string Marcador::toString(){

   std::stringstream s;
   s << "Marcador: " << etiquetas << std::endl;
   return s.str();
}

Marcador::~Marcador(){
    delete this->pagina;
}
