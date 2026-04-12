//
// Created by lucig on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_INCIDENCIABASE_H
#define PROYECTOL_PROGRAMACIONLL_INCIDENCIABASE_H

#include "Incidencia.h"

class IncidenciaBase : public Incidencia
{
    IncidenciaBase(const string &id, int dia);

    int getSeveridad() const override;
    string getDescripcion() const override;
};


#endif //PROYECTOL_PROGRAMACIONLL_INCIDENCIABASE_H