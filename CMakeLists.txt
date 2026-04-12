cmake_minimum_required(VERSION 4.1)
project(Proyectol_Programacionll)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyectol_Programacionll
        main.cpp
        GeneradorReportes.cpp
        GeneradorReportes.h
        Equipo.cpp
        Equipo.h
        EquipoCritico.cpp
        EquipoCritico.h
        EquipoEstandar.cpp
        EquipoEstandar.h
        OrdenamientoDiario.cpp
        OrdenamientoDiario.h
        Simulador.cpp
        Simulador.h
        ArchivoInvalidoException.cpp
        ArchivoInvalidoException.h
        FormatoInvalidoException.cpp
        FormatoInvalidoException.h
        OperacionInconsistenteException.cpp
        OperacionInconsistenteException.h
        Incidencia.cpp
        Incidencia.h
        IncidenciaBase.cpp
        IncidenciaBase.h
        InvalidoException.cpp
        InvalidoException.h
        LectorArchivos.cpp
        LectorArchivos.h
        MenorACeroException.cpp
        MenorACeroException.h)