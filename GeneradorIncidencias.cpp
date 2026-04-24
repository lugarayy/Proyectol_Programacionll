//
// Created by Jose on 21/4/2026.
//

#include "GeneradorIncidencias.h"
#include "FormatoInvalidoException.h"

GeneradorIncidencias::GeneradorIncidencias() {}

Incidencia* GeneradorIncidencias::crearIncidenciaPorSeveridad(const string& severidad, const string& idEquipo, int dia) {
    if (severidad == "ALTA" || severidad == "Alta" || severidad == "alta") {
        return new IncidenciaSeveridadAlta(new IncidenciaBase(idEquipo, dia));
    }
    if (severidad == "MEDIA" || severidad == "Media" || severidad == "media") {
        return new IncidenciaSeveridadMedia(new IncidenciaBase(idEquipo, dia));
    }
    if (severidad == "BAJA" || severidad == "Baja" || severidad == "baja") {
        return new IncidenciaSeveridadBaja(new IncidenciaBase(idEquipo, dia));
    }
    throw FormatoInvalidoException();
}

void GeneradorIncidencias::generarIncidencias(int dia, Equipo& equipo) {
        if (rand() % 100 <= 20) // 20% de posibilidad de generar incidencia
            {
            int tipo = rand() % 3; // de los tres tipos que hay elige random
            Incidencia* inci = nullptr;
            switch (tipo) {
                case 0:
                    inci = crearIncidenciaPorSeveridad("BAJA", equipo.getId(), dia);
                    break;
                case 1:
                    inci = crearIncidenciaPorSeveridad("MEDIA", equipo.getId(), dia);
                    break;
                case 2:
                    inci = crearIncidenciaPorSeveridad("ALTA", equipo.getId(), dia);
                    break;
                default:
                    inci = nullptr;
            }
            if (inci != nullptr) equipo.agregarIncidencias(inci);
        }

}
