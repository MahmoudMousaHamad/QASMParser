using namespace std;

#include <string>
#include <vector>

#include "enums.h"
#include "helperclasses.h"

class Statement {
  public:
    vector<string> gettokens();
  private:
    vector<string> tokens;
  
};