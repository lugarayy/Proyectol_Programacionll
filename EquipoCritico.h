//
// Created by lucig on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_EQUIPOCRITICO_H
#define PROYECTOL_PROGRAMACIONLL_EQUIPOCRITICO_H
#include "GeneradorIncidencias.h"
#include "Equipo.h"

class EquipoCritico : public Equipo
{
private:
    GeneradorIncidencias generadorIncidencias;
public:
    EquipoCritico(const string &id, double criti, int estado);

    void degradar(int dia, Equipo& equipo) override;
    void aplicaMantenimiento() override;
    string getTipo() const override;
    //para el downcast
    void generaAlerta() const ;
};


#endif //PROYECTOL_PROGRAMACIONLL_EQUIPOCRITICO_H