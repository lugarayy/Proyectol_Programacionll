#include <iostream>
#include "LectorArchivos.h"
using namespace std;

int main() {
cout<<"Proyecto I, Programacion II"<<endl;


    try {
        LectorArchivos lector;
        vector<Equipo*> equipos = lector.lectorDeArchivos("equipos.txt");
        for (auto e : equipos)
            cout << e->getId() << " | " << e->getTipo() << " | criticidad: "
                 << e->getCriticidad() << " | estado: " << e->getEstado() << endl;
    } catch (ArchivoInvalidoException& e) {
        cout << "Error: " << e.what() << endl;
    } catch (FormatoInvalidoException& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}