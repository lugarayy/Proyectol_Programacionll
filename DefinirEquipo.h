//
// Created by Jose on 22/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_DEFINIREQUIPO_H
#define PROYECTOL_PROGRAMACIONLL_DEFINIREQUIPO_H
#include <vector>
#include "Equipo.h"
#include "EquipoCritico.h"
#include "EquipoEstandar.h"
#include "ArchivoInvalidoException.h"
#include "MenorACeroException.h"

class DefinirEquipo {
public:
    DefinirEquipo();
    void definirEquipoConVariables(double criticidad, int estado, const string &id, vector<Equipo*>& equiposLeidos);
    vector<Equipo*> definirEquipoConVector(vector<Equipo*> &equiposLeidos);
};


#endif //PROYECTOL_PROGRAMACIONLL_DEFINIREQUIPO_H