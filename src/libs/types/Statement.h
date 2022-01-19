#pragma once

using namespace std;

#include <string>
#include <vector>
#include <boost/any.hpp>

class Statement {
  public:
    Statement(string type) {this->type = type;};
    virtual ~Statement() {};
    string type; 
    virtual boost::any value() = 0;
  private:
};