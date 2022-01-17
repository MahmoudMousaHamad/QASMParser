#include "Statement.h"

class Reset : public Statement {
  public:
    Reset(Argument* arg);

    static Statement Create(string s);

    Argument* getArg();

  private:
    Argument* arg;
};