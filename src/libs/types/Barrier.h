#include "Statement.h"

class Barrier : public Statement {
  public:
    Barrier(vector<Argument> args);
    static Statement* Create(vector<Argument> args);

    vector<Argument> getArgs();

  private:
    vector<Argument> args;
};