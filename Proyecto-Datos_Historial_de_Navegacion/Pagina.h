#pragma once
#include<iostream>
#include<string>
#include<sstream>
class Pagina
{
protected:
	std::string url;
	std::string dominio;
	std::string titulo;
public:
	Pagina();
	Pagina(std::string& Url, std::string& Dominio, std::string& Titulo);
	~Pagina();
	std::string getUrl() const;
	std::string getDominio() const;
	std::string getTitulo() const;
};