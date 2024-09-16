#include "Sesion.h"
#include "Pagina.h"
#include <iostream>

Sesion::Sesion() {
}

Sesion::~Sesion() {
}

// Guardar sesión en archivo binario
void Sesion::guardarSesion(const std::vector<Tab*>& tabs, const std::vector<Marcador*>& marcadores, const std::string& archivo) {
	std::ofstream salida(archivo, std::ios::binary);
	if (!salida) {
		std::cerr << "Error al abrir el archivo para guardar la sesión." << std::endl;
		return;
	}

	// Guardar cantidad de pestañas
	size_t cantidadTabs = tabs.size();
	salida.write(reinterpret_cast<char*>(&cantidadTabs), sizeof(cantidadTabs));

	// Guardar historial de cada pestaña
	for (Tab* tab : tabs) {
		std::vector<Pagina*> historial = tab->getHistorial();
		size_t cantidadPaginas = historial.size();
		salida.write(reinterpret_cast<char*>(&cantidadPaginas), sizeof(cantidadPaginas));

		for (Pagina* pagina : historial) {
			size_t urlLength = pagina->getUrl().size();
			salida.write(reinterpret_cast<char*>(&urlLength), sizeof(urlLength));
			salida.write(pagina->getUrl().c_str(), urlLength);

			size_t dominioLength = pagina->getDominio().size();
			salida.write(reinterpret_cast<char*>(&dominioLength), sizeof(dominioLength));
			salida.write(pagina->getDominio().c_str(), dominioLength);
		}
	}

	// Guardar cantidad de marcadores
	size_t cantidadMarcadores = marcadores.size();
	salida.write(reinterpret_cast<char*>(&cantidadMarcadores), sizeof(cantidadMarcadores));

	// Guardar marcadores
	for (Marcador* marcador : marcadores) {
		Pagina* pagina = marcador->getPagina();
		size_t urlLength = pagina->getUrl().size();
		salida.write(reinterpret_cast<char*>(&urlLength), sizeof(urlLength));
		salida.write(pagina->getUrl().c_str(), urlLength);

		size_t dominioLength = pagina->getDominio().size();
		salida.write(reinterpret_cast<char*>(&dominioLength), sizeof(dominioLength));
		salida.write(pagina->getDominio().c_str(), dominioLength);

		// Guardar etiquetas del marcador
		std::vector<std::string> etiquetas = marcador->getEtiquetas();
		size_t cantidadEtiquetas = etiquetas.size();
		salida.write(reinterpret_cast<char*>(&cantidadEtiquetas), sizeof(cantidadEtiquetas));

		for (const std::string& etiqueta : etiquetas) {
			size_t etiquetaLength = etiqueta.size();
			salida.write(reinterpret_cast<char*>(&etiquetaLength), sizeof(etiquetaLength));
			salida.write(etiqueta.c_str(), etiquetaLength);
		}
	}

	salida.close();
}

// Cargar sesión desde archivo binario
void Sesion::cargarSesion(std::vector<Tab*>& tabs, std::vector<Marcador*>& marcadores, const std::string& archivo) {
	std::ifstream entrada(archivo, std::ios::binary);
	if (!entrada) {
		std::cerr << "Error al abrir el archivo para cargar la sesión." << std::endl;
		return;
	}

	// Cargar cantidad de pestañas
	size_t cantidadTabs;
	entrada.read(reinterpret_cast<char*>(&cantidadTabs), sizeof(cantidadTabs));

	tabs.clear();
	for (size_t i = 0; i < cantidadTabs; ++i) {
		Tab* nuevaTab = new Tab();
		size_t cantidadPaginas;
		entrada.read(reinterpret_cast<char*>(&cantidadPaginas), sizeof(cantidadPaginas));

		for (size_t j = 0; j < cantidadPaginas; ++j) {
			size_t urlLength, dominioLength, tituloLength;

			entrada.read(reinterpret_cast<char*>(&urlLength), sizeof(urlLength));
			std::string url(urlLength, ' ');
			entrada.read(&url[0], urlLength);

			entrada.read(reinterpret_cast<char*>(&dominioLength), sizeof(dominioLength));
			std::string dominio(dominioLength, ' ');
			entrada.read(&dominio[0], dominioLength);

			entrada.read(reinterpret_cast<char*>(&tituloLength), sizeof(tituloLength));
			std::string titulo(tituloLength, ' ');
			entrada.read(&titulo[0], tituloLength);

			nuevaTab->navegar(url);  // Navegar a la página cargada
		}

		tabs.push_back(nuevaTab);
	}

	// Cargar cantidad de marcadores
	size_t cantidadMarcadores;
	entrada.read(reinterpret_cast<char*>(&cantidadMarcadores), sizeof(cantidadMarcadores));

	marcadores.clear();
	for (size_t i = 0; i < cantidadMarcadores; ++i) {
		size_t urlLength, dominioLength, tituloLength;

		entrada.read(reinterpret_cast<char*>(&urlLength), sizeof(urlLength));
		std::string url(urlLength, ' ');
		entrada.read(&url[0], urlLength);

		entrada.read(reinterpret_cast<char*>(&dominioLength), sizeof(dominioLength));
		std::string dominio(dominioLength, ' ');
		entrada.read(&dominio[0], dominioLength);

		entrada.read(reinterpret_cast<char*>(&tituloLength), sizeof(tituloLength));
		std::string titulo(tituloLength, ' ');
		entrada.read(&titulo[0], tituloLength);

		Pagina* paginaMarcada = new Pagina(url, dominio);

		size_t cantidadEtiquetas;
		entrada.read(reinterpret_cast<char*>(&cantidadEtiquetas), sizeof(cantidadEtiquetas));

		std::vector<std::string> etiquetas;
		for (size_t j = 0; j < cantidadEtiquetas; ++j) {
			size_t etiquetaLength;
			entrada.read(reinterpret_cast<char*>(&etiquetaLength), sizeof(etiquetaLength));
			std::string etiqueta(etiquetaLength, ' ');
			entrada.read(&etiqueta[0], etiquetaLength);
			etiquetas.push_back(etiqueta);
		}

		Marcador* nuevoMarcador = new Marcador(paginaMarcada, etiquetas);
		marcadores.push_back(nuevoMarcador);
	}

	entrada.close();
}
