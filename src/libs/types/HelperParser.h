#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>

#include "Argument.h"
#include "enums.h"
#include "Params.h"
#include "Statement.h"
#include "Barrier.h"
#include "GateApplication.h"
#include "GateDeclaration.h"
#include "IfBlock.h"
#include "Include.h"
#include "Measure.h"
#include "RegisterDeclaration.h"
#include "Reset.h"
#include "Version.h"

class HelperParser {
    public:
        static vector<Argument> ParseArgs(string s);
        static vector<string> Tokenize(string s, char delimiter);
        static vector<string> TokenizeUntil(string s, char delimiter, string until);
        static string GetName(string s);
        static Params GetParams(string s);
        static vector<Statement*> GetBodyStatements(string s);
        static Argument GetConditionCarg(string s);
        static int GetConditionInt(string s);
        static Statement* GetIfBlockQop(string s);
        static string GetFilename(string s);
        static Argument ParseArg(string s, ArgumentType type);
        static int GetSize(string s);
        static Statement* CreateStatement(string s);
        static string Preprocess(string s);
        static string* GetCommandAndStatement(string s);
        static string RemoveChars(string s, string chars);
    
    private: 
        template <typename Out>
        static void split(const string &s, char delim, Out result);
        static vector<string> split(const string &s, char delim);
        static string getSubstringBetweenChars(string s, char first, char second);
        static string getSubstring(string s, string first, string second);
        static string trim(const string &s);
};

