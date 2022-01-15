#include "Statement.h"

class Include : public Statement {
  public:
    Include(string filename);

    static Statement* Create(string filename);

    string getFilename();

  private:
    string filename;

};