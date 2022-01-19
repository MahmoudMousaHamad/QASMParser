#pragma once

#include "HelperParser.h"

class Barrier : public Statement {
  public:
    Barrier(vector<Argument> args);
    static Barrier* Create(string s);

    vector<Argument> getArgs();

    boost::any value() { return this; }

  private:
    vector<Argument> args;
};