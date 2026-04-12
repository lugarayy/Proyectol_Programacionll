//
// Created by lucig on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_INCIDENCIASEVERIDADMEDIA_H
#define PROYECTOL_PROGRAMACIONLL_INCIDENCIASEVERIDADMEDIA_H

#include "DecoradorIncidencia.h"

class IncidenciaSeveridadMedia : public DecoradorIncidencia
{
public:
    IncidenciaSeveridadMedia(Incidencia* incidencia);

    int getSeveridad() const override;
    string getDescripcion() const override;
};


#endif //PROYECTOL_PROGRAMACIONLL_INCIDENCIASEVERIDADMEDIA_H