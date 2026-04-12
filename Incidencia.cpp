//
// Created by lucig on 11/4/2026.
//

#include "Incidencia.h"

Incidencia::Incidencia(const string& id, int dia)
{
    this->IdEquipo = id;
    this->diaDiagnostico = dia;
}

string Incidencia::getEquipoId() const { return IdEquipo; }
int Incidencia::getDiaDiagnostico() const { return diaDiagnostico; }



