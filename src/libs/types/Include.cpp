#include "Include.h"

Include::Include(string filename) : Statement("Include") { this->filename = filename; }

Include* Include::Create(string s) { 
    string filename = HelperParser::GetFilename(s);
    
    return new Include(filename); 
}

string Include::getFilename() { return this->filename; }

