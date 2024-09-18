#include "Buscar.h"

Buscar::Buscar() : tabActual(0), modoIncognito(false)
{
	//tabs.push_back(new Pestania());
} 

Buscar::~Buscar()
{
	/*for (Pestania* tab : tabs) {
		delete tab;
	}*/
}

void Buscar::CambiarPestania(int pes)
{
	/*if (pes >= 0 && pes < tabs.size()) {
		tabActual = pes;
	}*/
}

void Buscar::CambiarModo()
{
	/*modoIncognito = !modoIncognito;*/
}

void Buscar::GuardarEntradas()
{
	/*if (GetAsyncKeyState(VK_LEFT) & 0X8000) {
		tabs[tabActual]->retroceder(); 
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0X8000) {  
		tabs[tabActual]->avanzar();   
	}
	if (GetAsyncKeyState(VK_UP) & 0X8000) {
		CambiarPestania(tabActual+1);
	}
	if (GetAsyncKeyState(VK_DOWN) & 0X8000) {
		CambiarPestania(tabActual - 1); 
	}
	Sleep(100);*/
}

void Buscar::Ejecutar()
{
	/*while (true) {
		GuardarEntradas();
	}*/
}

Pestania* Buscar::obtenerPestaniaActual() {
	/*if (tabActual >= 0 && tabActual < tabs.size()) {
		return tabs[tabActual];
	}*/
	return nullptr;
}