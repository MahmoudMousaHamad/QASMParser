#include "Statement.h"

class GateDeclaration : public Statement {
  public:
    GateDeclaration(
      string identifier,
      Params *params,
      vector<string> qargs,
      vector<Statement> bodyStatements,
      GateType gateType
    );

    static Statement* Create(
      string identifier,
      Params *params,
      vector<string> qargs,
      vector<Statement> bodyStatements,
      GateType gateType
    );

    string getIdentifier();
    Params* getGateParams();
    vector<string> getQargs();
    vector<Statement> getBodyStatements();
    GateType getGateType();
    
  private:
    string identifier;
    Params* params;
    vector<string> qargs;
    vector<Statement> bodyStatements;
    GateType gateType;
};
