//
// Created by Jose on 11/4/2026.
//

#include "Simulador.h"

void Simulador::ejecutaDiasSimulacion()
{
    degradaEquiposSimulacion();
    generarIncidencias();

    //ordena los equipos
    equipos = ordenamientoDiario.ordenar(equipos);

    //vector de los equipos seleccionados donde selecciona por prioridad
    vector<Equipo*> eqSel = eleccionPrioridad.seleccionPrioridad(equipos);

    aplicaMantenimiento(eqSel);

    cout <<"Equipos Atendidos: "<< endl;
    for (int i= 0; i < eqSel.size(); i++)
    {
        cout << eqSel[i]->getId() << " (" << eqSel[i]->getPrioridad() << ")";

        //se hace downcast por que agarra un equipo
        //pero se quiere ver si es un equipo critico
        EquipoCritico* critico = dynamic_cast<EquipoCritico*>(eqSel[i]);
        if (critico && critico->getEstado() < 30)
        {
            critico->generaAlerta();
        }
    }
    cout << endl;
}

void Simulador::degradaEquiposSimulacion()
{
    for (int i= 0; i < equipos.size(); i++)
    {
        equipos[i]->degradar();
    }
}

void Simulador::generarIncidencias()
{
    for (int i= 0; i < equipos.size(); i++)
    {
        if (rand() % 100 < 20) // 20% de posibilidad de generar incidencia
        {
            int tipo = rand() % 3; // de los tres tipos que hay elige random
            Incidencia* inci;

            if (tipo == 0)
            {
                inci = new IncidenciaSeveridadBaja(new IncidenciaBase(equipos[i]->getId(), diaSimulador));
            } else if (tipo == 1)
            {
                inci = new IncidenciaSeveridadMedia(new IncidenciaBase(equipos[i]->getId(), diaSimulador));

            }else
            {
                inci = new IncidenciaSeveridadAlta(new IncidenciaBase(equipos[i]->getId(), diaSimulador));

            }
          equipos[i]->agregarIncidencias(inci);
        }
    }
}

void Simulador::aplicaMantenimiento(vector<Equipo*>& eqSel)
{
    for (int i = 0; i < eqSel.size(); i++)
    {
        eqSel[i]->aplicaMantenimiento();
    }
}

Simulador::Simulador() : diaSimulador(1){}

Simulador::~Simulador()
{
    for (int i= 0; i < equipos.size(); i++)
    {
        delete equipos[i];
    }
    equipos.clear();
}

void Simulador::cargarEquipos(const string& archivo)
{
    LectorArchivos lector;
    equipos = lector.lectorDeArchivos(archivo);
}

void Simulador::ejecuta()
{
    for (diaSimulador= 1; diaSimulador <= diasSimulacion; diaSimulador++)
    {
        cout << "Dia de la simulacion: " << diaSimulador << endl;
        ejecutaDiasSimulacion();
    }
}
