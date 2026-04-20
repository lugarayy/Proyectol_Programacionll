//
// Created by Jose on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_SIMULADOR_H
#define PROYECTOL_PROGRAMACIONLL_SIMULADOR_H

#include <vector>
using namespace std;

#include "Equipo.h"
#include "EleccionPrioridad.h"

#include "OrdenamientoDiario.h"
#include "LectorArchivos.h"

#include "IncidenciaBase.h"
#include "IncidenciaSeveridadBaja.h"
#include "IncidenciaSeveridadMedia.h"
#include "IncidenciaSeveridadAlta.h"

#include "GeneradorReportes.h"



class Simulador {
private:
    const int diasSimulacion = 30; // definimos los 30 dias de un solo con una constante
    int diaSimulador;
    vector<Equipo*> equipos;
    OrdenamientoDiario ordenamientoDiario;
    EleccionPrioridad eleccionPrioridad;

    //Parnas y Responsabilidad unica
    void ejecutaDiasSimulacion();
    void degradaEquiposSimulacion();
    void generarIncidencias();
    void aplicaMantenimiento(vector<Equipo*>& eqSel);
public:
    Simulador();
    ~Simulador();

    //lo necesario, lo que el usuario si puede acceder
    void cargarEquipos(const string& archivo);
    void ejecuta();
};


#endif //PROYECTOL_PROGRAMACIONLL_SIMULADOR_H
