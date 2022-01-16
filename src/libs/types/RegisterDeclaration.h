#include "Statement.h"

class RegisterDeclaration : public Statement {
  public:
    RegisterDeclaration(RegisterType type, string identifier, int size);
    static Statement* Create(string s, RegisterType type);

    RegisterType getType();
    string getIdentifier();
    int getSize();

  private:
    RegisterType type;
    string identifier;
    int size;

};