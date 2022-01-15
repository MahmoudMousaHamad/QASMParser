#include "Version.h"

Version::Version(string version) {
    this->version = version;
}

Statement* Version::Create(string version) {
    return new Version(version);
}

string Version::getVersion() { return this->version; }
