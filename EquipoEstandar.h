//
// Created by lucig on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_EQUIPOESTANDAR_H
#define PROYECTOL_PROGRAMACIONLL_EQUIPOESTANDAR_H

#include "Equipo.h"

class EquipoEstandar : public Equipo
{
public:
    EquipoEstandar(const string &id,int crti, int estado);

    void degradar() override;
    void aplicaMantenimiento() override;
    string getTipo() const override;
};


#endif //PROYECTOL_PROGRAMACIONLL_EQUIPOESTANDAR_H