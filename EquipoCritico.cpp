//
// Created by lucig on 11/4/2026.
//

#include "EquipoCritico.h"
#include <cstdlib> //se usa para el random

EquipoCritico::EquipoCritico(const string& id, double crti, int estado)
    : Equipo(id, crti, estado){}

void EquipoCritico::degradar(int dia, Equipo& equipo){
    int degradado;
    degradado = 3 +(rand() % 3); //hacemos que se degraden de 3 y 5
    setEstado(getEstado() - degradado);
    setCriticidad(getCriticidad() + 0.20);
    if (getInciActivas()>0)incrementaTiempoInactivo();
}

void EquipoCritico::aplicaMantenimiento()
{
    /* si pierde 5 por dia, y el estado es de 20, queda en 45, por ejemplo*/
    setEstado(getEstado() + 45);
    resetTiempoInactivo();
    if (inciActivas > 0) //una incidencia por dia no todas
    {
        inciActivas--;
    }
    if (getInciActivas() > 0) setCriticidad(getCriticidad() - 5);
    if (getInciActivas() <= 0) setCriticidad(0);
}

string EquipoCritico::getTipo() const
{
    return "CRITICO";
}

void EquipoCritico::generaAlerta() const
{
    cout << "Equipo "<<id<<" en estado critico!" << " Estado: "<< estado<< endl;
}
