#include <chaiscript/chaiscript.hpp>
#include "stdlib.hpp"
#include "bindings.hpp"
#include "creator.hpp"

namespace chaidec {
  std::unique_ptr<chaiscript::ChaiScript> create_chaiscript()
  {
    auto chai = std::unique_ptr<chaiscript::ChaiScript>(new chaiscript::ChaiScript(create_chaiscript_stdlib()));
    chai->add(create_chaiscript_bindings());
    return chai;
  }

}
