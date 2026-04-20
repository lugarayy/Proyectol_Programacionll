//
// Created by lucig on 19/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_INCIDENCIASEVERIDADBAJA_H
#define PROYECTOL_PROGRAMACIONLL_INCIDENCIASEVERIDADBAJA_H

#include  "DecoradorIncidencia.h"

class IncidenciaSeveridadBaja : public DecoradorIncidencia
{
public:
    IncidenciaSeveridadBaja(Incidencia* incidencia);

    int getSeveridad() const override;
    string getDescripcion() const override;
};

#endif //PROYECTOL_PROGRAMACIONLL_INCIDENCIASEVERIDADBAJA_H