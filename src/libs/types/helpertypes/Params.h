using namespace std;

#include <string>

#include "enums.h"

class Params {
  public:
    Params(string theta, string phi, string lambda);

    string getParam(ParamType type);

  private:
    string theta;
    string phi;
    string lambda;
};