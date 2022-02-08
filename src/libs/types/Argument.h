#pragma once

using namespace std;

#include <string>

#include "enums.h"

class Argument {
  public:
    Argument(ArgumentType type, string identifier, int index = -1);
    Argument() = default;

    ArgumentType getArgumentType();
    string getIdentifier();
    int getIndex();

    string toString();
    
  private:
    ArgumentType argumentType;
    string identifier;
    int index;
};