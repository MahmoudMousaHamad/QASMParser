#include "Statement.h"

class Barrier : public Statement {
  public:
    Barrier(vector<Argument> args);
    static Statement Create(string s);

    vector<Argument> getArgs();

  private:
    vector<Argument> args;
};