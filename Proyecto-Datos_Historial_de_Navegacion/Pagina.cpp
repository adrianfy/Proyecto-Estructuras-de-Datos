#include "Pagina.h"

Pagina::Pagina()
{
	this->url = "";
}

Pagina::Pagina(std::string url)
{
	this->url = url;
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

Pagina::~Pagina()
{
}