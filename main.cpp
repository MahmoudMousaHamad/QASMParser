#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>

#include "statement.h"

using namespace std;

template <typename Out>
void split(const std::string &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

int main() {
  ifstream infile("filename.qasm");
  string line;
  
  typedef Statement* (*StatementFactory)();
  map<string, StatementFactory>  statementlookup;
  // TODO: generate statementlookup map

  while(getline(infile, line)) {
    // preprocess (strip) line 
    // TODO: remove semi colon at end of line
    string::iterator end_pos = remove(line.begin(), line.end(), ' ');
    line.erase(end_pos, line.end());

    // skip if comment
    if (line[0] == '/' && line[1] == '/') {
      continue;
    }

    // split line into tokens delimttied by space
    vector<string> tokens = split(line, ' ');
    
    // get statement type
    string command = tokens[0];
  }
} 