#include "GateApplication.h"

GateApplication::GateApplication(
    string gateIdentifier,
    GateType gateType, 
    Params gateParams, 
    vector<Argument> gateArgs) : Statement("GateApplication") {
    this->identifier = gateIdentifier;
    this->gateType = gateType;
    this->gateParams = gateParams;
    this->gateArgs = gateArgs;
}

GateApplication* GateApplication::Create(string gateIdentifier, string s) {
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

    return new GateApplication(gateIdentifier, gateType, gateParams, gateArguments);
}

GateType GateApplication::getGateType() { return this->gateType; }

Params GateApplication::getGateParams() { return this->gateParams; }

vector<Argument> GateApplication::getGateArgs() {
    return this->gateArgs;
}

string GateApplication::getIdentifier() {
    return this->identifier;
}

string GateApplication::toString() {
    string gate_args_s = "";

    for (int i = 0; i < gateArgs.size(); ++i) {
        gate_args_s += gateArgs.at(i).toString();

        if (i < gateArgs.size() - 1) {
            gate_args_s += ",";
        }
    }

    return identifier + " " + gate_args_s + ";";
}