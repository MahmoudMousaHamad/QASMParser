#include "IfBlock.h"

IfBlock::IfBlock(Argument carg, int intValue, Statement* bodyStatement) : Statement("IfBlock") {
    this->carg = carg;
    this->intValue = intValue;
    this->bodyStatement = bodyStatement;
}

IfBlock* IfBlock::Create(string s) {
    Argument carg = HelperParser::GetConditionCarg(s);
    int intValue = HelperParser::GetConditionInt(s);
    Statement* bodyStatement = HelperParser::GetIfBlockQop(s); // TODO: is it always a single operation or can it have multiple ones?

    return new IfBlock(carg, intValue, bodyStatement);
}

Argument IfBlock::getcarg() { return this->carg; }

int IfBlock::getIntValue() { return this->intValue; }

Statement* IfBlock::getBodyStatements() { return this->bodyStatement; }
