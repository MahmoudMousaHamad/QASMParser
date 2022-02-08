#include "GateDeclaration.h"

GateDeclaration::GateDeclaration(
    string identifier,
    Params params,
    vector<Argument> qargs,
    vector<Statement*> bodyStatements,
    GateType gateType) : Statement("GateDeclaration") {
    this->identifier = identifier;
    this->params = params;
    this->qargs = qargs;
    this->bodyStatements = bodyStatements;
    this->gateType = gateType;
}

GateDeclaration* GateDeclaration::Create(string s, GateType gateType) {
    vector<string> tokens = HelperParser::TokenizeUntil(s, ' ', "{");
    
    // gate name(params) qargs
    string identifier = HelperParser::GetName(tokens.at(0)); // TODO: FIXME AND TEST ME WITH PARAMS
    Params params = HelperParser::GetParams(tokens.at(0)); // TODO: FIXME AND TEST ME WITH PARAMS
    vector<Argument> qargs = HelperParser::ParseArgs(tokens.at(1));
    vector<Statement*> bodyStatements = HelperParser::GetBodyStatements(s);

    return new GateDeclaration(identifier, params, qargs, bodyStatements, gateType);
}

string GateDeclaration::getIdentifier() { return this->identifier; }

Params GateDeclaration::getGateParams() { return this->params; }

vector<Argument> GateDeclaration::getQargs() { return this->qargs; }

vector<Statement*> GateDeclaration::getBodyStatements() { return this->bodyStatements; }

GateType GateDeclaration::getGateType() { return this->gateType; }

