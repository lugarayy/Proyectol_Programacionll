//
// Created by Jose on 21/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_GENERADORINCIDENCIAS_H
#define PROYECTOL_PROGRAMACIONLL_GENERADORINCIDENCIAS_H
#include <vector>
#include "Equipo.h"
#include "IncidenciaBase.h"
#include "IncidenciaSeveridadBaja.h"
#include "IncidenciaSeveridadMedia.h"
#include "IncidenciaSeveridadAlta.h"

class GeneradorIncidencias {
public:
    GeneradorIncidencias();
    void generarIncidencias(int diaSimulador,  Equipo& equipo);
    Incidencia* crearIncidenciaPorSeveridad(const string& severidad, const string& idEquipo, int dia);
};


#endif //PROYECTOL_PROGRAMACIONLL_GENERADORINCIDENCIAS_H