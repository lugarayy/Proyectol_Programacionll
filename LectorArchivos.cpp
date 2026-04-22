//
// Created by Jose on 11/4/2026.
//

#include "LectorArchivos.h"

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

        DefinirEquipo def;
        def.definirEquipoConVariables(criticidad, estado, id, equiposLeidos);
    }

    return equiposLeidos;
}

LectorArchivos::~LectorArchivos() {}
