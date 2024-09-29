#ifndef ENTRADAUSUARIO_H
#define ENTRADAUSUARIO_H

#include <iostream>

using namespace std;

static class EntradaUsuario
{
public:
	static int obtenerSeleccionInt();
	static bool obtenerSeleccionBool();
	static double obtenerSeleccionDouble();
	static char obtenerSeleccionChar();
};

#endif // ! ENTRADAUSUARIO_H

