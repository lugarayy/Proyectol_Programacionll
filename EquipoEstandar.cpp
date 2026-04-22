//
// Created by lucig on 11/4/2026.
//

#include "EquipoEstandar.h"
#include <cstdlib> // para random

EquipoEstandar::EquipoEstandar(const string& id, double crti, int estado)
    : Equipo(id, crti, estado){}

void EquipoEstandar::degradar(int dia, Equipo& equipo)
{
    int degradado;
    //como es estandar, es mas lento q uno ciritico
    degradado = 1 +(rand() % 3); //hacemos que se degraden de 1 y 3
    setEstado(getEstado() - degradado);
    setCriticidad(getCriticidad() + 0.20);
    incrementaTiempoInactivo();
}

void EquipoEstandar::aplicaMantenimiento()
{
    /*este por cambio, recupera menos que uno ciritico*/
    setEstado(getEstado() + 40);
    resetTiempoInactivo();
    if (inciActivas > 0) //una incidencia por dia no todas
    {
        inciActivas--;
    }
    if (getInciActivas() > 0) setCriticidad(getCriticidad() - 4);
    if (getInciActivas() <= 0) setCriticidad(0);
}

string EquipoEstandar::getTipo() const
{
    return "ESTANDAR";
}
