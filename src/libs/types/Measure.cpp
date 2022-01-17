#include "Measure.h"

Measure::Measure(Argument *qarg, Argument *carg) {
    this->qarg = qarg;
    this->carg = carg;
}

Statement* Measure::Create(string s) {
    vector<string> tokens = HelperParser::Tokenize(s);

    Argument *qarg = HelperParser::ParseArg(tokens[0], ArgumentType::quantum);
    Argument *carg = HelperParser::ParseArg(tokens[2], ArgumentType:classical);
    
    return new Measure(qarg, carg);
}

Argument* Measure::getQarg() { return this->qarg; }

Argument* Measure::getcarg() { return this->carg; }
