using namespace std;

#include <string>
#include <vector>

class Statement {
  public:
    vector<string> gettokens();
  private:
    vector<string> tokens;
  
};