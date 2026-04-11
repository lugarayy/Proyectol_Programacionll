//
// Created by Jose on 11/4/2026.
//

#include "InvalidoException.h"

InvalidoException::InvalidoException() {
msg="Invalido";
}

InvalidoException::InvalidoException(const string &msg) : msg(msg) {}
