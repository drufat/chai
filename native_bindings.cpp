#include <chaiscript/chaiscript.hpp>

#include "bindings.hpp"

#define ADD_MET(Class, Name) module->add(chaiscript::fun(&Class::Name), #Name )
#define ADD_FUN(Name) module->add(chaiscript::fun(&Name), #Name )


double
T(int N, double x)
{
    return N*x;
}

double
U(int N, double x)
{
    return N*x;
}

double
h(int i)
{
    return 2.0*i;
}

namespace chaidec {

  std::shared_ptr<chaiscript::Module> create_chaiscript_bindings()
  {
    auto module = std::make_shared<chaiscript::Module>();

    ADD_FUN(T);
    ADD_FUN(U);
    ADD_FUN(h);

    return module;
  }

}
