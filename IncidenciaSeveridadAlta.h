//
// Created by lucig on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_INCIDENCIASEVERIDADALTA_H
#define PROYECTOL_PROGRAMACIONLL_INCIDENCIASEVERIDADALTA_H

#include "DecoradorIncidencia.h"

class IncidenciaSeveridadAlta : public DecoradorIncidencia
{
public:
    IncidenciaSeveridadAlta(Incidencia* incidencia);

    int getSeveridad() const override;
    string getDescripcion() const override;
};


#endif //PROYECTOL_PROGRAMACIONLL_INCIDENCIASEVERIDADALTA_H