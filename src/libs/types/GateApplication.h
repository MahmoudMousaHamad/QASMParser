#pragma once
#include "Statement.h"
#include "HelperParser.h"

class GateApplication : public Statement {
  public:
    GateApplication(GateType gateType, Params gateParams, vector<Argument> gateArguments);

    static GateApplication* Create(string s);

    GateType getGateType();
    Params getGateParams();
    vector<Argument> getGateArgs();

    boost::any value() { return this; }

  private:
    string identifier;
    GateType gateType;
    Params gateParams;
    vector<Argument> gateArgs;

};