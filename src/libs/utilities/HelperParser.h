#include <vector>
#include <string>

#include "enums.h"
#include "Argument.h"
#include "Params.h"

class HelperParser {
    public:
        static vector<Argument> ParseQargs(string s);
        static vector<string> Tokenize(string s, char delimiter = ' ');
        static string GetName(string s);
        static Params* GetParams(string s);
        static vector<Statement> GetBodyStatements(string s);
        static Argument GetConditionCarg(string s);
        static int GetConditionInt(string s);
        static Statement GetIfBlockQop(string s);
        static string GetFilename(string s);
        static Argument* ParseArg(string s);
        static int GetSize(string s);
};