#include "Barrier.h"

Barrier::Barrier(vector<Argument> args) {
    this->args = args;
}

Statement Barrier::Create(string s) {
    vector<Argument> args = HelperParser::ParseArgs(s);

    return Barrier(args);
}

vector<Argument> Barrier::getArgs() { return this->getArgs(); }