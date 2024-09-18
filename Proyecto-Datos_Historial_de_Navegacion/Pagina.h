#pragma once
#include <sstream>

class Pagina
{
private:
	std::string url;

public:
	Pagina();
	Pagina(std::string url);

	std::string getUrl();

	std::string toString();

	~Pagina();
};