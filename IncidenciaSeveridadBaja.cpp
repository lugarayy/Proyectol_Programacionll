//
// Created by lucig on 19/4/2026.
//

#include "IncidenciaSeveridadBaja.h"

IncidenciaSeveridadBaja::IncidenciaSeveridadBaja(Incidencia* incidencia) : DecoradorIncidencia(incidencia) {}

int IncidenciaSeveridadBaja::getSeveridad() const
{
    return  incidencia->getSeveridad() + 1;
}

string IncidenciaSeveridadBaja::getDescripcion() const
{
    return incidencia->getDescripcion() + " -> BAJA";
}
