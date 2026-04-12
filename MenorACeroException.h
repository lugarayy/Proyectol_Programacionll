//
// Created by Jose on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_MENORACEROEXCEPTION_H
#define PROYECTOL_PROGRAMACIONLL_MENORACEROEXCEPTION_H
#include "InvalidoException.h"
#include <string>

class MenorACeroException : public InvalidoException {
private:
    string msj= "Dato numerico menor a 0";
public:
    MenorACeroException();
};


#endif //PROYECTOL_PROGRAMACIONLL_MENORACEROEXCEPTION_H