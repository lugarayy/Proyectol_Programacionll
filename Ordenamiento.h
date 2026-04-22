//
// Created by Jose on 21/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_ORDENAMIENTO_H
#define PROYECTOL_PROGRAMACIONLL_ORDENAMIENTO_H
#include "Equipo.h"
#include <vector>
using namespace std;

class Ordenamiento {
private:
    void ordenamiento(vector<Equipo*>& equipos, int menor, int mayor);
    int particion(vector<Equipo*>& equipos, int menor, int mayor);

public:
    void ordenar(vector<Equipo*> &equipos);
};



#endif //PROYECTOL_PROGRAMACIONLL_ORDENAMIENTO_H