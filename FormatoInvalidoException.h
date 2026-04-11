//
// Created by Jose on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_FORMATOINVALIDOEXCEPTION_H
#define PROYECTOL_PROGRAMACIONLL_FORMATOINVALIDOEXCEPTION_H
#include "InvalidoException.h"
#include <string>

class FormatoInvalidoException : public InvalidoException {
private:
    string msj= "Formato Invalido";
public:
    FormatoInvalidoException();
};


#endif //PROYECTOL_PROGRAMACIONLL_FORMATOINVALIDOEXCEPTION_H