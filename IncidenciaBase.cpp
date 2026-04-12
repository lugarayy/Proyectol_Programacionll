//
// Created by lucig on 11/4/2026.
//

#include "IncidenciaBase.h"

IncidenciaBase::IncidenciaBase(const string& id, int dia)
: Incidencia(id, dia) {}

int IncidenciaBase::getSeveridad() const
{
    return 1; // la seriedad de la base es 1, no es algo grave, solo es base
}

string IncidenciaBase::getDescripcion() const
{
    return "Incidencia ";
}
