//
// Created by lucig on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_EQUIPOESTANDAR_H
#define PROYECTOL_PROGRAMACIONLL_EQUIPOESTANDAR_H
#include "GeneradorIncidencias.h"
#include "Equipo.h"

class EquipoEstandar : public Equipo
{
private:
    GeneradorIncidencias generadorIncidencias;
public:
    EquipoEstandar(const string &id,double crti, int estado);

    void degradar(int dia, Equipo& equipo) override;
    void aplicaMantenimiento() override;
    string getTipo() const override;
};


#endif //PROYECTOL_PROGRAMACIONLL_EQUIPOESTANDAR_H