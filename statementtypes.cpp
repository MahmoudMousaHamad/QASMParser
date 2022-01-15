using namespace std;

#include "statementtypes.h"
#include "statement.h"
#include "helperclasses.h"

Version::Version(string version) {
    this->version = version;
}

Statement* Version::Create(string version) {
    return new Version(version);
}

string Version::getVersion() { return this->version; }


RegisterDeclaration::RegisterDeclaration(RegisterType type, string identifier, int size) {
    this->type = type;
    this->identifier = identifier;
    this->size = size;
}

Statement* RegisterDeclaration::Create(RegisterType type, string identifier, int size) {
    return new RegisterDeclaration(type, identifier, size);
}

RegisterType RegisterDeclaration::getType() { return this->type; }

string RegisterDeclaration::getIdentifier() { return this->identifier; }

int RegisterDeclaration::getSize() { return this->size; }



Include::Include(string filename) { this->filename = filename; }

Statement* Include::Create(string filename) { return new Include(filename); }

string Include::getFilename() { return this->filename; }



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

Measure::Measure(Argument *qarg, Argument *carg) {
    this->qarg = qarg;
    this->carg = carg;
}

Statement* Measure::Create(Argument *qarg, Argument *carg) {
    return new Measure(qarg, carg);
}

Argument* Measure::getQarg() { return this->qarg; }

Argument* Measure::getcarg() { return this->carg; }



Reset::Reset(Argument* arg) { this->arg = arg; }

Statement* Reset::Create(Argument* arg) { return new Reset(arg); }

Argument* Reset::getArg() { return this->arg; }



IfBlock::IfBlock(Argument* carg, int intValue, vector<Statement> bodyStatements) {
    this->carg = carg;
    this->intValue = intValue;
    this->bodyStatements = bodyStatements;
}

Statement* IfBlock::Create(Argument* carg, int intValue, vector<Statement> bodyStatements) {
    return new IfBlock(carg, intValue, bodyStatements);
}

Argument* IfBlock::getcarg() { return this->carg; }

int IfBlock::getIntValue() { return this->intValue; }

vector<Statement> IfBlock::getBodyStatements() { return this->bodyStatements; }



Barrier::Barrier(vector<Argument> args) {
    this->args = args;
}

Statement* Barrier::Create(vector<Argument> args) {
    return new Barrier(args);
}

vector<Argument> Barrier::getArgs() { return this->getArgs(); }
