//
// Created by lucig on 11/4/2026.
//

#include "IncidenciaSeveridadAlta.h"

IncidenciaSeveridadAlta::IncidenciaSeveridadAlta(Incidencia* incidencia)
    : DecoradorIncidencia(incidencia) {}

int IncidenciaSeveridadAlta::getSeveridad() const
{
    return incidencia->getSeveridad() + 4;
}

string IncidenciaSeveridadAlta::getDescripcion() const
{
    return incidencia->getDescripcion() + " -> ALTA";
}