#pragma once
#include "Statement.h"
#include "HelperParser.h"

class Include : public Statement {
  public:
    Include(string filename);

    static Include* Create(string s);

    string getFilename();

    boost::any value() { return this; }

  private:
    string filename;

};