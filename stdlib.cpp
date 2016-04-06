#include <chaiscript/chaiscript_stdlib.hpp>
#include "stdlib.hpp"

namespace chaidec {
  std::shared_ptr<chaiscript::Module> create_chaiscript_stdlib()
  {
    return chaiscript::Std_Lib::library();
  }
}

