#include "Argument.h"

Argument::Argument(ArgumentType type, string identifier, int index = -1) {
    this->argumentType = type;
    this->identifier = identifier;
    this->index = index;
}

string Argument::getIdentifier() {
    return this->identifier;
}

int Argument::getIndex() {
    return this->index;
}