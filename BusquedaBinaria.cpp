//
// Created by Jose on 23/4/2026.
//

#include "BusquedaBinaria.h"

Equipo* BusquedaBinaria::buscarEquipoPorId(const vector<Equipo*>& equipos, const string& id) const {
	if (equipos.empty()) return nullptr;

	size_t ini = 0;
	size_t fin = equipos.size();

	while (ini < fin) {
		size_t medio = ini + (fin - ini) / 2;
		const string& idMedio = equipos[medio]->getId();
		if (idMedio < id) ini = medio + 1;
		else fin = medio;
	}

	if (ini < equipos.size() && equipos[ini]->getId() == id) return equipos[ini];
	return nullptr;
}
