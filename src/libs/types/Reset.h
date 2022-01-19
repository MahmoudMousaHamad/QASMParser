#pragma once

#include "Statement.h"
#include "Argument.h"

class Reset : public Statement {
  public:
    Reset(Argument arg);
    static Reset* Create(string s);
    Argument getArg();

    boost::any value() { return this; }

  private:
    Argument arg;
};