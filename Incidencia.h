//
// Created by lucig on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_INCIDENCIA_H
#define PROYECTOL_PROGRAMACIONLL_INCIDENCIA_H

#include <iostream>
using namespace std;

class Equipo;

class Incidencia
{
protected:
    //asi sabemos cuales equipos tiene cuales incidencias
   string IdEquipo;
    int diaDiagnostico;
public:
    Incidencia(const string& id, int dia);
    virtual ~Incidencia() {}

    virtual int getSeriedad() const = 0;
    virtual string getDescripcion() const = 0;

    string getEquipoId() const;
    int getDiaDiagnostico() const;
};


#endif //PROYECTOL_PROGRAMACIONLL_INCIDENCIA_H