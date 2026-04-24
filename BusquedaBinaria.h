//
// Created by Jose on 23/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_BUSQUEDABINARIA_H
#define PROYECTOL_PROGRAMACIONLL_BUSQUEDABINARIA_H

#include "Equipo.h"
#include <string>
#include <vector>

using namespace std;


class BusquedaBinaria {
public:
	Equipo* buscarEquipoPorId(const vector<Equipo*>& equipos, const string& id) const;
};


#endif //PROYECTOL_PROGRAMACIONLL_BUSQUEDABINARIA_H