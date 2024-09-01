#pragma once
#include<iostream>
#include<string>
#include<sstream>
class Page
{
protected:
	std::string url;
	std::string dominio;
	std::string titulo;
public:
	Page();
	Page(std::string& Url, std::string& Dominio, std::string& Titulo);
	~Page();
	std::string getUrl() const;
	std::string getDominio() const;
	std::string getTitulo() const;
};