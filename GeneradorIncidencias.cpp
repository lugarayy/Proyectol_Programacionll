//
// Created by Jose on 21/4/2026.
//

#include "GeneradorIncidencias.h"

GeneradorIncidencias::GeneradorIncidencias() {}
void GeneradorIncidencias::generarIncidencias(int diaSimulador, vector<Equipo *> &equipos) {
    for (int i= 0; i < equipos.size(); i++) {
        if (rand() % 100 < 20) // 20% de posibilidad de generar incidencia
        {
            int tipo = rand() % 3; // de los tres tipos que hay elige random
            Incidencia* inci;
            switch (tipo) {
                case 0:
                    inci = new IncidenciaSeveridadBaja(new IncidenciaBase(equipos[i]->getId(), diaSimulador));
                    break;
                case 1:
                    inci = new IncidenciaSeveridadMedia(new IncidenciaBase(equipos[i]->getId(), diaSimulador));
                    break;
                case 2:
                    inci = new IncidenciaSeveridadAlta(new IncidenciaBase(equipos[i]->getId(), diaSimulador));
                    break;
                default:
                    inci = nullptr;
            }
            equipos[i]->agregarIncidencias(inci);
        }
    }
}
