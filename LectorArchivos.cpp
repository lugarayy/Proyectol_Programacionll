//
// Created by Jose on 11/4/2026.
//

#include "LectorArchivos.h"

#include "MenorACeroException.h"

LectorArchivos::LectorArchivos() {}

vector<Equipo*> LectorArchivos::lectorDeArchivos(const string &equipos) {
    vector<Equipo*> equiposLeidos;
    ifstream archivo(equipos);
    if (!archivo.is_open()) {
        throw ArchivoInvalidoException();
    }

    string linea;
    while (getline(archivo, linea)) {
        istringstream ss(linea);
        string id, tipo, sCriticidad, sEstado;
        getline(ss, id, ',');
        getline(ss, tipo, ',');
        getline(ss, sCriticidad, ',');
        getline(ss, sEstado, ',');

        if (id.empty() || tipo.empty() || sCriticidad.empty() || sEstado.empty()) {
            throw FormatoInvalidoException();
        }
        int criticidad = stoi(sCriticidad);
        int estado = stoi(sEstado);

        if (criticidad < 0 || estado < 0) {
            throw MenorACeroException();
        }
        if (tipo=="critico") {
            equiposLeidos.push_back(new EquipoCritico(id, criticidad, estado));
        } else if (tipo=="estandar") {
            equiposLeidos.push_back(new EquipoEstandar(id, criticidad, estado));
        } else {
            throw FormatoInvalidoException();
        }
    }
    return equiposLeidos;
}

LectorArchivos::~LectorArchivos() {}
