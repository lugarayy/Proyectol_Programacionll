//
// Created by Jose on 11/4/2026.
//

#include "LectorArchivos.h"
//
// Created by Jose on 11/4/2026.
//

#include "LectorArchivos.h"
#include "IncidenciaBase.h"
#include "IncidenciaSeveridadAlta.h"
#include "IncidenciaSeveridadBaja.h"
#include "IncidenciaSeveridadMedia.h"
#include <algorithm>

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
            estado = stoi(sEstado);
        } catch (invalid_argument&) {
            throw FormatoInvalidoException();
        }

        DefinirEquipo def;
        def.definirEquipoConVariables(criticidad, estado, id, equiposLeidos);
    }

    return equiposLeidos;
}

void LectorArchivos::leerIncidencias(const string& archivoIncidencias, vector<Equipo*>& equiposLeidos) {
    ifstream archivo(archivoIncidencias);
    if (!archivo.is_open()) throw ArchivoInvalidoException();

    // Copia ordenada para buscar por ID con busqueda binaria.
    vector<Equipo*> equiposOrdenados = equiposLeidos;
    sort(equiposOrdenados.begin(), equiposOrdenados.end(), [](Equipo* a, Equipo* b) {
        return a->getId() < b->getId();
    });

    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;

        istringstream ss(linea);
        string id, sev, sDia;
        getline(ss, id, ';');
        getline(ss, sev, ';');
        getline(ss, sDia, ';');

        if (id.empty() || sev.empty() || sDia.empty()) throw FormatoInvalidoException();

        int dia;
        try {
            dia = stoi(sDia);
        } catch (invalid_argument&) {
            throw FormatoInvalidoException();
        }

        Equipo* eq = nullptr;
        int ini = 0;
        int fin = static_cast<int>(equiposOrdenados.size()) - 1;
        while (ini <= fin) {
            int medio = ini + (fin - ini) / 2;
            const string& idMedio = equiposOrdenados[medio]->getId();
            if (idMedio == id) {
                eq = equiposOrdenados[medio];
                break;
            }
            if (idMedio < id) ini = medio + 1;
            else fin = medio - 1;
        }
        if (!eq) throw FormatoInvalidoException();

        Incidencia* inci = nullptr;
        if (sev == "ALTA" || sev == "Alta" || sev == "alta") {
            inci = new IncidenciaSeveridadAlta(new IncidenciaBase(id, dia));
        } else if (sev == "MEDIA" || sev == "Media" || sev == "media") {
            inci = new IncidenciaSeveridadMedia(new IncidenciaBase(id, dia));
        } else if (sev == "BAJA" || sev == "Baja" || sev == "baja") {
            inci = new IncidenciaSeveridadBaja(new IncidenciaBase(id, dia));
        } else {
            throw FormatoInvalidoException();
        }

        eq->agregarIncidencias(inci);
    }
}

LectorArchivos::~LectorArchivos() {}
