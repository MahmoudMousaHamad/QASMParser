#include "GateApplication.h"

GateApplication::GateApplication(
    GateType gateType, 
    Params gateParams, 
    vector<Argument> gateArgs) : Statement("GateApplication") {
    this->gateType = gateType;
    this->gateParams = gateParams;
    this->gateArgs = gateArgs;
}

GateApplication* GateApplication::Create(string s) {
    GateType gateType;
    Params gateParams; 
    vector<Argument> gateArguments;

    vector<string> tokens = HelperParser::Tokenize(s, ' ');

    if (tokens.size() == 1) {
        gateArguments = HelperParser::ParseArgs(tokens.at(0));
    } else if (tokens.size() == 2) {
        gateArguments = HelperParser::ParseArgs(tokens.at(1)); 
    } else {
        throw "Gate Application tokens are not the correct size.";
    }

    // remember that paranthesize are optional if no params are present
    if (tokens.size() == 1) {
        gateParams = Params();
    } else {
        gateParams = Params(HelperParser::GetParams(tokens.at(0)));
    }

    return new GateApplication(gateType, gateParams, gateArguments);
}

GateType GateApplication::getGateType() { return this->gateType; }

Params GateApplication::getGateParams() { return this->gateParams; }

vector<Argument> GateApplication::getGateArgs() {
    return this->gateArgs;
}
