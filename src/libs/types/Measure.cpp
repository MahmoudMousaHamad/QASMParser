#include "Measure.h"

Measure::Measure(Argument *qarg, Argument *carg) {
    this->qarg = qarg;
    this->carg = carg;
}

Statement* Measure::Create(Argument *qarg, Argument *carg) {
    return new Measure(qarg, carg);
}

Argument* Measure::getQarg() { return this->qarg; }

Argument* Measure::getcarg() { return this->carg; }
