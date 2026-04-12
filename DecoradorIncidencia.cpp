//
// Created by lucig on 11/4/2026.
//

#include "DecoradorIncidencia.h"

DecoradorIncidencia::DecoradorIncidencia(Incidencia* incidencia)
: Incidencia(incidencia->getEquipoId(),
    incidencia->getDiaDiagnostico())
{
    this->incidencia = incidencia;
}

DecoradorIncidencia::~DecoradorIncidencia()
{
    delete this->incidencia;
}

int DecoradorIncidencia::getSeveridad() const
{
    return this->incidencia->getSeveridad();
}

string DecoradorIncidencia::getDescripcion() const
{
    return this->incidencia->getDescripcion();
}