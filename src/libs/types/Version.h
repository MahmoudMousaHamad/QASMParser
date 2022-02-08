#pragma once

#include "Statement.h"
#include "HelperParser.h"

class Version : public Statement {
  public:
    Version(string version);
    static Version* Create(string version);
    string getVersion();

    boost::any value() { return this; }

  private:
    string version;
};