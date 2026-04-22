//
// Created by Jose on 22/4/2026.
//

#include "DefinirEquipo.h"

const int criticidadMaxPermitida=5;

DefinirEquipo::DefinirEquipo() {
}

void DefinirEquipo::definirEquipoConVariables(const double criticidad, const int estado, const string &id, vector<Equipo *> &equiposLeidos) {
    if (criticidad < 0 || estado < 0) throw MenorACeroException();
    // Critico si criticidad > 5, estandar si <= 5
    if (criticidad > criticidadMaxPermitida)
        equiposLeidos.push_back(new EquipoCritico(id, criticidad, estado));
    else
        equiposLeidos.push_back(new EquipoEstandar(id, criticidad, estado));
}

vector<Equipo*> DefinirEquipo::definirEquipoConVector(vector<Equipo*> &equiposLeidos) {
    vector<Equipo*> equiposDefinidos;
    for (Equipo* equipo : equiposLeidos) {
        if (equipo->getCriticidad() > criticidadMaxPermitida)
            equiposDefinidos.push_back(new EquipoCritico(equipo->getId(), equipo->getCriticidad(), equipo->getEstado()));
        else
            equiposDefinidos.push_back(new EquipoEstandar(equipo->getId(), equipo->getCriticidad(), equipo->getEstado()));
    }
    return equiposDefinidos;
}

