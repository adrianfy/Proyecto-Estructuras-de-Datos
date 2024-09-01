#include "Marcador.h"

Marcador::Marcador(Page* Page, const std::vector<std::string>& tag) : page{Page}, tags{tag} 
{
}

Page* Marcador::getPage() const
{
    return page;
}

std::vector<std::string> Marcador::getTags() const
{
    return tags;
}
