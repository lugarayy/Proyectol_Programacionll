//
// Created by Jose on 22/4/2026.
//

#include "DefinirEquipo.h"
#include "EquipoCritico.h"
#include "EquipoEstandar.h"

DefinirEquipo::DefinirEquipo() {
}

void DefinirEquipo::definirEquipoConVariables(const double criticidad, const int estado, const string &id, vector<Equipo *> &equiposLeidos) {
    if (criticidad < 0 || estado < 0) throw MenorACeroException();
    // Critico si criticidad > 5, estandar si <= 5
    if (criticidad > Equipo::TipoCriticidad)
        equiposLeidos.push_back(new EquipoCritico(id, criticidad, estado));
    else
        equiposLeidos.push_back(new EquipoEstandar(id, criticidad, estado));
}


