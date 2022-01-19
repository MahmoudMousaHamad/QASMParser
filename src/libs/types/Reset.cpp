#include "Reset.h"
#include "HelperParser.h"

Reset::Reset(Argument arg) :  Statement("Reset") { this->arg = arg; }

Reset* Reset::Create(string s) { 
    Argument arg = HelperParser::ParseArg(s, ArgumentType::quantum);

    return new Reset(arg); 
}

Argument Reset::getArg() { return this->arg; }
