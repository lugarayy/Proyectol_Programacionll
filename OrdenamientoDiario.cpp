//
// Created by Jose on 11/4/2026.
//

#include "OrdenamientoDiario.h"

void OrdenamientoDiario::ordenamiento(vector<Equipo*>& equipos, int menor, int mayor) {
    if (menor < mayor) {
        int pivote = particion(equipos, menor, mayor);
        ordenamiento(equipos, menor, pivote - 1);
        ordenamiento(equipos, pivote + 1, mayor);
    }
}

int OrdenamientoDiario::particion(vector<Equipo*>& equipos, int menor, int mayor) {
    double pivote = equipos[mayor]->getPrioridad();
    int i = menor - 1;
    for (int j = menor; j < mayor; j++) {
        if (equipos[j]->getPrioridad() > pivote) {
            i++;
            swap(equipos[i], equipos[j]);
        }
    }
    swap(equipos[i + 1], equipos[mayor]);
    return i + 1;
}

vector<Equipo*> OrdenamientoDiario::ordenar(vector<Equipo*> equipos) {
    ordenamiento(equipos, 0, equipos.size() - 1);
    return equipos;
}
