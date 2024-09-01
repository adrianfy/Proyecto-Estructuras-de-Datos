#pragma once
#include"Page.h"
#include<vector>

class Marcador
{
protected:
	Page* page;
	std::vector<std::string> tags;
public: 
	Marcador(Page* Page, const std::vector<std::string>& tag);
	Page* getPage() const;
	std::vector<std::string> getTags() const;
};

