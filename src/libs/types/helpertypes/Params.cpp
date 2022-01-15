#include "Params.h"

Params::Params(string theta, string phi, string lambda) {
    this->theta = theta;
    this->phi = phi;
    this->lambda = lambda;
}

string Params::getParam(ParamType type) {
    switch (type) {
        case ParamType::theta:
            return this->theta;
            break;
        case ParamType::lambda:
            return this->lambda;
            break;
        case ParamType::phi:
            return this->phi;
            break;
        default:
            break;
    }

    return '\0';
}