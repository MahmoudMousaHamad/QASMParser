#include "GateApplication.h"


GateApplication::GateApplication(
    GateType gateType, 
    Params* gateParams, 
    vector<Argument> gateArgs) {
    this->gateType = gateType;
    this->gateParams = gateParams;
    this->gateArgs = gateArgs;
}

Statement* GateApplication::Create(
    GateType gateType, 
    Params* gateParams, 
    vector<Argument> gateArguments) {
    return new GateApplication(gateType, gateParams, gateArguments);
}

GateType GateApplication::getGateType() { return this->gateType; }

Params* GateApplication::getGateParams() { return this->gateParams; }

vector<Argument> GateApplication::getGateArgs() {
    return this->gateArgs;
}
