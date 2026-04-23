//
// Created by Jose on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_SIMULADOR_H
#define PROYECTOL_PROGRAMACIONLL_SIMULADOR_H

#include <vector>
#include "Equipo.h"
#include "EquipoCritico.h"
#include "EleccionPrioridad.h"
#include "Ordenamiento.h"
#include "LectorArchivos.h"
#include "GeneradorReportes.h"
#include "GeneradorIncidencias.h"
using namespace std;

const int diasSimulacion = 30; // definimos los 30 dias de un solo con una constante

class Simulador {
private:
    int diaSimulador;
    vector<Equipo*> equipos;
    Ordenamiento ordenamiento;
    EleccionPrioridad eleccionPrioridad;
    GeneradorReportes generadorReportes;
    GeneradorIncidencias generadorIncidencias;

    //Parnas y Responsabilidad unica
    void ejecutaDiasSimulacion();
    void degradaEquiposSimulacion() const;
    void aplicaMantenimiento(vector<Equipo*>& eqSel);
public:
    Simulador();
    ~Simulador();

    //lo necesario, lo que el usuario si puede acceder
    void cargarEquipos(const string& archivo);
    void ejecuta();
};


#endif //PROYECTOL_PROGRAMACIONLL_SIMULADOR_H
