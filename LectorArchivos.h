//
// Created by Jose on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_LECTORARCHIVOS_H
#define PROYECTOL_PROGRAMACIONLL_LECTORARCHIVOS_H
#include "Equipo.h"
#include <string>
#include <vector>

using namespace std;

class LectorArchivos {
    public:
    LectorArchivos();
    vector<Equipo*> lectorDeArchivos(const string &equipos);
    void leerIncidencias(const string& archivoIncidencias, vector<Equipo*>& equiposLeidos);
    ~LectorArchivos();
};


#endif //PROYECTOL_PROGRAMACIONLL_LECTORARCHIVOS_H