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

int main(int argc, char** argv) {
  ifstream infile(argv[1]);
  string line;
  vector<string> lines;
  vector<Statement*> statements;
  vector<GateApplication*> cx_statements;

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

  #ifdef DEBUG
    cout << "DEBUG 1: " << line << '\n';
  #endif

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

    Statement* s = HelperParser::CreateStatement(line);
    s->id = i;
    statements.push_back(s);
  }

  for (auto* s : statements) {
    cout << s->id << ": ";
    if(s->type == "Version") {
      Version *v = boost::any_cast<Version*>(s->value());
      cout << v->getVersion() << '\n';
    } 
    else if(s->type == "GateDeclaration") {
      GateDeclaration *g = boost::any_cast<GateDeclaration*>(s->value());
      cout << g->getIdentifier() << '\n';
    } else if (s->type == "GateApplication") {
      GateApplication *g = boost::any_cast<GateApplication*>(s->value());
      cout << g->toString() << '\n';
      if (g->getIdentifier() == "cx") {
        cx_statements.push_back(g);
      }
    }
  }

  string pattern_string = "";
  int num_qubits = 127;

  for (GateApplication *g : cx_statements) {
    vector<Argument> gate_args = g->getGateArgs();
    int unique_id = gate_args.at(0).getIndex() * num_qubits + gate_args.at(1).getIndex();
    pattern_string += to_string(unique_id) + " ";
  }

  cout << pattern_string << '\n';
} 
