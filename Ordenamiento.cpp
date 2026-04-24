//
// Created by Jose on 21/4/2026.
//

#include "Ordenamiento.h"

void Ordenamiento::ordenamiento(vector<Equipo*>& equipos, int menor, int mayor) {
    if (menor < mayor) {
        int pivote = particion(equipos, menor, mayor);
        ordenamiento(equipos, menor, pivote - 1);
        ordenamiento(equipos, pivote + 1, mayor);
    }
}

int Ordenamiento::particion(vector<Equipo*>& equipos, int menor, int mayor) {
    double pivote = equipos[mayor]->getPrioridad();
    double critipivote = equipos[mayor]->getCriticidad();
    int i = menor - 1;

    for (int j = menor; j < mayor; j++) {
        double pj = equipos[j]->getPrioridad();
        double cj = equipos[j]->getCriticidad();

        if (pj > pivote ||(pj == pivote && cj > critipivote)) {
            i++;
            swap(equipos[i], equipos[j]);
        }
    }
    swap(equipos[i + 1], equipos[mayor]);
    return i + 1;
}

void Ordenamiento::ordenar(vector<Equipo*> &equipos) {
    if (equipos.empty()) return;
    ordenamiento(equipos, 0, equipos.size() - 1);
}

int Ordenamiento::particionPorId(vector<Equipo*>& equipos, int menor, int mayor) {
    string pivote = equipos[mayor]->getId();
    int i = menor - 1;
    for (int j = menor; j < mayor; j++) {
        if (equipos[j]->getId() < pivote) {
            i++;
            swap(equipos[i], equipos[j]);
        }
    }
    swap(equipos[i + 1], equipos[mayor]);
    return i + 1;
}

void Ordenamiento::ordenamientoPorId(vector<Equipo*>& equipos, int menor, int mayor) {
    if (menor < mayor) {
        int pivote = particionPorId(equipos, menor, mayor);
        ordenamientoPorId(equipos, menor, pivote - 1);
        ordenamientoPorId(equipos, pivote + 1, mayor);
    }
}

void Ordenamiento::ordenarPorId(vector<Equipo*> &equipos) {
    if (equipos.empty()) return;
    ordenamientoPorId(equipos, 0, equipos.size() - 1);
}
