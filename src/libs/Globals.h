#include <map>

#include "Statement.h"

typedef Statement* (*StatementFactory)();
extern map<string, StatementFactory>  statementlookup;

