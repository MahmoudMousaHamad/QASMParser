#include "Statement.h"

class Version : public Statement {
  public:
    Version(string version);
    static Statement* Create(string version);

    string getVersion();

  private:
    string version;
};