//
// Created by Jose on 11/4/2026.
//

#include "LectorArchivos.h"
#include "ArchivoInvalidoException.h"
#include "DefinirEquipo.h"
#include "FormatoInvalidoException.h"
#include "BusquedaBinaria.h"
#include "GeneradorIncidencias.h"
#include "Ordenamiento.h"
#include <fstream>
#include <sstream>

namespace {
string limpiar(const string& txt) {
    const string ws = " \t\n\r\f\v";
    size_t ini = txt.find_first_not_of(ws);
    if (ini == string::npos) return "";
    size_t fin = txt.find_last_not_of(ws);
    return txt.substr(ini, fin - ini + 1);
}

string valorCampo(const string& campo) {
    size_t pos = campo.find('=');
    if (pos == string::npos) return limpiar(campo);
    return limpiar(campo.substr(pos + 1));
}

int leerEntero(const string& campo) {
    string v = valorCampo(campo);
    if (v.empty()) throw FormatoInvalidoException();
    try {
        return stoi(v);
    } catch (invalid_argument&) {
        throw FormatoInvalidoException();
    }
}
}

LectorArchivos::LectorArchivos() {}

vector<Equipo*> LectorArchivos::lectorDeArchivos(const string &equipos) {
    ifstream archivo(equipos);
    if (!archivo.is_open()) throw ArchivoInvalidoException();
    vector<Equipo*> equiposLeidos;
    string linea;

    while (getline(archivo, linea)) {
        linea = limpiar(linea);
        if (linea.empty()) continue;

        istringstream ss(linea);
        string id, sCriticidad, sEstado;

        // Formato: EQ-001; criticidad = 9; estado = 70
        getline(ss, id, ';');
        id = limpiar(id);
        if (id == "INC") continue; // Permite archivo mixto como el ejemplo del README.
        getline(ss, sCriticidad, ';');
        getline(ss, sEstado, ';');

        if (id.empty() || sCriticidad.empty() || sEstado.empty()) {
            throw FormatoInvalidoException();
        }

        int criticidad = leerEntero(sCriticidad);
        int estado = leerEntero(sEstado);

        DefinirEquipo def;
        def.definirEquipoConVariables(criticidad, estado, id, equiposLeidos);
    }

    return equiposLeidos;
}

void LectorArchivos::leerIncidencias(const string& archivoIncidencias, vector<Equipo*>& equiposLeidos) {
    ifstream archivo(archivoIncidencias);
    if (!archivo.is_open()) throw ArchivoInvalidoException();

    vector<Equipo*> equiposOrdenados = equiposLeidos;
    Ordenamiento ord;
    ord.ordenarPorId(equiposOrdenados);
    BusquedaBinaria busqueda;
    GeneradorIncidencias generador;

    string linea;
    while (getline(archivo, linea)) {
        linea = limpiar(linea);
        if (linea.empty()) continue;

        istringstream ss(linea);
        string inc, id, severidad, diaInc;
        getline(ss, inc, ';');
        inc = limpiar(inc);

        // Formato: INC; EQ-001; severidad = ALTA; dia = 3
        if (inc == "INC") {
            getline(ss, id, ';');
            getline(ss, severidad, ';');
            getline(ss, diaInc, ';');
        } else {
         throw FormatoInvalidoException();
        }

        id = limpiar(id);
        severidad = valorCampo(severidad);
        diaInc = valorCampo(diaInc);

        if (id.empty() || severidad.empty() || diaInc.empty()) throw FormatoInvalidoException();

        int dia = leerEntero(diaInc);

        Equipo* eq = busqueda.buscarEquipoPorId(equiposOrdenados, id);
        if (!eq) throw FormatoInvalidoException();

        Incidencia* inci = generador.crearIncidenciaPorSeveridad(severidad, id, dia);

        eq->agregarIncidencias(inci);
    }
}

LectorArchivos::~LectorArchivos() {}
