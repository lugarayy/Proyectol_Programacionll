//
// Created by Jose on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_ORDENAMIENTODIARIO_H
#define PROYECTOL_PROGRAMACIONLL_ORDENAMIENTODIARIO_H

#include "Equipo.h"
#include <vector>
using namespace std;

class OrdenamientoDiario {
private:
    void ordenamiento(vector<Equipo*>& equipos, int menor, int mayor);
    int particion(vector<Equipo*>& equipos, int menor, int mayor);

public:
    vector<Equipo*> ordenar(vector<Equipo*> equipos);
};

#endif //PROYECTOL_PROGRAMACIONLL_ORDENAMIENTODIARIO_H
