#include <iostream>

class ClassA
{
public:
  void DoSomething() {
    std::cout << "A" << std::endl;
  }
};

class ClassB
{
public:
  void DoSomething() {
    std::cout << "B" << std::endl;
    ClassA a = ClassA();
    a.DoSomething();
  }
};

class ClassC
{
public:
  void DoSomething() {
    std::cout << "C" << std::endl;
    ClassA a = ClassA();
    a.DoSomething();
    ClassB b = ClassB();
    b.DoSomething();
    b.DoSomething();
  }
};

class Facade
{
public:
  void DoDomainLogic() {
    ClassC c = ClassC();
    c.DoSomething();
  }
};

int main() {
  std::cout << "==== start ====" << std::endl;
  Facade f = Facade();
  f.DoDomainLogic();
  std::cout << "==== end ====" << std::endl;
}
