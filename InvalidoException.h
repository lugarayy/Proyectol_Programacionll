//
// Created by Jose on 11/4/2026.
//

#ifndef PROYECTOL_PROGRAMACIONLL_INVALIDOEXCEPTION_H
#define PROYECTOL_PROGRAMACIONLL_INVALIDOEXCEPTION_H

#include <stdexcept>
#include <string>
using namespace std;

class InvalidoException : public runtime_error {
public:
    explicit InvalidoException(const string &msg);
};

#endif //PROYECTOL_PROGRAMACIONLL_INVALIDOEXCEPTION_H
