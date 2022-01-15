using namespace std;

#include <string>

#include "enums.h"

class Params {
  public:
    Params(string theta, string phi, string lambda);

    string getParam(ParamType type);

  private:
    string theta;
    string phi;
    string lambda;
};

class Argument {
  public:
    Argument(ArgumentType type, string identifier, int index);

    ArgumentType getArgumentType();
    string getIdentifier();
    int getIndex();

  private:
    ArgumentType argumentType;
    string identifier;
    int index;
};