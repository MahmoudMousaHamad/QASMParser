#include "Params.h"

Params::Params(string theta, string phi, string lambda) {
    this->theta = theta;
    this->phi = phi;
    this->lambda = lambda;
}

Params::Params(vector<string> params) {
    int length = params.size();
    if (length == 1) {
        this->lambda = params[0];
    } else if (length == 2) {
        this->phi = params[0];
        this->lambda = params[1];
    } else if (length == 3) {
        this->theta = params[0];
        this->phi = params[1];
        this->lambda = params[2];
    }
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

    return "";
}