#include "EntradaUsuario.h"

int EntradaUsuario::obtenerSeleccionInt()
{
    int seleccion;
    bool error = false;

    do {
        try {
            cout << "Ingrese su opcion: ";
            cin >> seleccion;

            if (cin.fail()) {
                throw exception();
            }

            error = false;
            return seleccion;
        }
        catch (exception e) {
            cout << "Error: el valor ingresado no es una opcion valida." << endl;
            cin.clear();
            cin.ignore(256, '\n');
            error = true;
        }
    } while (error);

    return 0;
}

bool EntradaUsuario::obtenerSeleccionBool()
{
    bool seleccion;
    bool error = false;

    do {
        try {
            cout << "Ingrese su opcion: ";
            cin >> seleccion;

            if (cin.fail()) {
                throw exception();
            }

            error = false;
            return seleccion;
        }
        catch (exception e) {
            cout << "Error: el valor ingresado no es una opcion valida." << endl;
            cin.clear();
            cin.ignore(256, '\n');
            error = true;
        }
    } while (error);

    return false;
}

double EntradaUsuario::obtenerSeleccionDouble()
{
    double seleccion;
    bool error = false;

    do {
        try {
            cout << "Ingrese su opcion: ";
            cin >> seleccion;

            if (cin.fail()) {
                throw exception();
            }

            error = false;
            return seleccion;
        }
        catch (exception e) {
            cout << "Error: el valor ingresado no es una opcion valida." << endl;
            cin.clear();
            cin.ignore(256, '\n');
            error = true;
        }
    } while (error);

    return 0;
}

char EntradaUsuario::obtenerSeleccionChar()
{
    char seleccion;
    bool error = false;

    do {
        try {
            cout << "Ingrese su opcion: ";
            cin >> seleccion;

            if (cin.fail()) {
                throw exception();
            }

            error = false;
            return seleccion;
        }
        catch (exception e) {
            cout << "Error: el valor ingresado no es una opcion valida." << endl;
            cin.clear();
            cin.ignore(256, '\n');
            error = true;
        }
    } while (error);

    return ' ';
}