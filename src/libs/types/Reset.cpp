#include "Reset.h"

Reset::Reset(Argument* arg) { this->arg = arg; }

Statement* Reset::Create(Argument* arg) { return new Reset(arg); }

Argument* Reset::getArg() { return this->arg; }
