#include "Barrier.h"

Barrier::Barrier(vector<Argument> args) {
    this->args = args;
}

Statement* Barrier::Create(vector<Argument> args) {
    return new Barrier(args);
}

vector<Argument> Barrier::getArgs() { return this->getArgs(); }
