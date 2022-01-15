#include "GateDeclaration.h"

GateDeclaration::GateDeclaration(
    string identifier,
    Params *params,
    vector<string> qargs,
    vector<Statement> bodyStatements,
    GateType gateType) {
    this->identifier = identifier;
    this->params = params;
    this->qargs = qargs;
    this->bodyStatements = bodyStatements;
    this->gateType = gateType;
}

Statement* GateDeclaration::Create(string identifier,
    Params *params,
    vector<string> qargs,
    vector<Statement> bodyStatements,
    GateType gateType) {

    return new GateDeclaration(identifier, params, qargs, bodyStatements, gateType);
}

string GateDeclaration::getIdentifier() { return this->identifier; }

Params* GateDeclaration::getGateParams() { return this->params; }

vector<string> GateDeclaration::getQargs() { return this->qargs; }

vector<Statement> GateDeclaration::getBodyStatements() { return this->bodyStatements; }

GateType GateDeclaration::getGateType() { return this->gateType; }

