using namespace std;

#include "statement.h"
#include "enums.h"
#include "helperclasses.h"

class Version : public Statement {
  public:
    Version(string version);
    static Statement* Create(string version);

    string getVersion();

  private:
    string version;
};

class RegisterDeclaration : public Statement {
  public:
    RegisterDeclaration(RegisterType type, string identifier, int size);
    static Statement* Create(RegisterType type, string identifier, int size);

    RegisterType getType();
    string getIdentifier();
    int getSize();

  private:
    RegisterType type;
    string identifier;
    int size;

};

class Include : public Statement {
  public:
    Include(string filename);

    static Statement* Create(string filename);

    string getFilename();

  private:
    string filename;

};

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

class GateApplication : public Statement {
  public:
    GateApplication(GateType gateType, Params* gateParams, vector<Argument> gateArguments);

    static Statement* Create(GateType gateType, Params* gateParams, vector<Argument> gateArguments);

    GateType getGateType();
    Params* getGateParams();
    vector<Argument> getGateArgs();

  private:
    GateType gateType;
    Params* gateParams;
    vector<Argument> gateArgs;

};

class Measure : public Statement {
  public:
    Measure(Argument* qarg, Argument* carg);

    static Statement* Create(Argument* qarg, Argument* carg);

    Argument* getQarg();
    Argument* getcarg();

  private:
    Argument* qarg;
    Argument* carg;
};

class Reset : public Statement {
  public:
    Reset(Argument* arg);

    static Statement* Create(Argument* arg);

    Argument* getArg();

  private:
    Argument* arg;
};

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

class Barrier : public Statement {
  public:
    Barrier(vector<Argument> args);
    static Statement* Create(vector<Argument> args);

    vector<Argument> getArgs();

  private:
    vector<Argument> args;
};

