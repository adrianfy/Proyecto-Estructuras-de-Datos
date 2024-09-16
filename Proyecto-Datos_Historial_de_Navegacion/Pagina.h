#pragma once
#include<string>

class Pagina
{
private:
	std::string url;
	std::string dominio;

public:
	Pagina();
	Pagina(std::string url, std::string dominio);

	std::string getUrl();
	std::string getDominio();

	~Pagina();
};