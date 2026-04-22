//
// Created by Jose on 21/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_CALCULARRIESGO_H
#define PROYECTOL_PROGRAMACIONLL_CALCULARRIESGO_H
#include <vector>
#include "Equipo.h"
using namespace std;


class CalcularRiesgo {
private:
    double prom;
    string riesgo;
public:
    CalcularRiesgo(const vector<Equipo*> &equipos);
    string getRiesgo();
    double getProm();
};


#endif //PROYECTOL_PROGRAMACIONLL_CALCULARRIESGO_H