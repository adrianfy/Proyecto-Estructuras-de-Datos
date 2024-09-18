#include "Marcador.h"

Marcador::Marcador(){
    pagina = nullptr;
    etiquetas = {};
}

Marcador::Marcador(Pagina* pagina, const std::list<std::string>& etiquetas)
{
	this->pagina = pagina;
	this->etiquetas = etiquetas;
}

Pagina* Marcador::getPagina() const
{
    return pagina;
}

std::list<std::string> Marcador::getEtiquetas() const
{
    return std::list<std::string>();
}
