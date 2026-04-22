//
// Created by Jose on 21/4/2026.
//

#include "calcularRiesgo.h"

calcularRiesgo::calcularRiesgo(vector<Equipo *> &equipos) {
    double suma = 0;
    for (int i=0; i<equipos.size(); i++) {
        suma+= equipos[i]->getEstado();
    }
    double prom = suma / equipos.size();
    if (prom > 70) riesgo="BAJO";
    if (prom >= 40) riesgo="MEDIO";
    riesgo="ALTO";
}

string calcularRiesgo::getRiesgo() {
    return riesgo;
}
