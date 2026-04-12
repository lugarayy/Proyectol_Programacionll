//
// Created by lucig on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_EQUIPOCRITICO_H
#define PROYECTOL_PROGRAMACIONLL_EQUIPOCRITICO_H

#include "Equipo.h"

class EquipoCritico : public Equipo
{
public:
    EquipoCritico(const string &id,int crti, int estado);

    void degradar() override;
    void aplicaMantenimiento() override;
    string getTipo() const override;

    //para el downcast
    void generaAlerta() const ;
};


#endif //PROYECTOL_PROGRAMACIONLL_EQUIPOCRITICO_H