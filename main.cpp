#include <iostream>
#include "LectorArchivos.h"
#include "OrdenamientoDiario.h"
using namespace std;

int main() {
    cout << "Proyecto I, Programacion II" << endl;

    try {
        LectorArchivos lector;
        vector<Equipo*> equipos = lector.lectorDeArchivos("equipos.txt");

        cout << "\n--- Antes del ordenamiento ---" << endl;
        for (auto e : equipos)
            cout << e->getId() << " | prioridad: " << e->getPrioridad() << endl;

        OrdenamientoDiario ordenador;
        vector<Equipo*> ordenados = ordenador.ordenar(equipos);

        cout << "\n--- Despues del ordenamiento ---" << endl;
        for (auto e : ordenados)
            cout << e->getId() << " | prioridad: " << e->getPrioridad() << endl;

    } catch (ArchivoInvalidoException& e) {
        cout << "Error: " << e.what() << endl;
    } catch (FormatoInvalidoException& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
