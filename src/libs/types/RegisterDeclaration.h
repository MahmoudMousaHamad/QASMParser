#include "Statement.h"

class RegisterDeclaration : public Statement {
  public:
    RegisterDeclaration(RegisterType type, string identifier, int size);
    static Statement* Create(RegisterType type, string identifier, int size);

    RegisterType getType();
    string getIdentifier();
    int getSize();

  private:
    RegisterType type;
    string identifier;
    int size;

};