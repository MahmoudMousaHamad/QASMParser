#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>

#include "Statement.h"

using namespace std;

template <typename Out>
void split(const string &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

vector<string> split(const string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

int main() {
  ifstream infile("filename.qasm");
  string line;

  while(getline(infile, line)) {
    string preprocessed =  HelperParser::Preprocess(line);
    // skip if comment
    if (preprocessed[0] == '/' && preprocessed[1] == '/') {
      continue;
    }

    // split line into tokens delimttied by space
    vector<string> tokens = split(preprocessed, ' ');
  
    Statement current = HelperParser::CreateStatement(preprocessed);
  }
} 