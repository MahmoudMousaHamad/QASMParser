#include "Barrier.h"

Barrier::Barrier(vector<Argument> args) : Statement("Barrier") {
    this->args = args;
}

Barrier* Barrier::Create(string s) {
    vector<Argument> args = HelperParser::ParseArgs(s);

    return new Barrier(args);
}

vector<Argument> Barrier::getArgs() { return this->getArgs(); }