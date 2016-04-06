#include <iostream>
#include <chaiscript/chaiscript.hpp>

#include "creator.hpp"


struct MyClass {

    int memberdata;

    MyClass(int a) {
        memberdata = a;
    }

    void method() {
        memberdata++;
    }

    void method1(int a) {
        memberdata = a;
    }
};

int f(int x, int y)
{
    return x + y;
}

using namespace chaiscript;

int main()
{
    auto chai = chaidec::create_chaiscript();

    chai->add(var(5.0), "five");

    chai->add(fun(f), "f");
    std::cout << chai->eval<int>("f(2, 3)")
              << std::endl;

    chai->add(var(5), "N");
    chai->add(var(2.5), "n");

    std::cout << chai->eval<double>("T(N, 0.1)")
              << std::endl;
    std::cout << chai->eval<double>("U(N, 0.2)")
              << std::endl;
    std::cout << chai->eval<double>("h(N)")
              << std::endl;

    chai->add(constructor<MyClass(int)>(), "MyClass");
    chai->add(fun(&MyClass::memberdata), "memberdata");
    chai->add(fun(&MyClass::method), "method");
    chai->add(fun(&MyClass::method1), "method2");
    chai->add(user_type<MyClass>(), "MyClass");

    auto m = chai->eval("MyClass(5)");
    std::cout << typeid(m).name() << std::endl;
    chai->add(var(m), "m");
    std::cout << chai->eval<int>("m.memberdata")
              << std::endl;

    chai->eval("m.method2(10)");
    std::cout << chai->eval<int>("m.memberdata()")
              << std::endl;

    chai->eval("m.memberdata = 20");
    std::cout << chai->eval<int>("m.memberdata")
              << std::endl;

    auto p = std::make_shared<MyClass>(30);
    chai->add(var(p), "p");
    std::cout << chai->eval<int>("p.memberdata")
              << std::endl;
    p->memberdata = 50;
    std::cout << chai->eval<int>("p.memberdata")
              << std::endl;

    std::cout << "Locals: " << std::endl;
    for (const auto& l : chai->get_locals()) {
        std::cout << "\t"
                  << l.first
                  << "\t"
                  << l.second.get_type_info().name()
                  << "\t"
                  << l.second.get_type_info().bare_name()
                  << std::endl;
    }

}
