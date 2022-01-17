#include "HelperParser.h"

using namespace std;

vector<Argument> HelperParser::ParseArgs(string s) {
    vector<Argument> qargs;

    vector<string> tokens = Tokenize(s, ',');

    for (int i = 0; i < tokens.size(); ++i) {
        string sarg = tokens[i];
        Argument arg = ParseArg(sarg, ArgumentType::quantum);

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
    string identifier = getSubstring(s, "(", "==");

    Argument carg = Argument(ArgumentType::creg, identifier);

    return carg;
}

int HelperParser::GetConditionInt(string s) {
    return stoi(getSubstring(s, "==", ")"));
}

Statement HelperParser::GetIfBlockQop(string s) {
    int qopIndex = s.find_first_of(")") + 2; // find ) then add two to index so that you skip space
    string sstatement = s.substr(qopIndex, s.size() - qopIndex);
    string preprocessed = Preprocess(sstatement);

    return CreateStatement(preprocessed);
}

string HelperParser::GetFilename(string s) {
    return getSubstring(s, "\"", "\"");
}

Argument HelperParser::ParseArg(string s, ArgumentType generalType) {
    bool reg = s.find('[') == string::npos;

    string identifier = reg ?  Preprocess(s) : GetName(s);

    ArgumentType type;

    // determine specific type of argument
    if (reg) {
        // reg
        if (generalType == ArgumentType::classical) {
            type = ArgumentType::creg;
        } else {
            type = ArgumentType::qreg;
        }
    } else {
        // q/c bit
        if (generalType == ArgumentType::quantum) {
            type = ArgumentType::qubit;
        } else {
            type = ArgumentType::bit;
        }
    }

    // index
    int index;

    if (reg) {
        index = -1;
    } else {
        index = stoi(getSubstring(s, "[", "]"));
    }

    return Argument(type, identifier, index);
}

int HelperParser::GetSize(string s) {
    return stoi(getSubstring(s, "[", "]"));
}

Statement HelperParser::CreateStatement(string s) {
    // get command
    string* commandAndStatement = GetCommandAndStatement(s);
    string command = commandAndStatement[0];
    s = commandAndStatement[1];

    Statement statement;

    if (command == "OPENQASM") {
        statement = Version::Create(s);
    }
    else if (command == "qreg") {
        statement = RegisterDeclaration::Create(s, RegisterType::quantum);
    }
    else if (command == "creg") {
        statement = RegisterDeclaration::Create(s, RegisterType::classical);
    }
    else if (command == "include") {
        statement = Include::Create(s);
    }
    else if (command == "gate") {
        statement = GateDeclaration::Create(s, GateType::unitary);
    }
    else if (command == "opaque") {
        statement = GateDeclaration::Create(s, GateType::opaque);
    }
    else if (command == "measure") {
        statement = Measure::Create(s);
    }
    else if (command == "reset") {
        statement = Reset::Create(s);
    }
    else if (command == "if") {
        statement = IfBlock::Create(s);
    }
    else if (command == "barrier") {
        statement = Barrier::Create(s);
    } else {
        statement = GateApplication::Create(s);
    }

    return statement;
}

string HelperParser::Preprocess(string s) {
    // remove semi colon
    int charIndex = s.find(';');
    if (charIndex >= 0) {
        s = s.substr(0, charIndex);
    }

    // remove white space
    return trim(s);
}

string* HelperParser::GetCommandAndStatement(string s) {
    string array[2];

    int index = 0;
    char current = s.at(index);
    while (current != ' ' || current != '(') {
        current = s.at(index++);
    }
    string command = s.substr(0, index);
    string statement = s.substr(index, s.size() - index);

    array[0] = command;
    array[1] = statement;

    return array;
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

string trim(const string &s){
    auto start = s.begin();
    while (start != s.end() && std::isspace(*start)) {
        start++;
    }
 
    auto end = s.end();
    do {
        end--;
    } while (distance(start, end) > 0 && isspace(*end));
 
    return string(start, end + 1);
}
