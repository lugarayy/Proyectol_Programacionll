//
// Created by Jose on 11/4/2026.
//

#include "InvalidoException.h"

InvalidoException::InvalidoException(const string &msg) : runtime_error(msg) {}
