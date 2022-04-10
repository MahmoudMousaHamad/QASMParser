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

vector<vector<int>> get_segments(vector<int>* operations_stream, int pattern_length, map<int,int>* historgram) {
  printf("DEBUG: Running for pattern length %d\n", pattern_length);
  // Build pattern map
  map<vector<int>, PatternInfo> map = build_pattern_map(operations_stream, pattern_length);  
  
  // Get max count
  int max_count = 0;
  for (auto i = map.cbegin(); i != map.cend();) {
    if (i->second.count > max_count) {
      max_count = i->second.count;
    }
    i++;
  }

  // remove all patterns that have count less than max count
  for (auto i = map.cbegin(); i != map.cend();) {
    if (i->second.count < max_count) {
      map.erase(i++);
    } else {
      i++;
    }
  }

  // If map empty, return empty segments
  if (map.empty() || max_count == 1) {
    vector<vector<int>> empty;
    return empty;
  }

  // Write patterns to file
  ofstream patterns_file;
  patterns_file.open("../experiment/patterns_file.txt", ios_base::app);
  for (auto i = map.cbegin(); i != map.cend();) {
    patterns_file << "" << i->second.count << ',';
    if (historgram->count(pattern_length) > 0) {
      historgram->at(pattern_length) = historgram->at(pattern_length) + i->second.count;
    } else {
      historgram->insert(pair<int,int>(pattern_length, i->second.count));
    }
    vector<int> pattern = i->first;
    for (int n : pattern) {
      patterns_file << n << ' ';
    }
    patterns_file << '\n';
    ++i;
  }

  // Get segments
  vector<vector<int>> segments;

  // put all pattern start indeces in one set
  set<int> *global_indeces = new set<int>();
  for (auto i = map.begin(); i != map.end(); ++i) {
    for (int index : i->second.indeces){
      global_indeces->insert(index);
    }
  }

  // convert set to vector to iterate over it in order
  vector<int> *indeces_vector = new vector<int>(global_indeces->size()); 
  copy(global_indeces->begin(), global_indeces->end(), indeces_vector->begin());
  
  free(global_indeces);

  // Get segments 
  for (int i = 0; i < indeces_vector->size() - 1; i++) {
    vector<int> segment;

    int current_pattern_end = indeces_vector->at(i) + pattern_length - 1;
    int next_pattern_start = indeces_vector->at(i + 1);

    int segment_length = next_pattern_start - current_pattern_end - 1;
    if (segment_length >= 2) {
      int segment_start = current_pattern_end + 1;
      int segment_end = next_pattern_start;
      printf("DEBUG: printing found segment of size %d:\n", segment_length);
      for (int j = segment_start; j < segment_end; ++j) {
        printf("%d ", operations_stream->at(j));
        segment.push_back(operations_stream->at(j));
      }
      printf("\n");
      segments.push_back(segment);
    }
  }

  free(indeces_vector);
  
  return segments;
}

int main(int argc, char** argv) {
  ifstream infile(argv[1]);
  string histogram_file_name = argc == 3 ? argv[2] : "../experiment/histogram.txt";
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

  // Example: 257 1 383 ( 257 381 ) 257 1 383 ( 129 1 257 ) 257 1 383
  // Segments:  257 381, 129 1 257

  int num_qubits = 127;
  int pattern_length = 2;
  vector<int> *operations_stream = new vector<int>();

  // Generate operations stream
  printf("DEBUG: initial operations stream:\n");
  for (GateApplication *g : cx_statements) {
    vector<Argument> gate_args = g->getGateArgs();
    int unique_id = gate_args.at(0).getIndex() * num_qubits + gate_args.at(1).getIndex();
    operations_stream->push_back(unique_id);
    printf("%d ", unique_id);
  }

  // First get segments for l=2, then run l=3 on the segments and store new segments
  // keep doing that until l=10
  // Repeat for l=10 until l=2

  map<int, int> histogram;
  vector<vector<int>> segments = get_segments(operations_stream, pattern_length, &histogram);
  vector<vector<int>> temp;
  vector<vector<int>> temp2;

  pattern_length = 3;

  while (pattern_length <= 10) {
    for (vector<int> segment : segments) {
      if (segment.size() < pattern_length) continue;
      temp2 = get_segments(&segment, pattern_length, &histogram);
      temp.insert(temp.begin(), temp2.begin(), temp2.end());
    }
    segments = temp;
    pattern_length++;
  }

  pattern_length = 10;

  segments = get_segments(operations_stream, pattern_length, &histogram);

  pattern_length = 9;

  // get all segments after getting all max patterns from 10 to 2
  while (pattern_length >= 3) {
    for (vector<int> segment : segments) {
      if (segment.size() < pattern_length) continue;
      temp2 = get_segments(&segment, pattern_length, &histogram);
      temp.insert(temp.begin(), temp2.begin(), temp2.end());
    }
    segments = temp;
    pattern_length--;
  }

  // Write historgram values to file for later graphical representation using python
  ofstream histogram_file;
  histogram_file.open(histogram_file_name);
  for(auto i = histogram.begin(); i != histogram.end(); ++i) {
    histogram_file << i->first << ',' << i->second << '\n';
  }

  // Keep running experiment until segments are not empty
  // while (segments.empty() && pattern_length <= 10) {
  //   segments = run(operations_stream, pattern_length++);
  // }

  // vector<vector<int>> new_segments;

  // // Run for pattern length++ on segments until pattern length = 10
  // pattern_length++;
  // while(pattern_length <= 10) {
  //   while (segments.empty() && pattern_length <= 10) {
  //     segments = run(operations_stream, pattern_length);
  //     pattern_length++;
  //   }
  //   for (vector<int> segment : segments) {
  //     if (segment.size() > pattern_length) {
  //       printf("DEBUG: segment\n");
  //       vector<vector<int>> temp = run(&segment, pattern_length); 
  //       new_segments.insert(new_segments.begin(), temp.begin(), temp.end());
  //     }
  //   }
  //   segments = new_segments;
  //   pattern_length++;
  // }  
} 
