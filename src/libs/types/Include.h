#include "Statement.h"

class Include : public Statement {
  public:
    Include(string filename);

    static Statement Create(string s);

    string getFilename();

  private:
    string filename;

};