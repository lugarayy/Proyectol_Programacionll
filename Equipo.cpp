//
// Created by lucig on 11/4/2026.
//

#include "Equipo.h"
#include "Incidencia.h"

Equipo::Equipo(const string& id, int criti, int est)
{
    this->id = id;
    this->criticidad = criti;
    this->estado = est;
    this->tiempoInactivo = 0;
    this->inciActivas = 0;
}

Equipo::~Equipo()
{
    for (Incidencia* incidencia : incidencias)
    {
        delete incidencia;
    }
    incidencias.clear();
}


//metodo con formula dada
double Equipo::getPrioridad() const
{
    return (criticidad * 0.5) + (inciActivas * 0.3) + (tiempoInactivo * 0.2);
}

string Equipo::getId() const { return id; }
int Equipo::getCriticidad() const { return criticidad; }
int Equipo::getEstado() const { return estado; }
int Equipo::getInciActivas() const { return inciActivas; }
int Equipo::getTiempoInactivo() const { return tiempoInactivo; }


void Equipo::setEstado(int nuevoEs)
{
    if (nuevoEs < 0)
    {
        estado = 0;
    } else if (nuevoEs > 100)
    {
        estado = 100;
    } else
    {
        estado = nuevoEs;
    }
}

void Equipo::incrementaTiempoInactivo()
{
    tiempoInactivo++;
}

void Equipo::resetTiempoInactivo()
{
    tiempoInactivo = 0;
}

void Equipo::agregarIncidencias(Incidencia* in)
{
    incidencias.push_back(in);
    inciActivas++;
}

void Equipo::actualizarIncidencias()
{
    inciActivas = incidencias.size();
}

void Equipo::setCriticidad(int nuevoCri)
{
    if (nuevoCri < 0)
    {
        criticidad = 0;
    } else if (nuevoCri > 100)
    {
        criticidad = 100;
    } else
    {
        criticidad = nuevoCri;
    }
}
