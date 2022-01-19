#pragma once

#include "Statement.h"
#include "HelperParser.h"

class RegisterDeclaration : public Statement {
  public:
    RegisterDeclaration(RegisterType type, string identifier, int size);
    static RegisterDeclaration* Create(string s, RegisterType type);

    RegisterType getType();
    string getIdentifier();
    int getSize();

    boost::any value() { return this; }
    
  private:
    RegisterType type;
    string identifier;
    int size;

};