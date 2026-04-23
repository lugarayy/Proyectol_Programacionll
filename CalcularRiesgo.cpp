//
// Created by Jose on 21/4/2026.
//

#include "CalcularRiesgo.h"

CalcularRiesgo::CalcularRiesgo(const vector<Equipo *> &equipos) {
    if (equipos.empty()) {
        prom = 0;
        riesgo = "SIN DATOS";
        return;
    }

    double suma = 0;
    for (int i=0; i<equipos.size(); i++) {
        suma+= equipos[i]->getEstado();
    }
    prom = suma / equipos.size();
    if (prom>=70 ){ riesgo="MUY BAJO"; }
    else if (prom >= 50) { riesgo="BAJO"; }
    else if (prom >= 20) { riesgo="MEDIO"; }
    else if (prom >= 0) { riesgo="ALTO"; }
}

string CalcularRiesgo::getRiesgo() {
    return riesgo;
}

double CalcularRiesgo::getProm() {
    return prom;
}
