#include "HelperParser.h"

vector<Argument> HelperParser::ParseArgs(string s) {
    vector<Argument> qargs;

    vector<string> tokens = Tokenize(s, ',');

    for (int i = 0; i < tokens.size(); ++i) {
        string sarg = tokens[i];
        Argument arg = ParseArg(sarg);

        qargs.push_back(arg);
    }

    return qargs;
}

vector<string> HelperParser::Tokenize(string s, char delimiter = ' ') {
    return split(s, delimiter);
}

string HelperParser::GetName(string s) {
    string name = "";

    int counter = 0;
    char current = s[counter];
    while (current != '(' || current != '[') {
        name += current;
        current = s[counter++];
    }

    return name;
}

Params HelperParser::GetParams(string s) {
    // tokenize
    vector<string> tokens = Tokenize(getSubstring(s, "(", ")"), ',');

    return Params(&tokens[0]);
}

vector<Statement> HelperParser::GetBodyStatements(string s) {

}

Argument HelperParser::GetConditionCarg(string s) {

}

int HelperParser::GetConditionInt(string s) {

}

Statement HelperParser::GetIfBlockQop(string s) {

}

string HelperParser::GetFilename(string s) {

}

Argument HelperParser::ParseArg(string s) {

}

int HelperParser::GetSize(string s) {

}

template <typename Out>
void HelperParser::split(const string &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

vector<string> HelperParser::split(const string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}

string getSubstring(string s, string first, string second) {
    int firstIndex = s.find_first_of(first);
    int secondIndex = s.find_last_of(second);

    return s.substr(firstIndex + 1, secondIndex - firstIndex);
}