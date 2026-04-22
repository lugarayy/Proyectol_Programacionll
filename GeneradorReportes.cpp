//
// Created by Jose on 11/4/2026.
//

#include "GeneradorReportes.h"

GeneradorReportes::GeneradorReportes() {
    if (fs::exists("Simulacion")) fs::remove_all("Simulacion");
    fs::create_directory("Simulacion");
} //Crear nuestra carpeta Simulacion para guardar los reportes, tambien eliminarla si ya existe, para nuevas simulaciones

void GeneradorReportes::generarDia(int dia, vector<Equipo*>& atendidos, vector<Equipo*>& todos) {
    //Las referencias simplemente son para no estar copiando vectores.
    ofstream archivo("Simulacion/dia_" + to_string(dia) + ".txt");

    //El to_string es para convertir el numero del dia a string y asi poder crear un archivo con el nombre dia_1.txt, dia_2.txt, etc.

    archivo << "Dia " << dia << "\n";

    archivo << "Top prioridad: ";
    for (int i = 0; i < atendidos.size(); i++) {
        if (i > 0) archivo << ", ";
        archivo << atendidos[i]->getId() << " (" << atendidos[i]->getPrioridad() << ")";
    }
    archivo << "\n";

    archivo << "Asignados: ";
    for (int i = 0; i < atendidos.size(); i++) {
        if (i > 0) archivo << ", ";
        archivo << atendidos[i]->getId();
    }
    archivo << "\n";
    archivo << "Backlog pendiente: " << (todos.size() - atendidos.size()) << "\n";
    CalcularRiesgo calcular_riesgo(todos);
    archivo << "Riesgo global: " <<calcular_riesgo.getRiesgo()<< "\n";
}

void GeneradorReportes::generarReporteAcumulado(vector<Equipo*>& todos) {
    ofstream archivo("Simulacion/reporte_final.txt");

    archivo << "=== Reporte de 30 dias ===\n\n";
    archivo << "Estado final de equipos:\n";\
    for (int i = 0; i < todos.size(); i++) {
        archivo << todos[i]->getId()
                << "   | Estado: " << todos[i]->getEstado()
                << "   | Prioridad: " << todos[i]->getPrioridad()
        <<"   | Incidencias Activas: " << todos[i]->getInciActivas()
        << "\n";
    }

    archivo << "\n";
    CalcularRiesgo calcular_riesgo(todos);
    archivo << "Riesgo global final: " << calcular_riesgo.getRiesgo() << "\n";
    archivo << "Equipos en backlog final: " << todos.size() << "\n";
}
