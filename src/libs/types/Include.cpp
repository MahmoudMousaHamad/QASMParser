#include "Include.h"

Include::Include(string filename) { this->filename = filename; }

Statement Include::Create(string s) { 
    string filename = HelperParser::GetFilename(s);
    
    return Include(filename); 
}

string Include::getFilename() { return this->filename; }

