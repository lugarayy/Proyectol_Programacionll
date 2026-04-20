//
// Created by lucig on 11/4/2026.
//

#include "IncidenciaSeveridadMedia.h"

IncidenciaSeveridadMedia::IncidenciaSeveridadMedia(Incidencia* incidencia)
    : DecoradorIncidencia(incidencia) {}

int IncidenciaSeveridadMedia::getSeveridad() const
{
    return incidencia->getSeveridad() + 3;
}

string IncidenciaSeveridadMedia::getDescripcion() const
{
    return incidencia->getDescripcion() + " -> MEDIA";
}