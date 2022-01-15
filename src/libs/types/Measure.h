#include "Statement.h"

class Measure : public Statement {
  public:
    Measure(Argument* qarg, Argument* carg);

    static Statement* Create(Argument* qarg, Argument* carg);

    Argument* getQarg();
    Argument* getcarg();

  private:
    Argument* qarg;
    Argument* carg;
};