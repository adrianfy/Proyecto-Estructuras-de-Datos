#include "Pagina.h"

Pagina::Pagina()
{
	this->url = "";	
	this->dominio = "";	
}

Pagina::Pagina(std::string url, std::string dominio)
{
	this->url = url;
	this->dominio = dominio;
}


std::string Pagina::getUrl()
{
	return url;
}

std::string Pagina::getDominio() 
{
	return dominio;
}

Pagina::~Pagina()
{
}