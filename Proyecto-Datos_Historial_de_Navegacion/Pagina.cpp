#include "Pagina.h"

Pagina::Pagina() : url{""}, dominio{""}, titulo{""}
{
}

Pagina::Pagina(std::string& Url, std::string& Dominio, std::string& Titulo) : url{Url}, dominio{Dominio}, titulo{Titulo}
{
}

Pagina::~Pagina()
{
}

std::string Pagina::getUrl() const
{
	return url;
}

std::string Pagina::getDominio() const
{
	return dominio;
}

std::string Pagina::getTitulo() const
{
	return titulo;
}
