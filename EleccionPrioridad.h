//
// Created by lucig on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_ELECCIONPRIORIDAD_H
#define PROYECTOL_PROGRAMACIONLL_ELECCIONPRIORIDAD_H

#include <vector>
#include "Equipo.h"
using namespace std;

class EleccionPrioridad
{
private:
    int maxDia;
public:
    EleccionPrioridad();
    vector<Equipo*> seleccionPrioridad(const vector<Equipo*>& equipos);
};


#endif //PROYECTOL_PROGRAMACIONLL_ELECCIONPRIORIDAD_H