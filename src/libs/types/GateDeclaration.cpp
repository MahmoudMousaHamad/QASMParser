#include "GateDeclaration.h"

GateDeclaration::GateDeclaration(
    string identifier,
    Params *params,
    vector<Argument> qargs,
    vector<Statement> bodyStatements,
    GateType gateType) {
    this->identifier = identifier;
    this->params = params;
    this->qargs = qargs;
    this->bodyStatements = bodyStatements;
    this->gateType = gateType;
}

Statement* GateDeclaration::Create(string s, GateType gateType = GateType::unitary) {
    vector<string> tokens = HelperParser::Tokenize(s);

    string identifier = HelperParser::GetName(tokens.at(0));
    Params params = HelperParser::GetParams(tokens.at(0));
    vector<Argument> qargs = HelperParser::ParseArgs(tokens.at(1));
    vector<Statement> bodyStatements = HelperParser::GetBodyStatements(s);

    return new GateDeclaration(identifier, params, qargs, bodyStatements, gateType);
}

string GateDeclaration::getIdentifier() { return this->identifier; }

Params* GateDeclaration::getGateParams() { return this->params; }

vector<Argument> GateDeclaration::getQargs() { return this->qargs; }

vector<Statement> GateDeclaration::getBodyStatements() { return this->bodyStatements; }

GateType GateDeclaration::getGateType() { return this->gateType; }

