//
// Created by lucig on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_DECORADORINCIDENCIA_H
#define PROYECTOL_PROGRAMACIONLL_DECORADORINCIDENCIA_H

#include "Incidencia.h"

class DecoradorIncidencia : public Incidencia
{
protected:
    Incidencia* incidencia;
public:
    DecoradorIncidencia(Incidencia* incidencia);
    virtual ~DecoradorIncidencia();

    int getSeveridad() const override;
    string getDescripcion() const override;
};


#endif //PROYECTOL_PROGRAMACIONLL_DECORADORINCIDENCIA_H