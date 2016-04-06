#ifndef CHAISCRIPT_CREATOR
#define CHAISCRIPT_CREATOR

#include <memory>

namespace chaiscript {
  class ChaiScript;
}

namespace chaidec {
  std::unique_ptr<chaiscript::ChaiScript> create_chaiscript();
}

#endif
