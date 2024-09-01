#include "Marcador.h"

Marcador::Marcador(){

}

Marcador::Marcador(Pagina* pagina, const std::vector<std::string>& tag) : pagina{pagina}, etiquetas{ etiquetas }
{
}

Pagina* Marcador::getPagina() const
{
    return pagina;
}

std::vector<std::string> Marcador::getEtiquetas() const
{
    return etiquetas;
}
