//
// Created by Jose on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_OPERACIONINCONSISTENTEEXCEPTION_H
#define PROYECTOL_PROGRAMACIONLL_OPERACIONINCONSISTENTEEXCEPTION_H
#include "InvalidoException.h"
#include <string>

class OperacionInconsistenteException : public InvalidoException {
private:
    string msj= "Formato Invalido";
public:
    OperacionInconsistenteException();
};

#endif //PROYECTOL_PROGRAMACIONLL_OPERACIONINCONSISTENTEEXCEPTION_H