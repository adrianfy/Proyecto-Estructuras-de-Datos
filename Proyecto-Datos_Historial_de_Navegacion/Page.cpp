#include "Page.h"

Page::Page() : url{""}, dominio{""}, titulo{""}
{
}

Page::Page(std::string& Url, std::string& Dominio, std::string& Titulo) : url{Url}, dominio{Dominio}, titulo{Titulo}
{
}

Page::~Page()
{
}

std::string Page::getUrl() const
{
	return url;
}

std::string Page::getDominio() const
{
	return dominio;
}

std::string Page::getTitulo() const
{
	return titulo;
}
