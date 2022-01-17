#include "Statement.h"

class Measure : public Statement {
  public:
    Measure(Argument* qarg, Argument* carg);

    static Statement Create(string s);

    Argument* getQarg();
    Argument* getcarg();

  private:
    Argument* qarg;
    Argument* carg;
};