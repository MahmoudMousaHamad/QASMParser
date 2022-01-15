#include "Statement.h"

class Reset : public Statement {
  public:
    Reset(Argument* arg);

    static Statement* Create(Argument* arg);

    Argument* getArg();

  private:
    Argument* arg;
};