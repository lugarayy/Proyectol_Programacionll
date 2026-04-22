//
// Created by Jose on 21/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_CALCULARRIESGO_H
#define PROYECTOL_PROGRAMACIONLL_CALCULARRIESGO_H
#include <vector>
#include "Equipo.h"
using namespace std;


class calcularRiesgo {
private:
    string riesgo;
public:
    calcularRiesgo(vector<Equipo*> &equipos);
    string getRiesgo();
};


#endif //PROYECTOL_PROGRAMACIONLL_CALCULARRIESGO_H