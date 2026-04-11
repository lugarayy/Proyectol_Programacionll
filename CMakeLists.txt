cmake_minimum_required(VERSION 4.2)
project(Proyectol_Programacionll)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyectol_Programacionll main.cpp
        main.cpp
        GeneradorReportes.cpp
        GeneradorReportes.h
        OrdenamientoDiario.cpp
        OrdenamientoDiario.h
        Simulador.cpp
        Simulador.h
        ArchivoInvalidoException.cpp
        ArchivoInvalidoException.h
        FormatoInvalidoException.cpp
        FormatoInvalidoException.h
        OperacionInconsistenteException.cpp
        OperacionInconsistenteException.h)
