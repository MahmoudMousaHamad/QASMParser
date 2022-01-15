#include "Include.h"

Include::Include(string filename) { this->filename = filename; }

Statement* Include::Create(string filename) { return new Include(filename); }

string Include::getFilename() { return this->filename; }

