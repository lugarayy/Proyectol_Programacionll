//
// Created by Jose on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_GENERADORREPORTES_H
#define PROYECTOL_PROGRAMACIONLL_GENERADORREPORTES_H
#include <filesystem>
#include <fstream>
#include <vector>
#include "Equipo.h"
#include "calcularRiesgo.h"
using namespace std;
namespace fs = filesystem;

class GeneradorReportes {

public:
    GeneradorReportes();
    void generarDia(int dia, vector<Equipo*> &atendidos, vector<Equipo*> &todos);\

};



#endif //PROYECTOL_PROGRAMACIONLL_GENERADORREPORTES_H