//
// Created by lucig on 11/4/2026.
//

#include "IncidenciaBase.h"

IncidenciaBase::IncidenciaBase(const string& id, int dia)
: Incidencia(id, dia) {}

int IncidenciaBase::getSeveridad() const
{
    return 0; //no es algo grave, solo es base
}

string IncidenciaBase::getDescripcion() const
{
    return "Incidencia ";
}
