#include "Statement.h"

class IfBlock : public Statement {
  public:
    IfBlock(Argument* carg, int intValue, vector<Statement> bodyStatements);

    static Statement* Create(Argument* carg, int intValue, vector<Statement> bodyStatements);

    Argument* getcarg();
    int getIntValue();
    vector<Statement> getBodyStatements();

  private:
    Argument* carg;
    int intValue;
    vector<Statement> bodyStatements;
};