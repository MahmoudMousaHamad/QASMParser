#include "IfBlock.h"

IfBlock::IfBlock(Argument carg, int intValue, Statement bodyStatements) {
    this->carg = carg;
    this->intValue = intValue;
    this->bodyStatements = bodyStatements;
}

Statement IfBlock::Create(string s) {
    // TODO: FIXME: why argument pointer?
    Argument carg = HelperParser::GetConditionCarg(s);
    int intValue = HelperParser::GetConditionInt(s);
    Statement bodyStatements = HelperParser::GetIfBlockQop(s); // TODO: is it always a single operation or can it have multiple ones?

    return IfBlock(carg, intValue, bodyStatements);
}

Argument IfBlock::getcarg() { return this->carg; }

int IfBlock::getIntValue() { return this->intValue; }

Statement IfBlock::getBodyStatements() { return this->bodyStatements; }
