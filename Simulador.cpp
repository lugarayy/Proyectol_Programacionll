//
// Created by Jose on 11/4/2026.
// arreglado tambien por Lu jajaj
//

#include "Simulador.h"

#include "OperacionInconsistenteException.h"

Simulador::Simulador() : diaSimulador(1) {}
void Simulador::ejecuta() {
    if (equipos.empty()) throw OperacionInconsistenteException(); //si no se cargan equipos, no se puede ejecutar la simulacion
    for (diaSimulador= 1; diaSimulador <= diasSimulacion; diaSimulador++)
    {
        cout << "Dia de la simulacion: " << diaSimulador << endl;
        ejecutaDiasSimulacion();
    }
    ordenamiento.ordenar(equipos); //ordenamos los equipos al final de la simulacion para el reporte acumulado
    generadorReportes.generarReporteAcumulado(equipos);
}
void Simulador::ejecutaDiasSimulacion() {
    degradaEquiposSimulacion();
    generarIncidencias();

    //ordena los equipos
    ordenamiento.ordenar(equipos);

    //vector de los equipos seleccionados donde selecciona por prioridad
    vector<Equipo*> eqSel = eleccionPrioridad.seleccionPrioridad(equipos);

    cout <<"Equipos Atendidos: "<< endl;
    ordenamiento.ordenar(eqSel); //Una formalidad para que aparezca de primero el equipo con mas prioridad
    for (int i= 0; i < eqSel.size(); i++) {
        cout << eqSel[i]->getId() << " (Prioridad: " << eqSel[i]->getPrioridad() << ")"<<endl;

        //se hace downcast por que agarra un equipo
        //pero se quiere ver si es un equipo critico
        auto* critico = dynamic_cast<EquipoCritico*>(eqSel[i]);
        if (critico && critico->getEstado() < 30) {
            critico->generaAlerta();
        }
    }

    aplicaMantenimiento(eqSel);
    cout << endl;

    generadorReportes.generarDia(diaSimulador, eqSel, equipos);
}
void Simulador::degradaEquiposSimulacion() const {
    for (int i= 0; i < equipos.size(); i++)
    {
        equipos[i]->degradar();
    }
}
void Simulador::generarIncidencias(){
    generadorIncidencias.generarIncidencias(diaSimulador, equipos);
}
void Simulador::aplicaMantenimiento(vector<Equipo*>& eqSel) {
    for (int i = 0; i < eqSel.size(); i++)
    {
        eqSel[i]->aplicaMantenimiento();
    }
}
void Simulador::cargarEquipos(const string& archivo) {
    LectorArchivos lector;
    equipos = lector.lectorDeArchivos(archivo);
}
Simulador::~Simulador() {
    for (int i= 0; i < equipos.size(); i++)
    {
        delete equipos[i];
    }
    equipos.clear();
}
