//
// Created by lucig on 11/4/2026.
//

#include "EleccionPrioridad.h"

EleccionPrioridad::EleccionPrioridad()
{
    this->maxDia = 3; //solo tres por dia
}

vector<Equipo*> EleccionPrioridad::seleccionPrioridad(const vector<Equipo*>& equipos)
{
    vector<Equipo*> seleccion;

    //mientras sea igual a cero, no pase de 3 y no se sale del vector
    //si hay menos de tres, o sea, que agarre los que hayan si hubiesen menos de tres
    for (int i = 0; i < maxDia && i < equipos.size(); i++)
    {
        seleccion.push_back(equipos[i]); //agarra los seleccionados
    }
    return seleccion; //y retorna
}
