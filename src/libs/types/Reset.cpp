#include "Reset.h"

Reset::Reset(Argument* arg) { this->arg = arg; }

Statement* Reset::Create(string s) { 
    Argument *arg = HelperParser::ParseArg(s, ArgumentType::quantum);

    return new Reset(arg); 
}

Argument* Reset::getArg() { return this->arg; }
