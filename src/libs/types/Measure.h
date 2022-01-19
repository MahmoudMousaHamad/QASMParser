#pragma once
#include "Statement.h"
#include "Argument.h"
#include "HelperParser.h"

class Measure : public Statement {
  public:
    Measure(Argument qarg, Argument carg);

    static Measure* Create(string s);

    Argument getQarg();
    Argument getcarg();

    boost::any value() { return this; }
    
  private:
    Argument qarg;
    Argument carg;
};