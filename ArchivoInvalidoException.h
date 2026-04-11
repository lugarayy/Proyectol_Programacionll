//
// Created by Jose on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_ARCHIVOINVALIDOEXCEPTION_H
#define PROYECTOL_PROGRAMACIONLL_ARCHIVOINVALIDOEXCEPTION_H
#include "InvalidoException.h"
#include <string>

class ArchivoInvalidoException : public InvalidoException {
private:
    string msj= "Archivo Invalido";
public:
    ArchivoInvalidoException();
};

#endif //PROYECTOL_PROGRAMACIONLL_ARCHIVOINVALIDOEXCEPTION_H