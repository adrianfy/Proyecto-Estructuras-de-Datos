#include "Tab.h"

Tab::Tab()
{
    this->modoIncognito = false;
    this->urlActual = "";
}

std::string Tab::getUrlActual()
{
    return urlActual;
}

void Tab::navegar(std::string& url)
{
    if (!modoIncognito) {
        historial.agregarEntrada(url);
    }
    urlActual = url;
}

void Tab::retroceder()
{
    urlActual = historial.retroceder();
}

void Tab::avanzar()
{
    urlActual = historial.avanzar();
}

void Tab::cambiarModoIncognito(bool incognito)
{
    modoIncognito = incognito;
}

bool Tab::esIncognito()
{
    return modoIncognito;
}

Tab::~Tab()
{
}
