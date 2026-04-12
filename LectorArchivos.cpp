//
// Created by Jose on 11/4/2026.
//

#include "LectorArchivos.h"
#include "MenorACeroException.h"

LectorArchivos::LectorArchivos() {}

vector<Equipo*> LectorArchivos::lectorDeArchivos(const string &equipos) {
    ifstream archivo(equipos);
    if (!archivo.is_open()) throw ArchivoInvalidoException();
    vector<Equipo*> equiposLeidos;
    string linea;

    while (getline(archivo, linea)) {
        istringstream ss(linea);
        string id, sCriticidad, sEstado;

        // Formato: ID; Criticidad; Estado
        getline(ss, id, ';');
        getline(ss, sCriticidad, ';');
        getline(ss, sEstado, ';');

        if (id.empty() || sCriticidad.empty() || sEstado.empty()) {
            throw FormatoInvalidoException();
        }

        int criticidad, estado;
        try {
            criticidad = stoi(sCriticidad);
            estado     = stoi(sEstado);
        } catch (invalid_argument&) {
            throw FormatoInvalidoException();
        }

        if (criticidad < 0 || estado < 0) throw MenorACeroException();

        // Critico si criticidad > 5, estandar si <= 5
        if (criticidad > 5)
            equiposLeidos.push_back(new EquipoCritico(id, criticidad, estado));
        else
            equiposLeidos.push_back(new EquipoEstandar(id, criticidad, estado));
    }

    return equiposLeidos;
}

LectorArchivos::~LectorArchivos() {}
