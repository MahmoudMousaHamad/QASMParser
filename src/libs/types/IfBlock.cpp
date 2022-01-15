#include "IfBlock.h"

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
