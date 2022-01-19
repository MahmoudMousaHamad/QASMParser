#pragma once
#include "Statement.h"
#include "HelperParser.h"

class GateDeclaration : public Statement {
  public:
    GateDeclaration(
      string identifier,
      Params params,
      vector<Argument> qargs,
      vector<Statement*> bodyStatements,
      GateType gateType
    );

    static GateDeclaration* Create(string s, GateType gateType = GateType::unitary);

    string getIdentifier();
    Params getGateParams();
    vector<Argument> getQargs();
    vector<Statement*> getBodyStatements();
    GateType getGateType();

    boost::any value() { return this; }
    
  private:
    string identifier;
    Params params;
    vector<Argument> qargs;
    vector<Statement*> bodyStatements;
    GateType gateType;
};
