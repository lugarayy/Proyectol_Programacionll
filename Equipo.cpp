//
// Created by lucig on 11/4/2026.
//

#include "Equipo.h"
#include "Incidencia.h"

Equipo::Equipo(const string& id, double criti, int est)
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
    if ((criticidad * 0.5) + (inciActivas * 0.3) + (tiempoInactivo * 0.2) > 10)
    {
        return 10;
    }
    return (criticidad * 0.5) + (inciActivas * 0.3) + (tiempoInactivo * 0.2);
}

string Equipo::getId() const { return id; }
double Equipo::getCriticidad() const { return criticidad; }
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
    inciActivas++;
    incidencias.push_back(in);

}

void Equipo::actualizarIncidencias()
{
    inciActivas = incidencias.size();
}

void Equipo::setCriticidad(double nuevoCri)
{
    if (nuevoCri < 0)
    {
        criticidad = 0;
    } else if (nuevoCri > 10)
    {
        criticidad = 10;
    } else
    {
        criticidad = nuevoCri;
    }
}
