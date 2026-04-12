//
// Created by Jose on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_LECTORARCHIVOS_H
#define PROYECTOL_PROGRAMACIONLL_LECTORARCHIVOS_H
#include "Equipo.h"
#include "EquipoCritico.h"
#include "EquipoEstandar.h"
#include "ArchivoInvalidoException.h"
#include "FormatoInvalidoException.h"
#include "MenorACeroException.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class LectorArchivos {
    public:
    LectorArchivos();
    vector<Equipo*> lectorDeArchivos(const string &equipos);
    ~LectorArchivos();
};


#endif //PROYECTOL_PROGRAMACIONLL_LECTORARCHIVOS_H