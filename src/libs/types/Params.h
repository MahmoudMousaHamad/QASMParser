#pragma once

using namespace std;

#include <string>
#include <vector>

#include "enums.h"

class Params {
  public:
    Params() = default;
    Params(vector<string> params);
    Params(string theta, string phi, string lambda);

    string getParam(ParamType type);

  private:
    string theta;
    string phi;
    string lambda;
};