#pragma once
#include<string>

class Pagina
{
private:
	std::string url;
	std::string dominio;

public:
	Pagina();
	Pagina(std::string Url, std::string Dominio);

	std::string getUrl();
	std::string getDominio();

	~Pagina();
};