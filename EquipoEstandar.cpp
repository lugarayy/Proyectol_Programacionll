//
// Created by lucig on 11/4/2026.
//

#include "EquipoEstandar.h"
#include <cstdlib> // para random

EquipoEstandar::EquipoEstandar(const string& id, int crti, int estado)
    : Equipo(id, crti, estado){}

void EquipoEstandar::degradar()
{
    int degradado;
    //como es estandar, es mas lento q uno ciritico
    degradado = 1 +(rand() % 3); //hacemos que se degraden de 1 y 3
    setEstado(getEstado() - degradado);
    setCriticidad(getCriticidad() + 2);
    incrementaTiempoInactivo();
}

void EquipoEstandar::aplicaMantenimiento()
{
    /*este por cambio, recupera menos que uno ciritico*/
    setEstado(getEstado() + 40);
    setCriticidad(getCriticidad() - 2);
    resetTiempoInactivo();
    if (inciActivas > 0) //una incidencia por dia no todas
    {
        inciActivas--;
    }
}

string EquipoEstandar::getTipo() const
{
    return "ESTANDAR";
}
