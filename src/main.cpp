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
#include <set>

#include "HelperParser.h"
#include "Statement.h"
#include "PatternInfo.h"

using namespace std;


map<vector<int>, PatternInfo> build_pattern_map(vector<int>* operations_stream, int pattern_length) {
  map<vector<int>, PatternInfo> map;

  for(int i = 0; i < operations_stream->size() - pattern_length; ++i) {
    vector<int> current_subarray;
    for (int j = i; j < i + pattern_length; ++j) {
      current_subarray.push_back(operations_stream->at(j));
    }
    if (map.count(current_subarray) > 0) {
      map[current_subarray].count++;
      map[current_subarray].indeces.push_back(i);
    } else {
      PatternInfo pi;
      pi.count = 1;
      pi.indeces.push_back(i);

      map.insert(pair<vector<int>, PatternInfo>(current_subarray, pi));
    }
  }
  return map;
}

vector<vector<int>> run(vector<int>* operations_stream, int pattern_length) {
  // Build pattern map
  map<vector<int>, PatternInfo> map = build_pattern_map(operations_stream, pattern_length);
  
  // Filter 
  for (auto i = map.cbegin(); i != map.cend();) {
    if (i->second.count <= 1) {
      map.erase(i++);
    } else {
      ++i;
    }
  }

  // Write patterns to file
  // for (auto i = map.begin(); i != map.end(); ++i) {
  //   vector<int> pattern = i->first;
  //   for (int num : pattern) {
  //     printf("%d ", num);
  //   }
  //   printf("count: %d\n", i->second.count);
  // }

  // Update count for pattern_length in histogram

  // Generate segments after slicing original operations stream
  vector<vector<int>> segments;
  set<int> *global_indeces = new set<int>();
  int previous_index = -1;
  for (auto i = map.begin(); i != map.end(); ++i) {
    vector<int> indeces = i->second.indeces;
    for (int index : indeces){
      if (abs(index - previous_index) >= pattern_length || previous_index == -1){
        global_indeces->insert(index);
        previous_index = index;
      }
    }
  }

  previous_index = -1 * pattern_length;
  for (auto i = global_indeces->begin(); i != global_indeces->end(); ++i) {
    vector<int> segment;
    for (int j = previous_index + pattern_length; j < *i; ++j) {
      segment.push_back(operations_stream->at(j));
    }
    previous_index = *i;
    if (segment.size() > pattern_length) {
      segments.push_back(segment);
    }
  }
  
  return segments;
}

int main(int argc, char** argv) {
  ifstream infile(argv[1]);
  string line;
  vector<string> lines;
  vector<Statement*> statements;
  vector<GateApplication*> cx_statements;

  // convert file to vector, line by line and process each line
  while(getline(infile, line)) {
    // skip if comment
    if ((line[0] == '/' && line[1] == '/') || line == "\n" || line == "") {
      continue;
    }

    lines.push_back(HelperParser::Preprocess(line));
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

    Statement* s = HelperParser::CreateStatement(line);
    s->id = i;
    statements.push_back(s);
  }

  for (auto* s : statements) {
    if (s->type == "GateApplication") {
      GateApplication *g = boost::any_cast<GateApplication*>(s->value());
      if (g->getIdentifier() == "cx") {
        cx_statements.push_back(g);
      }
    }
  }

  // Example: 257 1 383 257 381 257 1 383 129 1 257 257 1 383
  // Segments:  257 381, 129 1 257

  int num_qubits = 127;
  int pattern_length = 2;
  vector<int> *operations_stream = new vector<int>();

  // Generate operations stream
  for (GateApplication *g : cx_statements) {
    vector<Argument> gate_args = g->getGateArgs();
    int unique_id = gate_args.at(0).getIndex() * num_qubits + gate_args.at(1).getIndex();
    operations_stream->push_back(unique_id);
    cout << unique_id << " ";
  }
  cout << "\n\n";

  vector<vector<int>> segments = run(operations_stream, pattern_length);
  free(operations_stream);

  vector<vector<int>> new_segments;

  // Run for pattern length++ on segments until pattern length = 10
  pattern_length++;
  cout << segments.size() << "\n";
  while(pattern_length <= 10) {
    for (vector<int> segment : segments) {
      for(int num : segment) {
        printf("%d ", num);
      }
      printf("\n");
      vector<vector<int>> temp = run(&segment, pattern_length); 
      new_segments.insert(new_segments.begin(), temp.begin(), temp.end());
    }
    segments = new_segments;
    cout << segments.size() << "\n";
    pattern_length++;
  }  
} 
