#include <iostream>
#include "LectorArchivos.h"
#include "Simulador.h"
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    cout<<"Proyecto I, Programacion II"<<endl<<endl;
    try {
        Simulador sim;
        sim.cargarEquipos("equipos.txt");
        sim.ejecuta();
    } catch (ArchivoInvalidoException& e) {
        cout << "Error: " << e.what() << endl;
    } catch (FormatoInvalidoException& e) {
        cout << "Error: " << e.what() << endl;
    } catch (OperacionInconsistenteException& e) {
        cout << "Error: " << e.what() << endl;
    } catch (MenorACeroException& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
