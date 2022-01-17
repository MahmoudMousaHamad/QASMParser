using namespace std;

#include <string>

#include "enums.h"

class Argument {
  public:
    Argument(ArgumentType type, string identifier, int index = -1);

    ArgumentType getArgumentType();
    string getIdentifier();
    int getIndex();

  private:
    ArgumentType argumentType;
    string identifier;
    int index;
};