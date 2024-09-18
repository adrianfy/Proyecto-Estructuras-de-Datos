#include "Marcador.h"

Marcador::Marcador(){
    pagina = nullptr;
    etiquetas = "";
}

Marcador::Marcador(Pagina* pagina, const std::string etiquetas)
{
	this->pagina = pagina;
	this->etiquetas = etiquetas;
}

Pagina* Marcador::getPagina() const
{
    return pagina;
}

std::string Marcador::getEtiquetas() const
{
    return etiquetas;
}
