#include "Version.h"

Version::Version(string version) : Statement("Version") {
    this->version = version;
}

Version* Version::Create(string version) {
    return new Version(HelperParser::Preprocess(version));
}

string Version::getVersion() { return this->version; }
