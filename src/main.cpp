#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
#include <memory>
#include <boost/any.hpp>

#include "HelperParser.h"
#include "Statement.h"

using namespace std;

/*
class Base {
  public:
    Base(string name) {this->name = name;};
    string name = "BaseName";
    virtual ~Base() {};
    virtual boost::any value() = 0;
};

class Derived : public Base {
  public:
    Derived(string derivedName) : Base("TEST_TEST") {this->derivedName = derivedName;};
    string derivedName = "DerivedName";
    boost::any value() { return this; };
};


int main() {

  vector<Base*> objects;

  Derived* derived = new Derived("TESET");

  derived->derivedName = "derivedName";
  derived->name = "name";

  objects.push_back(new Derived("SECOND TEST!!!"));

  Derived *d = dynamic_cast<Derived*>(objects.at(0));

  Derived *d2 = boost::any_cast<Derived*>(objects.at(0)->value());

  return 1;
}

*/


int main(int argc, char** argv) {
  ifstream infile(argv[1]);
  string line;
  vector<string> lines;
  vector<Statement*> statements;

  // convert file to vector, line by line and process each line
  while(getline(infile, line)) {
    string preprocessed =  HelperParser::Preprocess(line);

    // skip if comment
    if ((preprocessed[0] == '/' && preprocessed[1] == '/') || preprocessed == "\n" || preprocessed == "") {
      continue;
    }

    lines.push_back(preprocessed);
  }

  infile.close();

  // convert array of string statements to objects
  for (int i = 0; i < lines.size(); ++i) {
    string line = lines.at(i);
    string gatePrefix = "gate ";

    if (!line.compare(0, gatePrefix.size(), gatePrefix)) {
      line += '\n';
      for (int j = i + 1; j < lines.size(); ++j) {
        line += lines.at(j) + '\n';
        i = j;
        if (lines.at(j).find('}') != string::npos) {
          break;
        }
      }
    }

    statements.push_back(HelperParser::CreateStatement(line));
  }

  for (auto* s : statements) {
    if(s->type == "Version") {
      Version *v = boost::any_cast<Version*>(s->value());
      cout << v->getVersion() << '\n';
    } 
    else if(s->type == "GateDeclaration") {
      GateDeclaration *g = boost::any_cast<GateDeclaration*>(s->value());
      cout << g->getIdentifier() << '\n';
    }
  }
} 
