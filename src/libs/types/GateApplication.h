#include "Statement.h"

class GateApplication : public Statement {
  public:
    GateApplication(GateType gateType, Params* gateParams, vector<Argument> gateArguments);

    static Statement Create(string s);

    GateType getGateType();
    Params* getGateParams();
    vector<Argument> getGateArgs();

  private:
    GateType gateType;
    Params* gateParams;
    vector<Argument> gateArgs;

};