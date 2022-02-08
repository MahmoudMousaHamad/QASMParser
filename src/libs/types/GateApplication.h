#pragma once
#include "Statement.h"
#include "HelperParser.h"

class GateApplication : public Statement {
  public:
    GateApplication(string gateIdentifier, 
                    GateType gateType,
                    Params gateParams, 
                    vector<Argument> gateArguments);

    static GateApplication* Create(string gateIdentifier, string s);

    GateType getGateType();
    Params getGateParams();
    vector<Argument> getGateArgs();
    string getIdentifier();

    string toString();

    boost::any value() { return this; }

  private:
    string identifier;
    GateType gateType;
    Params gateParams;
    vector<Argument> gateArgs;

};