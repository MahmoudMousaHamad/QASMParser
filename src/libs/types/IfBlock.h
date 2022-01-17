#include "Statement.h"

class IfBlock : public Statement {
  public:
    IfBlock(Argument carg, int intValue, Statement bodyStatements);

    static Statement Create(string s);

    Argument getcarg();
    int getIntValue();
    Statement getBodyStatements();

  private:
    Argument carg;
    int intValue;
    Statement bodyStatements;
};