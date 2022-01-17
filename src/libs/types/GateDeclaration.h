#include "Statement.h"

class GateDeclaration : public Statement {
  public:
    GateDeclaration(
      string identifier,
      Params *params,
      vector<Argument> qargs,
      vector<Statement> bodyStatements,
      GateType gateType
    );

    static Statement Create(string s, GateType gateType = GateType::unitary);

    string getIdentifier();
    Params* getGateParams();
    vector<Argument> getQargs();
    vector<Statement> getBodyStatements();
    GateType getGateType();
    
  private:
    string identifier;
    Params* params;
    vector<Argument> qargs;
    vector<Statement> bodyStatements;
    GateType gateType;
};
