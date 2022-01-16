using namespace std;

#include <string>
#include <vector>

#include "Argument.h"
#include "enums.h"
#include "Params.h"
#include "HelperParser.h"

class Statement {
  public:
    vector<string> gettokens();
  private:
    vector<string> tokens;
  
};