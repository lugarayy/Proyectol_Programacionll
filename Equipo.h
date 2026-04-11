//
// Created by lucig on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_EQUIPO_H
#define PROYECTOL_PROGRAMACIONLL_EQUIPO_H

#include <iostream>
#include <vector>
using namespace std;

class Incidencia; // fc con dependencia mutua

class Equipo
{
    protected:
    string id;
    int criticidad;
    int estado;
    int tiempoInactivo; //los dias
    int inciActivas;
    vector <Incidencia*> incidencias;

public:
    Equipo(const string &id, int criti, int est);
    virtual ~Equipo();

    virtual void degradar() = 0;
    virtual void aplicaMantenimiento() = 0;
    virtual string getTipo() const = 0;

    //formula RF4
    double getPrioridad() const;

    string getId() const;
    int getCriticidad() const;
    int getEstado() const;
    int getTiempoInactivo() const;
    int getInciActivas() const;

    void setEstado(int nuevoes);

    void incrementaTiempoInactivo();
    void resetTiempoInactivo();
    void agregarIncidencias(Incidencia* in);
    void actualizarIncidencias();
};


#endif //PROYECTOL_PROGRAMACIONLL_EQUIPO_H