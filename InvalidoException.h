//
// Created by Jose on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_INVALIDOEXCEPTION_H
#define PROYECTOL_PROGRAMACIONLL_INVALIDOEXCEPTION_H
#include <exception>
#include <iostream>
using namespace std;

class InvalidoException : public exception {
protected:
    string msg;
public:
    InvalidoException();
    explicit InvalidoException(const string &msg); //El explicit está para evitar la inicializacion en automatico,
    //el const porque no se va a modificar y la referencia para no hacer una copia del string.
};


#endif //PROYECTOL_PROGRAMACIONLL_INVALIDOEXCEPTION_H