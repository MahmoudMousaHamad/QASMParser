#include "RegisterDeclaration.h"

RegisterDeclaration::RegisterDeclaration(RegisterType type, string identifier, int size) {
    this->type = type;
    this->identifier = identifier;
    this->size = size;
}

Statement* RegisterDeclaration::Create(string s, RegisterType type) {
    string identifier = HelperParser::GetName(s);
    int size = HelperParser::GetSize(s);
    
    return new RegisterDeclaration(type, identifier, size);
}

RegisterType RegisterDeclaration::getType() { return this->type; }

string RegisterDeclaration::getIdentifier() { return this->identifier; }

int RegisterDeclaration::getSize() { return this->size; }
