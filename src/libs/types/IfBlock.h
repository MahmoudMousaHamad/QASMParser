#pragma once
#include "Statement.h"
#include "HelperParser.h"
#include "Argument.h"
class IfBlock : public Statement {
  public:
    IfBlock(Argument carg, int intValue, Statement* bodyStatement);

    static IfBlock* Create(string s);

    Argument getcarg();
    int getIntValue();
    Statement* getBodyStatements();

    boost::any value() { return this; }

  private:
    Argument carg;
    int intValue;
    Statement* bodyStatement;
};