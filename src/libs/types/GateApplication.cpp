#include "GateApplication.h"

GateApplication::GateApplication(
    GateType gateType, 
    Params* gateParams, 
    vector<Argument> gateArgs) {
    this->gateType = gateType;
    this->gateParams = gateParams;
    this->gateArgs = gateArgs;
}

Statement* GateApplication::Create(string s) {
    GateType gateType; // TODO: FIXME: why do we need gate type for gate application?
    Params* gateParams; 
    vector<Argument> gateArguments;

    vector<string> tokens = HelperParser::Tokenize(s);

    if (tokens.size() == 1) {
        gateArguments = HelperParser::ParseArgs(tokens.at(0));
    } else if (tokens.size() == 2) {
        gateArguments = HelperParser::ParseArgs(tokens.at(1)); 
    } else {
        throw new exception("Gate Application tokens are not the correct size.");
    }

    // remember that paranthesize are optional if no params are present
    if (tokens.size() == 1) {
        gateParams = NULL; // TODO: FIXME
    } else {
        tokens.at(0) = HelperParser::RemoveChars(tokens.at(0), ['(', ')']);
        string *stringparams = HelperParser::Tokenize(tokens.at(0), ','); 
        gateParams = new Params(stringparams);
    }

    return new GateApplication(gateType, gateParams, gateArguments);
}

GateType GateApplication::getGateType() { return this->gateType; }

Params* GateApplication::getGateParams() { return this->gateParams; }

vector<Argument> GateApplication::getGateArgs() {
    return this->gateArgs;
}
